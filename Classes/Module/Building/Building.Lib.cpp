#include "Building.Lib.h"
#include "Building.Static.h"
#include "Include/IncludeBuildingBase.h"
#include "Include/IncludeCityBuilding.h"
#include "Module/Building/CityBuildingBase.h"
#include "Module/Player/Player.Static.h"

void BuildingLib::buildCity() {}

void BuildingLib::buildAt(const char* BuildingPlace) { EBuildingType buildingType; }

RCityBuildingUnit& BuildingLib::getBuildingAt(const char* BuildingPlace) {
  RCityBuildingUnit t("", "", EBuildingPos::CBPlace_None);
  return t;
}
CityBuildingBase* BuildingLib::getBuildingNodeAt(const char* BuildingPlace) { return nullptr; }

CityBuildingBase* BuildingLib::getBuildingClassByType(EBuildingType buildingType) {
  switch (buildingType) {
    case EBuildingType::None:
      return BuildingNone::create();
    case EBuildingType::Barrack:
      return BuildingABarrack::create();
    case EBuildingType::ChariotPlant:
      return BuildingAChariotPlant::create();
    case EBuildingType::Fortress:
      return BuildingAFortress::create();
    case EBuildingType::TargetRange:
      return BuildingARange::create();
    case EBuildingType::Stable:
      return BuildingAStable::create();
    case EBuildingType::ArrowTower:
      return BuildingFArrowTower::create();
    case EBuildingType::StarBraveStatue:
      return BuildingFBraveStatue::create();
    case EBuildingType::Castle:
      return BuildingFCastle::create();
    case EBuildingType::ElitePalace:
      return BuildingFElitePalace::create();
    case EBuildingType::EpicBattle:
      return BuildingFEpicBattle::create();
    case EBuildingType::Port:
      return BuildingFHarbor::create();
    case EBuildingType::LeisureHouse:
      return BuildingFLeisureCenter::create();
    case EBuildingType::MaterialWorkShop:
      return BuildingFMaterialWorkShop::create();
    case EBuildingType::Miracle:
      return BuildingFMiracle::create();
    case EBuildingType::Monument:
      return BuildingFMonument::create();
    case EBuildingType::PetHouse:
      return BuildingFPetCenter::create();
    case EBuildingType::Prison:
      return BuildingFPrison::create();
    case EBuildingType::ResurrectionHall:
      return BuildingFRevivalHall::create();
    case EBuildingType::ServiceCenter:
      return BuildingFServiceCenter::create();
    case EBuildingType::TrainHall:
      return BuildingFTrainHall::create();
    case EBuildingType::Wall:
      return BuildingFWall::create();
    case EBuildingType::Blacksmith:
      return BuildingIBlackSmith::create();
    case EBuildingType::DrillGrounds:
      return BuildingIDrillGrounds::create();
    case EBuildingType::Embassy:
      return BuildingIEmbassy::create();
    case EBuildingType::HallOfWar:
      return BuildingIHallOfWar::create();
    case EBuildingType::Institute:
      return BuildingIInstitute::create();
    case EBuildingType::Market:
      return BuildingIMarket::create();
    case EBuildingType::Warehouse:
      return BuildingIWareHouse::create();
    case EBuildingType::TreasurePool:
      return BuildingIWishWell::create();
    case EBuildingType::CrystalMine:
      return BuildingOCrystalMine::create();
    case EBuildingType::Farm:
      return BuildingOFarm::create();
    case EBuildingType::FirstAidTent:
      return BuildingOHosptial::create();
    case EBuildingType::IronMine:
      return BuildingOIronMine::create();
    case EBuildingType::MarchingTent:
      return BuildingOMilitaryTent::create();
    case EBuildingType::LumberMill:
      return BuildingOSawmill::create();
    case EBuildingType::SilverMine:
      return BuildingOSilver::create();
    default:
      return BuildingNone::create();
  }
};

RCityBuilding& BuildingLib::getCurentCityBuilding() { return PlayerStatic::SultanPlayer.City.CityBuilding; }

GVector<RCityBuildingUnit> BuildingLib::getBuildingList(EBuildingType buildingType) {
  GVector<RCityBuildingUnit> BuildingList;
  auto buildings = getCurentCityBuilding().BuildingList;
  for (auto building : buildings) {
    if (buildingType == building.second.eBuildingType) BuildingList.push_back(building.second);
  }
  for (auto it = buildings.begin(); it != buildings.end(); it++) {
    if (buildingType == it->second.eBuildingType) BuildingList.push_back(it->second);
  }
  return BuildingList;
}

GVector<RCityBuildingUnit> BuildingLib::getBuildingResList() {
  GVector<RCityBuildingUnit> BuildingList;
  auto Frams = getBuildingList(EBuildingType::Farm);
  auto SawMills = getBuildingList(EBuildingType::LumberMill);
  auto IronMines = getBuildingList(EBuildingType::IronMine);
  auto SilverMines = getBuildingList(EBuildingType::SilverMine);
  auto CrystalMines = getBuildingList(EBuildingType::CrystalMine);

  BuildingList.insert(BuildingList.end(), Frams.begin(), Frams.end());
  BuildingList.insert(BuildingList.end(), SawMills.begin(), SawMills.end());
  BuildingList.insert(BuildingList.end(), IronMines.begin(), IronMines.end());
  BuildingList.insert(BuildingList.end(), SilverMines.begin(), SilverMines.end());
  BuildingList.insert(BuildingList.end(), CrystalMines.begin(), CrystalMines.end());

  return BuildingList;
}

GVector<RBuildingSpecs> BuildingLib::getCanBuildList(EBuildingType p_BuildingType) {
  GVector<RBuildingSpecs> l_BuildableList;
  for (auto l_building : BuildingStatic::BuildableList) {
    if (BuildingStatic::BuildingInfo.count(l_building)) l_BuildableList.push_back(BuildingStatic::BuildingInfo[l_building]);
  }
  return l_BuildableList;
}

bool BuildingLib::isCanBuild(EBuildingType p_BuildingType) { return true; }
