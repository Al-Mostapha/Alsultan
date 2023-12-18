#pragma once

#include "Include/IncludeEngine.h"
#include "Base/Type/XVector.h"
#include "Base/BaseTypeDef.h"
#include "Base/Containers/Set.h"


#define CreateUIPanel(__TYPE__)\
static __TYPE__ *CreateBaseView(Size p_Size, bool p_IsColor = false, Node *p_Target = nullptr)\
{\
  if(p_Target)\
    return dynamic_cast<__TYPE__ *>(p_Target);\
  auto l_View  = __TYPE__::create();\
  l_View->setContentSize(p_Size);\
  if(p_IsColor){\
    l_View->setBackGroundColorType(ui::Layout::BackGroundColorType::SOLID);\
    l_View->setBackGroundColor(Color3B(255, 0, 0));\
    l_View->setBackGroundColorOpacity(100);\
  }\
  l_View->setAnchorPoint(Vec2(0.5, 0.5));\
  l_View->setPosition(Vec2(GDisplay::Get()->cx, GDisplay::Get()->cy));\
  l_View->setTouchEnabled(true);\
  l_View->setSwallowTouches(true);\
  return l_View;\
}

class UIBaseView : public ui::Layout
{
private:

  GSet<GString> m_ArrayImagesPath;
  bool m_ADType = false;
  int32 m_MenuID = 0;
public:
  bool m_FreeImagesOnExit = false;
  bool _IsHideCurrentSceneView = false;
  Node *_CcsView = nullptr;
  bool _IsTranslucentView = false;
  CREATE_FUNC(UIBaseView);
  static UIBaseView *Create(Size p_Size, bool p_IsColor = false, Node *p_Target = nullptr);
  virtual void Ctor();
  void SetBackGround(float p_Opacity, Color3B p_Color = Color3B::BLACK);
  float GetPanelOffsetHeight();
  typedef std::function<void()> CallBack;
  void LoadImages(const GVector<GString> &p_ArrayImagesPath, CallBack p_CallBack = nullptr);
  bool IsImageLoaded(GString p_ImageName);
  GString GetViewName(){return getName();}
};