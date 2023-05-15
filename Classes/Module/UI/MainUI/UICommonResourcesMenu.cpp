#include "UICommonResourcesMenu.h"

UICommonResourcesMenu *UICommonResourcesMenu::Create(){
  auto l_Panel = Create("UiParts/MainUi/commonResourcesMenu.csb");
  return l_Panel;
}

void UICommonResourcesMenu::Ctor(){
  CCLOG("Am Here in commonResourcesMenu ");
}

void UICommonResourcesMenu::RunAnimation(){

}

void UICommonResourcesMenu::HiddleMainUI(bool p_IsHiddle){

}