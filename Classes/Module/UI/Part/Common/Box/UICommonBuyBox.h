#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

struct RShowBuyBoxParam ;

class UICommonBuyBox : public UIBasePanel
{

  CREATE_FUNC(UICommonBuyBox);
  CreateUIPanel(UICommonBuyBox);
  CreateUICCSView(UICommonBuyBox);

  
public: 
  static UICommonBuyBox* Create();
  void Ctor() override {};
  void InitData(const RShowBuyBoxParam &p_Param){}
  void SetHandle(const std::function<void(EMsgBoxCallBack)> &p_Handle){}
  void SetUseToolStyle(const std::function<void(EMsgBoxCallBack)> &p_Handle, const GString &p_String){}
  void SetBtnBuy(bool p_IsCan){}
};