#pragma once
#include "Include/IncludeBase.h"
#include "City.Func.Parm.h"
#include "Module/Building/Building.Enum.h"


class MainCityView;
class MainCityFunctions{
public:
  static MainCityFunctions *Get();
  void UpdateLockArea(class MainCityView *p_View);
  void AddBuild(MainCityView *p_MainCity, EBuilding p_BuildingId, EBuildingIndex p_BuildingIndex);
  void ReArrangeZorder(MainCityView *p_MainCity);
  void CancelBuildTint(Node *p_Node);
  void ShowNodeTint(Node *p_Node);
  void ShowNodeTintOnce(Node *p_Node);
  void DoOffsetContainerWithSelectBuild(
    MainCityView *p_MainCity, Node *p_Building, float p_Scale = 1, 
    RDoOffestMoveParam p_Other = RDoOffestMoveParam());

};