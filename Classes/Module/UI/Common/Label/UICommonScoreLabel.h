#pragma once 
#include "Include/IncludeBase.h"
#include "Include/IncludeEngine.h"
#include "Module/UI/Panel/UIPanelBase.h"


class UICommonScoreLabel : public UIPanelBase
{
bool m_IsThousandFormat = false;
private:
  CREATE_FUNC(UICommonScoreLabel);
public:
  UICommonScoreLabel(){};
  ~UICommonScoreLabel(){};
  void InitPanel() override{};
  void Show() override {};
  void InitData(uint32 p_IdItem) {};
  static UICommonScoreLabel *Create() {return create();};
  //newBMFontLabel
  static UICommonScoreLabel *DCreateScoreLabel(Node *p_lable, bool p_IsThousandFormat = false);
  void SetIsFormatThousands(bool p_IsThousandFormat);
};
