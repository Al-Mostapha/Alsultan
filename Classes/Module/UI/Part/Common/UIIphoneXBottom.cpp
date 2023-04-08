#include "UIIphoneXBottom.h"


UIIphoneXBottom *UIIphoneXBottom::Create()
{
  auto l_Panel = create();
  RBasePenelData l_Data;
  l_Data.FutureName = "loginView";
  l_Panel->InitPanel("UiParts/Parts/Common/iphoneXBottom.csb", &l_Data);
  return l_Panel;
}

void UIIphoneXBottom::AddSubViews(){
  addChild(_Panel);
}

void UIIphoneXBottom::Ctor()
{
  UIBasePanel::Ctor();
  AddSubViews();

}
