#pragma once
#include "Module/UI/UICCSView.h"
#include "UIWorldMapBoss.View.h"

class IWorldMapInstance;

class UIWorldMapEndlessTrialBossInfo : public UIWorldMapBossView
{
  CREATE_FUNC(UIWorldMapEndlessTrialBossInfo);
  CreateUIPanel(UIWorldMapEndlessTrialBossInfo);
  CreateUICCSView(UIWorldMapEndlessTrialBossInfo);
public: 
  static UIWorldMapEndlessTrialBossInfo* Create();
  void InitData(IWorldMapInstance *pMapInstance) override;
  void Ctor() override;
};