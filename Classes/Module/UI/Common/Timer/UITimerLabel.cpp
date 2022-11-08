#include "UITimerLabel.h"

UITimerLabel *UITimerLabel::DCreateTimerLabel(Node *p_lable){
  auto l_TimerLabel = UITimerLabel::Create();
  l_TimerLabel->InitPanel();
  l_TimerLabel->m_Panel = p_lable;
  return l_TimerLabel;
}