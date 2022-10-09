#pragma once
#include "Include/IncludeBase.h"
#include "Module/Building/Building.Enum.h"

class CityLib{
public: 
  static CityLib *Get();
  void ShowTintOnce(class Node *p_Node);
  void PlaySound(const char *p_Sound, EBuilding p_Building, EBuildingActionTag p_Tag);
};