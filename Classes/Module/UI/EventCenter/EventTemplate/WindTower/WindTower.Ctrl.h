#pragma once
#include "WindTower.Type.h"

USING_NS_CC;

class WindTowerCtrl{
public:
  static WindTowerCtrl *Get();
  int32 GetNewSurveyNum();
  RWindTowerQuestInfo GetQuestInfo(Vec2 pPoint);
};