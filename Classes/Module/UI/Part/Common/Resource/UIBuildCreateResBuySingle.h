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

class UIBuildCreateResBuySingle : public UIBasePanel
{

  CREATE_FUNC(UIBuildCreateResBuySingle);
  CreateUIPanel(UIBuildCreateResBuySingle);
  CreateUICCSView(UIBuildCreateResBuySingle);

  
public: 
  static UIBuildCreateResBuySingle* Create();
  void Ctor() override;
  void InitData(GVector<RTableResNeedBuy> p_CostRes, int32 p_ToGold, EResBuyViewType p_ResType);
  void SetBuyResCallBack(std::function<void()> p_CallBack){}
  void InitWidget();
};