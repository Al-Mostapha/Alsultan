#pragma once
#include "Include/IncludeBase.h"
#include "CityScene.View.h"
#include "CityScene.Create.h"
#include "CityScene.ABMManager.h"
#include "CityScene.Move.h"
#include "CityScene.Msg.h"

MainCityView *MainCityView::Create(RViewOtherData p_Data){
  auto l_Panel =  Create("UiParts/Panel/MainCity/mainCityView.csb");
  l_Panel->m_Param = p_Data;
  return l_Panel;
}

void MainCityView::AddToBufferNodeArrayByName(const char *p_Name, Node *p_Node){
  if(!p_Node)
    return;
  n_BufferNodeArray[p_Name] = p_Node;
}

void MainCityView::Ctor(){
  setPosition(Vec2(GDisplay::Get()->cx, GDisplay::Get()->rcy));
  setContentSize(GDisplay::Get()->realSize);
  setAnchorPoint(Vec2(0.5, 0.5));
  setPosition(Vec2(GDisplay::Get()->cx, GDisplay::Get()->rcy));
  auto l_CSize = getContentSize();
  auto l_BlindHeight = (_HUITop + _HUIBottom + GDisplay::Get()->iPhoneXOffset);
  _ViewScrollSize = Size(l_CSize.width, l_CSize.height - l_BlindHeight);
  _CityView = this;
  // n_MainCityView->n_ViewScrollView->setDelegate(nullptr);
  CityFloor::Ctor();
  addChild(_ViewScrollView, 0);
  PreLoadImages();
}

void MainCityView::InitAfterCreate() {
  UpdatePeriod();
  CityFloor::InitWithBuildData();
  CityFloor::InitWithHuoChuangData();
  CityFloor::InitMatouData();
  InitCelebrateGift();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_PYRAMID_BATTLE_MSG");
  n_MainCityView->MsgUpdateLion();
  MainCityBuildingMove::Get()->Init(this);
  MainCityABMManager::Get()->Init(this);
}

void MainCityView::UpdatePeriod(){
  //   local isDealed = false
  // if not isDealed and not self.isCfgNightOn then
  //   self.currentDayPeriod = gDay.DAY_TIME
  //   self:enterDayPeriod(self.currentDayPeriod)
  //   isDealed = true
  // end
  // if not isDealed then
  //   local currentDayPeriod = SoraDGetDayPeriod()
  //   if self.currentDayPeriod ~= currentDayPeriod then
  //     self.currentDayPeriod = currentDayPeriod
  //     self:enterDayPeriod(self.currentDayPeriod)
  //   end
  // end
  // if self.timerHandlerPeriod then
  //   SoraDManagerRemoveTimer(self, self.timerHandlerPeriod)
  //   self.timerHandlerPeriod = nil
  // end
  // local delay = mainCityFunctions:getNextPeroidDelay()
  // self.timerHandlerPeriod = SoraDCreateDelayTimer(self, handler(self, self.updatePeriod), delay)
}

void MainCityView::PreLoadImages(){
  GVector<GString> l_ImgArray;
  l_ImgArray.push_back("MainCity/mainCity");
  l_ImgArray.push_back("MainCity/mainCity2");
  l_ImgArray.push_back("MainCity/mainCityOuter");
  l_ImgArray.push_back("FrameAnimation/mainCityNpc");
  m_IsNeedFirstFight = IsNeedFirstFight();
  std::set<int32> l_SpecialIndexArray = { 1, 2, 3, 4,  6, 7, 8, 9, 13, 21 };
  if(GBase::Const::Get()->IsArClient){
    l_ImgArray.push_back("MainCity/mainCityInner");
    l_ImgArray.push_back("MainCity/mainCityBGHall_top");
    l_ImgArray.push_back("MainCity/mainCityBGDH");
    l_ImgArray.push_back("MainCity/mainCityWall");
    for(auto i = 1 ; i <= 15; i++){
      if(GBase::Const::Get()->RamadanSwitch)
        l_ImgArray.push_back(StringUtils::format("MainCity/mainCityBGHall_%d", i));
      else if(l_SpecialIndexArray.find(i) != l_SpecialIndexArray.end())
        l_ImgArray.push_back(StringUtils::format("MainCity/mainCityBGHall_%d_pre", i));
      else
        l_ImgArray.push_back(StringUtils::format("MainCity/mainCityBGHall_%d", i));
    }

    for(auto i = 16; i <= 28; i++){
      if(GBase::Const::Get()->RamadanSwitch){
        l_ImgArray.push_back(StringUtils::format("MainCity/mainCityBGHall_%d", i));
      }else if(l_SpecialIndexArray.find(i) != l_SpecialIndexArray.end()){
        l_ImgArray.push_back(StringUtils::format("MainCity/mainCityBGHall_%d_pre", i));
      }else{
        l_ImgArray.push_back(StringUtils::format("MainCity/mainCityBGHall_%d", i));
      }

    }
  }
  if(m_IsNeedFirstFight){
    l_ImgArray.push_back("FrameAnimation/mainCitySoliderFirst");
  }
  LoadImages(l_ImgArray, std::bind(&MainCityView::FinishLoadImages, this));
}

