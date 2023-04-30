#include "UICollegeScrollSingle.h"

UICollegeScrollSingle *UICollegeScrollSingle::Create(){
  auto l_Panel = Create("UiParts/Panel/Building/View/College/collegeScrollSingle.csb");
  return l_Panel;
}

void UICollegeScrollSingle::Ctor(){
  UIBasePanel::Ctor();


}
