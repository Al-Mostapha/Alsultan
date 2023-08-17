#include "WorldMapMonster.h"
#include "Base/Utils/XTransition.h"
#include "Base/Common/Common.Func.h"
#include "Base/Common/Common.Msg.h"
#include "Module/World/WorldMap/WorldMap.Define.h"
#include "Module/World/WorldMap/WorldMap.Func.h"
#include "Module/World/WorldMap/View/WorldMap.View.h"
#include "Module/UI/Panel/World/WorldMap/Instance/Unit/UIWorldMapMonsterInfo.Panel.h"


void WorldMapMonster::Ctor(){
  _MonsterClassID = 0;
  _ImgName = "";
  _ImgNameAngle = "";
  _IsFlipX = false;
  _InitUI();
  _InitData();
}

void WorldMapMonster::_InitData(){
  _MonsterState = EMapObjStateTypeDef::Free;
  _IsCanKill = false;
  _FightingFrames.clear();
  _FightingImgNameAngle = "";
  _FightingIsFlipX = false;
  _FramesNumber = 8;
  _FramesTimes = 0.15;
  _GroupID = EGrouID::None;
}

void WorldMapMonster::_InitUI(){
  _Monster = GDisplay::Get()->NewSprite("anbs_dj_ws_01.png");
  this->addChild(_Monster, -1);
  GBase::RCreateLabelParm lParm;
  lParm._Text = "";
  lParm._FontSize = 16;
  lParm._UILabelType = GBase::EUILabelType::TTF;
  _MonsterNameLabel = GBase::DCreateLabel(lParm);
  _MonsterNameLabel->setColor(Color3B(88, 52, 16));
  _MonsterNameLabel->setAnchorPoint(Vec2(0.5, 0.5));
  _MonsterNameLabel->setPosition(_CenterPoint - Vec2(0, 70));
  addChild(_MonsterNameLabel, 1);
  // self.monsterNameLabel:setGroupID(worldMapDefine.GROU_ID.group_text_monster)
  _ImageLevel = GDisplay::Get()->NewSprite("frame_SJDT_dengjipai.png");
  _ImageLevel->setPosition(_CenterPoint - Vec2(63, 70));
  addChild(_ImageLevel, 1);
  // self.image_level:setGroupID(worldMapDefine.GROU_ID.group_level_monster)
  lParm._FontSize = 15;
  _MonsterLevelLabel = GBase::DCreateLabel(lParm);
  _MonsterLevelLabel->setAnchorPoint(Vec2(0.5, 0.5));
  _MonsterLevelLabel->setPosition(_CenterPoint - Vec2{64, 70});
  addChild(_MonsterLevelLabel, 1);
  // self.monsterLevelLabel:setGroupID(worldMapDefine.GROU_ID.group_text_monster)
}

void WorldMapMonster::AddCacheBefore(){
  DoStopAllActions();
  if(_ImgName == "mny"){
    if(getChildByName("sp_mny"))
      removeChildByName("sp_mny", true);
  } else if(_ImgName == "jsmny"){
    if(getChildByName("sp_jsmny"))
      removeChildByName("sp_jsmny", true);
  } else {
    auto lEtNode = getChildByName("attackNode");
    if(lEtNode){
      removeChildByName("attackNode", true);
    }
  }
}

void WorldMapMonster::SetBatchNodeGroupID(EGrouID pBatchNodeGroupID){
  // self.monster:setGroupID(groupID)
  // self.groupID = groupID
}

