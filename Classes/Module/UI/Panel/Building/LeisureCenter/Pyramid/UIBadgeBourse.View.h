#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIBadgeBourseView : public UIBasePanel
{

  CREATE_FUNC(UIBadgeBourseView);
  CreateUIPanel(UIBadgeBourseView);
  CreateUICCSView(UIBadgeBourseView);

  
public: 
  static UIBadgeBourseView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};