#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Building/Building.Enum.h"

class IBuilding;
class UISoldiersCampView : public UIBasePanel
{

  CREATE_FUNC(UISoldiersCampView);
  CreateUIPanel(UISoldiersCampView);
  CreateUICCSView(UISoldiersCampView);

  
public: 
  static UISoldiersCampView* Create();
  void Ctor() override;
  void InitData(EBuildingIndex p_Index, IBuilding *p_Building);
  void InitWidget();
};