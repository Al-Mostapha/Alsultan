#include "WorldMapKingdomLvTower.h"
#include "Base/Math/Math.Base.h"
#include "Global/Global.h"
#include "Engine/Base/UI/XUILabel.h"
#include "Module/Activity/ClientEvent.Mgr.h"
#include "Module/Player/Player.Top.h"
#include "Module/Player/LordInfo.Ctrl.h"
#include "Base/Common/Common.Msg.h"
#include "Module/Guild/Alliance.Mgr.h"
#include "Module/World/WorldWar/PyramidWar/ConquestWar.Ctrl.h"
#include "Module/World/WorldMap/WorldMap.Define.h"
#include "Module/UI/Panel/World/Kingdom/Lvl/UIWorldKingdomLv.View.h"

void WorldMapKingdomLvTower::Ctor() {
  _InitUI();
  _InitData();
}


void WorldMapKingdomLvTower::_InitData(){}

void WorldMapKingdomLvTower::_InitUI(){
  auto lOffsetX = 45;
  auto lOffsetY = 95;
  
  _OccupyIcon = GDisplay::Get()->NewSprite("icon_map_res_me.png");
  _OccupyIcon->setAnchorPoint(Vec2(0.5, 0));
  _OccupyIcon->setVisible(INIT_FALSE);
  addChild(_OccupyIcon, 2);
  // self.occupyIcon:setGroupID(worldMapDefine.GROU_ID.group_protect)
  _ResourceImage = GDisplay::Get()->NewSprite("Map_build_kingdomLv.png");
  _ResourceImage->setScale(0.8);
  _ResourceImage->setPosition(Vec2(-90 + lOffsetX, 20 + lOffsetY));
  addChild(_ResourceImage, -1);
  
  auto [lEffectBottom, l_] = GBase::DCreateAnimation("UiParts/Panel/World/WorldMap/Floor/Animation/xiangyata_bottom.csb");
  lEffectBottom->setPosition(Vec2(lEffectBottom->getContentSize().width / 2, lEffectBottom->getContentSize().height / 2 + 110));
  addChild(lEffectBottom, -10);
  lEffectBottom->setVisible(INIT_FALSE);
  _EffectBottom = lEffectBottom;
  // effectBottom:setGroupID(worldMapDefine.GROU_ID.group_particle_bg)
  // effectBottom:setGroupAuto(true)
  auto [lEffect, l_1] = GBase::DCreateAnimation("UiParts/Panel/World/WorldMap/Floor/Animation/xiangyata.csb");
  lEffect->setPosition(Vec2(_ResourceImage->getContentSize().width / 2 + 70, _ResourceImage->getContentSize().height / 2 - 30));
  _ResourceImage->addChild(lEffect);
  lEffect->setVisible(INIT_FALSE);
  _Effect = lEffect;
  _ImageNameLv = GDisplay::Get()->NewSprite("frame_map_07.png");
  _ImageNameLv->setAnchorPoint(Vec2(0.5, 0.5));
  _ImageNameLv->setPosition(Vec2(_CenterPoint + Vec2(-30 + lOffsetX, -90 + lOffsetY)));
  addChild(_ImageNameLv, 1);
  auto lBuildName = Translate::i18n("common_text_3957");

  UIFontLabelParam lParam;
  lParam._UILabelType = GBase::EUILabelType::TTF;
  lParam._Text = lBuildName;
  lParam._FontSize = 20;
  _TextNameLv = XUILabel::Create<Label>(lParam);
  _TextNameLv->setAnchorPoint(Vec2(0.5, 0.5));
  _TextNameLv->setPosition(Vec2(_CenterPoint + Vec2(-30 + lOffsetX, -93 + lOffsetY)));
  addChild(_TextNameLv, 2);
  _TextNameLv->setColor(Color3B(255, 200, 100));
  // self.text_NameLv:setGroupID(worldMapDefine.GROU_ID.group_text)

  auto lTextLen = _TextNameLv->getContentSize().width;
  auto lMaxWidth = GMath::Max(lTextLen + 120, _ImageNameLv->getContentSize().width);
  _ImageNameLv->setScaleX(lMaxWidth / _ImageNameLv->getContentSize().width);
  _SpriteLock = GDisplay::Get()->NewSprite("frame_techtree_lock_01.png");
  auto lLockName = "img_build_lock";
  _SpriteLock->setName(lLockName);
  _SpriteLock->setScale(1.3);
  _SpriteLock->setPosition(Vec2(_CenterPoint + Vec2(-30 + lOffsetX, -90 + lOffsetY)));
  addChild(_SpriteLock, 3);
  auto lOffsetLv = Vec2(80, -25);
  _ImageLevel = GDisplay::Get()->NewSprite("icon_map_kingdomlv.png");
  _ImageLevel->setPosition(Vec2(_CenterPoint + lOffsetLv));
  addChild(_ImageLevel, 3);
  // self.image_level:setGroupID(worldMapDefine.GROU_ID.group_level_build)

  GBase::RCreateLabelParm lParam1;
  lParam1._UILabelType = GBase::EUILabelType::TTF;
  lParam1._Text = "1";
  lParam1._FontSize = 14;
  _ResourceLevelLabel = GBase::DCreateLabel(lParam1);
  _ResourceLevelLabel->setAnchorPoint(Vec2(0.5, 0.5));
  _ResourceLevelLabel->setSkewY(25);
  _ResourceLevelLabel->setPosition(_CenterPoint + lOffsetLv + Vec2(6, 0));
  addChild(_ResourceLevelLabel, 3);
  // self.resourceLevelLabel:setGroupID(worldMapDefine.GROU_ID.group_text)
  UpdateActivityState();
}


