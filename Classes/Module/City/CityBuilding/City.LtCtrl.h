#pragma once
#include "Include/IncludeBase.h"
#include "Base/Type/XVector.h"
#include "Module/Building/Building.Enum.h"
#include "Module/Building/Building.Type.h"

class CityLtCtrl{
  private:
    static GVector<int32> m_BuildIdList;
    GHashMap<EBuilding, RBuildingSpecs> BuildInfo;
  public:
    void Init();
    static CityLtCtrl *Get();
    GString GetBuildStarLight(int32 pStarLv);
    int32 GetBuildStarColor(int32 pStarLv);
    bool IsOpenWL(EBuilding pBuilding){
      return true;
    };
};