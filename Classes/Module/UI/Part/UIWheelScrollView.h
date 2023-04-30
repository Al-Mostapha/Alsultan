#include "Include/IncludeBase.h"
#include "Module/UI/UIBaseView.h"
#include "Module/UI/Types/UIWheelScrollViewArgs.h"

class UIWheelScrollView : public UIBaseView
{
  CREATE_FUNC(UIWheelScrollView);
  CreateUIPanel(UIWheelScrollView);

  
private:
  using selectedItemListener = std::function<void(size_t index, Node *)>;
  ui::ScrollView* _ScrollView;
  GVector<ui::Widget*> m_WidgetArray;
  float _CellHeight = 0;
  float _CircleRadius = 0;
  float _OffsetPosX = 0;
  GVector<Node *> _ItemArray;
  selectedItemListener _ItemSelectedListener;
  float _TransparentOffset = 0;
    // self.curI = nil
  bool _SingleIsMoved = false;
  bool _IgnoreOpacity = false;
  int _IsScrollToIndex = false;
  bool _IsScrollEnd = false;
  bool _IsBounceEnd = false;
  bool _IsSound = true;
  int _CurrentIndex  = -1;


public:
  static UIWheelScrollView *Create(Size p_Size);
  void Ctor();

  void removeChildren();
  void setInertiaValue(bool p_Inertia);
  void initData(GVector<Node *> p_Array, float p_PosX, float p_CellHeight, float p_CircleRadius, bool p_IsSound, bool p_IsIgnoreOpacity = false);
  void ScrollEventCallBack(Ref* p_Ref, ui::ScrollView::EventType p_EventType){}
  void ScrollTouchEventCallBack(Ref* p_Ref, ui::Widget::TouchEventType p_EventType);
  void UpdateItems();
  void selectedCellIndex(int p_CellIndex, float p_TimeInSec = 0, bool p_Attenuated = false, float p_AttenuatedY = 0);

  int pointCurSelectSingle(bool p_IsUpdateCurI);

  void SetTouchDetection(float delay);
  void bounceSingle();
  void UnfoldAction(float p_delay);
  void SetItemSelectedListener(const selectedItemListener& p_CallBack){
    _ItemSelectedListener = p_CallBack;
  };
};

