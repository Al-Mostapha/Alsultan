#include "UICollegeDetailsView.h"

UICollegeDetailsView *UICollegeDetailsView::Create(){
  auto l_Panel = Create("UiParts/Panel/Building/View/College/collegeDetailsView.csb");
  return l_Panel;
}

void UICollegeDetailsView::Ctor(){
  UIBasePanel::Ctor();
}
