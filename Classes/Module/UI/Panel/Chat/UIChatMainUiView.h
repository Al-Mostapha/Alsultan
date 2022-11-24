#pragma once 
#include "Include/IncludeBase.h"

#include "Include/IncludeEngine.h"
#include "Module/UI/Panel/UIPanelBase.h"


class UIChatMainUiView : public UIPanelBase
{

private:
  CREATE_FUNC(UIChatMainUiView);
public:
  UIChatMainUiView(){};
  ~UIChatMainUiView(){};
  void InitPanel() override{};
  void Show() override {};
  void InitWithData(){};
  static UIChatMainUiView *Create() {return create();};
};
