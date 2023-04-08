#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIPetMapView : public UIBasePanel
{

  CREATE_FUNC(UIPetMapView);
  CreateUIPanel(UIPetMapView);
  CreateUICCSView(UIPetMapView);
  
public: 
  static UIPetMapView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};