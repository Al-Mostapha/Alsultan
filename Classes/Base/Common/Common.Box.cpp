#include "Common.Box.h"
#include "Module/UI/Part/Common/Box/UICommonBuyBox.h"
void GBase::DShowBuyBox(
  const RShowBuyBoxParam &p_Param, 
  const std::function<void(EMsgBoxCallBack)> &p_Handle,
  bool *p_CanBuy,
  const std::function<void(EMsgBoxCallBack)> &p_HandleTool,
  const GString &p_Tool 
  ){

  auto l_Panel = UICommonBuyBox::Create();
  l_Panel->SetHandle(p_Handle);
  l_Panel->InitData(p_Param);
  if(p_CanBuy)
    l_Panel->SetBtnBuy(*p_CanBuy);
  if(p_HandleTool)
    l_Panel->SetUseToolStyle(p_HandleTool, p_Tool);
  l_Panel->Show();

}


Node *GBase::DShowLoading(Node *p_Parent, const Size &p_Size, 
  int32 p_Mark, bool p_Transparent, GTime p_TimeOut, bool p_IsShadow){
  // if not parent or tolua.isnull(parent) then
  //   parent = display.getRunningScene()
  // end
  // if parent.getPivot then
  //   parent = parent:displayObject()
  // end
  // local preLoading = parent:getChildByName("commonLoading")
  // if preLoading then
  //   preLoading:closeLoading(parent, mark)
  // end
  // local newLoading = include("commonLoading").new(size)
  // newLoading:showLoading(parent, mark, isTransparent, timeOut, isShadow)
  // return newLoading
  return Node::create();
}

