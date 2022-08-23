#include "Include/IncludeBase.h"
#include "Include/IncludeUiBase.h"
#include "Module/UI/Types/UIWheelScrollViewArgs.h"

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
  UIWheelScrollView();
  ~UIWheelScrollView();
  void removeChildren();
  void setInertiaValue(bool p_Inertia);
  void initData(const UIWheelScrollViewArgs& p_WheelScrollViewArgs);
  void scrollEventCallBack(Ref* p_Ref, ui::ScrollView::EventType p_EventType);
  void scrollTouchEventCallBack(Ref* p_Ref, ui::Widget::TouchEventType p_EventType);
  void updateItems();
  void selectedCellIndex(int p_CellIndex, float p_TimeInSec = 0, bool p_Attenuated = false, float p_AttenuatedY = 0);

  int pointCurSelectSingle(bool p_IsUpdateCurI);

  void setTouchDetection(float delay);
  void bounceSingle();
  bool init();
  void unfoldAction(float p_delay);
  void setSelectedItemListener(const selectedItemListener& p_CallBack){
    m_SelectedItemListener = p_CallBack;
  };

  CREATE_FUNC(UIWheelScrollView);
};

