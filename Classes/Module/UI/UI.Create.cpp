#include "UI.Create.h"
#include "Module/UI/Part/UIWheelScrollView.h"


UICreate *UICreate::Get()
{
  static UICreate *s_UICreate = nullptr;
  if (s_UICreate == nullptr)
  {
    s_UICreate = new UICreate();
  }
  return s_UICreate;
}

UIWheelScrollView *UICreate::DCreateWheelScrollView(
      GVector<Node *>p_ItemArray,  Size p_ViewSize, float p_CellHeight, 
    float p_CircleRadius, float p_PosX, bool p_IsSound, bool p_IsIgnoreOpacity
)
{
  auto l_Wheel = UIWheelScrollView::Create(p_ViewSize);
  p_CircleRadius = p_CircleRadius == 0 ? p_ViewSize.width : p_CircleRadius;
  l_Wheel->initData(p_ItemArray, p_PosX, p_CellHeight, p_CircleRadius, p_IsSound, p_IsIgnoreOpacity);
  return l_Wheel;
}