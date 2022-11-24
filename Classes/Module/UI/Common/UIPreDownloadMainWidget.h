#pragma once 
#include "Include/IncludeBase.h"

#include "Include/IncludeEngine.h"
#include "Module/UI/Panel/UIPanelBase.h"


class UIPreDownloadMainWidget : public UIPanelBase
{

private:
  CREATE_FUNC(UIPreDownloadMainWidget);
public:
  UIPreDownloadMainWidget(){};
  ~UIPreDownloadMainWidget(){};
  void InitPanel() override{};
  void Show() override {};
  void InitData(uint32 p_IdItem) {};
  static UIPreDownloadMainWidget *Create() {return create();};
};
