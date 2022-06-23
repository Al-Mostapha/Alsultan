#pragma once
#include "Module/City/City.DT.h"

struct DSPlayer
{
    int32 idCurrentCity;
    int32 idPlayer;
    DSCity City;
};

class DTPlayer
{
public:
    static DSPlayer SultanPlayer;
};
