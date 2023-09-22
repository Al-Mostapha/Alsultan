#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class IBuilding;

struct RCastleChangeViewInit{
  bool _IsFromWorld;
  bool _ToShop;
  bool _ToWorld;
  int32 _DressID;
};

class UICastleChangeView : public UIBasePanel
{

  CREATE_FUNC(UICastleChangeView);
  CreateUIPanel(UICastleChangeView);
  CreateUICCSView(UICastleChangeView);

  
public: 
  static UICastleChangeView* Create();
  void Ctor() override;
  void InitData(const RCastleChangeViewInit &pData);
  void InitWidget();
};