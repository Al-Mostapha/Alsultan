#include "WorldMapTreasureBowl.h"
#include "Base/Base.Const.h"
#include "Base/Base.create.h"
#include "Module/World/WorldMap/WorldMap.Define.h"
#include "Module/Player/Player.Top.h"
#include "Module/Player/LordInfo.Ctrl.h"
#include "Module/Item/Item.Read.h"
#include "Base/Utils/XTransition.h"
#include "Base/Common/Common.Func.h"
#include "Module/World/Kingdom/KingdomMap.Ctrl.h"
#include "Module/Activity/ClientEvent.Mgr.h"
#include "Module/UI/EventCenter/EventTemplate/TreasureBowl/UIWorldMapTreasureBowl.View.h"


static GHashMap<int32, int32> _TreeId = {
  {
    {1, 851501},
    {2, 851601},
    {3, 851701},
    {4, 851801}
  }
};

static GHashMap<int32, GString> _TreeName = {
  {
    {1, "8515.png"},
    {2, "8516.png"},
    {3, "8517.png"},
    {4, "8518.png"}
  }
};

void WorldMapTreasureBowl::Ctor() {
  _TreasureImg = "zhouniangz_egg.png";
  _InitUI();
  _InitData();
}

void WorldMapTreasureBowl::_InitData(){
  _IsColl = false;
  _TreasureBowlLevel = 0;
  _LockStatus = false;
  _CoolTime = 5;
  _MaxCount = 10;
  _TreasureState = EMapObjStateTypeDef::Free;
}

void WorldMapTreasureBowl::_InitUI(){
  if(GBase::Const::Get()->IsArClient){
    _TreasureBowlImg = GDisplay::Get()->NewSprite(_TreasureImg);
  }else{
    _TreasureBowlImg = GDisplay::Get()->NewSprite("zhouniangz_03.png");
  }
  addChild(_TreasureBowlImg, -1);
  
  GBase::RCreateLabelParm lParam;
  lParam._UILabelType = GBase::EUILabelType::TTF;
  lParam._Text = "";
  lParam._FontSize = 16;
  _NameLabel = GBase::DCreateLabel(lParam);
  _NameLabel->setColor(Color3B(88, 52, 16));
  _NameLabel->setAnchorPoint(Vec2(0.5, 0.5));
  _NameLabel->setPosition(Vec2(_CenterPoint.x + 10, _CenterPoint.y - 65));
  addChild(_NameLabel, 1);
  // self.nameLabel:setGroupID(worldMapDefine.GROU_ID.group_text_monster)
  
  _ImageLevel = GDisplay::Get()->NewSprite("frame_SJDT_dengjipai.png");
  _ImageLevel->setPosition(Vec2(_CenterPoint.x - 65, _CenterPoint.y - 62));
  addChild(_ImageLevel, 1);
  // self.image_level:setGroupID(worldMapDefine.GROU_ID.group_level_monster)
  lParam._FontSize = 15;
  _LevelLabel = GBase::DCreateLabel(lParam);
  _LevelLabel->setAnchorPoint(Vec2(0.5, 0.5));
  _LevelLabel->setPosition(Vec2(_CenterPoint.x - 66, _CenterPoint.y - 61));
  addChild(_LevelLabel, 1);
  // self.levelLabel:setGroupID(worldMapDefine.GROU_ID.group_text_monster)
}

void WorldMapTreasureBowl::AddCacheBefore() {
  _TreasureBowlImg->stopAllActions();
  if(_ImageHammer){
    _ImageHammer->stopAllActions();
    _ImageHammer->setVisible(false);
  }
  
  if(_PyramidProtectNode){
    _PyramidProtectNode->removeFromParent();
    _PyramidProtectNode = nullptr;
  }
}

void WorldMapTreasureBowl::SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) {
  // self.treasureBowlImg:setGroupID(groupID)
}

void WorldMapTreasureBowl::InitInstanceData(int32 pClass, void *pObjData, int32 pObjID) {
  if(pObjData)
    return;
  
  _TreasureBowlClassID = pClass;
  auto lTreasueBowl = WorldMapDefine::Get()->GetTreasureBowlpackShow(_TreasureBowlClassID);
  _NameLabel->setString(Translate::i18n(lTreasueBowl._Name.c_str()));
  _TreasureBowlImg->setSpriteFrame(lTreasueBowl._Image);
  UpdateData(*(RUnitTreasureBowlInit *)pObjData);
}

