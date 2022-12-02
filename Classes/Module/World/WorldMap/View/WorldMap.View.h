#pragma once
#include "Module/UI/UICCSView.h"

class WorldMapView : public UIBaseView{
  CREATE_FUNC(WorldMapView);
  CreateUIPanel(WorldMapView);
  CreateUICCSView(WorldMapView);
public: 
  static WorldMapView *Create(){
    return Create("UiParts/Panel/World/WorldMap/worldMapView.csb");
  }
};