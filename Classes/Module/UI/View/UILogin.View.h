#pragma once
#include "Include/IncludeEngine.h"
#include "Module/UI/Panel/UIPanelBase.h"
#include "Include/IncludeGlobal.h"


class UILoginView : public UIPanelBase
{

private:
  CREATE_FUNC(UILoginView);
public:
  UILoginView(){};
  ~UILoginView(){};
  void InitPanel() override{};
  void Show() override {};
  static UILoginView *Create() {return create();};
  void SetKingdomClass(EKingdomClass p_KingdomClass){}
  void SetShowViewType(EScene p_Type){}
};