void MainCityView::FinishLoadImages(){
  m_IsFinishInit = true;
  OnMessageListener_FinishLoadImage();
  MainCityView::InitAfterCreate();
  GBase::DPushItemAward(GBase::DPopItemAward());
  if(GBase::DCloseLoginView()){
      //   userSDKManager.logEvent(gSDKDef.TDonEvent.enter_city, {})
      if(m_IsNeedFirstFight){
        std::unique_ptr<bool> l_IsShow = std::make_unique<bool>(true);
        GBase::DSendMessage("MESSAGE_MAIN_SCENE_IPHONEX", l_IsShow.get());
      }
  }
}

void MainCityView::OnMessageListener_FinishLoadImage(){
  MainCityMsg::Get()->RegisterMessage(this);
}

bool MainCityView::IsNeedFirstFight(){
  return false;
}

void MainCityView::LoadFixedBuilds(){
//  print("mainCityView:loadFixedBuilds star")
//   self:addBuild(cityBuildConstDef.fixedBuildDef.LeisureCenter, cityBuildConstDef.fixedBuildDef.LeisureCenter)
//   self:addBuild(cityBuildConstDef.buildIndexDef.index_Material_WorkShop, BUILDID.MATERIAL_WORKSHOP)
//   self:addBuild(cityBuildConstDef.fixedBuildDef.HuoChuang, cityBuildConstDef.fixedBuildDef.HuoChuang)
//   self:addBuild(cityBuildConstDef.fixedBuildDef.ServiceCenter, cityBuildConstDef.fixedBuildDef.ServiceCenter)
//   self:addBuild(cityBuildConstDef.buildIndexDef.index_PetCenter, cityBuildConstDef.fixedBuildDef.PetCenter)
//   self:addBuild(cityBuildConstDef.buildIndexDef.index_ResurrectionHall, cityBuildConstDef.fixedBuildDef.ResurrectionHall)
//   self:addBuild(cityBuildConstDef.buildIndexDef.index_EpicBattle, cityBuildConstDef.fixedBuildDef.EpicBattle)
//   self:addBuild(cityBuildConstDef.buildIndexDef.index_Monument, BUILDID.MONUMENT)
//   if not IsArClient then
//     self:addBuild(cityBuildConstDef.buildIndexDef.index_Mastery, cityBuildConstDef.fixedBuildDef.Mastery)
//   end
//   print("mainCityView:loadFixedBuilds end")
}

void MainCityView::SetMainCityEnabled(bool p_Enabled){
  if(_ViewScrollView){
    _ViewScrollView->setTouchEnabled(p_Enabled);
    _IsBuildBtnEnable = p_Enabled;
  }
}

void MainCityView::UpdateBuildTiles(){
  // for i = 1100, 1114 do
  //   local buildBtnName = "build_" .. i
  //   local buildBtn = self:getBufferNodeByName(buildBtnName)
  //   self:updateBuildTile(buildBtn)
  // end
}

void MainCityView::AutoUpdateViewScrollViewPos(float p_Delay){
  // self.viewScrollView:stopAllActions()
  // local delayTime = delay or self.initZoomScaleDuration
  // local actionScaleToV = cca.scaleTo(0, self.normlScrollViewScale)
  // local viewScrollViewSize = cc.size(self:getContentSize().width, self:getContentSize().height - (self.hUITop + self.hUIBottom + display.iPhoneXOffset))
  // local targetY = self.hUIBottom + display.iPhoneXBottom + viewScrollViewSize.height / 2
  // local actionMoveTo = cca.moveTo(0, display.width / 2, targetY)
  // self.viewScrollView:runAction(actionScaleToV)
  // self.viewScrollView:runAction(actionMoveTo)
}

