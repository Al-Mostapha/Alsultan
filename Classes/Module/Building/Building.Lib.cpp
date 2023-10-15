#include "Building.Lib.h"
#include "Building.Static.h"
#include "Include/IncludeBuildingBase.h"
#include "Include/IncludeCityBuilding.h"
#include "Module/Building/IBuilding.h"
#include "Module/Player/Player.Static.h"
#include "Module/City/City.Static.h"

void BuildingLib::buildCity() {}

BuildingLib *BuildingLib::Get(){
  static auto l_Inst = new BuildingLib();
  return l_Inst;
}

void BuildingLib::buildAt(const char* BuildingPlace) { EBuilding buildingType; }

RCityBuildingUnit& BuildingLib::getBuildingAt(const char* BuildingPlace) {
  RCityBuildingUnit t("", "", EBuildingPos::CBPlace_None);
  return t;
}
IBuilding* BuildingLib::getBuildingNodeAt(const char* BuildingPlace) { return nullptr; }

IBuilding* BuildingLib::getBuildingClassByType(EBuilding buildingType) {
  switch (buildingType) {
    case EBuilding::None:
      return BuildingNone::create();
    case EBuilding::Barrack:
      return BuildingABarrack::create();
    case EBuilding::ChariotPlant:
      return BuildingAChariotPlant::create();
    case EBuilding::Fortress:
      return BuildingAFortress::create();
    case EBuilding::TargetRange:
      return BuildingARange::create();
    case EBuilding::Stable:
      return BuildingAStable::create();
    case EBuilding::ArrowTower:
      return BuildingFArrowTower::create();
    case EBuilding::StarBraveStatue:
      return BuildingFBraveStatue::create();
    case EBuilding::Castle:
      return BuildingFCastle::create();
    case EBuilding::ElitePalace:
      return BuildingFElitePalace::create();
    case EBuilding::EpicBattle:
      return BuildingFEpicBattle::create();
    case EBuilding::Port:
      return BuildingFHarbor::create();
    case EBuilding::LeisureHouse:
      return BuildingFLeisureCenter::create();
    case EBuilding::MaterialWorkShop:
      return BuildingFMaterialWorkShop::create();
    case EBuilding::Miracle:
      return BuildingFMiracle::create();
    case EBuilding::Monument:
      return BuildingFMonument::create();
    case EBuilding::PetHouse:
      return BuildingFPetCenter::create();
    case EBuilding::Prison:
      return BuildingFPrison::create();
    case EBuilding::ResurrectionHall:
      return BuildingFRevivalHall::create();
    case EBuilding::ServiceCenter:
      return BuildingFServiceCenter::create();
    case EBuilding::TrainHall:
      return BuildingFTrainHall::create();
    case EBuilding::Wall:
      return BuildingFWall::create();
    case EBuilding::Blacksmith:
      return BuildingIBlackSmith::create();
    case EBuilding::DrillGrounds:
      return BuildingIDrillGrounds::create();
    case EBuilding::Embassy:
      return BuildingIEmbassy::create();
    case EBuilding::HallOfWar:
      return BuildingIHallOfWar::create();
    case EBuilding::Institute:
      return BuildingIInstitute::create();
    case EBuilding::Market:
      return BuildingIMarket::create();
    case EBuilding::Depot:
      return BuildingIWareHouse::create();
    case EBuilding::TreasurePool:
      return BuildingIWishWell::create();
    case EBuilding::CrystalMine:
      return BuildingOCrystalMine::create();
    case EBuilding::Farm:
      return BuildingOFarm::create();
    case EBuilding::FirstAidTent:
      return BuildingOHosptial::create();
    case EBuilding::IronMine:
      return BuildingOIronMine::create();
    case EBuilding::MarchingTent:
      return BuildingOMilitaryTent::create();
    case EBuilding::LumberMill:
      return BuildingOSawmill::create();
    case EBuilding::SilverMine:
      return BuildingOSilver::create();
    default:
      return BuildingNone::create();
  }
};

RCityBuilding& BuildingLib::getCurentCityBuilding() { return CityStatic::Get()->GetCurrentCity().CityBuilding; }

GVector<RCityBuildingUnit> BuildingLib::getBuildingList(EBuilding buildingType) {
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
  auto Frams = getBuildingList(EBuilding::Farm);
  auto SawMills = getBuildingList(EBuilding::LumberMill);
  auto IronMines = getBuildingList(EBuilding::IronMine);
  auto SilverMines = getBuildingList(EBuilding::SilverMine);
  auto CrystalMines = getBuildingList(EBuilding::CrystalMine);

  BuildingList.insert(BuildingList.end(), Frams.begin(), Frams.end());
  BuildingList.insert(BuildingList.end(), SawMills.begin(), SawMills.end());
  BuildingList.insert(BuildingList.end(), IronMines.begin(), IronMines.end());
  BuildingList.insert(BuildingList.end(), SilverMines.begin(), SilverMines.end());
  BuildingList.insert(BuildingList.end(), CrystalMines.begin(), CrystalMines.end());

  return BuildingList;
}

GVector<RBuildingSpecs> BuildingLib::getCanBuildList(EBuilding p_BuildingType) {
  GVector<RBuildingSpecs> l_BuildableList;
  for (auto l_building : BuildingStatic::BuildableList) {
    if (BuildingStatic::BuildingInfo.count(l_building)) 
    l_BuildableList.push_back(BuildingStatic::BuildingInfo[l_building]);
  }
  return l_BuildableList;
}

bool BuildingLib::isCanBuild(EBuilding p_BuildingType) { return true; }


EBuildingPlace BuildingLib::DGetBuildTypeByIndex(EBuildingIndex p_Building){
  int32 l_BuildingPlace  = static_cast<int32>(p_Building);
  if(l_BuildingPlace < 1100)  
    return EBuildingPlace::Inner;
    //TODO: this is trivial condiction look to next condition
  if(l_BuildingPlace > 30000)
    return EBuildingPlace::Inner;
  if(l_BuildingPlace >= 1200) // this also greater the 30k
    return EBuildingPlace::Inner;
  return EBuildingPlace::Outer;
}

bool BuildingLib::DIsFixedBuild(EBuildingIndex pIndex){
  auto lBuildingIndex = static_cast<int32>(pIndex);
  if(lBuildingIndex >= (int32)EBuildingIndex::LeisureCenter && lBuildingIndex <= (int32)EBuildingIndex::ResurrectionHall)
    return true;
  if(pIndex == EBuildingIndex::MaterialWorkShop)
    return true;
  return false;
}

EBuildingPlace BuildingLib::DGetBuildTypeByBid(EBuilding p_Building){
  auto l_IdBuilding = static_cast<int32>(p_Building);
  if(l_IdBuilding < 200 || l_IdBuilding > 30000 || l_IdBuilding >= 300 )
    return EBuildingPlace::Inner;
  return EBuildingPlace::Outer;
}