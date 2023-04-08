#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIFriendView : public UIBasePanel
{

  CREATE_FUNC(UIFriendView);
  CreateUIPanel(UIFriendView);
  CreateUICCSView(UIFriendView);

  
public: 
  static UIFriendView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};