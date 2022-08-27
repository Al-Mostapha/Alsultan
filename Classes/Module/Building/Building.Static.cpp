#include "Building.Static.h"
#include "Building.Enum.h"

GVector<EBuildingType> BuildingStatic::BuildableList = {
    EBuildingType::None,
    EBuildingType::Castle,
    EBuildingType::Wall,
    EBuildingType::ArrowTower,
    EBuildingType::WatchTower,
    EBuildingType::Warehouse,
    EBuildingType::Embassy,
    EBuildingType::Market,
    EBuildingType::Institute,
    EBuildingType::TreasurePool,
    EBuildingType::Blacksmith,
    EBuildingType::Stable,
    EBuildingType::TargetRange,
    EBuildingType::Barrack,
    EBuildingType::ChariotPlant,
    EBuildingType::Fortress,
    EBuildingType::DrillGrounds,
    EBuildingType::HallOfWar,
    EBuildingType::TrainHall,
    EBuildingType::Prison,
    EBuildingType::Farm,
    EBuildingType::LumberMill,
    EBuildingType::IronMine,
    EBuildingType::SilverMine,
    EBuildingType::MarchingTent,
    EBuildingType::FirstAidTent,
    EBuildingType::CrystalMine,
    EBuildingType::Miracle,
    EBuildingType::ElitePalace
};

GMap<EBuildingType, TBuildingInfoUnit> BuildingStatic::BuildingInfo;