#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIAllianceMemberList : public UIBasePanel
{

  CREATE_FUNC(UIAllianceMemberList);
  CreateUIPanel(UIAllianceMemberList);
  CreateUICCSView(UIAllianceMemberList);

  
public: 
  static UIAllianceMemberList* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};