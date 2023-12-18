#include "WorldMapLostRuins.h"
#include "Base/Base.create.h"
#include "Base/Utils/XTransition.h"
#include "Base/Math/Math.Base.h"
#include "Base/Functions/ServiceFunction.h"
#include "Module/UI/EventCenter/EventTemplate/LostRuins/UILostRuinsMap.Tip.h"
#include "Module/UI/EventCenter/EventTemplate/LostRuins/LostRuins.Ctrl.h"
#include "Module/UI/EventCenter/EventTemplate/LostRuins/LostRuins.Read.h"
#include "Module/UI/EventCenter/EventTemplate/LostRuins/UIWorldMapLostRuinsSurvey.View.h"
#include "Module/UI/EventCenter/EventTemplate/LostRuins/UIWorldMapLostRuins.View.h"
#include "Module/Player/LordInfo.Ctrl.h"


#define CD_TIME 120

void WorldMapLostRuins::Ctor() {
  _CreateUID = 0;
  _LeagueID = 0;
  _Status = ELosRuinsStatus::SURVEY;
  _LostRuins = GDisplay::Get()->NewSprite("Map_build_lostRuin.png");
  addChild(_LostRuins);
  _LostRuinsEffect = GDisplay::Get()->NewSprite("dh_yijijianzhu_00.png");
  _LostRuins->addChild(_LostRuinsEffect);
  _LostRuinsEffect->setPosition(123, 179);
  auto lFrames = GDisplay::Get()->NewFrames("dh_yijijianzhu_%.2d.png", 0, 15);
  auto lAnimation = GDisplay::Get()->NewAnimation(lFrames, 0.08333333333333333f);
  XTransition::Get()->PlayAnimationForever(_LostRuinsEffect, lAnimation);
  _CDTipNode = UILostRuinsMapTip::Create();
  _LostRuins->addChild(_CDTipNode);
  _CDTipNode->setPosition(Vec2(120, 60));
  GBase::RCreateLabelParm lParm;
  lParm._Text = "";
  lParm._FontSize = 20;
  _CampNameLabel = GBase::DCreateLabel(lParm);

  _CampNameLabel->setAnchorPoint(Vec2(0.5, 0.5));
  _CampNameLabel->setPosition(Vec2(0, -55));
  // self.campNameLabel:setGroupID(worldMapDefine.GROU_ID.group_text)
  addChild(_CampNameLabel);
  _SpriteBg = GDisplay::Get()->NewSprite("frame_main_receive.png");
  _SpriteBg->setAnchorPoint(Vec2(0.5, 0));
  _SpriteBg->setPosition(Vec2(155, 115));
  _LostRuins->addChild(_SpriteBg);
  _SpriteBg->setScale(0.5f);
  _StatusImg = GDisplay::Get()->NewSprite("icon_set_search.png");
  _StatusImg->setAnchorPoint(Vec2(0.5, 0.5));
  _StatusImg->setPosition(Vec2(40, 42));
  _SpriteBg->addChild(_StatusImg);
}

