#include "Module/Building/Building.Module.h"
#include "Module/Building/Building.Service.h"
#include "Module/Player/Player.Static.h"
#include "Module/City/City.Module.h"

void BuildingModule::init()
{
    BuildingService::fetchBuildingInfo();
    BuildingService::fetchCityBuilding(PlayerStatic::SultanPlayer.idCurrentCity);

}

void BuildingModule::buildCity()
{

    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingFixed.castle.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingFixed.arrowTowerL.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingFixed.wall.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingFixed.arrowTowerR.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingFixed.watchTower.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingFixed.merchant.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingFixed.harbor.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingFixed.troopDetail.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingFixed.leisureHouse.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingFixed.prison.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingFixed.trainHall.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingFixed.miracle.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingFixed.braveStatue.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingFixed.petCenter.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingFixed.resurrectionHall.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingFixed.serviceCenter.buildUnit().addToBuildingList();
    // PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingFixed.eventCenter.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingFixed.epicBattle.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingFixed.monument.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingFixed.veteransHall.buildUnit().addToBuildingList(); // Elite Palace

    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingInner.innerBuilding_1.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingInner.innerBuilding_2.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingInner.innerBuilding_3.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingInner.innerBuilding_4.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingInner.innerBuilding_5.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingInner.innerBuilding_6.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingInner.innerBuilding_7.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingInner.innerBuilding_8.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingInner.innerBuilding_9.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingInner.innerBuilding_10.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingInner.innerBuilding_11.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingInner.innerBuilding_12.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingInner.innerBuilding_13.buildUnit().addToBuildingList();

    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingOuter.resBuilding_1.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingOuter.resBuilding_2.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingOuter.resBuilding_3.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingOuter.resBuilding_4.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingOuter.resBuilding_5.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingOuter.resBuilding_6.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingOuter.resBuilding_7.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingOuter.resBuilding_8.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingOuter.resBuilding_9.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingOuter.resBuilding_10.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingOuter.resBuilding_11.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingOuter.resBuilding_12.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingOuter.resBuilding_13.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingOuter.resBuilding_14.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingOuter.resBuilding_15.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingOuter.resBuilding_16.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingOuter.resBuilding_17.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingOuter.resBuilding_18.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingOuter.resBuilding_19.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingOuter.resBuilding_20.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingOuter.resBuilding_21.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingOuter.resBuilding_22.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingOuter.resBuilding_23.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingOuter.resBuilding_24.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingOuter.resBuilding_25.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingOuter.resBuilding_26.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingOuter.resBuilding_27.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingOuter.resBuilding_28.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingOuter.resBuilding_29.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingOuter.resBuilding_30.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingOuter.resBuilding_31.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingOuter.resBuilding_32.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingOuter.resBuilding_33.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingOuter.resBuilding_34.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingOuter.resBuilding_35.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingOuter.resBuilding_36.buildUnit().addToBuildingList();
    CityStatic::Get()->GetCurrentCity().CityBuilding.CityBuildingOuter.resBuilding_37.buildUnit().addToBuildingList();
}


RCityBuilding& BuildingModule::getCurentCityBuilding(){
    return CityStatic::Get()->GetCurrentCity().CityBuilding;
}