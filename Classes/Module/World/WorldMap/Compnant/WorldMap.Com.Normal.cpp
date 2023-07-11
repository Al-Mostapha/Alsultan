#include "WorldMap.Com.Normal.h"
#include "Base/Common/Common.Teml.h"
#include "Base/Common/Common.Func.h"
#include "Module/World/WorldWar/PyramidWar/ConquestWar.Ctrl.h"
#include "Module/World/WorldMap/WorldMap.Define.h"
#include "Module/World/WorldMap/View/WorldMap.View.h"
#include "Module/World/WorldMap/View/WorldMap.Cell.h"
#include "Module/World/WorldMap/Monster/KillMonsterVerify.Ctrl.h"
#include "Module/UI/Common/Timer/UITimerLabel.h"
#include "Module/UI/Panel/World/WorldMap/Floor/UIWorldMapWar.Tip.h"
#include "Module/UI/Scene/World/MainUI/UIWorldMapMonsterSearch.h"
#include "Module/Activity/ClientEvent.Mgr.h"
#include "Module/Player/Player.Top.h"

void WorldMapComNormal::Init()
{
  IWorldMapComponent::Init();
  _BtnMonsterSearch = GBase::DGetChildByName<ui::Button *>(_Target, "Button_monsterSearch");
  _BtnMonsterSearch->setPositionY(160 + GDisplay::Get()->iPhoneXBottom);
  _BtnMonsterSearch->addTouchEventListener(CC_CALLBACK_2(WorldMapComNormal::BtnMonsterSearchCall, this));
  _SeaMonsterRedPoint = Sprite::create();
  _SeaMonsterRedPoint->setSpriteFrame("frame_mail_round_01.png");
  _SeaMonsterRedPoint->setPosition(Vec2(80, 80));
  _SeaMonsterRedPoint->setScale(0.8);
  _BtnMonsterSearch->addChild(_SeaMonsterRedPoint, 3);
  _SeaMonsterRedPoint->setVisible(false);
  // if clientEventMgr.judgeIsOpen(gActivityTimeActivityID.SEA_MONSTER_INVADE_ACTIVITY) then
  //   self.seaMonsterRedPoint:setVisible(SoraDConfigGet("Game:worldMapView:seaMonsterRedPoint~bool"))
  // end
  _SpMonsterBg = GBase::DGetChildByName<Sprite *>(_BtnMonsterSearch, "Sprite_monsterBg");
  _SpMonsterLock = GBase::DGetChildByName<Sprite *>(_BtnMonsterSearch, "Sprite_monsterLock");
  _NodeParticle = GBase::DGetChildByName<Node *>(_BtnMonsterSearch, "Node_particle");
  _LabelLockTime = UITimerLabel::DCreateTimerLabel(GBase::DGetChildByName<ui::Text *>(_BtnMonsterSearch, "Text_lockTime"));
  _LabelLockTime->setVisible(false);
  _SpMonsterBg->setVisible(false);
  _SpMonsterLock->setVisible(false);
  MonsterSearchLock(nullptr);
  _EffectMonster = _BtnMonsterSearch->getChildByName("Node_particle");
  if(_EffectMonster){
    auto l_Bool = GBase::DConfigGet<bool>("Game:worldMapView:monsterEffect~bool");
    _EffectMonster->setVisible(l_Bool);
    if(l_Bool){
      GVector<RCreatEffctParam> p_Et;
      auto l_OneParam = RCreatEffctParam();
      l_OneParam._PList = "et_guaiwu_01.plist";
      l_OneParam._Scale = Vec2(0.74, 0.74);
      p_Et.push_back(l_OneParam);
      l_OneParam._PList = "et_guaiwu_02.plist";
      l_OneParam._Scale = Vec2(0.7, 0.7);
      p_Et.push_back(l_OneParam);
      l_OneParam._PList = "et_guaiwu_03.plist";
      l_OneParam._Scale = Vec2(0.7, 0.7);
      p_Et.push_back(l_OneParam);
      auto l_EtBottom = GBase::DCreateEffectNode(p_Et);
      _NodeParticle->addChild(l_EtBottom);
    }
  }

  auto l_LocalBattleState = ConquestWarCtrl::Get()->GetConquestWarState();
  if(EConquestWarState::OPENING == l_LocalBattleState){
    auto l_WarTip = UIWorldMapWarTip::Create();
    l_WarTip->setPosition({
      GDisplay::Get()->cx,
      GDisplay::Get()->height - 270 + GDisplay::Get()->iPhoneXBottom
    });
    _Target->addChild(l_WarTip, static_cast<int32>(EWorldMapZOrder::topTipView));
  }

  ShowOrHideGuideView(nullptr);
}

