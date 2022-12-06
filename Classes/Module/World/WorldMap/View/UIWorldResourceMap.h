#pragma once
#include "Module/UI/UICCSView.h"

class UIWorldResourceMap : public UIBaseView{
  CREATE_FUNC(UIWorldResourceMap);
  CreateUIPanel(UIWorldResourceMap);
  CreateUICCSView(UIWorldResourceMap);
public: 
  static UIWorldResourceMap *Create(){
    return Create("UiParts/Panel/World/WorldMap/worldResourceMap.csb");
  }
};