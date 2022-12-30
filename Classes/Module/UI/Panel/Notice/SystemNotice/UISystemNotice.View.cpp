#include "UISystemNotice.View.h"


UISystemNoticeView *UISystemNoticeView::Create()
{

  auto l_Panel = Create("UiParts/Panel/Common/Notice/System/systemNoticeView.csb");
  l_Panel->setName("systemNoticeView");
  return l_Panel;
}

void UISystemNoticeView::AddSubViews(){
  
}

void UISystemNoticeView::Ctor()
{
  UIBaseView::Ctor();
  AddSubViews();

}
