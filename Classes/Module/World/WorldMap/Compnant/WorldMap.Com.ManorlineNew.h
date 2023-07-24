#pragma once
#include "IWorldMap.Com.h"

USING_NS_CC;

class WorldMapComManorLineNew : public IWorldMapComponent{
    // self.currentShowLeagueManorLineArrary = {}
    int32 _TiledBgX = 0;
    int32 _TiledBgY = 0;
    bool _IsNeedRefresh = false;
    GVector<int32> _LeagueIDArrary;
    int32 _CurMaxSn = 0;
    GHashMap<int32, float> _ColorIdArrary;
    bool _IsInNebula = false;
    int32 _MapRangMaxX = 0;
    Sprite *_TiledBg = nullptr;
    GLProgram *_Program;
    GLProgramState *_State;
    int32 _CurSelectNodeInfo = 0;

  public:
    void Ctor() override;
    void Init() override;
    void OnMessageListener() override;

    void RefreshMapPos(Vec2 pTilePos);
    void ShowManorline(bool pIsShow);

    void UpdateMapPos(EventCustom* pEvent);
    void Toggle3D(EventCustom* pEvent);
    void UpdateLodLevel(EventCustom* pEvent);
    void UpdateInfo(EventCustom* pEvent);
    void UpdateLeagueManorInstance(EventCustom* pEvent);
    void ResetLeagueManorInstance(EventCustom* pEvent);
    void UpdateNodeInfoSelect(EventCustom* pEvent);
    void UpdateRelationChange(EventCustom* pEvent);
};