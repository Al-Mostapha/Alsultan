#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UITouchBaseView.h"
#include "Module/CityResource/Resource.Enum.h"
#include "Module/World/WorldMap/WorldMap.Type.h"

struct RResourceOccupyInit{
  int32 _InstID;
  EResource _ClassID;
  Vec2 _ResPos;
};

struct RResourceOccupyInitFromWar{
  uint32 _InstID;
  EResource _ClassID;
  Vec2 _ResPos;
  RTipButtonTouchCallEvAr::RTipButtonData _Data;
  GString _PlayerName; 
  GString _LeagueName;
};


class UIWorldMapResOccupyView : public UITouchBaseView{
  CREATE_FUNC(UIWorldMapResOccupyView);
  CreateUIPanel(UIWorldMapResOccupyView);
  CreateUICCSView(UIWorldMapResOccupyView);
public: 
  static UIWorldMapResOccupyView* Create();
  void InitData(const RResourceOccupyInit &pData);
  void InitDataFromWar(const RResourceOccupyInitFromWar &pData);
};