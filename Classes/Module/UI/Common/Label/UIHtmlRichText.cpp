#include "UIHtmlRichText.h"


void UIHtmlRichText::SetIsHtml(bool p_IsHtml)
{
  m_IsHtml = p_IsHtml;
}

UIHtmlRichText *UIHtmlRichText::DChangeTextToHtml(Node *p_lable){
  auto l_Inst = UIHtmlRichText::Create();
  l_Inst->SetIsHtml(true);
  return l_Inst;
}