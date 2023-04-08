#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIRechargeCastleGiftView : public UIBasePanel
{

  CREATE_FUNC(UIRechargeCastleGiftView);
  CreateUIPanel(UIRechargeCastleGiftView);
  CreateUICCSView(UIRechargeCastleGiftView);

  
public: 
  static UIRechargeCastleGiftView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};