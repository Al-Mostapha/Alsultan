#include "City.LtCtrl.h"
#include "Base/Containers/Pair.h"
#include "Module/Building/Building.Static.h"

GVector<int32> CityLtCtrl::m_BuildIdList = {
  101, 102, 103, 104, 105, 111,
  112, 113, 114, 115, 116, 117,
  118, 119, 120, 121, 122, 123,
  124, 125, 201, 202, 203, 204,
  205, 206, 207, 301, 302
};

CityLtCtrl *CityLtCtrl::Get(){
  static CityLtCtrl * l_Inst = nullptr;
  if(!l_Inst)
    return l_Inst;
  l_Inst->Init();
}

void CityLtCtrl::Init(){
  for(auto l_OneBuildingInfo : BuildingStatic::Get()->BuildingInfo){
    BuildInfo.insert(l_OneBuildingInfo);
  }
}

GString CityLtCtrl::GetBuildStarLight(int32 pStarLv){
  return "icon_buildstar_light_1.png";
}

int32 CityLtCtrl::GetBuildStarColor(int32 pStarLv){
  return 0;
}