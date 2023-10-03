#pragma once
#include "Base/BaseTypeDef.h"
#include "Module/Net/NetBase.Module.h"
#include "Include/IncludeBuildingBase.h"

class BuildingService
{

public:
    static BuildingService *Get();
    void Init();
    IRequest *GetBuildingList();
    static void fetchCityBuilding(int32 idCity);
    static void fetchBuildingInfo();
};
