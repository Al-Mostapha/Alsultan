#include "Module/CityResource/Resource.Module.h"
#include "Module/CityResource/CityResource.Service.h"
#include "Module/Player/Player.DT.h"

void ResourceModule::init()
{
    CityResourceService::getCityResource(DTPlayer::SultanPlayer.idCurrentCity);
}