Vec2 MainCityView::GetDefaultMainCityPos(){
  // local Button_Chengbao = self:getBufferNodeByName("build_1050")
  auto l_BtnChengBao = _ContainerView->getChildByName("build_1050");
  // local posX = Button_Chengbao:getPositionX()
  const auto l_PosX = l_BtnChengBao->getPositionX() - 500;
  // local posY = Button_Chengbao:getPositionY() + 500
  const auto l_Posy = l_BtnChengBao->getPositionY() + 500;
  
  // local retPos = self:getContainerOffsetWhenPosPoint(cc.p(posX, posY),
  // cc.p(display.width / 2, display.height / 2), false, true)

  
  // local zoomScale = self:getZoomScale(true)
  // retPos.x = retPos.x - 200 * zoomScale
  // retPos.y = retPos.y
  // return retPos
  return {l_PosX, l_Posy};
}

void MainCityView::LoadSoldiers(){
//  print("-------------------- device.platform = ", device.platform)
//   if device.platform == "mac" then
//     mainCityFunctions.loadSoldiers(self)
//   elseif xpcall(function()
//     mainCityFunctions.loadSoldiers(self)
//   end, function()
//     print(debug.traceback())
//   end) then
//   else
//     print("mainCityView:loadSoldiers \229\188\130\229\184\184\228\186\134\239\188\140\232\175\183\229\164\132\231\144\134-------@hlp")
//   end
}

void MainCityView::UpdateTime(float p_Time){
  //  if self.isNeedFirstFight == true then
  //   return
  // end
  // if self.tipBoxCount >= self.tipBoxMaxCount then
  //   SoraDSendMessage({
  //     msg = "MESSAGE_MAINCITYVIEW_UPDATE_BUILD_TIP_BOX"
  //   })
  //   SoraDSendMessage({
  //     msg = "MESSAGE_MAINCITYVIEW_SHOW_COMMUNITYCENTER_MSG"
  //   })
  //   self.tipBoxCount = 1
  // else
  //   self.tipBoxCount = self.tipBoxCount + 1
  // end
  // if self.soldierBoxCount >= self.soldierBoxMaxCount then
  //   SoraDSendMessage({
  //     msg = "MESSAGE_MAINCITYVIEW_UPDATE_GUARD_SOLDIER_BOX"
  //   })
  //   self.soldierBoxCount = 1
  // else
  //   self.soldierBoxCount = self.soldierBoxCount + 1
  //   if self.isSoldierBoxCountOffset and self.soldierBoxCount == self.soldierBoxCountOffset then
  //     self.soldierBoxCount = 1
  //     self.isSoldierBoxCountOffset = false
  //   end
  // end
  // if self.merchantBoxCount >= self.merchantBoxMaxCount then
  //   SoraDSendMessage({
  //     msg = "MESSAGE_MAINCITYVIEW_UPDATE_MERCHANT_VIEW"
  //   })
  //   self.merchantBoxCount = 1
  // else
  //   self.merchantBoxCount = self.merchantBoxCount + 1
  // end
  // if self.conquerBoxCount >= self.conquerBoxMaxCount then
  //   self.hasConquerGateMsg = false
  //   SoraDSendMessage({
  //     msg = "MESSAGE_MAINCITYVIEW_UPDATE_BUILD_TIP_BOX"
  //   })
  //   self.conquerBoxCount = 1
  // else
  //   self.conquerBoxCount = self.conquerBoxCount + 1
  // end
  // if self.petBoxCount >= self.petBoxMaxCount then
  //   SoraDSendMessage({
  //     msg = "MESSAGE_MAINCITYVIEW_UPDATE_PET_TIP_BOX"
  //   })
  //   self.petBoxCount = 1
  // else
  //   self.petBoxCount = self.petBoxCount + 1
  // end
}

void MainCityView::UpdateTimePerFrame(float p_Time){
  // if not self.frameCount then
  //   self.frameCount = 1
  // end
  // if self.frameCount < 3 then
  //   self.frameCount = self.frameCount + 1
  //   return
  // end
  // self.frameCount = 1
  // if self.isVisibleAreaDirty then
  //   self:moveVisible()
  //   self.isVisibleAreaDirty = false
  // end
}

void MainCityView::RefreshCastleSkin(bool p_IsInit){
  // mainCityMsg.refreshCastleSkin(self, target, data)
}


