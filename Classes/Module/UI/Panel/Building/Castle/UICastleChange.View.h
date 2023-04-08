#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class IBuilding;
class UICastleChangeView : public UIBasePanel
{

  CREATE_FUNC(UICastleChangeView);
  CreateUIPanel(UICastleChangeView);
  CreateUICCSView(UICastleChangeView);

  
public: 
  static UICastleChangeView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};