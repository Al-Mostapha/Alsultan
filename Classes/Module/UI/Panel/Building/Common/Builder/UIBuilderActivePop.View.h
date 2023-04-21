#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIBuilderActivePopView : public UIBasePanel
{

  CREATE_FUNC(UIBuilderActivePopView);
  CreateUIPanel(UIBuilderActivePopView);
  CreateUICCSView(UIBuilderActivePopView);

  
public: 
  static UIBuilderActivePopView* Create();
  void Ctor() override;
  void InitData(int32 p_Style, GString p_Msg, GTime p_Time = 0){}
};