void WorldMapMonster::InitInstanceData(
  int32 pMonsterClassID, const GString &pImgNameAngle,
  bool pIsFlipX, const RMonsterInitData &pNpcData
){
  _MonsterClassID = pMonsterClassID;
  _ImgName =  WorldMapDefine::Get()->GetMonsterImageName(pMonsterClassID);
  _ImgNameAngle = pImgNameAngle;
  _IsFlipX = pIsFlipX;
  _IsWastelandMonster = CheckIsWastelandMonster(pMonsterClassID);
  _MonsterName = WorldMapDefine::Get()->GetMonsterName(pMonsterClassID);
  _MonsterLevel = WorldMapDefine::Get()->GetMonsterLevel(pMonsterClassID);
  _InstanceLevel = _MonsterLevel;
  RefreshNameLabel(pNpcData);
  _MonsterLevelLabel->setString(std::to_string(_MonsterLevel));
  if(_IsWastelandMonster){
    _MonsterLevelLabel->setVisible(false);
    _ImageLevel->setSpriteFrame("icon_hhzz_guaiwu.png");
  }else{
    _MonsterLevelLabel->setVisible(true);
    _ImageLevel->setSpriteFrame("frame_SJDT_dengjipai.png");
  }
  auto lOffsetX = GBase::DGetTextLen(_MonsterNameLabel) * 0.5 + 25;
  _ImageLevel->setPosition(_CenterPoint - Vec2(lOffsetX, 70));
  _MonsterLevelLabel->setPosition(_CenterPoint - Vec2(lOffsetX, 70));
  _Monster->setSpriteFrame(_ImgName + "_dj_" + "ws" + "_01.png");
  _Monster->setFlippedX(_IsFlipX);
  UpdateData(pNpcData);
}

void WorldMapMonster::UpdateData(const RMonsterInitData &pNpcData){
  // if not data then
  //   return
  // end
  _NpcData = pNpcData;
  if(pNpcData._IsCanKill){
    _IsCanKill = pNpcData._IsCanKill.value();
    if(_IsCanKill){
      _MonsterLevelLabel->setColor(Color3B(255, 255, 255));
    } else {
      _MonsterLevelLabel->setColor(Color3B(250, 150, 25));
    }
  }

  if(pNpcData._Status){
    _MonsterState = pNpcData._Status.value();
  }
  if(_MonsterState == EMapObjStateTypeDef::Free){
    DoStandingAnimation();
  } else if(_MonsterState == EMapObjStateTypeDef::HurtDie){
    DoDieingAnimation();
  }
  RefreshNameLabel(pNpcData);
}

void WorldMapMonster::RefreshNameLabel(const RMonsterInitData &pData){
  if(pData._LifeCount && _IsWastelandMonster){
    _LifeCount = pData._LifeCount.value();
    _MonsterNameLabel->setString(GString("x") + std::to_string(_LifeCount));
  }else{
    _MonsterNameLabel->setString(_MonsterName);
  }
}


void WorldMapMonster::DoStopAllActions(){
  _Monster->stopAllActions();
  _Monster->setVisible(true);
  auto lAttackEffectNode =  getChildByName("attackEffectNode");
  if(lAttackEffectNode)
    lAttackEffectNode->removeFromParent();
}

void WorldMapMonster::BeginAttack(Vec2 pFacePoint){
  auto lWorldMapView = dynamic_cast<WorldMapView *>(GBase::DCurrentSceneShowView("worldMapView"));
  if(lWorldMapView)
    pFacePoint = lWorldMapView->GetPointWithTile(pFacePoint);
  auto lBeginPoint = getPosition();
  bool _;
  std::tie(_, _FightingImgNameAngle, _FightingIsFlipX) = WorldMapFunction::Get()->GetMonsterImgAngel(lBeginPoint, pFacePoint);
  _Monster->setFlippedX(_FightingIsFlipX);
  auto lPattern = GString(_ImgName + "_gj_" + _FightingImgNameAngle + "_%02d.png").c_str();
  _FightingFrames = GDisplay::Get()->NewFrames( lPattern , 1, _FramesNumber );
  DoStopAllActions();
  DoFightingAnimation();
  GBase::PlaySound("worldmap", 3);
}

void WorldMapMonster::DoStandingAnimation(){
  DoStopAllActions();
  auto lPattern = GString(_ImgName + "_dj_" + "ws" + "_%02d.png").c_str();
  auto lFrames = GDisplay::Get()->NewFrames(lPattern, 1, _FramesNumber);
  auto lAnimation = GDisplay::Get()->NewAnimation(lFrames, _FramesTimes);
  XTransition::Get()->PlayAnimationForever(_Monster, lAnimation);
  _Monster->setFlippedX(_IsFlipX);
}