void MainCityView::InitVisibleArea(){
  // function mainCityView:initVisibleArea()
  //   do return end
  //   self.checkVisibleNodes = {
  //     [self.WaterFallNode:getName()] = {
  //       visibleType = cityBuildConstDef.visibleType.single,
  //       node = self.WaterFallNode,
  //       boundingBox = cc.rect(1319, 1579, 600, 500),
  //       parent = self.containerView
  //     },
  //     [self.cityBuildSoldiersMatrixNode:getName()] = {
  //       visibleType = cityBuildConstDef.visibleType.single,
  //       node = self.cityBuildSoldiersMatrixNode,
  //       boundingBox = cc.rect(1198, 120, 1300, 700),
  //       parent = self.containerView
  //     }
  //   }
  //   local blockAreaInnerNodes1 = {
  //     self:getBufferNodeByName("build_1058"),
  //     self:getBufferNodeByName("build_1059"),
  //     self:getBufferNodeByName("build_1060")
  //   }
  //   local boundingBoxInner1 = cc.rect(1544, 1202, 950, 350)
  //   self.checkVisibleNodes[cityBuildConstDef.blockArea.blockAreaInner1] = {
  //     visibleType = cityBuildConstDef.visibleType.block,
  //     nodes = blockAreaInnerNodes1,
  //     boundingBox = boundingBoxInner1,
  //     parent = self.containerView
  //   }
  //   local blockAreaInnerNodes2 = {
  //     self:getBufferNodeByName("build_1061"),
  //     self:getBufferNodeByName("build_1062"),
  //     self:getBufferNodeByName("build_1066"),
  //     self:getBufferNodeByName("build_1067")
  //   }
  //   local boundingBoxInner2 = cc.rect(1930, 695, 1100, 600)
  //   self.checkVisibleNodes[cityBuildConstDef.blockArea.blockAreaInner2] = {
  //     visibleType = cityBuildConstDef.visibleType.block,
  //     nodes = blockAreaInnerNodes2,
  //     boundingBox = boundingBoxInner2,
  //     parent = self.containerView
  //   }
  //   local blockAreaInnerNodes3 = {
  //     self:getBufferNodeByName("build_1051"),
  //     self:getBufferNodeByName("build_1056"),
  //     self:getBufferNodeByName("build_1057")
  //   }
  //   local boundingBoxInner3 = cc.rect(2406, 1488, 700, 500)
  //   self.checkVisibleNodes[cityBuildConstDef.blockArea.blockAreaInner3] = {
  //     visibleType = cityBuildConstDef.visibleType.block,
  //     nodes = blockAreaInnerNodes3,
  //     boundingBox = boundingBoxInner3,
  //     parent = self.containerView
  //   }
  //   local blockAreaInnerNodes4 = {
  //     self:getBufferNodeByName("build_1063"),
  //     self:getBufferNodeByName("build_1064"),
  //     self:getBufferNodeByName("build_1065")
  //   }
  //   local boundingBoxInner4 = cc.rect(2935, 1185, 820, 600)
  //   self.checkVisibleNodes[cityBuildConstDef.blockArea.blockAreaInner4] = {
  //     visibleType = cityBuildConstDef.visibleType.block,
  //     nodes = blockAreaInnerNodes4,
  //     boundingBox = boundingBoxInner4,
  //     parent = self.containerView
  //   }
  // end
}

void MainCityView::EnableShack(){
  // if SoraDConfigGet("Game:GameOptionsView:shake~bool") then
  //   print("\229\144\175\231\148\168\230\145\135\228\184\128\230\145\135")
  //   SoraDShackON(self, handler(self, self.onShackCallBack))
  // end
}


void MainCityView::DelBuildTile(Node *p_BuildingBtn){
  //TODO: uncomment this line when start production
  // if(!p_BuildingBtn)
  //   return;
  auto l_BuildingIndex = p_BuildingBtn->getTag();
  if(p_BuildingBtn){
    auto l_TileName = GString("res_tile") + std::to_string(l_BuildingIndex);
    auto l_Sprite = _BatchNodeOuterTiles->getChildByName(l_TileName.c_str());
    if(l_Sprite)
      l_Sprite->removeFromParent();
  }
}

Node *MainCityView::GetBufferNodeByName(const char *p_NodeName){
  if(!p_NodeName)
    return nullptr;
  if(p_NodeName == "")
    return nullptr;
  if(!n_BufferNodeArray.Contains(p_NodeName))
    return nullptr;
  return n_BufferNodeArray[GString(p_NodeName)];
};

