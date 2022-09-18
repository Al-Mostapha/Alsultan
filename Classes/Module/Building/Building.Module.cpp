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

    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingFixed.castle.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingFixed.arrowTowerL.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingFixed.wall.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingFixed.arrowTowerR.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingFixed.watchTower.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingFixed.merchant.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingFixed.harbor.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingFixed.troopDetail.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingFixed.leisureHouse.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingFixed.prison.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingFixed.trainHall.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingFixed.miracle.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingFixed.braveStatue.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingFixed.petCenter.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingFixed.resurrectionHall.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingFixed.serviceCenter.buildUnit().addToBuildingList();
    // PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingFixed.eventCenter.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingFixed.epicBattle.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingFixed.monument.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingFixed.veteransHall.buildUnit().addToBuildingList(); // Elite Palace

    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_1.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_2.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_3.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_4.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_5.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_6.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_7.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_8.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_9.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_10.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_11.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_12.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_13.buildUnit().addToBuildingList();

    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_1.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_2.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_3.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_4.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_5.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_6.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_7.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_8.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_9.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_10.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_11.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_12.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_13.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_14.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_15.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_16.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_17.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_18.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_19.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_20.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_21.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_22.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_23.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_24.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_25.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_26.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_27.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_28.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_29.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_30.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_31.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_32.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_33.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_34.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_35.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_36.buildUnit().addToBuildingList();
    PlayerStatic::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_37.buildUnit().addToBuildingList();
}


RCityBuilding& BuildingModule::getCurentCityBuilding(){
    return CityModule::getCurrentCity().CityBuilding;
}