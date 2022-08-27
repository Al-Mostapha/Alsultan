#include "Module/Building/Building.Module.h"
#include "Module/Building/Building.Service.h"
#include "Module/Player/Player.DT.h"
#include "Module/City/City.Module.h"

void BuildingModule::init()
{
    BuildingService::fetchBuildingInfo();
    BuildingService::fetchCityBuilding(DTPlayer::SultanPlayer.idCurrentCity);

}

void BuildingModule::buildCity()
{

    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.castle.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.arrowTowerL.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.wall.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.arrowTowerR.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.watchTower.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.merchant.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.harbor.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.troopDetail.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.leisureHouse.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.prison.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.trainHall.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.miracle.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.braveStatue.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.petCenter.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.resurrectionHall.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.serviceCenter.buildUnit().addToBuildingList();
    // DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.eventCenter.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.epicBattle.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.monument.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.veteransHall.buildUnit().addToBuildingList(); // Elite Palace

    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_1.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_2.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_3.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_4.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_5.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_6.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_7.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_8.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_9.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_10.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_11.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_12.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_13.buildUnit().addToBuildingList();

    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_1.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_2.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_3.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_4.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_5.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_6.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_7.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_8.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_9.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_10.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_11.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_12.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_13.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_14.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_15.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_16.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_17.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_18.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_19.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_20.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_21.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_22.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_23.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_24.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_25.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_26.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_27.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_28.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_29.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_30.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_31.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_32.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_33.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_34.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_35.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_36.buildUnit().addToBuildingList();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_37.buildUnit().addToBuildingList();
}


TCityBuilding& BuildingModule::getCurentCityBuilding(){
    return CityModule::getCurrentCity().CityBuilding;
}