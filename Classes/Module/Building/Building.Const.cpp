#include "Building.Const.h"

BuildingConst *BuildingConst::Get(){
  static BuildingConst *l_Instant = new BuildingConst();
  return l_Instant;
}