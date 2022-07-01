#include "Module/Building/Building.Lib.h"
#include "Module/Building/Building.Const.h"
#include "Include/IncludeCityBuilding.h"

void BuildingLib::buildCity()
{
}

void BuildingLib::buildAt(const char *BuildingPlace)
{
    EBuildingType buildingType;
}

DSCityBuildingUnit &BuildingLib::getBuildingAt(const char *BuildingPlace)
{
    DSCityBuildingUnit t("", "", EBuildingPos::CBPlace_None);
    return t;
}
CityBuildingBase *BuildingLib::getBuildingNodeAt(const char *BuildingPlace)
{
    return nullptr;
}

CityBuildingBase *BuildingLib::getBuildingClassByType(EBuildingType buildingType)
{
    cocos2d::log("Building Type %d", static_cast<int32>(buildingType));
    switch (buildingType)
    {
    case EBuildingType::CBType_None:
        return BuildingNone::create();
    case EBuildingType::CBType_Barrack:
        return BuildingABarrack::create();
    case EBuildingType::CBType_Workshop:
        return BuildingAChariotPlant::create();
    case EBuildingType::CBType_Fortress:
        return BuildingAFortress::create();
    case EBuildingType::CBType_TargetRange:
        return BuildingARange::create();
    case EBuildingType::CBType_Stable:
        return BuildingAStable::create();
    case EBuildingType::CBType_ArrowTower:
        return BuildingFArrowTower::create();
    case EBuildingType::CBType_StarBraveStatue:
        return BuildingFBraveStatue::create();
    case EBuildingType::CBType_Castle:
        return BuildingFCastle::create();
    case EBuildingType::CBType_ElitePalace:
        return BuildingFElitePalace::create();
    case EBuildingType::CBType_EpicBattle:
        return BuildingFEpicBattle::create();
    case EBuildingType::CBType_Port:
        return BuildingFHarbor::create();
    case EBuildingType::CBType_LeisureHouse:
        return BuildingFLeisureCenter::create();
    case EBuildingType::CBType_MaterialWorkShop:
        return BuildingFMaterialWorkShop::create();
    case EBuildingType::CBType_Miracle:
        return BuildingFMiracle::create();
    case EBuildingType::CBType_Monument:
        return BuildingFMonument::create();
    case EBuildingType::CBType_PetHouse:
        return BuildingFPetCenter::create();
    case EBuildingType::CBType_HeroPrison:
        return BuildingFPrison::create();
    case EBuildingType::CBType_ResurrectionHall:
        return BuildingFRevivalHall::create();
    case EBuildingType::CBType_HeroTrainGround:
        return BuildingFTrainHall::create();
    case EBuildingType::CBType_Wall:
        return BuildingFWall::create();
    case EBuildingType::CBType_Blacksmith:
        return BuildingIBlackSmith::create();
    case EBuildingType::CBType_DrillGrounds:
        return BuildingIDrillGrounds::create();
    case EBuildingType::CBType_Embassy:
        return BuildingIEmbassy::create();
    case EBuildingType::CBType_HallOfWar:
        return BuildingIHallOfWar::create();
    case EBuildingType::CBType_Institute:
        return BuildingIInstitute::create();
    case EBuildingType::CBType_Market:
        return BuildingIMarket::create();
    case EBuildingType::CBType_Warehouse:
        return BuildingIWareHouse::create();
    case EBuildingType::CBType_TreasurePool:
        return BuildingIWishWell::create();
    case EBuildingType::CBType_CrystalMine:
        return BuildingOCrystalMine::create();
    case EBuildingType::CBType_Farm:
        return BuildingOFarm::create();
    case EBuildingType::CBType_FirstAidTent:
        return BuildingOHosptial::create();
    case EBuildingType::CBType_IronMine:
        return BuildingOIronMine::create();
    case EBuildingType::CBType_MarchingTent:
        return BuildingOMilitaryTent::create();
    case EBuildingType::CBType_LumberMill:
        return BuildingOSawmill::create();
    case EBuildingType::CBType_SilverMine:
        return BuildingOSilver::create();

    default:
        return BuildingNone::create();
    }
};