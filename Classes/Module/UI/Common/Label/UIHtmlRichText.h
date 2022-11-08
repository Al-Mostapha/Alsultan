#pragma once 
#include "Include/IncludeBase.h"
#include "Include/IncludeEngine.h"
#include "Module/UI/Panel/UIPanelBase.h"


class UIHtmlRichText : public UIPanelBase
{
  bool m_IsHtml = false;
private:
  CREATE_FUNC(UIHtmlRichText);
public:
  UIHtmlRichText(){};
  ~UIHtmlRichText(){};
  void InitPanel() override{};
  void Show() override {};
  void InitData(uint32 p_IdItem) {};
  static UIHtmlRichText *Create() {return create();};
  void SetIsHtml(bool p_IsHtml);
  static UIHtmlRichText *DChangeTextToHtml(Node *p_lable);
};
