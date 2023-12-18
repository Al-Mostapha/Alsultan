#include "WorldMapBoss.h"
#include "Engine/OS.h"
#include "Module/World/WorldMap/WorldMap.Define.h"
#include "Module/World/WorldMap/View/WorldMap.View.h"
#include "Module/World/WorldMap/WorldMap.Func.h"
#include "Base/Utils/XTransition.h"
#include "Base/Common/Common.Func.h"
#include "Base/Common/Common.Msg.h"
#include "Base/Base.create.h"
#include "Base/Functions/ServiceFunction.h"
#include "Module/Player/LordInfo.Ctrl.h"
#include "Module/Player/Player.Top.h"
#include "Module/Guild/Alliance.Mgr.h"
#include "Module/World/WorldWar/PyramidWar/ConquestWar.Ctrl.h"
#include "Module/UI/Panel/World/WorldMap/Instance/Unit/Boss/UIWorldMapBoss.View.h"
#include "Module/UI/Panel/World/WorldMap/Instance/Unit/Boss/UIWorldMapEndlessTrialBossInfo.h"
#include "Module/World/WorldMap/Monster/Boss/WasteLand/WasteLand.Ctrl.h"


void WorldMapBoss::Ctor() {
  _InitUI();
  _InitData();
}

void WorldMapBoss::_InitData(){
  _BossState = EMapObjStateTypeDef::Free;
}

void WorldMapBoss::_InitUI(){
  _BossImg = GDisplay::Get()->NewSprite(_ImgName + "_dj_ws.png");
  addChild(_BossImg, -1);
  _BossImg->setScale(1.5f);

  GBase::RCreateLabelParm lParm;
  lParm._UILabelType = GBase::EUILabelType::TTF;
  lParm._Text = "";
  lParm._FontSize = 16;
  
  _NameLabel = GBase::DCreateLabel(lParm);
  _NameLabel->setColor(Color3B(88, 52, 16));
  _NameLabel->setAnchorPoint(Vec2(0.5f, 0.5f));
  _NameLabel->setPosition(Vec2(_CenterPoint.x - 0, _CenterPoint.y - 93));
  addChild(_NameLabel, 1);
  // self.nameLabel:setGroupID(worldMapDefine.GROU_ID.group_text_monster)

  _ImageLevel = GDisplay::Get()->NewSprite("frame_SJDT_dengjipai.png");
  _ImageLevel->setPosition(Vec2(_CenterPoint - Vec2(88, 69)));
  addChild(_ImageLevel, 1);
  // self.image_level:setGroupID(worldMapDefine.GROU_ID.group_level_monster)

  lParm._Text = "";
  lParm._FontSize = 15;
  _LevelLabel = GBase::DCreateLabel(lParm);
  _LevelLabel->setAnchorPoint(Vec2(0.5f, 0.5f));
  _LevelLabel->setPosition(Vec2(_CenterPoint - Vec2(89, 68)));
  addChild(_LevelLabel, 1);
  // self.levelLabel:setGroupID(worldMapDefine.GROU_ID.group_text_monster)
  
  _ProgressBar = UIWorldMapBossProgressBar::Create();
  _ProgressBar->setPosition(Vec2(_CenterPoint - Vec2(0, 70)));
  _ProgressBar->setAnchorPoint(Vec2(0.5f, 0.5f));
  addChild(_ProgressBar, 1);
  _ProgressBar->setVisible(false);
  // self.progressBar:setGroupID(worldMapDefine.GROU_ID.group_progress_monster)
  // self.progressBar:setGroupAuto(true)

  _RefNode = GDisplay::Get()->NewNode();
  addChild(_RefNode, 1);
  _RefNode->setPosition(Vec2(_CenterPoint - Vec2(0, 50)));
  _RefNode->setVisible(false);
  auto lImage = GDisplay::Get()->NewSprite("frame_sheer_black_01.png");
  _RefNode->addChild(lImage);
  
  lImage->setScale(0.5f, 0.7f);
  lParm._Text = "";
  lParm._FontSize = 16;
  _RefLabel = GBase::DCreateLabel(lParm);
  _RefLabel->setColor(Color3B(255, 255, 255));
  _RefLabel->setAnchorPoint(Vec2(0.5f, 0.5f));
  _RefNode->addChild(_RefLabel);
  // label:setGroupID(worldMapDefine.GROU_ID.group_text_monster)
}

