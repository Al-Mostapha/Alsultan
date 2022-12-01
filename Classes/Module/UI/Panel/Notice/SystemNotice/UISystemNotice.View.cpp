#include "UISystemNotice.View.h"


UISystemNoticeView *UISystemNoticeView::Create()
{
  auto l_Panel = create();
  RBasePenelData l_Data;
  l_Data.FutureName = "systemNoticeView";
  l_Panel->InitPanel("UiParts/Panel/Common/Notice/System/systemNoticeView.csb", &l_Data);
  return l_Panel;
}

void UISystemNoticeView::AddSubViews(){
  addChild(m_Panel);
}

void UISystemNoticeView::Ctor()
{
  UIBasePanel::Ctor();
  AddSubViews();

}