void WorldMapKingdomLvTower::OnMessageListener() {
  // SoraDAddMessage(self, "MESSAGE_SERVER_WORLDKINGDOM_LV_OPEN_CHANGE", handler(self, self.updateActivityState))
}

void WorldMapKingdomLvTower::AddCacheBefore() {}

void WorldMapKingdomLvTower::SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) {
  // self.resourceImage:setGroupID(groupID)
}

void WorldMapKingdomLvTower::InitInstanceData(int32 pSiteClassID, void *pData, int32 pObjID) {
  if(!pData) return;
  auto lData = static_cast<RKingdomLvTowerInit *>(pData);
  InitInstanceData(pSiteClassID, *lData, pObjID);
}

void WorldMapKingdomLvTower::InitInstanceData(int32 pSiteClassID, const RKingdomLvTowerInit &pBuildData, int32 pObjData){
  UpdateData(pBuildData);
}

void WorldMapKingdomLvTower::UpdateData(const RKingdomLvTowerInit &pBuildData){
  _Level = pBuildData._Level;
  _IsUnlock = pBuildData._IsUnlock;
  UpdateLevel();
  if(!_IsUnlock)
    _SpriteLock->setVisible(true);
  else
    _SpriteLock->setVisible(false);
}

void WorldMapKingdomLvTower::UpdateLevel(){
  // self.resourceLevelLabel:setString(self.level)
  _ResourceLevelLabel->setString(std::to_string(_Level));
}

void WorldMapKingdomLvTower::PlayClickSound() {
  GBase::PlaySound("worldmap", 18);
}

void WorldMapKingdomLvTower::UpdateActivityState(EventCustom *pEvent){
  if(!ClientEventMgr::Get()->JudgeIsOpen(EActivityTime::SERVER_EXP_DOUBLE_ACTIVITY, false)){
    _Effect->setVisible(false);
    _EffectBottom->setVisible(false);
  }else{
    _Effect->setVisible(true);
    _EffectBottom->setVisible(true);
  }

}

GTuple<UIBasePanel *, bool, Node*> WorldMapKingdomLvTower::OnClickInstance(Node *pNode) {
  auto lMyKindomID = PlayerTop::Get()->GetMapID();
  if(lMyKindomID != _KingdomID){
    GBase::ShowServerTip(Translate::i18n("common_text_3957"), Translate::i18n("common_text_3958"));
    return {nullptr, false, nullptr};
  }
  auto lSelfLeagueID = AllianceManager::Get()->GetOwnTeamID();
  auto lIsInWarKingdom = false;
  if(WorldMapDefine::Get()->IsInWar()){
    lIsInWarKingdom = true;
  }else if(ConquestWarCtrl::Get()->IsPlayerConquestWarMigration() && LordInfoCtrl::Get()->GetSourceKid() > 0){
    lIsInWarKingdom = true;
  }

  if(lIsInWarKingdom){
    GBase::ShowServerTip(Translate::i18n("common_text_3957"), Translate::i18n("common_text_3958"));
  }else{
    if(!_IsUnlock){
      GBase::DShowMsgBox(Translate::i18n("common_text_3968"));
      return {nullptr, false, nullptr};
    }
    UIWorldKingdomLvView::Create()->Show();
  }
  PlayClickSound();
}