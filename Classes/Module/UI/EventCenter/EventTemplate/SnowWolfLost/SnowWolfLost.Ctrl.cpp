#include "SnowWolfLost.Ctrl.h"

SnowWolfLostCtrl* SnowWolfLostCtrl::Get(){
  static SnowWolfLostCtrl* pCtrl = nullptr;
  if (pCtrl == nullptr){
    pCtrl = new SnowWolfLostCtrl();
  }
  return pCtrl;
}

int32 SnowWolfLostCtrl::GetNewSurveyNum(){
  return 0;
}