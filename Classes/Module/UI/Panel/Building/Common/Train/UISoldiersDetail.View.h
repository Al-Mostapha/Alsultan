#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "UISoldiersCampView.h"

class UISoldiersDetailView : public UIBasePanel
{

  CREATE_FUNC(UISoldiersDetailView);
  CreateUIPanel(UISoldiersDetailView);
  CreateUICCSView(UISoldiersDetailView);

  
public: 
  static UISoldiersDetailView* Create();
  void InitData(UISoldiersCampView::RCurrentSoldierData){}
  void Ctor() override;
};