#include "WorldMapMineBuild.h"
#include "Module/Guild/AllianceStrongholdMine.Read.h"
#include "Module/Guild/Alliance.Mgr.h"
#include "Module/Guild/Relation/AllianceRelation.Ctrl.h"
#include "Module/World/WorldMap/WorldMap.Define.h"
#include "Module/Config/ConfigRead/Public.Read.h"

void WorldMapMineBuild::Ctor() {
  _InitData();
  _InitUI();
}

void WorldMapMineBuild::_InitData(){
  // self.objId = nil
  // self.buildID = nil
  // self.leagueID = 0
  // self.leagueAbbrName = ""
  // self.size = 2
  _Size  = 2;
  _Radioation = 0;
}

void WorldMapMineBuild::_InitUI(){
  _ModelImage = GDisplay::Get()->NewSprite("alliance_mineral_nongtian.png");
  _ModelImage->setPosition(0, 30);
  addChild(_ModelImage, -1);

  _ImageNameBg = GDisplay::Get()->NewSprite("frame_map_07.png");
  _ImageNameBg->setAnchorPoint(Vec2(0.5, 0.5));
  _ImageNameBg->setPosition(_CenterPoint.x - 0, _CenterPoint.y - 60);
  addChild(_ImageNameBg, 1);
  //   self.image_name_bg:setGroupID(worldMapDefine.GROU_ID.group_level_build)

  GBase::RCreateLabelParm lParam;
  lParam._UILabelType = GBase::EUILabelType::TTF;
  lParam._Text = "leagueName";
  lParam._FontSize = 20;
  _TextName = GBase::DCreateLabel(lParam);
  _TextName->setAnchorPoint(Vec2(0.5, 0.5));
  _TextName->setPosition(_CenterPoint.x - 0, _CenterPoint.y - 62);
  addChild(_TextName, 1);
  //   self.text_Name:setGroupID(worldMapDefine.GROU_ID.group_text)

  _SpriteBg = GDisplay::Get()->NewSprite("frame_main_receive.png");
  _SpriteBg->setAnchorPoint(Vec2(0.5, 0.5));
  _SpriteBg->setPosition(_CenterPoint.x - 0, _CenterPoint.y + 100);
  addChild(_SpriteBg, 1);

  _SpriteBg->setOpacity(180);
  _StatusImg = GDisplay::Get()->NewSprite("icon_saleRoom_symbol.png");
  _StatusImg->setAnchorPoint(Vec2(0.5, 0.5));
  _StatusImg->setScale(0.65f);
  _StatusImg->setPosition(40, 42);
  _SpriteBg->addChild(_StatusImg);
}

void WorldMapMineBuild::SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) {
  // self.modelImage:setGroupID(groupID)
}

void WorldMapMineBuild::SetBuildSize(int32 pSize, int32 pRadioation){
  _Size = pSize;
  _Radioation = pRadioation;
}

void WorldMapMineBuild::InitInstanceData(int32 pClass, void *pObjData, int32 pObjID) {
  _ObjID = pObjID;
  InitMineEffect();
  
  if(pObjData != nullptr) {
    RMineBuildInit *pData = (RMineBuildInit *)pObjData;
    UpdateData(*pData);
  }
}

void WorldMapMineBuild::InitMineEffect(){
  // local resID = allianceStrongholdMineRead.getMineOutputId(self.objId)
  auto lResID = AllianceStrongholdMineRead::Get()->GetMineOutputId(_ObjID);
  if(_MineEffect) {
    if(*((EResource *)_MineEffect->getUserData()) == lResID) {
      return;
    }
    _MineEffect->removeFromParent();
    _MineEffect = nullptr;
  }
  
  auto lCsd = "Node_mine_fmc";
  auto lOffset = Vec2(2, 0);
  if(lResID == EResource::Wood){
    lCsd = "Node_mine_fmc";
    lOffset = Vec2(2, 0);
  }else if(lResID == EResource::Iron){
    lCsd = "Node_mine_tk";
    lOffset = Vec2(-4, 0);
  }else if(lResID == EResource::Mithril){
    lCsd = "Node_mine_my";
    lOffset = Vec2(2, 0);
  }else {
    return;
  }

  auto [lEffect, _]  = GBase::DCreateAnimation(lCsd);
  addChild(lEffect);
  auto lPos = Vec2(lOffset.x + _ModelImage->getPositionX(), lOffset.y + _ModelImage->getPositionY());
  lEffect->setPosition(lPos);
  lEffect->setUserData((void *)lResID);
  _MineEffect = lEffect;
}

int32 WorldMapMineBuild::GetBuildClassID(){
  return _ObjID;
}

void WorldMapMineBuild::UpdateData(const RMineBuildInit &pData){
  _LeagueID = pData._LeagueID;
  UpdatePlayerInfo();
  UpdateStatusImg();
}

void WorldMapMineBuild::OnMessageListener() {
  GBase::DAddMessage(this, "MESSAGE_RAMADAN_WORLD_EXPLORER_TASK_UPDATE", CC_CALLBACK_1(WorldMapMineBuild::UpdateStatusImg, this));
}

uint32 WorldMapMineBuild::GetRamdanWorldTaskIndex(){
  return _TaskIndex;
}

