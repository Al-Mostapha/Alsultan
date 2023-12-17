#include "WorldMapWindTower.h"
#include "Base/Math/Math.Base.h"
#include "Base/Functions/ServiceFunction.h"
#include "Module/Player/LordInfo.Ctrl.h"
#include "Module/UI/EventCenter/EventTemplate/WindTower/WindTower.Ctrl.h"
#include "Module/UI/EventCenter/EventTemplate/WindTower/WindTower.Util.h"
#include "Module/UI/EventCenter/EventTemplate/WindTower/WindTower.Read.h"
#include "Module/UI/EventCenter/EventTemplate/WindTower/UIWindTowerBuild.View.h"

static const GTime CD_TIME = 1800;

void WorldMapWindTower::Ctor() {
  _InitUI();
  _InitData();
}

void WorldMapWindTower::_InitData(){
  _CreateUID = 0;
  _LeagueID = 0;
  _Status = EWindTowerStatus::SURVEY;
}

void WorldMapWindTower::_InitUI(){
  _LostRuins = GDisplay::Get()->NewSprite("Map_build_windTower.png");
  _LostRuins->setPosition(Vec2(_CenterPoint.x + 10, _CenterPoint.y + 10));
  addChild(_LostRuins);
  _CDTipNode = UIWindTowerMapTip::Create();
  addChild(_CDTipNode);
  _CDTipNode->setPosition(Vec2(_CenterPoint.x + 20, _CenterPoint.y - 60));
  _SpriteBg = GDisplay::Get()->NewSprite("frame_main_receive.png");
  _SpriteBg->setAnchorPoint(Vec2(0.5, 0));
  _SpriteBg->setPosition(Vec2(_CenterPoint.x + 55, _CenterPoint.y + 15));
  addChild(_SpriteBg);
  _SpriteBg->setScale(0.5);
  _StatusImg = GDisplay::Get()->NewSprite("icon_set_search.png");
  _StatusImg->setAnchorPoint(Vec2(0.5, 0.5));
  _StatusImg->setPosition(Vec2(40, 42));
  _StatusImg->addChild(_SpriteBg);
}

void WorldMapWindTower::OnMessageListener() {
  GBase::DAddMessage(this, "MESSAGE_WIND_TOWER_REFRESH", CC_CALLBACK_1(WorldMapWindTower::UpdateData, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_WORLD_MAP_EVENT_LSIT_INFO_NEW", CC_CALLBACK_1(WorldMapWindTower::UpdateData, this));
}

void WorldMapWindTower::InitInstanceData(int32 pClass, void *pObjData, int32 pObjID) {
  UpdateData();
}

void WorldMapWindTower::UpdateData(EventCustom *pEvent){
  auto lQuestInfo = WindTowerCtrl::Get()->GetQuestInfo(Vec2(_TilePoint.x + 1, _TilePoint.y + 1));
  _Status = lQuestInfo._Status;
  _SpriteBg->setVisible(true);
  _CDTipNode->setVisible(false);
  auto lCdTime = WindTowerUtil::Get()->GetBuildCD(_TilePoint);

  if(lCdTime > 0){
    _Status = EWindTowerStatus::OVERDUE;
    _CDTipNode->InitActivityTime(lCdTime, CD_TIME, _Status);
    _CDTipNode->setVisible(true);
    _SpriteBg->setVisible(false);
  }else if(_Status == EWindTowerStatus::NOT_RECIEVE){
    _StatusImg->setSpriteFrame("icon_lostRuins_gth.png");
  } else if(_Status == EWindTowerStatus::RECIEVED){
    if(lQuestInfo._Finish){
      _StatusImg->setSpriteFrame("icon_equip_box.png");
    } else {
      auto lTotalTime = WindTowerRead::Get()->GetTaskTimeByQuestId(lQuestInfo._QuestID);
      auto lLeftTimes = GMath::Max(0, lQuestInfo._EndTime - GServiceFunction::Get()->SystemTime());
      _CDTipNode->InitActivityTime(lLeftTimes, lTotalTime, _Status);
      _SpriteBg->setVisible(false);
      _CDTipNode->setVisible(true);
    }
  }else{
    auto [lIsSurveying, lLeftTime, lTotalTime] = IsSurveying();
    if(lIsSurveying){
      _CDTipNode->InitActivityTime(lLeftTime, lTotalTime, _Status, lIsSurveying);
      _CDTipNode->setVisible(true);
      _SpriteBg->setVisible(false);
    }else{
      _StatusImg->setSpriteFrame("icon_lostRuins_quest.png");
    }
  }
}

void WorldMapWindTower::PlayClickSound() {
  GBase::PlaySound();
}

GTuple<bool, GTime, GTime> WorldMapWindTower::IsSurveying(){
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

GTuple<UIBasePanel *, bool, Node*> WorldMapWindTower::OnClickInstance(Node *pNode) {
  auto lSourceKid = LordInfoCtrl::Get()->GetSourceKid();
  if(lSourceKid > 0 || LordInfoCtrl::Get()->GetMapSourceKid() != _KingdomID){
    return {nullptr, false, nullptr};
  }
  
  PlayClickSound();
  auto lCdTime = WindTowerUtil::Get()->GetBuildCD(_TilePoint);
  if(lCdTime > 0){
    GBase::DShowMsgTip(
      Translate::i18n(
        "lost_ruins_text_27", 
        {
          {"time", GBase::DConvertSecondToString(lCdTime)}
        }
      )
    );
    return {nullptr, false, nullptr};
  }
  
  auto lSelectShowPanel = UIWindTowerBuildView::Create();
  lSelectShowPanel->SetTilePoint(_TilePoint);
  lSelectShowPanel->InitData(_InstanceID, _Status);
  lSelectShowPanel->Show();
  return {lSelectShowPanel, true, nullptr};
}

void WorldMapWindTower::AddCacheBefore() {

}

void WorldMapWindTower::SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) {

}
