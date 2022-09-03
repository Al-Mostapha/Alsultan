
#include "Module/Army/Army.Module.h"
#include "Module/Army/Army.Service.h"
#include "Module/Player/Player.Static.h"

void ArmyModule::init()
{
    ArmyService::getCityArmy(PlayerStatic::SultanPlayer.idCurrentCity);
}