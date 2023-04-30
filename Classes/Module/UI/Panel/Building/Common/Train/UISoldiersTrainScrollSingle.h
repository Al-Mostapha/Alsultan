#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Army/Army.Type.h"


class UISoldiersTrainScrollSingle : public UIBasePanel
{

  CREATE_FUNC(UISoldiersTrainScrollSingle);
  CreateUIPanel(UISoldiersTrainScrollSingle);
  CreateUICCSView(UISoldiersTrainScrollSingle);

  
public: 
  static UISoldiersTrainScrollSingle* Create();
  void InitData(RCanTrainArmy, ETrainType){}
  void Ctor() override;
};