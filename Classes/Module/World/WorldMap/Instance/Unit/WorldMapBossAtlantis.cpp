#include "WorldMapBossAtlantis.h"
#include "Module/World/WorldMap/WorldMap.Define.h"

void WorldMapBossAtlantis::_InitData() {
  WorldMapBoss::_InitData();
  _WarStatus = EKingdomWarStatusType::close;
}

void WorldMapBossAtlantis::_InitUI() {
  WorldMapBoss::_InitUI();
  _ImageProtect = WorldMapDefine::Get()->CreateWorldMapProtect();
  _ImageProtect->setScale(1.4f);
  _ImageProtect->setPosition(_CenterPoint + Vec2(0, 50));
  addChild(_ImageProtect, 1);
  _ImageLevel->setVisible(false);
  _LevelLabel->setVisible(false);
}

void WorldMapBossAtlantis::updateData(const RWorldMapBossInit &pInitData) {
  WorldMapBoss::updateData(pInitData);
  _ObjId = pInitData._ObjId;
  _WarStatus = pInitData._WarStatus;
  UpdateSafeState();
}

GTuple<UIBasePanel *, bool, Node*> WorldMapBossAtlantis::OnClickInstance(Node *pNode) {
  PlayClickSound();
  // local selectShowPanel = SoraDCreatePanel("worldMapAtlantisBossView")
  // selectShowPanel:setTilePoint(self.tilePoint)
  // selectShowPanel:initData(self)
  // selectShowPanel:show()
  // return selectShowPanel, true
  return {nullptr, true, nullptr};
}

uint32 WorldMapBossAtlantis::GetObjId(){
  return _ObjId;
}

void WorldMapBossAtlantis::UpdateSafeState(){
  if(_WarStatus == EKingdomWarStatusType::inWar){
    _ImageProtect->setVisible(false);
  }else{
    _ImageProtect->setVisible(true);
    _ProgressBar->setVisible(false);
  }
}