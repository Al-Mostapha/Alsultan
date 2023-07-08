#include "WorldMap.Com.3D.h"
#include "Base/Common/Common.Teml.h"
#include "Module/World/WorldMap/WorldMap.Event.h"
#include "Module/World/WorldMap/View/WorldMap.View.h"

void WorldMapCom3D::Ctor(){}

void WorldMapCom3D::Init(){
  IWorldMapComponent::Init();
  _TopFog = GBase::DGetChildByName<ui::ImageView *>(_Target, "Top_Image_fog");
  _TopFog->setPositionY(GDisplay::Get()->height + GDisplay::Get()->iPhoneXBottom);
  _BottomFog = GBase::DGetChildByName<ui::ImageView *>(_Target, "Bottom_Image_fog");
  _BottomFog->setPositionY(0);
}

void WorldMapCom3D::OnMessageListener(){
  GBase::DAddMessage(_Target, "MESSAGE_WORLD_MAP_TOGGLE_3D", CC_CALLBACK_1(WorldMapCom3D::Toggle3D, this));
  // SoraDAddMessage(self, "MESSAGE_WORLD_MAP_TOGGLE_DEBUG", handler(self, self.toggleDebugLayer))
  Toggle3D(nullptr);
}

void WorldMapCom3D::Toggle3D(EventCustom *p_Event){
  if(!GGlobal::Get()->gEnableWorldMap3D){
    GGlobal::Get()->gEnableWorldMap3D = GBase::DConfigGet<bool>("Game:GameOptionsView:show3d~bool", true);
  }

  auto l_Director = Director::getInstance();
  if(GGlobal::Get()->gEnableWorldMap3D){
    l_Director->setProjection(Director::Projection::_3D);
    _TopFog->setVisible(true);
    _BottomFog->setVisible(true);
  }else{
    l_Director->setProjection(Director::Projection::_2D);
    _TopFog->setVisible(false);
    _BottomFog->setVisible(false);
  }
  _Target->getEventDispatcher()->dispatchCustomEvent(WorldMapEvent::Get()->EVENT_TOOGLE_3D, nullptr);
}