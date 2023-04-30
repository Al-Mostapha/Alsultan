#include "UICollegeWaitSingle.h"

UICollegeWaitSingle *UICollegeWaitSingle::Create(){
  auto l_Panel = Create("UiParts/Panel/Building/View/College/collegeWaitSingle.csb");
  return l_Panel;
}

void UICollegeWaitSingle::Ctor(){
  UIBasePanel::Ctor();
}
