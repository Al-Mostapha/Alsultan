#pragma once
#include "Include/IncludeBase.h"
#include "Module/UI/UICCSView.h"
#include "Module/Guild/Alliance.Type.h"

class UIAllianceInfoView : public UIBaseView
{
  CREATE_FUNC(UIAllianceInfoView);
  CreateUICCSView(UIAllianceInfoView);
  CreateUIPanel(UIAllianceInfoView);
public:
  static UIAllianceInfoView *Create();
  void InitData(const RAlliance &p_Alliance, int32 p_KingdomID);
  void Show();
};