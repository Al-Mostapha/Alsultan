#include "Include/IncludeBase.h"
#include "Include/IncludeUiBase.h"

class UIWheelScrollView : public UIElment
{
private:
  using selectedItemListener = std::function<void(size_t index)>;
  ui::ScrollView* m_ScrollView;
  GVector<ui::Widget*> m_WidgetArray;
  float m_CellHeight;
  float m_CircleRadius;
  float m_OffsetPosX;
  float m_TransparentOffset = 0;
  bool m_SingleIsMoved = false;
  bool m_IgnoreOpacity = false;
  int m_IsScrollToIndex = 0;
  bool m_IsScrollEnd = false;
  bool m_IsBounceEnd = false;
  bool m_IsSound = true;
  int m_CurrentIndex  = -123456789;
  selectedItemListener m_SelectedItemListener;
   
public:
  UIWheelScrollView(Size p_Size);
  ~UIWheelScrollView();
  void removeChildren();
  void setInertiaValue(bool p_Inertia);
  void initData(
    const GVector<ui::Widget*>& p_vecWidget, const float p_OffsetPosX,
    const float p_CellHeight, const float p_CircleRadius, bool p_IsSound, bool p_IgnoreOpacity
    );
  void scrollEventCallBack(Ref* p_Ref, ui::ScrollView::EventType p_EventType);
  void scrollTouchEventCallBack(Ref* p_Ref, ui::Widget::TouchEventType p_EventType);
  void updateItems();
  void selectedCellIndex(int p_CellIndex, float p_TimeInSec, bool p_Attenuated = false, float p_AttenuatedY = 0);

  int pointCurSelectSingle(bool p_IsUpdateCurI);

  void setTouchDetection(float delay);
  void bounceSingle();
  void unfoldAction(float p_delay);
};