void WorldMapMonster::DoFightingAnimation(){
  auto lNodeName = WorldMapDefine::Get()->GetAttackEffectCsbName(_ImgName, _FightingImgNameAngle);
  if(!lNodeName.empty()){
    //   self.monster:setVisible(false)
    //   local nodeName = worldMapDefine.getAttackEffectCsbName(self.imgName, self.fightingImgNameAngle)
    //   local node = worldMapDefine.createAttackEffectCsb({
    //     nodeName = nodeName,
    //     groupID1 = instanceFactory.batchNode.attackEffectBatchNode,
    //     groupID2 = self.groupID,
    //     pos = cc.p(self.monster:getPositionX(), self.monster:getPositionY()),
    //     scale = self.monster:getScaleX(),
    //     isFlipX = self.fightingIsFlipX
    //   })
    //   node:addTo(self, 99)
    //   return
  }
  auto lAnimation = GDisplay::Get()->NewAnimation(_FightingFrames, _FramesTimes);
  _Monster->runAction(Animate::create(lAnimation));
  auto lIndex = float(WorldMapDefine::Get()->GetBeginAnimationByName(_ImgName));
  auto lActions = Sequence::create(
    DelayTime::create(0.1 * lIndex),
    CallFunc::create([this](){
      AddFightEffect();
    }),
    DelayTime::create(1.2f - 0.1f * lIndex),
    CallFunc::create([this](){
      DoFightingAnimation();
    }),
    nullptr
  );
  _Monster->runAction(lActions);
}

void WorldMapMonster::DoDieingAnimation(){
  DoStopAllActions();
  auto lPattern = GString(_ImgName + "_sw_" + "ws" + "_%02d.png").c_str();
  auto lFrames = GDisplay::Get()->NewFrames(lPattern, 1, _FramesNumber);
  auto lAnimation = GDisplay::Get()->NewAnimation(lFrames, _FramesTimes);
  XTransition::Get()->PlayAnimationOnce(_Monster, lAnimation, false, CC_CALLBACK_0(WorldMapMonster::FinishedAfterDead, this), 0.0f);
  _Monster->setFlippedX(_FightingIsFlipX);
}

void WorldMapMonster::FinishedAfterDead(){
  Vector<FiniteTimeAction *> lActionsArray;
  lActionsArray.pushBack(DelayTime::create(1));
  lActionsArray.pushBack(CallFunc::create([this](){
    GBase::DSendMessage("MESSAGE_WORLD_MAP_REMOVE_MAPINSTANCE", this);
  }));
  runAction(XTransition::Get()->Sequence_(lActionsArray));
}

