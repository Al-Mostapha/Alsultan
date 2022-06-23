#include "Module/Building/Building.Module.h"
#include "Module/Building/Building.Service.h"
#include "Module/Player/Player.DT.h"

void BuildingModule::init()
{
    BuildingService::getCityBuilding(DTPlayer::SultanPlayer.idCurrentCity);
}