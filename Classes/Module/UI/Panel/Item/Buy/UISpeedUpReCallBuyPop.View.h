#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UITouchBaseView.h"
#include "Module/Item/Item.Enum.h"



class UISpeedUpReCallBuyPopView : public UITouchBaseView
{
  CREATE_FUNC(UISpeedUpReCallBuyPopView);
  CreateUIPanel(UISpeedUpReCallBuyPopView);
  CreateUICCSView(UISpeedUpReCallBuyPopView);
public: 
  struct RItemData{
    int32 _TroopId;
    bool _IsMass;
    bool _IsMainQueue;
    bool _IsJieSan;
    bool _IsRecall;
  };
  static UISpeedUpReCallBuyPopView* Create();
  void InitData(EItemType pItemType, RItemData pItemData);
  void Ctor() override;
};