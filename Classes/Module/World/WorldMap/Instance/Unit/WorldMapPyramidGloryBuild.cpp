#include "WorldMapPyramidGloryBuild.h"
#include "Module/UI/Panel/World/WorldWar/PyramidBattel/UIAlliancePBLHonor.View.h"

void WorldMapPyramidGloryBuild::Ctor() {
  _InitUI();
  _InitData();
}

void WorldMapPyramidGloryBuild::_InitData(){
  _Level = 0;
}

void WorldMapPyramidGloryBuild::_InitUI(){
  
  auto lOffsetX = 5;
  auto lOffsetY = 5;
  
  _OccupyIcon = GDisplay::Get()->NewSprite("icon_map_res_me.png");
  _OccupyIcon->setAnchorPoint(Vec2(0.5, 0));
  _OccupyIcon->setVisible(false);
  addChild(_OccupyIcon, 2);
  // self.occupyIcon:setGroupID(worldMapDefine.GROU_ID.group_protect)
  
  _ResourceImage = GDisplay::Get()->NewSprite("map_building_honor.png");
  _ResourceImage->setScale(0.8f);
  _ResourceImage->setPosition(Vec2(lOffsetX, lOffsetY));
  addChild(_ResourceImage, -1);

  _ImageNameLv = GDisplay::Get()->NewSprite("frame_map_07.png");
  _ImageNameLv->setAnchorPoint(Vec2(0.5, 0.5));
  _ImageNameLv->setPosition(Vec2(_CenterPoint.x + lOffsetX, _CenterPoint.y - 70 + lOffsetY));
  addChild(_ImageNameLv, 1);

  GBase::RCreateLabelParm lParam;
  lParam._UILabelType = GBase::EUILabelType::TTF;
  lParam._Text = Translate::i18n("pyramid_title_08");
  lParam._FontSize = 20;
  
  _TextNameLv = GBase::DCreateLabel(lParam);
  _TextNameLv->setAnchorPoint(Vec2(0.5, 0.5));
  _TextNameLv->setPosition(Vec2(_CenterPoint.x + lOffsetX, _CenterPoint.y - 73 + lOffsetY));
  _TextNameLv->setColor(Color3B(255, 200, 100));
  addChild(_TextNameLv, 2);
  // self.text_NameLv:setGroupID(worldMapDefine.GROU_ID.group_text)
  
  auto lTextLen = _TextNameLv->getContentSize().width;
  auto lMaxWidth = GMath::Max(lTextLen + 120, _ImageNameLv->getContentSize().width);
  _ImageNameLv->setScaleX(lMaxWidth / _ImageNameLv->getContentSize().width);
  UpdateActivityState();
}

void WorldMapPyramidGloryBuild::AddCacheBefore() {

}

void WorldMapPyramidGloryBuild::SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) {
  //  self.resourceImage:setGroupID(groupID)
}

void WorldMapPyramidGloryBuild::InitInstanceData(int32 pClass, void *pObjData, int32 pObjID) {
  if(!pObjData) {
    return;
  }
  UpdateData(*(RUnitPyramidGloryBuildInit *)pObjData);
}

void WorldMapPyramidGloryBuild::UpdateData(const RUnitPyramidGloryBuildInit &pData){
  _Level = pData._Level;
  _IsUnlock = pData._IsUnlock;
  UpdateLevel();
}

void WorldMapPyramidGloryBuild::UpdateLevel(){

}

void WorldMapPyramidGloryBuild::PlayClickSound() {
  GBase::PlaySound("worldmap", 18);
}

void WorldMapPyramidGloryBuild::UpdateActivityState(){

}

GTuple<UIBasePanel *, bool, Node*> OnClickInstance(Node *pNode) {
  UIAlliancePBLHonorView::Create()->Show();
  return {nullptr, false, nullptr};
}