void WorldMapLostRuins::OnMessageListener() {
  GBase::DAddMessage(this, "MESSAGE_LOST_RUINS_REFRESH", CC_CALLBACK_1(WorldMapLostRuins::UpdateData, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_WORLD_MAP_EVENT_LSIT_INFO_NEW", CC_CALLBACK_1(WorldMapLostRuins::UpdateData, this));
}

void WorldMapLostRuins::SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) {}

void WorldMapLostRuins::AddCacheBefore() {}

void WorldMapLostRuins::InitInstanceData(int32 pResourceClassID, void *pData, int32 pObjData) {
  UpdateData(nullptr);
}

void WorldMapLostRuins::UpdateData(EventCustom *pEvent){
  auto lQuestInfo = LostRuinsCtrl::Get()->GetQuestInfo(Vec2(_TilePoint.x + 1, _TilePoint.y + 1));
  _Status = lQuestInfo._State;
  _SpriteBg->setVisible(true);
  _CDTipNode->setVisible(false);
  _LostRuinsEffect->setVisible(true);

  if(_Status == ELosRuinsStatus::SURVEY){
    auto [lSurveying, lLeftTime, lTotalTime]  = IsSurveying();
    if(lSurveying){
      _CDTipNode->InitActivityTime(lLeftTime, lTotalTime, _Status, lSurveying);
      _CDTipNode->setVisible(true);
      _SpriteBg->setVisible(false);
    }else{
      _StatusImg->setSpriteFrame("icon_lostRuins_quest.png");
    }
  } else if(_Status == ELosRuinsStatus::NOT_RECIEVE){
    _StatusImg->setSpriteFrame("icon_lostRuins_gth.png");
  } else if(_Status == ELosRuinsStatus::RECIEVED){
    auto lTotalTime = LostRuinsRead::Get()->GetTaskTimeByQuestId(lQuestInfo._QuestID);
    auto lLeftTime = GMath::Max(0, lTotalTime - (GServiceFunction::Get()->SystemTime() - LostRuinsCtrl::Get()->GetRunningQuestInfo()._StartTime));
    _CDTipNode->InitActivityTime(lLeftTime, lTotalTime, _Status);
    _SpriteBg->setVisible(false);
    _CDTipNode->setVisible(true);
    
  } else if(_Status == ELosRuinsStatus::COMPLETE){
    _LostRuinsEffect->setVisible(false);
    _StatusImg->setSpriteFrame("icon_equip_box.png");
  } else if(_Status == ELosRuinsStatus::GIVE_UP || _Status == ELosRuinsStatus::RECIEVED_REWARD || _Status == ELosRuinsStatus::OVERDUE || _Status == ELosRuinsStatus::CANCEL){
    auto lCdBeginTime = LostRuinsCtrl::Get()->GetQuestInfo(Vec2(_TilePoint.x + 1, _TilePoint.y + 1))._CdBeginTime;
    auto lLeftTime = GMath::Max(0, CD_TIME - (GServiceFunction::Get()->SystemTime() - lCdBeginTime));

    if(lLeftTime > 0){
      _CDTipNode->InitActivityTime(lLeftTime, CD_TIME, _Status);
      _CDTipNode->SetTimeEndCallBack([this](){
        UpdateData(nullptr);
      });
      _CDTipNode->setVisible(true);
      _SpriteBg->setVisible(false);
    }else{
      auto [lSurveying, lLeftTime, lTotalTime]  = IsSurveying();
      if(lSurveying){
        _CDTipNode->InitActivityTime(lLeftTime, lTotalTime, _Status, lSurveying);
        _CDTipNode->setVisible(true);
        _SpriteBg->setVisible(false);
      }else{
        _StatusImg->setSpriteFrame("icon_lostRuins_quest.png");
      }
    }
  }
}

void WorldMapLostRuins::PlayClickSound() {
  // SoraDPlaySound()
  GBase::PlaySound();
}

GTuple<bool, GTime, GTime> WorldMapLostRuins::IsSurveying(){
  // local queues = kingdomMapCtrl:getMapEventList() or {}
  // for _, v in pairs(queues) do
  //   if v.to.x == self.tilePoint.x and v.to.y == self.tilePoint.y then
  //     local leftTime = v:getStatusRemainTime()
  //     local totalTime = v.endTime - v.createTime
  //     return true, leftTime, totalTime
  //   end
  // end
  // return false
  return {false, 0, 0};
}

GTuple<UIBasePanel *, bool, Node*> WorldMapLostRuins::OnClickInstance(Node *pNode) {
  if(LordInfoCtrl::Get()->GetSourceKid() > 0 || LordInfoCtrl::Get()->GetSourceKid() != _KingdomID)
    return {nullptr, false, nullptr};
  PlayClickSound();
  UIBasePanel *lView = nullptr;
  if(_Status == ELosRuinsStatus::SURVEY){
    auto lSelectShowPanel = UIWorldMapLostRuinsSurveyView::Create();
    lSelectShowPanel->SetTilePoint(_TilePoint);
    lSelectShowPanel->InitData(GetInstanceID());
    lSelectShowPanel->Show();
    lView = lSelectShowPanel;
  }else if(_Status == ELosRuinsStatus::GIVE_UP || _Status == ELosRuinsStatus::RECIEVED_REWARD || _Status == ELosRuinsStatus::CANCEL || _Status == ELosRuinsStatus::OVERDUE){
    auto lCdBeginTime = LostRuinsCtrl::Get()->GetQuestInfo(Vec2(_TilePoint.x + 1, _TilePoint.y + 1))._CdBeginTime;
    auto lLeftTime = GMath::Max(0, CD_TIME - (GServiceFunction::Get()->SystemTime() - lCdBeginTime));
    if(lLeftTime > 0){
      GBase::DShowMsgTip(
        Translate::i18n("lost_ruins_text_27", 
          {{"time", GBase::DConvertSecondToString(lLeftTime)}}
        ));
      return {nullptr, false, nullptr};
    }
    auto lSelectShowPanel = UIWorldMapLostRuinsSurveyView::Create();
    lSelectShowPanel->SetTilePoint(_TilePoint);
    lSelectShowPanel->InitData(GetInstanceID());
    lSelectShowPanel->Show();
    lView = lSelectShowPanel;
  }else{
    auto lSelectShowPanel = UIWorldMapLostRuinsView::Create();
    lSelectShowPanel->SetTilePoint(_TilePoint);
    lSelectShowPanel->InitData(GetInstanceID());
    lSelectShowPanel->Show();
    lView = lSelectShowPanel;
  }

  return {lView, false, nullptr};
}