#include "UICollegeDetailsSingle.h"

UICollegeDetailsSingle *UICollegeDetailsSingle::Create(){
  auto l_Panel = Create("UiParts/Panel/Building/View/College/collegeDetailsView.csb");
  return l_Panel;
}

void UICollegeDetailsSingle::Ctor(){
  UIBasePanel::Ctor();
}