void WorldMapBoss::OnMessageListener() {
}

void WorldMapBoss::AddCacheBefore() {
  DoStopAllActions();
  auto lEtNode = getChildByName("attackNode");
  if(lEtNode)
    lEtNode->removeFromParent();
  _RefNode->setVisible(false);
}

void WorldMapBoss::SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) {
  // if self:checkIsEndlessTrialBoss() then
  //   groupID = worldMapDefine.GROU_ID.endlessTrialBatchNode
  // end
  // self.bossImg:setGroupID(groupID)
  // self.groupID = groupID
}

void WorldMapBoss::InitInstanceData(
  EBossType pBossClassID, const GString &pImageAngle, 
  bool pIsFlipX, const RWorldMapBossInit &pInitData
){
  _HasHD = WorldMapDefine::Get()->HasBossHdRes(pBossClassID, pInitData._Level);
  _ImgNameAngle = pImageAngle;
  _IsFlipX = pIsFlipX;
  _BossClassID = pBossClassID;
  _LeftLife = pInitData._LeftLife;

  // if self.recalculateLeftLife then
  //   self:recalculateLeftLife()
  // end

  _IsManuPlace = pInitData._IsManuPlace;
  if(pInitData._LeftTime > GOS::Get()->GetTime())
    _LeftTime = pInitData._LeftTime;
  else
    _LeftTime = 0;
    
  _BossData = WorldMapDefine::Get()->GetWorldBossShow(_BossClassID, pInitData._Level);
  _ImgName = _BossData._Effects;
  
  if(_BossData._Frams)
    _FramesNumber = _BossData._Frams;
  if(_FramesNumber == 8)
    _FramesTimes = 0.15f;
  else if(_BossClassID >= EBossType::windTowerBoss)
    _FramesTimes = 0.06666666666666667f;
  else
    _FramesTimes = 0.08333333333333333f;

  _BossName = Translate::i18n(_BossData._Name.c_str());
  _BossLevel = pInitData._Level;
  _InstanceLevel = _BossLevel;
  
  _NameLabel->setString(_BossName);
  _LevelLabel->setString(std::to_string(_BossLevel));
  _SettingID = pInitData._SettingID;

  if(_HasHD){
    _BossImg->setSpriteFrame(GDisplay::Get()->NewSpriteFrame((_ImgName + "_dj_ws_01.png").c_str()));
  }else{
    _BossImg->setSpriteFrame(GDisplay::Get()->NewSpriteFrame((_ImgName + "_dj_ws.png").c_str()));
  }
  
  if(_BossClassID == EBossType::windTowerBoss){
    _IsFlipX = false;
  }
  
  _BossImg->setFlippedX(_IsFlipX);
  SetScaleAndPositionY();
  updateData(pInitData);
}

EBossType WorldMapBoss::GetBossClassID() const{
    // return self.bossClassID
    return _BossClassID;
}

void WorldMapBoss::updateData(const RWorldMapBossInit &pData){
  if(pData._LeftLife){
    _LeftLife = pData._LeftLife;
    //   if self.recalculateLeftLife then
    //     self:recalculateLeftLife()
    //   end
  }
  _BossState = pData._Status;
  _PlaceUid = pData._PlaceUid;
  if(_BossState == EMapObjStateTypeDef::Free){
    DoStandingAnimation();
  }else if(_BossState == EMapObjStateTypeDef::HurtDie){
    DoDieingAnimation();
  }
  
  _RecoverBeginTime = pData._RecoverBeginTime;
  UpdateProcessBar();
}
void WorldMapBoss::AddFireEffect(float pFightTime, const RAddFireData &pData){
  auto lFacePoint = Vec2::ZERO;
  if(pData._FightingToPointX && pData._FightingToPointY){
    lFacePoint = Vec2(pData._FightingToPointX.value(), pData._FightingToPointY.value());
  }

  BeginAttack(lFacePoint);
  auto lSeq = Sequence::create(
    DelayTime::create(pFightTime),
    CallFunc::create([this](){
      DoStopAllActions();
    }),
    nullptr
  );
  _BossImg->runAction(lSeq);
}