void WorldMapComNormal::Relogin()
{
  MonsterSearchLock(nullptr);
}

void WorldMapComNormal::OnMessageListener(){
  GBase::DAddMessage(_Target, "MESSAGE_SERVER_WORLD_MAP_MONSTER_SEARCH_LOCK", CC_CALLBACK_1(WorldMapComNormal::MonsterSearchLock, this));
  GBase::DAddMessage(_Target, "MESSAGE_SERVER_EVENTCENTER_COMMONEVENT_REFRESH", CC_CALLBACK_1(WorldMapComNormal::JudgeOpen, this));
  GBase::DAddMessage(_Target, "MESSAGE_SERVER_GUIDE_HIDE_AND_SHOW", CC_CALLBACK_1(WorldMapComNormal::ShowOrHideGuideView, this));
}

void WorldMapComNormal::ShowOrHideGuideView( cocos2d::EventCustom *p_Event )
{
  // local guideCtrl = gametop.playertop_:getModule("guideCtrl")
  // local guideStep = guideCtrl:getCurForceGuideStep()
  // self.btnMonsterSearch:setVisible(false)
  // if not guideStep then
  //   self.btnMonsterSearch:setVisible(true)
  // end
}

void WorldMapComNormal::JudgeOpen( cocos2d::EventCustom *p_Event )
{
  GBase::DConfigSet<bool>("Game:worldMapView:seaMonsterRedPoint~bool", false);
  if(ClientEventMgr::Get()->JudgeIsOpen(EActivityTime::SEA_MONSTER_INVADE_ACTIVITY)){
    if(!p_Event)
      return;
    if(!p_Event->getUserData())
      return;
    auto l_ActivityID = static_cast<EActivityTime *>(p_Event->getUserData());
    if(EActivityTime::SEA_MONSTER_INVADE_ACTIVITY == *l_ActivityID){
      GBase::DConfigSet<bool>("Game:worldMapView:seaMonsterRedPoint~bool", true);
    }else if(false /**data.activityID and type(data.activityID) == "table" */){
      //     for i, v in ipairs(data.activityID) do
      //       if v == gActivityTimeActivityID.SEA_MONSTER_INVADE_ACTIVITY then
      //         SoraDConfigSet("Game:worldMapView:seaMonsterRedPoint~bool", true)
      //       end
      //     end
    }
  }
  _SeaMonsterRedPoint->setVisible(GBase::DConfigGet<bool>("Game:worldMapView:seaMonsterRedPoint~bool"));
}

void WorldMapComNormal::MonsterSearchLock( cocos2d::EventCustom *p_Event )
{
  if(KillMonsterVerifyCtrl::Get()->IsQuickSearchMonsterLock()){
    auto l_LeftTime = KillMonsterVerifyCtrl::Get()->GetQuickSearchMonsterLockLeftTime();
    _LabelLockTime->BeginTime(l_LeftTime);
    _SpMonsterBg->setVisible(true);
    _SpMonsterLock->setVisible(true);
    _LabelLockTime->setVisible(true);
  }else{
    _SpMonsterBg->setVisible(false);
    _SpMonsterLock->setVisible(false);
    _LabelLockTime->setVisible(false);
  }
}

void WorldMapComNormal::BtnMonsterSearchCall(Ref *p_Sender, ui::Widget::TouchEventType p_Type )
{
  if(p_Type != ui::Widget::TouchEventType::ENDED)
    return;

  GBase::PlaySound();
  GBase::DSendMessage("MESSAGE_WORLD_MAP_REMOVE_SELECTSHOWPANEL");
  
  auto l_MyKindomID = PlayerTop::Get()->GetMapID();
  if(_Target->_CurrentInMapViewCell->_KingdomID != l_MyKindomID){
    GBase::DShowMsgTip(Translate::i18n("common_text_2180"));
    return;
  }

  if(KillMonsterVerifyCtrl::Get()->IsQuickSearchMonsterLock()){
    GBase::DShowMsgTip(Translate::i18n("common_text_2863"));
  }else{
    auto l_Panel = UIWorldMapMonsterSearch::Create();
    l_Panel->Show();
    if(_EffectMonster->isVisible()){
      GBase::DConfigSet<bool>("Game:worldMapView:monsterEffect~bool", false);
      _EffectMonster->setVisible(false);
      _NodeParticle->removeAllChildren();
    }
    GBase::DConfigSet("Game:worldMapView:seaMonsterRedPoint~bool", false);
    if(_SeaMonsterRedPoint){
      _SeaMonsterRedPoint->setVisible(GBase::DConfigGet<bool>("Game:worldMapView:seaMonsterRedPoint~bool"));
    }
  }

}