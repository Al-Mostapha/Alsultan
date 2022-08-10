#include "Module/Building/Building.Lib.h"
#include "Module/Building/Building.Const.h"
#include "Include/IncludeCityBuilding.h"
#include "Module/Player/Player.DT.h"

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
    case EBuildingType::CBType_ServiceCenter:
        return BuildingFServiceCenter::create();
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

DSCityBuilding &BuildingLib::getCurentCityBuilding()
{
    return DTPlayer::SultanPlayer.City.CityBuilding;
}

GVector<DSCityBuildingUnit> BuildingLib::getBuildingList(EBuildingType buildingType)
{
    GVector<DSCityBuildingUnit> BuildingList;
    auto buildings = getCurentCityBuilding().BuildingList;
    for (auto building : buildings)
    {
        if (buildingType == building.second.eBuildingType)
            BuildingList.push_back(building.second);
    }
    for (auto it = buildings.begin(); it != buildings.end(); it++)
    {
        if (buildingType == it->second.eBuildingType)
            BuildingList.push_back(it->second);
    }
    return BuildingList;
}

GVector<DSCityBuildingUnit> BuildingLib::getBuildingResList()
{
    GVector<DSCityBuildingUnit> BuildingList;
    auto Frams = getBuildingList(EBuildingType::CBType_Farm);
    auto SawMills = getBuildingList(EBuildingType::CBType_LumberMill);
    auto IronMines = getBuildingList(EBuildingType::CBType_IronMine);
    auto SilverMines = getBuildingList(EBuildingType::CBType_SilverMine);
    auto CrystalMines = getBuildingList(EBuildingType::CBType_CrystalMine);

    BuildingList.insert(BuildingList.end(), Frams.begin(), Frams.end());
    BuildingList.insert(BuildingList.end(), SawMills.begin(), SawMills.end());
    BuildingList.insert(BuildingList.end(), IronMines.begin(), IronMines.end());
    BuildingList.insert(BuildingList.end(), SilverMines.begin(), SilverMines.end());
    BuildingList.insert(BuildingList.end(), CrystalMines.begin(), CrystalMines.end());

    return BuildingList;
}

GVector<DSBuildingInfoUnit> BuildingLib::getCanBuildList(EBuildingType p_BuildingType)
{
    GVector<DSBuildingInfoUnit> l_BuildableList;

    for(auto l_building : BuildingStatic::BuildableList)
        l_BuildableList.push_back(l_building);

}