#include "UICommonScoreLabel.h"


void UICommonScoreLabel::SetIsFormatThousands(bool p_IsThousandFormat){
  m_IsThousandFormat = p_IsThousandFormat;
}

UICommonScoreLabel *UICommonScoreLabel::DCreateScoreLabel(Node *p_lable, bool p_IsThousandFormat){
  if(p_lable == nullptr)
    p_lable = Label::createWithBMFont("res/Default/defaultBMFont.fnt", "", TextHAlignment::CENTER);
  auto l_ScoreLabel = UICommonScoreLabel::Create();
  l_ScoreLabel->InitPanel();
  l_ScoreLabel->_Panel = p_lable;
  l_ScoreLabel->SetIsFormatThousands(p_IsThousandFormat);
  return l_ScoreLabel;
}