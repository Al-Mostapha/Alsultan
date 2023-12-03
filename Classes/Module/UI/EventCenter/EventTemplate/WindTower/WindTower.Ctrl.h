#pragma once
#include "WindTower.Type.h"
#include "Base/Type/XEngine.h"

class WindTowerCtrl{
public:
  static WindTowerCtrl *Get();
  int32 GetNewSurveyNum();
  RWindTowerQuestInfo GetQuestInfo(Vec2 pPoint);
};