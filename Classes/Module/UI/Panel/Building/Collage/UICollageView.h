#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Building/Building.Enum.h"

class IBuilding;
class UICollageView : public UIBasePanel
{

  CREATE_FUNC(UICollageView);
  CreateUIPanel(UICollageView);
  CreateUICCSView(UICollageView);

  
public: 
  static UICollageView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};