void WorldMapMineBuild::UpdateStatusImg(EventCustom *pEvent){
  // self.taskIndex = ramadanWorldExplorerCtrl:getTaskIdxByMapInstanceID(self:getInstanceID())
  // self.spriteBg:setVisible(ramadanWorldExplorerCtrl:isTaskFinished(self.taskIndex) == false)
}

void WorldMapMineBuild::UpdatePlayerInfo(){
  SetBuildSize(2, 0);
  _ModelImage->setSpriteFrame(AllianceStrongholdMineRead::Get()->GetMineImage(_ObjID));
  _TextName->setString(AllianceStrongholdMineRead::Get()->GetMineName(_ObjID));
  _TextName->setColor(Color3B(255, 255, 255));

  if(_LeagueID > 0){
    if(_LeagueID == AllianceManager::Get()->GetOwnAid()){
      _TextName->setColor(WorldMapDefine::Get()->GetLeagueManorLineColor(true));
      ShowProduceAct();
    }

    _TextName->setString(Translate::i18n("common_text_186", {
      {"abbr", _LeagueAbbrName},
      {"name", AllianceStrongholdMineRead::Get()->GetMineName(_ObjID)}
    }));
    auto lAllianceRelationType = AllianceRelationCtrl::Get()->GetRelationTypeWith(_LeagueID);
    auto lNameColor = WorldMapDefine::Get()->GetLeagueManorLineColor(_LeagueID == AllianceManager::Get()->GetOwnAid(), lAllianceRelationType);
    _TextName->setColor(lNameColor);
  }else{
    _TextName->setColor(Color3B(255, 255, 255));
    HideProduceAct();
  }
}

void WorldMapMineBuild::ShowProduceAct(){
  auto lResID = AllianceStrongholdMineRead::Get()->GetMineOutputId(_ObjID);
  auto lResNum = AllianceStrongholdMineRead::Get()->GetMineOutputNum(_ObjID);

  if(!_NodeProduce){
    _NodeProduce = GDisplay::Get()->NewNode();
    _NodeProduce->setPosition(_CenterPoint);
    addChild(_NodeProduce, 9);
    auto lIcon = GDisplay::Get()->NewSprite(PublicRead::Get()->GetIcon(lResID));
    lIcon->setName("icon");
    lIcon->setScale(0.5);
    _NodeProduce->addChild(lIcon);
    lIcon->setPosition(-20, 0);

    auto lTextProduce = ui::Text::create("", "", 18);
    lTextProduce->setName("text_produce");
    lTextProduce->setAnchorPoint(Vec2(0.5, 0.5));
    lTextProduce->setPosition(Vec2(20, 0));
    _NodeProduce->addChild(lTextProduce);
  }
  
  auto lSprite = static_cast<Sprite *>(_NodeProduce->getChildByName("icon"));
  lSprite->setSpriteFrame(PublicRead::Get()->GetIcon(lResID));
  auto lText = static_cast<ui::Text *>(_NodeProduce->getChildByName("text_produce"));
  lText->setString("+" + std::to_string(GMath::Floor(lResNum/40)));
  _NodeProduce->setVisible(true);
  _NodeProduce->stopAllActions();
  _NodeProduce->setPositionY(0);

  auto lSeqAct = Sequence::create(
    MoveTo::create(1, {0, 80}),
    CallFunc::create([this](){
      _NodeProduce->setPositionY(0);
      _NodeProduce->setVisible(false);
    }),
    DelayTime::create(90),
    CallFunc::create([this](){
      _NodeProduce->setVisible(true);
    }),
    nullptr
  );
  _NodeProduce->runAction(RepeatForever::create(lSeqAct));
}

void WorldMapMineBuild::HideProduceAct(){
  if(_NodeProduce){
    _NodeProduce->stopAllActions();
    _NodeProduce->setPositionY(0);
    _NodeProduce->setVisible(false);
  }
}

GString WorldMapMineBuild::GetFavoriteName(){
  if(_ObjID > 0){
    return AllianceStrongholdMineRead::Get()->GetMineName(_ObjID);
  }
  return "";
}

void WorldMapMineBuild::PlayClickSound() {
  GBase::PlaySound("innerbuildsound", 119);
}

GTuple<UIBasePanel *, bool, Node*> WorldMapMineBuild::OnClickInstance(Node *pNode){
  PlayClickSound();
  auto [lSelectShowPanel, _, l_ ]= OnShowWorldMapTip(pNode);
  return {lSelectShowPanel, true, nullptr};
}

GVector<RButtonTypeArray> WorldMapMineBuild::GetInstanceOp(bool pIsSelfKingdom, bool pIsInWar) {
  GVector<RButtonTypeArray> lButtonTypeArray;
  // if false == ramadanWorldExplorerCtrl:isTaskFinished(self.taskIndex) then
  //   table.insert(buttonTypeArray, {
  //     buttonType = worldMapDefine.worldMapTipButtonType_ramadan_world_explore
  //   })
  // end
  lButtonTypeArray.push_back({EWorldMapTipButtonType::xiangqing});
  return lButtonTypeArray;
}

void WorldMapMineBuild::AddCacheBefore() {

}
