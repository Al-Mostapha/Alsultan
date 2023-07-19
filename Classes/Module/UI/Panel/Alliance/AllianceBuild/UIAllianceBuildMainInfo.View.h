#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Guild/Alliance.Type.h"

class UIAllianceBuildMainInfoView : public UIBasePanel
{
CREATE_FUNC(UIAllianceBuildMainInfoView);
CreateUIPanel(UIAllianceBuildMainInfoView);
CreateUICCSView(UIAllianceBuildMainInfoView);
public:
  static UIAllianceBuildMainInfoView* Create();
  void Ctor() override;
  void InitData(const RAllianceBuildMainInfo& pInfo);
  void InitWidget();
};