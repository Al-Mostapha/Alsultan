#pragma once 
#include "Include/IncludeBase.h"

#include "Include/IncludeEngine.h"
#include "Module/UI/Panel/UIPanelBase.h"


class UITimerLabel : public UIPanelBase
{

private:
  CREATE_FUNC(UITimerLabel);
public:
  UITimerLabel(){};
  ~UITimerLabel(){};
  void InitPanel() override{};
  void Show() override {};
  static UITimerLabel *Create() {return create();};
  static UITimerLabel *DCreateTimerLabel(Node *p_lable);
  void BeginTime(GTime){}
  void RemoveTime();
};
