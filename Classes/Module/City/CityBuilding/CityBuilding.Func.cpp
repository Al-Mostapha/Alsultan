#include "CityBuilding.Func.h"

CityBuildingFunc *CityBuildingFunc::Get()
{
  static CityBuildingFunc *pInstance = new CityBuildingFunc();
  return pInstance;
}

bool CityBuildingFunc::CheckPopUpWindow()
{
  return false;
}

bool CityBuildingFunc::CheckPopUnlockPrinceGift()
{
  return false;
}

bool CityBuildingFunc::CheckPopUpSinbadTreasure()
{
  return false;
}