Vec2 MainCityView::GetContainerOffsetWhenPosPoint(Vec2 p_Center, Vec2 p_WinPos, bool p_IgnoreCheck, bool p_Force){
  return GetContainerOffsetWhenPosPoint(p_Center, p_WinPos, p_IgnoreCheck, p_Force, GetZoomScale(p_Force));
}

Vec2 MainCityView::GetContainerOffsetWhenPosTarget(Node *p_Target, Vec2 p_WinPos, bool p_IgnoreCheck, bool p_Force){
  CCASSERT(p_Target, "Target Node Cannot be Null");
  auto l_TargetPos = p_Target->getPosition();
  auto l_ContentSize = p_Target->getContentSize();
  auto l_TargetAP = p_Target->getAnchorPoint();
  auto l_CenterX = l_TargetPos.x + (0.5 - l_TargetAP.x) * l_ContentSize.width;
  auto l_CenterY = l_TargetPos.y + (0.5 - l_TargetAP.y) * l_ContentSize.height;
  return GetContainerOffsetWhenPosPoint(Vec2(l_CenterX, l_CenterY), p_WinPos, p_IgnoreCheck, p_Force);
}

Vec2 MainCityView::GetContainerOffsetWhenPosPoint(Vec2 p_Center, Vec2 p_WinPos, bool p_IgnoreCheck, bool p_Force, float p_Zoom){
  p_WinPos.y = p_WinPos.y - _HUIBottom - GDisplay::Get()->iPhoneXBottom;
  p_Center *= p_Zoom;
  auto l_dOffestX = p_WinPos;
  auto l_OffsetX = - (p_Center.x - l_dOffestX.x);
  auto l_OffsetY = - (p_Center.y - l_dOffestX.y);
  auto l_MinOffset = _ViewScrollView->minContainerOffset();
  auto l_MaxOffset = _ViewScrollView->maxContainerOffset();
  if(!p_IgnoreCheck){
    l_OffsetX = std::max(l_MinOffset.x, std::min(l_MaxOffset.x, l_OffsetX));
    l_OffsetY = std::max(l_MinOffset.y, std::min(l_MaxOffset.y, l_OffsetY));
  }
  return Vec2(l_OffsetX, l_OffsetY);
}

float MainCityView::GetZoomScale(bool p_Force){
  if(p_Force)
    _ZoomScale = _ViewScrollView->getZoomScale();
  return _ZoomScale;
}

void MainCityView::SetZoomScale(float p_Zoom, bool p_Anim, float p_Duration, bool p_CustomAnim){
  _ZoomScale = p_Zoom;
  _ContainerView->stopAllActionsByTag(1002);
  if(p_CustomAnim){
    if(p_Duration == 0)
      _ContainerView->setScale(p_Zoom);
    else{
      auto l_ActScaleTo = ScaleTo::create(p_Duration, p_Zoom);
      l_ActScaleTo->setTag(1002);
      _ContainerView->runAction(l_ActScaleTo);
    }
  }
  if(p_Duration == 0)
    _ViewScrollView->setZoomScale(p_Zoom, p_Anim);
  else 
    _ViewScrollView->setZoomScaleInDuration(p_Zoom, p_Duration);
}

void MainCityView::RunContainerViewMove(Vec2 p_MoveToPos, float p_Duration){
  // self.containerView:stopAllActionsByTag(cityBuildConstDef.ActionTag.Tag_ContainerViewMove)
  _ContainerView->stopAllActionsByTag(1001);
  if(p_Duration == 0){
    _ContainerView->setPosition(p_MoveToPos);
  }else{
    auto l_MoveTo = MoveTo::create(p_Duration, p_MoveToPos);
    l_MoveTo->setTag(1001);
    _ContainerView->runAction(l_MoveTo);
  }
}

void MainCityView::DisableMoveForDuration(float p_Duration){
  if(!_ViewScrollView)
    return;
  SetMainCityEnabled(false);
  _ViewScrollView->stopAllActionsByTag(100);
  auto l_Delay = DelayTime::create(p_Duration);
  auto l_CallFunc = CallFunc::create([this](){
    SetMainCityEnabled(true);
    //     self.isVisibleAreaDirty = true
    GBase::DSendMessage("MESSAGE_MAINCITY_FINISH_UPDATEPOS");
  });
  auto l_Seq = Sequence::create(l_Delay, l_CallFunc, nullptr);
  l_Seq->setTag(100);
  _ViewScrollView->runAction(l_Seq);
}
