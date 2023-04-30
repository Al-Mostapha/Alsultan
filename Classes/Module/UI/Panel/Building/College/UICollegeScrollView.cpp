#include "UICollegeScrollView.h"

UICollegeScrollView *UICollegeScrollView::Create(const char *p_FileName){
  auto l_Panel = Create(StringUtils::format("UiParts/Panel/Building/View/College/Views/%s.csb", p_FileName));
  return l_Panel;
}

void UICollegeScrollView::Ctor(){
  UIBasePanel::Ctor();
}
