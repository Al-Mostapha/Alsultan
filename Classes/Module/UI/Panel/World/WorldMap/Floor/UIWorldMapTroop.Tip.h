#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIWorldMapTroopTip : public UIBaseView
{

  CREATE_FUNC(UIWorldMapTroopTip);
  CreateUIPanel(UIWorldMapTroopTip);
  CreateUICCSView(UIWorldMapTroopTip);

  
public: 
  static UIWorldMapTroopTip* Create();
  void Ctor() override;
  int32 GetMoveLineID();
};