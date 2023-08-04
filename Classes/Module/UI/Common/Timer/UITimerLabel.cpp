#include "UITimerLabel.h"

UITimerLabel *UITimerLabel::DCreateTimerLabel(Node *p_lable){
  auto l_TimerLabel = UITimerLabel::Create();
  l_TimerLabel->InitPanel();
  l_TimerLabel->_Panel = p_lable;
  return l_TimerLabel;
}

void UITimerLabel::RemoveTime(){
}