void WorldMapBoss::SetScaleAndPositionY(){
  _BossImg->setScale(_BossData._Scale ? _BossData._Scale : 1.5f);
  _BossImg->setPositionY(_BossData._OffsetY);
}

void WorldMapBoss::DoStopAllActions(){
  _BossImg->stopAllActions();
  _BossImg->setVisible(true);
  auto lAttackEffectNode = getChildByName("attackEffectNode");
  if(lAttackEffectNode)
    lAttackEffectNode->removeFromParent();
}

void WorldMapBoss::BeginAttack(Vec2 pFacePoint){
  auto lWorldMapView = dynamic_cast<WorldMapView *>(GBase::DCurrentSceneShowView("worldMapView"));
  if(lWorldMapView)
    pFacePoint = lWorldMapView->GetPointWithTile(pFacePoint);
  auto lBeginPoint = getPosition();
  auto lEndPoint = pFacePoint;
  
  float lRotation;
  std::tie(lRotation, _FightingImgNameAngle, _FightingIsFlipX) =  WorldMapFunction::Get()->GetMonsterImgAngel(lBeginPoint, lEndPoint);
  _BossImg->setFlippedX(_FightingIsFlipX);
  if(_HasHD){
    _FightingFrames = GDisplay::Get()->NewFrames(
      (_ImgName + "_gj_" + _FightingImgNameAngle + "_%02d.png").c_str(), 1, _FramesNumber);
  }else{
    _BossImg->setSpriteFrame(GDisplay::Get()->NewSpriteFrame(
      (_ImgName + "_gj_" + _FightingImgNameAngle + ".png").c_str()));
  }
  
  DoStopAllActions();
  DoFightingAnimation();
  GBase::PlaySound("worldmap", 3);
}

void WorldMapBoss::DoStandingAnimation(){
  DoStopAllActions();
  if(_HasHD){
    auto lFrames = GDisplay::Get()->NewFrames(
      (_ImgName + "_dj_" + "ws" + "_%02d.png").c_str(), 1, _FramesNumber);
    auto lAnimation = GDisplay::Get()->NewAnimation(lFrames, _FramesTimes);
    XTransition::Get()->PlayAnimationForever(_BossImg, lAnimation);
  }else{
    _BossImg->setSpriteFrame((_ImgName + "_dj_ws.png").c_str());
  }
  _BossImg->setFlippedX(_IsFlipX);
}

void WorldMapBoss::DoFightingAnimation(){
  auto lNodeName = WorldMapDefine::Get()->GetAttackEffectCsbName(_ImgName, _FightingImgNameAngle);
  if(!lNodeName.empty()){
    if(_HasHD){
      _BossImg->setVisible(false);
      auto lNodeName = WorldMapDefine::Get()->GetAttackEffectCsbName(_ImgName, _FightingImgNameAngle);

      RAttackEffectData lData;
      lData._NodeName = lNodeName;
      lData._Pos = _BossImg->getPosition();
      lData._Scale = _BossImg->getScaleX();
      lData._IsFlipX = _FightingIsFlipX;

      auto lNode  = WorldMapDefine::Get()->CreateAttackEffectCsb(lData);
      addChild(lNode, 99);
      if(CheckIsEndlessTrialBoss()){
        GBase::DMixtureGLONEByParent(lNode);
        //       node:setGroupID(self.groupID)
        //       node:setGroupAuto(true)
      }else{
        GBase::DMixtureGLONEByParent(lNode);
      }
    }
    return;
  }
  
  if(_HasHD){
    auto lAnimation = GDisplay::Get()->NewAnimation(_FightingFrames, _FramesTimes);
    XTransition::Get()->PlayAnimationOnce(_BossImg, lAnimation, false, [this](){
      DoFightingAnimation();
    });
  }
  
  auto lIndex = WorldMapDefine::Get()->GetBeginAnimationByName(_ImgName);
  Vector<FiniteTimeAction *> lActionsArray;
  lActionsArray.pushBack(DelayTime::create(0.1f * lIndex));
  lActionsArray.pushBack(CallFunc::create([this](){
    AddFightEffect();
  }));

  auto lActions = XTransition::Get()->Sequence_(lActionsArray);
  _BossImg->runAction(lActions);
}

