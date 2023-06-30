#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIWorldMapTip : public UIBaseView
{

  CREATE_FUNC(UIWorldMapTip);
  CreateUIPanel(UIWorldMapTip);
  CreateUICCSView(UIWorldMapTip);

  
public: 
  static UIWorldMapTip* Create();
  void Ctor() override;
  // local selectShowPanel = include("worldMapTip").new(self.kingdomID)
  // selectShowPanel:setTilePoint(tilePos)
  // selectShowPanel:setWorldMapCell(self)
  // selectShowPanel:setFavoriteName(favoriteName)
};