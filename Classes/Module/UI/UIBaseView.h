#pragma once
#include "Include/IncludeBase.h"

class UIBaseView : public ui::Layout
{
private:
  bool m_FreeImagesOnExit = false;
  GSet<GString> m_ArrayImagesPath;
  bool m_ADType = false;
  int32 m_MenuID = 0;
private:
  CREATE_FUNC(UIBaseView);
public:
  static UIBaseView *Create(Size p_Size, bool p_IsColor = false, Node *p_Target = nullptr);
  void Ctor();
  void SetBackGround(float p_Opacity, Color3B p_Color);
  float GetPanelOffsetHeight();
  typedef std::function<void()> CallBack;
  void LoadImages(const GVector<GString> &p_ArrayImagesPath, CallBack p_CallBack = nullptr);
  bool IsImageLoaded(GString p_ImageName);
};