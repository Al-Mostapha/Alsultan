#include "UICCSView.h"

UIBaseView *UICCSView::Create(GString p_CCSFile, Size p_ViewSize)
{

  if(p_CCSFile.empty())
    return nullptr;

  // local typeView = type(ccsFile)
  // local view
  // if "string" == typeView then
  //   view = cc.uiloader:load(ccsFile)
  auto l_View = CSLoader::createNode(p_CCSFile);
  // elseif "userdata" == typeView then
  //   ccsFile:setPosition(cc.p(0, 0))
  //   ccsFile:setAnchorPoint(cc.p(0, 0))
  //   view = ccsFile
  // end
  // viewSize = viewSize or view:getContentSize()
  if(p_ViewSize.height  <=  0 || p_ViewSize.width <= 0)
    p_ViewSize = l_View->getContentSize();
  // local baseView = include("baseView")
  auto l_BaseView = UIBaseView::Create(p_ViewSize, false);
  // local bgView = baseView.new(viewSize, false)
  l_View->setName("ccsView");
  // view:setName("ccsView")
  // bgView:addChild(view, 1)
  l_BaseView->addChild(l_View, 1);
  // bgView._ccsView = view
  // return bgView
  return l_BaseView;
}

UIBaseView *UICCSView::Create(Node *p_CCSFile, Size p_ViewSize)
{

  if(!p_CCSFile)
    return nullptr;
  auto l_View = p_CCSFile;
  l_View->setPosition(Vec2(0, 0));
  l_View->setAnchorPoint(Vec2(0, 0));
  if(p_ViewSize.height  <=  0 || p_ViewSize.width <= 0)
    p_ViewSize = l_View->getContentSize();
  auto l_BaseView = UIBaseView::Create(p_ViewSize, false);
  l_View->setName("ccsView");
  l_BaseView->addChild(l_View, 1);
  // bgView._ccsView = view
  return l_BaseView;
}