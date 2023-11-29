#include "Base/BaseTypeDef.h"
#include "Module/Building/Building.Enum.h"
#include "Base/Containers/Pair.h"
#include "Base/Type/XTuple.h"

namespace GBase{
  GTuple<bool, int32, GString> DGetBuildWarLv(const uint32 p_BuildingLvl);
  GPair<int32, int32> DGetBuildStarLv(const EBuilding p_Building);
  EBuildingPlace DGetBuildingTypeByIndex(EBuildingIndex p_Building);
  bool DIsMilitaryFOpen();
  bool DIsBrave8Level();
};