#include "UIIphoneXTop.h"


UIIphoneXTop *UIIphoneXTop::Create()
{
  auto l_Panel = create();
  RBasePenelData l_Data;
  l_Data.FutureName = "loginView";
  l_Panel->InitPanel("UiParts/Parts/Common/iphoneXTop.csb", &l_Data);
  return l_Panel;
}

void UIIphoneXTop::AddSubViews(){
  addChild(m_Panel);
}

void UIIphoneXTop::Ctor()
{
  UIBasePanel::Ctor();
  AddSubViews();

}
