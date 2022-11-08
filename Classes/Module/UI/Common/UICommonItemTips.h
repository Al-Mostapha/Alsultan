#pragma once 
#include "Include/IncludeBase.h"

#include "Include/IncludeEngine.h"
#include "Module/UI/Panel/UIPanelBase.h"


class UICommonItemTips : public UIPanelBase
{

private:
  CREATE_FUNC(UICommonItemTips);
public:
  UICommonItemTips(){};
  ~UICommonItemTips(){};
  void InitPanel() override{};
  void Show() override {};
  void InitData(int32 p_BuffId, int32 p_Num){};
  void CustomData(const char *p_CutomName) {};
  void SetBuffInfo(int32 p_BuffId, int32 p_Num){}
  Size GetBgSize() { return Size::ZERO; };
  static UICommonItemTips *Create() {return create();};
};


struct RCommonIconData{
  int32 id;
  int32 num;
  Vec2 Pos;
  GString CustomName;
  UICommonItemTips *CustomTip;
};

