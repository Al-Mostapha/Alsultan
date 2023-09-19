#pragma once
#include "Module/World/WorldMap/Instance/IWorldMapInstance.h"

class WorldMapAnniversaryCamp : public IWorldMapInstance
{
  public:
    bool _IsFirstCreate;
    int32 _CreateUid;
    int32 _LeagueID;
    GString _OwerName;
    int32 _FlameStage;
    int32 _FlameNum;
    Sprite *_TreasureImg;
    Label *_CampNameLabel;
    Sprite *_ImageName;
    Sprite *_WorkManImg;
};