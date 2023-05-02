#include "UICommonFramTitle.h"

UICommonFramTitle *UICommonFramTitle::Create(){
  auto l_Panel = Create("UiParts/Parts/Common/Frame/commonFramTitle.csb");
  return l_Panel;
}

void UICommonFramTitle::Ctor(){
  UIBasePanel::Ctor();
}
