#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UITouchBaseView.h"

class IWorldMapInstance;

class UIEndlessTrialsProtal : public UITouchBaseView
{
  CREATE_FUNC(UIEndlessTrialsProtal);
  CreateUIPanel(UIEndlessTrialsProtal);
  CreateUICCSView(UIEndlessTrialsProtal);
public: 
  static UIEndlessTrialsProtal* Create();
  void InitData(uint32 pBuildClassID, const Vec2 &pTilePoint);
  void Ctor() override;
};