#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIWarframeStoreroom : public UIBasePanel
{

  CREATE_FUNC(UIWarframeStoreroom);
  CreateUIPanel(UIWarframeStoreroom);
  CreateUICCSView(UIWarframeStoreroom);
  
public: 
  static UIWarframeStoreroom* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};