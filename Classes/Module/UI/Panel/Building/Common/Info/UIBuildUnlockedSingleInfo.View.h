#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Building/Building.Enum.h"

class IBuilding;
class UIBuildUnlockedSingleInfoView : public UIBasePanel
{

  CREATE_FUNC(UIBuildUnlockedSingleInfoView);
  CreateUIPanel(UIBuildUnlockedSingleInfoView);
  CreateUICCSView(UIBuildUnlockedSingleInfoView);

  
public: 
  static UIBuildUnlockedSingleInfoView* Create();
  void Ctor() override;
  void InitData(EBuilding p_BuildingId, int32 p_UnlockId){}
};