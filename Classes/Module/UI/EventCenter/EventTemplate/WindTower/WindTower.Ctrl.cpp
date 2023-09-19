#include "WindTower.Ctrl.h"

WindTowerCtrl * WindTowerCtrl::Get(){
  static WindTowerCtrl * _WindTowerCtrl = nullptr;
  if(_WindTowerCtrl == nullptr){
    _WindTowerCtrl = new WindTowerCtrl();
  }
  return _WindTowerCtrl;
}

int32 WindTowerCtrl::GetNewSurveyNum(){
  return 0;
}

RWindTowerQuestInfo WindTowerCtrl::GetQuestInfo(Vec2 pPoint){
  RWindTowerQuestInfo lQuestInfo;
  return lQuestInfo;
}