void WorldMapBoss::DoDieingAnimation(){
  DoStopAllActions();
  if(_HasHD){
    auto lFrames = GDisplay::Get()->NewFrames((_ImgName + "_sw_ws_%02d.png").c_str(), 1, _FramesNumber);
    auto lAnimation = GDisplay::Get()->NewAnimation(lFrames, _FramesTimes);
    XTransition::Get()->PlayAnimationOnce(
      _BossImg, lAnimation, false, 
      CC_CALLBACK_0(
        WorldMapBoss::FinishedAfterDead, this
      )
    );
  }else{
    _BossImg->setSpriteFrame((_ImgName + "_sw_ws.png").c_str());
    FinishedAfterDead();
  }
  _BossImg->setFlippedX(_IsFlipX);
}

void WorldMapBoss::FinishedAfterDead(){
  Vector<FiniteTimeAction *> lActionsArray;
  lActionsArray.pushBack(DelayTime::create(1));
  lActionsArray.pushBack(CallFunc::create([this](){
    GBase::DSendMessage(
      "MESSAGE_WORLD_MAP_REMOVE_MAPINSTANCE",
      this
    );
  }));
  
  auto lActions = XTransition::Get()->Sequence_(lActionsArray);
  runAction(lActions);
}

void WorldMapBoss::AddFightEffect(){
  auto lEffectSource = WorldMapDefine::Get()->GetEffectByNameAndDir(_ImgName, _FightingImgNameAngle);
  if(lEffectSource.empty())
    return;
  auto lEtNode = getChildByName("attackNode");
  if(lEtNode){
    GBase::DResetEffectNode(lEtNode);
  }else{
    auto lAttackNode = GBase::DCreateEffectNode(lEffectSource);
    lAttackNode->setName("attackNode");
    auto lScaleX = 1;
    if(_FightingIsFlipX)
      lScaleX = -1;
    lAttackNode->setScaleX(lScaleX);
    addChild(lAttackNode, 5);
  }
}


GTuple<UIBasePanel *, bool, Node*> WorldMapBoss::OnClickInstance(Node *pNode) {
  if(CheckIsEndlessTrialBoss()){
    return OnClickEndlessTrialBoss(pNode);
  }
  
  if(GetBossClassID() == EBossType::heroBattleBoss1 || GetBossClassID() == EBossType::heroBattleBoss2 || GetBossClassID() == EBossType::wastelandBoss){
    if(ConquestWarCtrl::Get()->IsPlayerConquestWarMigration() && LordInfoCtrl::Get()->GetSourceKid() > 0){
      GBase::DShowMsgBox(Translate::i18n("common_text_3302"), Translate::i18n("common_text_204"));
      return {nullptr, false, nullptr};
    }
  }
  
  if(GetBossClassID() == EBossType::mirajBoss){
    if(GetPlaceUid() != PlayerTop::Get()->GetPlayerID()){
      GBase::DShowMsgBox(Translate::i18n("almirajChange_text16"));
      return {nullptr, false, nullptr};
    }
    if(AllianceManager::Get()->HasJoinAlliance()){
      GBase::DShowMsgBox(Translate::i18n("almirajChange_text17"));
      return {nullptr, false, nullptr};
    }
  }
  
  PlayClickSound();
  auto lSelectShowPanel = UIWorldMapBossView::Create();
  lSelectShowPanel->setPosition(Vec2(GDisplay::Get()->width/2, GDisplay::Get()->height/2));
  lSelectShowPanel->SetTilePoint(_TilePoint);
  lSelectShowPanel->InitData(this);
  lSelectShowPanel->Show();
  return {lSelectShowPanel, true, nullptr};
}

