#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Building/Building.Enum.h"

class IBuilding;
class UIStorageBoxView : public UIBasePanel
{

  CREATE_FUNC(UIStorageBoxView);
  CreateUIPanel(UIStorageBoxView);
  CreateUICCSView(UIStorageBoxView);

  
public: 
  static UIStorageBoxView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};