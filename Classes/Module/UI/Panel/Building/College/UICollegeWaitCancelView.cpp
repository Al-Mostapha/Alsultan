#include "UICollegeWaitCancelView.h"

UICollegeWaitCancelView *UICollegeWaitCancelView::Create(){
  auto l_Panel = Create("UiParts/Panel/Building/View/College/collegeWaitCancelView.csb");
  return l_Panel;
}

void UICollegeWaitCancelView::Ctor(){
  UIBasePanel::Ctor();
}
