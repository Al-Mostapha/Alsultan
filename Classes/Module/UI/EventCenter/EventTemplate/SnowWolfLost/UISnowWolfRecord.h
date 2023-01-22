#pragma once
#include "Module/UI/UICCSView.h"

class UISnowWolfRecord : UIBaseView{
  CREATE_FUNC(UISnowWolfRecord);
  CreateUIPanel(UISnowWolfRecord);
  CreateUICCSView(UISnowWolfRecord);
public: 
  static UISnowWolfRecord* Create();
  void Show();
};