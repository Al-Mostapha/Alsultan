#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class IBuilding;
class UIEndlessTreasureView : public UIBasePanel
{

  CREATE_FUNC(UIEndlessTreasureView);
  CreateUIPanel(UIEndlessTreasureView);
  CreateUICCSView(UIEndlessTreasureView);

  
public: 
  static UIEndlessTreasureView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};