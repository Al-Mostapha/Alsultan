#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIQuestView : public UIBasePanel
{

  CREATE_FUNC(UIQuestView);
  CreateUIPanel(UIQuestView);
  CreateUICCSView(UIQuestView);

  
public: 
  static UIQuestView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};