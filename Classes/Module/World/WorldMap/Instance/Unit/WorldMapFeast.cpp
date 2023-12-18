#include "WorldMapFeast.h"
#include "Global/Global.h"
#include "Base/Base.create.h"
#include "Module/Guild/Alliance.Read.h"
#include "Module/Player/Player.Top.h"
#include "Module/Guild/Alliance.Mgr.h"

void WorldMapFeast::Ctor() {
  _ModelImage = GDisplay::Get()->NewSprite("Map_build_feast.png");
  _ModelImage->setPosition(Vec2(0, 0));
  addChild(_ModelImage, -1);

  _OccupyIcon = GDisplay::Get()->NewSprite("frame_ditubiaoji.png");
  _OccupyIcon->setAnchorPoint(Vec2(0.5, 0));
  _OccupyIcon->setVisible(INIT_FALSE);
  _OccupyIcon->setPosition(Vec2(0, _CenterPoint.y + 100));
  addChild(_OccupyIcon, 2);

  // self.occupyIcon:setGroupID(worldMapDefine.GROU_ID.group_protect)
  _ImageLeagueFlag = GDisplay::Get()->NewSprite(AllianceRead::Get()->GetFlagIcon(_LeagueFlag, true));
  _ImageLeagueFlag->setScale(0.3f);
  _ImageLeagueFlag->setPosition(Vec2(_CenterPoint.x - 90, _CenterPoint.y - 80));
  _ImageLeagueFlag->setVisible(INIT_FALSE);
  addChild(_ImageLeagueFlag, 2);

  // self.image_LeagueFlag:setGroupID(worldMapDefine.GROU_ID.group_flag)
  _ImageName = GDisplay::Get()->NewSprite("frame_map_07.png");
  _ImageName->setAnchorPoint(Vec2(0.5, 0.5));
  _ImageName->setPosition(Vec2(_CenterPoint.x - 0, _CenterPoint.y - 80));
  addChild(_ImageName, 3);

  // self.image_name:setGroupID(worldMapDefine.GROU_ID.group_level_build)
  GBase::RCreateLabelParm lParam;
  lParam._UILabelType = GBase::EUILabelType::TTF;
  lParam._Text = "";
  lParam._FontSize = 20;
  _TextName = GBase::DCreateLabel(lParam);
  _TextName->setAnchorPoint(Vec2(0.5, 0.5));
  _TextName->setPosition(Vec2(_CenterPoint.x - 0, _CenterPoint.y - 85));
  _TextName->setColor(Color3B(98, 185, 235));
  addChild(_TextName, 4);
  // self.text_Name:setGroupID(worldMapDefine.GROU_ID.group_text)
  auto [lEffectLast, _] = GBase::DCreateAnimation("hjyt_map_last", nullptr, true);
  lEffectLast->setPosition(Vec2(0, 0));
  addChild(lEffectLast, 10);
}

void WorldMapFeast::OnMessageListener() {
  GBase::DAddMessage(this, "MESSAGE_ALLIACNE_MEMBER_UPDATE", [this](EventCustom *pEvent) {
    auto lFeastData = (RUnitFeastInit *)pEvent->getUserData();
    UpdateData(*lFeastData);
  });
  GBase::DAddMessage(this, "MESSAGE_ALLIANCE_RELATION_DATA_CHANGE", [this](EventCustom *pEvent) {
    auto lFeastData = (RUnitFeastInit *)pEvent->getUserData();
    UpdateData(*lFeastData);
  });
}

void WorldMapFeast::SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) {
  // self.modelImage:setGroupID(groupID)
}

void WorldMapFeast::InitInstanceData(int32 pClass, void *pObjData, int32 pObjID) {
  _FeastClassID = pClass;
  if(pObjData != nullptr) {
    auto lFeastData = (RUnitFeastInit *)pObjData;
    UpdateData(*lFeastData);
  }
}

void WorldMapFeast::SetTilePoint(Vec2 pTilePoint){
  _TilePoint = pTilePoint;
}

Vec2 WorldMapFeast::GetTilePoint(){
  return _TilePoint;
}

void WorldMapFeast::SetInstanceID(uint32 pInstanceID){
  _InstanceID = pInstanceID;
}

uint32 WorldMapFeast::GetInstanceID(){
  return _InstanceID;
}

void WorldMapFeast::UpdateData( const RUnitFeastInit &pData){
  _FeastData = pData;
  if(pData._AllianceFlag != 0) {
    _ImageLeagueFlag->setVisible(true);
    _ImageLeagueFlag->setSpriteFrame(AllianceRead::Get()->GetFlagIcon(pData._AllianceFlag));
  }
  
  if(pData._FeastLv && _LeagueName != "") {
    _TextName->setString(Translate::i18n(
      "activity_feastLv_name02", {
        {"var1", pData._LeagueName},
        {"var2", std::to_string(pData._FeastLv)}
      }));
  }

  if(!pData._FeastRef.empty()){
    auto lIsShow = false;
    auto lUid = PlayerTop::Get()->GetPlayerID();
    for(auto &lFeastRef : pData._FeastRef) {
      if(lUid == lFeastRef.second) {
        lIsShow = true;
      }
    }
    _OccupyIcon->setVisible(lIsShow);
  }
  
  if(pData._Aid != 0) {
    auto lSelfLeagueID = AllianceManager::Get()->GetOwnAid();
    _TextName->setColor(Color3B(98, 185, 235));
  }
}

GTuple<UIBasePanel *, bool, Node*> WorldMapFeast::OnClickInstance(Node *pNode) {
  PlayClickSound();
  if(!AllianceManager::Get()->HasJoinAlliance()) {
    GBase::DShowMsgTip(Translate::i18n("tips_place_noUnion"));
    return {nullptr, false, nullptr};
  }
  if(AllianceManager::Get()->GetOwnAid() !=  _FeastData._Aid) {
    GBase::DShowMsgTip(Translate::i18n("tips_activity_hjyt_viewOtherUnion"));
    return {nullptr, false, nullptr};
  }
  // local feastPopPanel = SoraDSearchPanelFromManagerByName("getTogertherFeastPopView")
  // if feastPopPanel then
  //   feastPopPanel:removeFromParent()
  // end
  // local selectShowPanel = SoraDCreatePanel("getTogertherFeastPopView")
  // selectShowPanel:initData(self.feastData, self.instanceID)
  // selectShowPanel:show()
  // return selectShowPanel, false
  return {nullptr, false, nullptr};
}

void WorldMapFeast::PlayClickSound() {
  GBase::PlaySound("innerbuildsound", 119);
}

void WorldMapFeast::AddCacheBefore() {}