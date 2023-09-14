#include "WorldMapChest.h"
#include "Base/Utils/XTransition.h"
#include "Module/Player/Player.Top.h"
#include "Module/UI/Panel/World/WorldMap/Instance/Unit/Chest/UIWorldMapChest.View.h"

void WorldMapChest::Ctor() {
  _InitUI();
  _InitData();
}

void WorldMapChest::_InitData(){
  // self.chestClassID = nil
  // self.isColl = false
  // self.chestLevel = 0
  // self.leftCount = 0
  // self.dailyMaxCount = 0
}

void WorldMapChest::_InitUI(){
  _ChestImg = GDisplay::Get()->NewSprite("zwbx_01.png");
  addChild(_ChestImg, -1);
  GBase::RCreateLabelParm lParam;
  lParam._UILabelType = GBase::EUILabelType::TTF;
  lParam._Text = "";
  lParam._FontSize = 16;
  _NameLabel = GBase::DCreateLabel(lParam);
  _NameLabel->setColor(Color3B(88, 52, 16));
  _NameLabel->setAnchorPoint(Vec2(0.5, 0.5));
  _NameLabel->setPosition(Vec2(_CenterPoint.x + 10, _CenterPoint.y - 70));
  addChild(_NameLabel, 1);
  //   self.nameLabel:setGroupID(worldMapDefine.GROU_ID.group_text_monster)
  _ImageLevel = GDisplay::Get()->NewSprite("frame_SJDT_dengjipai.png");
  _ImageLevel->setPosition(Vec2(_CenterPoint.x - 65, _CenterPoint.y - 62));
  addChild(_ImageLevel, 1);
  //   self.image_level:setGroupID(worldMapDefine.GROU_ID.group_level_monster)
  lParam._FontSize = 15;
  _LevelLabel = GBase::DCreateLabel(lParam);
  _LevelLabel->setAnchorPoint(Vec2(0.5, 0.5));
  _LevelLabel->setPosition(Vec2(_CenterPoint.x - 66, _CenterPoint.y - 61));
  addChild(_LevelLabel, 1);
  //   self.levelLabel:setGroupID(worldMapDefine.GROU_ID.group_text_monster)
  _CountLabelBg = GDisplay::Get()->NewSprite("frame_map_18.png");
  _CountLabelBg->setScale(0.6f);
  _CountLabelBg->setPosition(Vec2(_CenterPoint.x, _CenterPoint.y + 35));
  addChild(_CountLabelBg, 0);
  //   self.countLabelBg:setGroupID(worldMapDefine.GROU_ID.group_level_build)
  lParam._FontSize = 18;
  _CountLabel = GBase::DCreateLabel(lParam);
  _CountLabel->setAnchorPoint(Vec2(0.5, 0.5));
  _CountLabel->setPosition(Vec2(_CenterPoint.x, _CenterPoint.y + 35));
  _CountLabel->setColor(Color3B(0, 255, 85));
  addChild(_CountLabel, 1);
  //   self.countLabel:setGroupID(worldMapDefine.GROU_ID.group_text)
}


void WorldMapChest::AddCacheBefore() {
  _ChestImg->setVisible(true);
  _ChestImg->stopAllActions();
}

void WorldMapChest::SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) {
  // self.chestImg:setGroupID(groupID)
}

void WorldMapChest::OnMessageListener() {

}


void WorldMapChest::InitInstanceData(int32 pClass, void *pChestData, int32 pObjID) {
  if(!pChestData)
    return;
  auto lChestData = (RUnitChestInit *)pChestData;
  _ChestClassID = pClass;
  _ChestShow = WorldMapDefine::Get()->GetChestpackShow(_ChestClassID);
  _NameLabel->setString(Translate::i18n(_ChestShow._Name));
  _ChestImg->setSpriteFrame(_ChestShow._Effects + "_01.png");

  Animation *lAnimation = nullptr;
  if(_ChestClassID == 2 && WorldMapDefine::Get()->_HasCamelHdRes) {
    auto lFrames = GDisplay::Get()->NewFrames("zyluotuo0" + std::to_string(lChestData->_Level) + "_dj_ws_%.2d.png", 1, 24);
    lAnimation = GDisplay::Get()->NewAnimation(lFrames, 0.05f);
  } else {
    auto lFrames = GDisplay::Get()->NewFrames(_ChestShow._Effects + "_%.2d.png", 1, 6);
    if(_ChestShow._Effects == "zwbx"){
      lFrames.pushBack(GDisplay::Get()->GetSpriteFrame(_ChestShow._Effects + "_01.png"));
    }else if(_ChestShow._Effects == "sdlr"){
      lFrames = GDisplay::Get()->NewFrames(_ChestShow._Effects + "_ws_%.2d.png", 1, 8);
      lFrames.pushBack(GDisplay::Get()->GetSpriteFrame(_ChestShow._Effects + "_ws_01.png"));
      _CountLabel->setPosition(Vec2(_CenterPoint.x, _CenterPoint.y - 35));
      _CountLabelBg->setPosition(Vec2(_CenterPoint.x, _CenterPoint.y - 35));
    }

    lAnimation = GDisplay::Get()->NewAnimation(lFrames, 1.2f / lFrames.size());
  }
  _ChestImg->stopAllActions();
  XTransition::Get()->PlayAnimationForever(_ChestImg, lAnimation, _ChestShow._Delay);
  UpdateData(*lChestData);
}

void WorldMapChest::UpdateData(const RUnitChestInit &pChestData){
  auto lSelfPlayerID = PlayerTop::Get()->GetPlayerID();
  if(pChestData.Contain(lSelfPlayerID))
    _IsColl = pChestData[lSelfPlayerID];
  else
    _IsColl = false;
  _ChestLevel = pChestData._Level;
  _LevelLabel->setString(std::to_string(_ChestLevel));
  _LeftCount = pChestData._LeftCount;
  _CountLabel->setString(Translate::i18n("common_text_1673", {{"count", std::to_string(_LeftCount)}}));
  _DailyMaxCount = pChestData._ChestRewardLimit;
}

int32 WorldMapChest::GetChestClassID(){
  return _ChestClassID;
}

GTuple<UIBasePanel *, bool, Node*> WorldMapChest::OnClickInstance(Node *pNode) {
  auto lSelectShowPanel = UIWorldMapChestView::Create();
  lSelectShowPanel->setPosition(Vec2(GDisplay::Get()->width/2, GDisplay::Get()->height/2));
  lSelectShowPanel->SetTilePoint(_TilePoint);
  lSelectShowPanel->InitData(this);
  lSelectShowPanel->Show();
  return {lSelectShowPanel, true, nullptr};
}

void WorldMapChest::PlayClickSound() {
  
}
