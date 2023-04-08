#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIAllianceStoreHouseView : public UIBasePanel
{

  CREATE_FUNC(UIAllianceStoreHouseView);
  CreateUIPanel(UIAllianceStoreHouseView);
  CreateUICCSView(UIAllianceStoreHouseView);

  
public: 
  static UIAllianceStoreHouseView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};