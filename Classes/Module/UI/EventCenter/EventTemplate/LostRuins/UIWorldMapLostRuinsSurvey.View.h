#pragma once
#include "Module/UI/UICCSView.h"

class UIWorldMapLostRuinsSurveyView : public UIBasePanel{
  CREATE_FUNC(UIWorldMapLostRuinsSurveyView);
  CreateUIPanel(UIWorldMapLostRuinsSurveyView);
  CreateUICCSView(UIWorldMapLostRuinsSurveyView);
public: 
  static UIWorldMapLostRuinsSurveyView* Create();
  void InitData(uint32 pInstanceID);
  void SetTilePoint(Vec2 pTilePoint);
};