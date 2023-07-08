#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/World/WorldMap/WorldMap.Type.h"



class UIWorldMapAllianceMark : public UIBasePanel
{
  CREATE_FUNC(UIWorldMapAllianceMark);
  CreateUIPanel(UIWorldMapAllianceMark);
  CreateUICCSView(UIWorldMapAllianceMark);
public: 


  static UIWorldMapAllianceMark* Create();
  void Ctor() override;
  void Toggle3D();
  void UpdateScaleZoom(float p_Scale);
  void UpdateLodLevel(EWorldLodDef);
  void InitData(const RAllianceMarkData &p_Data){}
};