void WorldMapTreasureBowl::UpdateData(const RUnitTreasureBowlInit &pData){
  if(pData._CollUids.size()){
    auto lSelfPlayerID = PlayerTop::Get()->GetPlayerID();
    if(pData._CollUids.Contains(lSelfPlayerID))
      _IsColl = pData._CollUids.at(lSelfPlayerID);
  }

  if(pData._Level > 0){
    _TreasureBowlLevel = pData._Level;
    _LevelLabel->setString(std::to_string(_TreasureBowlLevel));
  }

  _LockStatus = pData._LockStatus;
  ShowHammer(_LockStatus);
  _MaxCount = pData._ClickCount;
  _CoolTime = pData._CoolTime;
  _TreasureState = pData._TreasureState;
  
  if(_TreasureState == EMapObjStateTypeDef::HurtDie){
    DoDieingAnimation();
  }

  if(_TreeData){
    _TreeData->_IsColl = _IsColl;
  }

  if(pData._MapType == EMapObjTypeDef::mapObjTypeChristmasTree){
    _NameLabel->setString(ItemRead::Get()->GetName(_TreeId[pData._Level]));
    _TreasureBowlImg->setSpriteFrame("sds_bust_outside.png");
    _TreeData = pData;
    _TreasureBowlImg->setPosition(Vec2(-10, 60));
    _ImageLevel->setPosition(Vec2(_CenterPoint.x - 65, _CenterPoint.y - 80));
    _LevelLabel->setPosition(Vec2(_CenterPoint.x - 66, _CenterPoint.y - 80));
    _NameLabel->setPosition(Vec2(_CenterPoint.x - 30, _CenterPoint.y - 80));
    _NameLabel->setAnchorPoint(Vec2(0, 0.5));
  }
}

int32 WorldMapTreasureBowl::GetTreasureBowlClassID(){
  return _TreasureBowlClassID;
}
void WorldMapTreasureBowl::ShowHammer(bool pShow){
  if(pShow){
    if(!_ImageHammer){
      _ImageHammer = GDisplay::Get()->NewSprite("znqchuizi_01.png");
      _ImageHammer->setPosition(Vec2(_CenterPoint.x + 22.5, _CenterPoint.y + 55));
      addChild(_ImageHammer, 1);
    }
    _ImageHammer->setVisible(true);
    _ImageHammer->stopAllActions();
    auto lFrames = GDisplay::Get()->NewFrames("znqchuizi_0%d.png", 1, 4);
    lFrames.pushBack(GDisplay::Get()->NewSpriteFrame("znqchuizi_01.png"));
    auto lAnimation = GDisplay::Get()->NewAnimation(lFrames, 0.1);
    XTransition::Get()->PlayAnimationForever(_ImageHammer, lAnimation);
  }else if(_ImageHammer){
    _ImageHammer->stopAllActions();
    _ImageHammer->setVisible(false);
  }
}

void WorldMapTreasureBowl::DoDieingAnimation(){
  _TreasureBowlImg->stopAllActions();
  Vector<FiniteTimeAction *> lActionsArray;
  lActionsArray.pushBack(DelayTime::create(0.1));
  lActionsArray.pushBack(CallFunc::create([this](){
    if(GBase::Const::Get()->IsArClient){
      _TreasureBowlImg->setSpriteFrame("zhouniangz_02.png");
    }else{
      _TreasureBowlImg->setSpriteFrame("zhouniangz_03.png");
    }
  }));
  
  lActionsArray.pushBack(DelayTime::create(1));
  lActionsArray.pushBack(CallFunc::create([this](){
    GBase::DSendMessage("MESSAGE_WORLD_MAP_REMOVE_MAPINSTANCE" /*instance = self*/);
  }));
  auto lActions = XTransition::Get()->Sequence_(lActionsArray);
  _TreasureBowlImg->runAction(lActions);
  PosuitxEffect();
}

void WorldMapTreasureBowl::PosuitxEffect(){

  GVector<RCreatEffctParam> lParams(4);
  lParams[0]._PList = "et_posuitx_01.plist";
  lParams[1]._PList = "et_posuitx_02.plist";
  lParams[2]._PList = "et_posuitx_03.plist";
  lParams[3]._PList = "et_posuitx_04.plist";
  
  if(_PyramidProtectNode){
    GBase::DResetEffectNode(_PyramidProtectNode);
  }else{
    _PyramidProtectNode = GBase::DCreateEffectNode(lParams);
    addChild(_PyramidProtectNode, 5);
    _PyramidProtectNode->setPosition(_CenterPoint.x, _CenterPoint.y - 50);
  }
}

GTuple<UIBasePanel *, bool, Node*> WorldMapTreasureBowl::OnClickInstance(Node *pNode) {
  auto lSourceKid = LordInfoCtrl::Get()->GetSourceKid();
  if(lSourceKid <= 0)
    lSourceKid = PlayerTop::Get()->GetKingdomID();
  
  if(lSourceKid == _KingdomID){
    auto lBowldata = KingdomMapCtrl::Get()->GetTreasureBowlInfo();
    if(lBowldata && !lBowldata->_IsCanClick){
      GBase::DShowMsgTip(
        Translate::i18n(
          "notice_0192", 
          {
            {"count", std::to_string(lBowldata->_RewardLimit)}
          }
        )
      );
      return {};
    }
  }else if(!ClientEventMgr::Get()->JudgeIsOpen(EActivityTime::TREASUREBOWL_ACTIVITY)){
    GBase::DShowMsgTip(Translate::i18n("activity_text_04"));
    return {};
  }
  
  auto lSelectShowPanel = UIWorldMapTreasureBowlView::Create();
  lSelectShowPanel->setPosition(Vec2(GDisplay::Get()->width/2, GDisplay::Get()->height/2));
  lSelectShowPanel->SetTilePoint(_TilePoint);
  lSelectShowPanel->InitData(this, _TreeData, _TilePoint, _InstanceID);
  lSelectShowPanel->Show();
  
  return {lSelectShowPanel, true, nullptr};
}

void WorldMapTreasureBowl::PlayClickSound() {

}
