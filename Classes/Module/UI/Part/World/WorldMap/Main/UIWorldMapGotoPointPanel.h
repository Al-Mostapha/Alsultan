#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"



class UIWorldMapGotoPointPanel : public UIBasePanel
{
  CREATE_FUNC(UIWorldMapGotoPointPanel);
  CreateUIPanel(UIWorldMapGotoPointPanel);
  CreateUICCSView(UIWorldMapGotoPointPanel);
public: 
  bool _HideKingIDTextField;
  static UIWorldMapGotoPointPanel* Create(bool pHideKingIDTextField = false);
  void Ctor() override;
  void UpdateData(int32 pKingdomID, Vec2 pPoint);
};