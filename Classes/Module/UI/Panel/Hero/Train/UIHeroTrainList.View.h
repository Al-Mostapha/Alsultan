#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Building/Building.Enum.h"

class IBuilding;
class UIHeroTrainListView : public UIBasePanel
{

  CREATE_FUNC(UIHeroTrainListView);
  CreateUIPanel(UIHeroTrainListView);
  CreateUICCSView(UIHeroTrainListView);

  
public: 
  static UIHeroTrainListView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};