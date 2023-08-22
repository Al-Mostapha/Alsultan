#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBaseView.h"
#include "Module/World/WorldMap/Instance/Unit/WorldMapAllianceBuild.h"

class UIWorldMapAllianceBuildProgressBar : public UIBaseView
{

  CREATE_FUNC(UIWorldMapAllianceBuildProgressBar);
  CreateUIPanel(UIWorldMapAllianceBuildProgressBar);
  CreateUICCSView(UIWorldMapAllianceBuildProgressBar);

  
public: 
  static UIWorldMapAllianceBuildProgressBar* Create();
  void Ctor() override;
  void InitData(const RWorldAllianceBuildInitData &pData, bool pIsShow = false);
};