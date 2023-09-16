#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIAlliancePBLHonorView : public UIBasePanel
{

  CREATE_FUNC(UIAlliancePBLHonorView);
  CreateUIPanel(UIAlliancePBLHonorView);
  CreateUICCSView(UIAlliancePBLHonorView);

  
public: 
  static UIAlliancePBLHonorView* Create();
  void Ctor() override;
};