#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UITouchBaseView.h"
#include "Module/World/WorldMap/WorldMap.Enum.h"
#include "Module/CityResource/Resource.Enum.h"


class UIWorldMapExplainView : public UITouchBaseView{
  CREATE_FUNC(UIWorldMapExplainView);
  CreateUIPanel(UIWorldMapExplainView);
  CreateUICCSView(UIWorldMapExplainView);
public: 
  static UIWorldMapExplainView* Create();
  void InitData(EMapObjTypeDef pInstanceType, EResource pClassID, GString pTitle = "");
};