#pragma once
#include "Module/World/WorldMap/Instance/IWorldMapInstance.h"

struct RUnitTreasureInit{
  int32 _PlayerID;
  int32 _LeagueID;
  int32 _EmojiID;
  GString _LeagueName;
  GString _PlayerName;
  GTime _DigEndTime;
};

class UITimerLabel;
class WorldMapTreasure : public IWorldMapInstance
{
  public:

  GTime _StateTime;
  EMapObjStateTypeDef _TreasureState;
  int32 _EmojiID;
  Sprite *_TreasureImg;
  Sprite *_ImageTimeBg;
  UITimerLabel *_TextStateTime;
  Sprite *_WorkManImg;

  public:
    CREATE_FUNC(WorldMapTreasure);
    void Ctor() override;
    void SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) override;
    void InitInstanceData(int32 pClass, void *pObjData, int32 pObjID = 0) override;
    void UpdateData(const RUnitTreasureInit &pData);
    GString GetFavoriteName();
    void PlayClickSound() override;
    GVector<RButtonTypeArray> GetInstanceOp(bool pIsSelfKingdom, bool pIsInWar) override;
    void AddCacheBefore() override;
};