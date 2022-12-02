#pragma once
#include "Include/IncludeBase.h"
#include "CityScene.View.h"

MainCityView *MainCityView::Create(RViewOtherData p_Data){
  auto l_Panel =  Create("UiParts/Panel/MainCity/mainCityView.csb");
  l_Panel->m_Param = p_Data;
  return l_Panel;
}

void MainCityView::Ctor(){
  //userSDKManager.timeInfo.t_maincity.tbegin = SoraDGetSocketTime()
  //print("\229\188\128\229\167\139\229\136\155\229\187\186\229\134\133\229\159\142------")
  //self.param = param
  PreLoadImages();
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
  // print("\229\134\133\229\159\142 \233\162\132\229\138\160\232\189\189\229\155\190\231\137\135\229\174\140\230\136\144---------------------")
  // self.isFinishInit = true
  m_IsFinishInit = true;
  Ctor();
  OnMessageListener_FinishLoadImage();
  InitAfterCreate();
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
  if(n_ViewScrollView){
    n_ViewScrollView->setTouchEnabled(p_Enabled);
    m_IsBuildBtnEnable = p_Enabled;
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

void MainCityView::SetZoomScale(
  float p_ZoomScale, bool p_Animated,
  float p_duration, bool p_CustomAnim
  ){
  // self.zoomScale = zoomScale
  // self.containerView:stopAllActionsByTag(cityBuildConstDef.ActionTag.Tag_ContainerViewScale)
  // if customAnim ~= nil then
  //   if duration == nil or duration == 0 then
  //     self.containerView:setScale(zoomScale)
  //   else
  //     local actScaleTo = cca.scaleTo(duration, zoomScale)
  //     local callFunc = cca.callFunc(handler(self, self.afterCustomAnim))
  //     local seq = cca.seq({actScaleTo, callFunc})
  //     seq:setTag(cityBuildConstDef.ActionTag.Tag_ContainerViewScale)
  //     self.containerView:runAction(seq)
  //   end
  //   return
  // end
  // if duration == nil then
  //   self.viewScrollView:setZoomScale(zoomScale, animated)
  // elseif duration ~= nil then
  //   self.viewScrollView:setZoomScaleInDuration(zoomScale, duration)
  // end
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