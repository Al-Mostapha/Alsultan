#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/CityResource/Resource.Enum.h"

struct RTableResNeedBuy
{
  EResource _ResId;
  int32  _ItemId;
  int32 _ItemCount;
  int32 _ResCount;
};

class UIBuildCreateResBuy : public UIBasePanel
{

  CREATE_FUNC(UIBuildCreateResBuy);
  CreateUIPanel(UIBuildCreateResBuy);
  CreateUICCSView(UIBuildCreateResBuy);

  
public: 
  static UIBuildCreateResBuy* Create();
  void Ctor() override;
  void InitData(GVector<RTableResNeedBuy> p_CostRes, int32 p_ToGold, EResBuyViewType p_ResType);
  void SetBuyResCallBack(std::function<void()> p_CallBack){}
  void InitWidget();
};