#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIWorldMapKingdomCityStateView : public UIBasePanel
{

  CREATE_FUNC(UIWorldMapKingdomCityStateView);
  CreateUIPanel(UIWorldMapKingdomCityStateView);
  CreateUICCSView(UIWorldMapKingdomCityStateView);

  
public: 
  static UIWorldMapKingdomCityStateView *Create();
  void Ctor() override;  
  void InitView(GTime pTime);
};