void WorldMapBoss::PlayClickSound() {
  if(GGlobal::Get()->gSoundDataList.Contains(_ImgName)){
    GBase::PlaySound("worldMapMonster", _ImgName);
  }else{
    GBase::PlaySound("worldmap", 5);
  }
}

void WorldMapBoss::UpdateProcessBar(){
  if(_LeftLife  > 0)
    _ProgressBar->SetPercent(_LeftLife);
  else
    _ProgressBar->setVisible(false);
  _ProgressBar->SetReleaseTime(GetReleaseLeftTime());
}

bool WorldMapBoss::CheckIsEndlessTrialBoss(){
  auto lBoss = GetBossClassID();
  if(
      lBoss == EBossType::endlessTrialBoss1 
      || lBoss == EBossType::endlessTrialBoss2 
      || lBoss == EBossType::endlessTrialBoss3 
      || lBoss == EBossType::endlessTrialBoss4 
      || lBoss == EBossType::endlessTrialBoss5 
      || lBoss == EBossType::endlessTrialBoss6 
      || lBoss == EBossType::endlessTrialBoss7 
      || lBoss == EBossType::endlessTrialBoss8
    )
    return true;

  return false;
}

GTuple<UIBasePanel *, bool, Node*> WorldMapBoss::OnClickEndlessTrialBoss(Node *pNode){
  if(WorldMapDefine::Get()->IsInKingdomBattle()){
    GBase::DShowMsgBox(Translate::i18n("common_text_3302"));
    return {nullptr, false, nullptr};
  }
  
  PlayClickSound();

  auto lSelectShowPanel = UIWorldMapEndlessTrialBossInfo::Create();
  lSelectShowPanel->setPosition(Vec2(GDisplay::Get()->width/2, GDisplay::Get()->height/2));
  lSelectShowPanel->SetTilePoint(_TilePoint);
  lSelectShowPanel->InitData(this);
  lSelectShowPanel->Show();
  return {lSelectShowPanel, true, nullptr};
}

void WorldMapBoss::SetMassRef(GOpt<RMassRef> pMassRef){
  if(pMassRef){
    _RefNode->setVisible(true);
    if(WorldMapDefine::Get()->IsWorldBossCanAttackAlone(GetBossClassID(), _BossLevel)){
      _RefLabel->setString(
        Translate::i18n("lost_ruins_text_26", {
            {"num", std::to_string(GetRefNum(pMassRef.value()))}
          }
        )
      );
    }else{
      _RefLabel->setString(
        Translate::i18n(
          "AncienTreasure_text_71", 
          {{"num", std::to_string(GetRefNum(pMassRef.value()))}}
        )
      );
    }
  }else{
    _RefNode->setVisible(false);
  }
}

GTime WorldMapBoss::GetReleaseLeftTime(){
  if(!_RecoverBeginTime)
    return 0;
  auto lReleaseTime = WasteLandCtrl::Get()->GetBossConfigByLv()._Release;
  return _RecoverBeginTime + lReleaseTime - GServiceFunction::Get()->SystemTime();
}

int32 WorldMapBoss::GetRefNum(const RMassRef &pMassRef){
  // local num = 0
  // for _, v in pairs(ref) do
  //   num = num + table.nums(v)
  // end
  // return num
  return 0;
}

int32 WorldMapBoss::GetPlaceUid(){
  return _PlaceUid;
}

int32 WorldMapBoss::GetSettingID(){
  return _SettingID;
}
