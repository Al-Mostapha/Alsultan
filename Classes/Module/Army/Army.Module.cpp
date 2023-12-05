
#include "Module/Army/Army.Module.h"
#include "Module/Army/Army.Service.h"
#include "Module/Player/Player.Static.h"

ArmyModule *ArmyModule::Get()
{
    static ArmyModule *s_ArmyModule = new ArmyModule();
    return s_ArmyModule;
}

void ArmyModule::Init()
{
    ArmyService::getCityArmy(PlayerStatic::SultanPlayer.idCurrentCity);
}

void ArmyModule::StartGame()
{
}