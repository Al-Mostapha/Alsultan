#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UITouchBaseView.h"
#include "Module/CityResource/Resource.Enum.h"

USING_NS_CC;

class IWorldMapInstance;

struct RadianceWarResOccupyInit{
  int32 _ClassID;
  Vec2 _ResPos;
  int32 _InsID;
  EResource _ResourceType;
  IWorldMapInstance *_MapInstance;
};

class UIRadianceWarResOccupyView : public UITouchBaseView{
  CREATE_FUNC(UIRadianceWarResOccupyView);
  CreateUIPanel(UIRadianceWarResOccupyView);
  CreateUICCSView(UIRadianceWarResOccupyView);
public: 
  static UIRadianceWarResOccupyView* Create();
  void InitData(const RadianceWarResOccupyInit &pData);
};