#pragma once
#include "Include/IncludeBase.h"
#include "CityScene.View.h"

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