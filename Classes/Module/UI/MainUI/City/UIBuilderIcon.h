#pragma once 
#include "Module/UI/UICCSView.h"
#include "Module/Task/Task.Enum.h"


class UIBuilderIcon : public UIBaseView
{

private:
  CREATE_FUNC(UIBuilderIcon);
  CreateUIPanel(UIBuilderIcon);
  CreateUICCSView(UIBuilderIcon);
public: 
  static UIBuilderIcon* Create();
  void InitData(ETask p_BuildingTypeQueue = ETask::None);
  void Show();
  void InitPanel();
  ETask GetBuilderType();
};
