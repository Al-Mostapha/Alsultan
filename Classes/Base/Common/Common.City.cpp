#include "Common.City.h"

GTuple<bool, int32, GString> GBase::DGetBuildWarLv(const uint32 p_BuildingLvl) { 
  return {false, 1, "Desc or perc"}; 
}

GPair<int32, int32> GBase::DGetBuildStarLv(const EBuilding p_Building) { return GPair<int32, int32>::Make(0, 0); }

EBuildingPlace GBase::DGetBuildingTypeByIndex(EBuildingIndex p_Building) { return EBuildingPlace::Outer; }

bool  GBase::DIsMilitaryFOpen(){
  // return SoraDGetBuildStarLv(BUILDID.HALL_OF_WAR) >= 17 and commonCheck.MILITARYFORTRESS
  return true;
}

bool GBase::DIsBrave8Level() { return false; }

