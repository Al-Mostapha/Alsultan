#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Building/Building.Enum.h"

class IBuilding;
class UIEmbassyView : public UIBasePanel
{

  CREATE_FUNC(UIEmbassyView);
  CreateUIPanel(UIEmbassyView);
  CreateUICCSView(UIEmbassyView);

  
public: 
  static UIEmbassyView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};