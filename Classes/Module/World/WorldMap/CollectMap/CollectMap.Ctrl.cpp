#include "CollectMap.Ctrl.h"

CollectMapCtrl *CollectMapCtrl::Get(){
  static CollectMapCtrl *l_CollectMapCtrl = new CollectMapCtrl();
  return l_CollectMapCtrl;
}

GHashMap<int32, RAllianceMarkData> CollectMapCtrl::GetAllianceMarkData(){
  return GHashMap<int32, RAllianceMarkData>();
}