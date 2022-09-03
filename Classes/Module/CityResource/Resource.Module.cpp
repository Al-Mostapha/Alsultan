#include "Module/CityResource/Resource.Module.h"
#include "Module/CityResource/CityResource.Service.h"
#include "Module/Player/Player.Static.h"

void ResourceModule::init()
{
    CityResourceService::getCityResource(PlayerStatic::SultanPlayer.idCurrentCity);
}