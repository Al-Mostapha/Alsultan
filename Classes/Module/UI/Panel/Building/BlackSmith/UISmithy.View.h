#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class IBuilding;
class UISmithyView : public UIBasePanel
{

  CREATE_FUNC(UISmithyView);
  CreateUIPanel(UISmithyView);
  CreateUICCSView(UISmithyView);

  
public: 
  static UISmithyView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};