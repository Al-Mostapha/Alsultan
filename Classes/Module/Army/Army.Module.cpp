
#include "Module/Army/Army.Module.h"
#include "Module/Army/Army.Service.h"
#include "Module/Player/Player.DT.h"

void ArmyModule::init()
{
    ArmyService::getCityArmy(DTPlayer::SultanPlayer.idCurrentCity);
}