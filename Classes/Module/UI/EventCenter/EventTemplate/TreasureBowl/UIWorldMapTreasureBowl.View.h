#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UITouchBaseView.h"
#include "Module/World/WorldMap/Instance/Unit/WorldMapTreasureBowl.h"

class UIWorldMapTreasureBowlView : public UITouchBaseView{
  CREATE_FUNC(UIWorldMapTreasureBowlView);
  CreateUIPanel(UIWorldMapTreasureBowlView);
  CreateUICCSView(UIWorldMapTreasureBowlView);
public: 
  static UIWorldMapTreasureBowlView* Create();
  void InitData( WorldMapTreasureBowl *pMapInstance, 
    GOpt<RUnitTreasureBowlInit> pTreeData, Vec2 pTilePoint, int32 pInstanceID);
  void SetTilePoint(Vec2 pTilePoint);
};