void WorldMapMonster::AddFightEffect(){
  auto lEffectSource = WorldMapDefine::Get()->GetEffectByNameAndDir(_ImgName, _FightingImgNameAngle);
  if(lEffectSource.empty())
    return;
  if(_ImgName == "mny"){
    if(getChildByName("sp_mny"))
      removeChildByName("sp_mny", true);
    auto lSpMny = GDisplay::Get()->NewSprite(GString("et_mny_attack_" + _FightingImgNameAngle + "_01.png").c_str());
    lSpMny->setPosition(lEffectSource[0]._Pos);
    lSpMny->setName("sp_mny");
    lSpMny->setFlippedX(_FightingIsFlipX);
    addChild(lSpMny, 5);
    auto lPattern = GString("et_mny_attack_" + _FightingImgNameAngle + "_%.2d.png").c_str();
    auto lFrames = GDisplay::Get()->NewFrames(lPattern, 1, 2);
    auto lAnimation = GDisplay::Get()->NewAnimation(lFrames, 0.15);
    XTransition::Get()->PlayAnimationOnce(lSpMny, lAnimation, false, nullptr, 0.6f);
  } else if(_ImgName == "jsmny"){
    if(getChildByName("sp_jsmny"))
      removeChildByName("sp_jsmny", true);
    auto lSpJsmny = GDisplay::Get()->NewSprite("dh_jsmny_01.png");
    if(_FightingIsFlipX){
      lSpJsmny->setPosition(-lEffectSource[0]._Pos.x, lEffectSource[0]._Pos.y);
      lSpJsmny->setRotation(-lEffectSource[0]._Rotate);
    } else {
      lSpJsmny->setPosition(lEffectSource[0]._Pos);
      lSpJsmny->setRotation(lEffectSource[0]._Rotate);
    }
    lSpJsmny->setName("sp_jsmny");
    lSpJsmny->setFlippedX(_FightingIsFlipX);
    addChild(lSpJsmny, 5);
    auto lFrames = GDisplay::Get()->NewFrames("dh_jsmny_%.2d.png", 1, 5);
    auto lAnimation = GDisplay::Get()->NewAnimation(lFrames, 0.8 / lFrames.size());
    XTransition::Get()->PlayAnimationOnce(lSpJsmny, lAnimation);
  }else{
    auto lEtNode = getChildByName("attackNode");
    if(lEtNode){
      GBase::DResetEffectNode(lEtNode);
    }else{
      auto lAttackNode = GBase::DCreateEffectNode(lEffectSource);
      lAttackNode->setName("attackNode");
      auto lScaleX = 1;
      auto lMoveY = 1;
      if(_FightingIsFlipX)
        lScaleX = -1;
      if(_FightingImgNameAngle == "ws")
        lMoveY = -1;
      
      lAttackNode->setScaleX(lScaleX);
      addChild(lAttackNode, 5);
      if(_ImgName == "b"){
        lAttackNode->runAction(MoveBy::create(0.5, Vec2(-50 * lScaleX, 50 * lMoveY)));
      }
    }
  }
}


void WorldMapMonster::BottomApertureEffect(){
  RCreatEffctParam lParam;
  lParam._PList = "et_zhanhun_display_01.plist";
  lParam._Scale = Vec2(3.32f, 2.4f);
  lParam._Rotate = 3.17f;
  auto lParNode = GBase::DCreateEffectNode({lParam});
  lParNode->setPositionY(-_Monster->getContentSize().height / 2.f + 50.f);
  addChild(lParNode, 2);
}

GTuple<UIBasePanel *, bool, Node*> WorldMapMonster::OnClickInstance(Node *pNode){
  if(_IsWastelandMonster && WorldMapDefine::Get()->IsInKingdomBattle()){
    GBase::DShowMsgBox(Translate::i18n("common_text_3302"), Translate::i18n("common_text_204"));
    return { nullptr, false, nullptr };
  }
  PlayClickSound();
  auto lSelectShowPanel = UIWorldMapMonsterInfoPanel::Create(this);
  lSelectShowPanel->setAnchorPoint(Vec2(0.5, 0));
  lSelectShowPanel->setPosition(Vec2(GDisplay::Get()->width / 2, GDisplay::Get()->iPhoneXBottom));
  lSelectShowPanel->SetTilePoint(_TilePoint);
  lSelectShowPanel->InitData(this);
  lSelectShowPanel->UpateInfoPanel(_MonsterClassID);
  lSelectShowPanel->Show();

  if(_MonsterLevel == 1){
    //   local guideCtrl = SoraDGetCtrl("guideCtrl")
    //   if guideCtrl:isGuideNotCompleted(gGuideModule.WORLD_MONSTER) and guideCtrl:updateGuideModule(gGuideModule.WORLD_MONSTER) ~= nil then
    //     selectShowPanel:setVisible(false)
    //   end
  }

  return { lSelectShowPanel, true, nullptr };
}

void WorldMapMonster::PlayClickSound(){
  if(GGlobal::Get()->gSoundDataList.Contains(_ImgName))
    GBase::PlaySound("worldMapMonster", _ImgName);
  else
    GBase::PlaySound("worldmap", 5);
}

bool WorldMapMonster::CheckIsWastelandMonster(int32 pMonsterClassID){
  pMonsterClassID = pMonsterClassID ? pMonsterClassID : _MonsterClassID;
  return WorldMapDefine::Get()->CheckIsWastelandMonster(pMonsterClassID);
}


int32  WorldMapMonster::GetBelongInstanceID(){
    return _NpcData._BossID;
}