#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIRechargeStarCastleGiftView : public UIBasePanel
{

  CREATE_FUNC(UIRechargeStarCastleGiftView);
  CreateUIPanel(UIRechargeStarCastleGiftView);
  CreateUICCSView(UIRechargeStarCastleGiftView);

  
public: 
  static UIRechargeStarCastleGiftView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};