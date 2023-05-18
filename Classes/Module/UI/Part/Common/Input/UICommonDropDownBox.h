#pragma once
#include "Module/UI/UICCSView.h"

struct RCommonDropDownBoxChildData{
  GString _Title;
  int32 _Tag;
};

struct RCommonDropDownBoxInitData{
  int32 _MaxHeight = 300;
  Size _ChildSize = Size(360, 47);
  GVector<RCommonDropDownBoxChildData> _ChildData;
};

class UICommonDropDownBox : public UIBaseView
{

  CREATE_FUNC(UICommonDropDownBox);
  CreateUIPanel(UICommonDropDownBox);
  CreateUICCSView(UICommonDropDownBox);

  
public: 
  static UICommonDropDownBox* Create();
  void Ctor() override ;

  void SetCustomColor(bool p_IsCustomColor){}
  void SetIsCustom(bool p_IsCustom){}
  void SetSelectSingleTarget(const GString &){}
  void SetTouchClose(){}
  void SetFlipArrow(int32 p_FlipArrow){}
  void SetChooseTag(int32 p_Tag){}
  void InitData(const RCommonDropDownBoxInitData &p_InitData){}
  void SetDefaultIndex(int32 p_Index){}
  void AddEventListener(const std::function<void(int32)> &p_Listener){}
};