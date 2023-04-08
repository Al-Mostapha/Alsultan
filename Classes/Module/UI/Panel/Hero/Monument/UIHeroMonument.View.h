#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Building/Building.Enum.h"

class IBuilding;
class UIHeroMonumentView : public UIBasePanel
{

  CREATE_FUNC(UIHeroMonumentView);
  CreateUIPanel(UIHeroMonumentView);
  CreateUICCSView(UIHeroMonumentView);

  
public: 
  static UIHeroMonumentView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};