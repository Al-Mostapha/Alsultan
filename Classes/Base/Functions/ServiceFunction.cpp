#include "ServiceFunction.h"

GServiceFunction *GServiceFunction::Get(){
  static GServiceFunction *l_ServiceFunction = new GServiceFunction();
  return l_ServiceFunction;
}

EIDType GServiceFunction::GetIDType(int p_ID){
  return EIDType::None;
}

GTime GServiceFunction::SystemTime(){
  return 0;
}