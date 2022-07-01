#include "Module/Building/Building.Module.h"
#include "Module/Building/Building.Service.h"
#include "Module/Player/Player.DT.h"

void BuildingModule::init()
{
    BuildingService::getCityBuilding(DTPlayer::SultanPlayer.idCurrentCity);
}

void BuildingModule::buildCity()
{

    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.castle.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.arrowTowerL.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.wall.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.arrowTowerR.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.watchTower.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.merchant.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.harbor.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.troopDetail.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.leisureHouse.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.prison.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.trainHall.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.miracle.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.braveStatue.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.petCenter.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.resurrectionHall.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.eventCenter.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.epicBattle.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.monument.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingFixed.veteransHall.buildUnit(); // Elite Palace

    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_1.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_2.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_3.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_4.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_5.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_6.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_7.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_8.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_9.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_10.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_11.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_12.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingInner.innerBuilding_13.buildUnit();

    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_1.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_2.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_3.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_4.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_5.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_6.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_7.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_8.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_9.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_10.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_11.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_12.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_13.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_14.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_15.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_16.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_17.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_18.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_19.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_20.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_21.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_22.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_23.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_24.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_25.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_26.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_27.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_28.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_29.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_30.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_31.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_32.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_33.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_34.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_35.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_36.buildUnit();
    DTPlayer::SultanPlayer.City.CityBuilding.CityBuildingOuter.resBuilding_37.buildUnit();
}