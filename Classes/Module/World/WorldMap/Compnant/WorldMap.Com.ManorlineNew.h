#pragma once
#include "IWorldMap.Com.h"
#include "Base/Utils/MeshNode.h"

USING_NS_CC;

class WorldMapComManorLineNew : public IWorldMapComponent{
    // self.currentShowLeagueManorLineArrary = {}
    int32 _TiledBgX = 0;
    int32 _TiledBgY = 0;
    int32 _MyLeagueID = 0;
    bool _IsNeedRefresh = false;
    GVector<int32> _LeagueIDArrary;
    int32 _CurMaxSn = 0;
    GHashMap<int32, float> _ColorIdArrary;
    bool _IsInNebula = false;
    float _MapRangMaxX = 0;
    Sprite *_TiledBg = nullptr;
    GLProgram *_Program;
    GLProgramState *_State;
    int32 _CurSelectNodeInfo = 0;
    typedef GHashMap<int32,GHashMap<int32,GHashMap<int32, GVector<float>>>> ManorArray;
    ManorArray _CurrentShowLeagueManorLineArrary;
    MeshNode *_MeshNode1 = nullptr;
    RenderTexture *_RenderTexture1 = nullptr;
    MeshNode *_MeshNode2 = nullptr;
    GLProgram *_Shader2 = nullptr;
    GLProgramState *_State2 = nullptr;
    RenderTexture *_RenderTexture2 = nullptr;
    Texture2D *_TileTexture = nullptr;

    Vec4 _Resolution;
    Vec4 _TileInfo;

  public:
    void Ctor() override;
    void Init() override;
    void OnMessageListener() override;
    void OnExit() override;

    void RefreshMapPos(Vec2 pTilePos);
    void ShowManorline(bool pIsShow);
    GVector<float> GetLineArray(const GVector<float> &pLineData, float pSN);
    int32 GetLeagueIDIndex(int32 pLeagueID, bool pIsActivity = false);
    float GetSnIndex( GHashMap<int32, int32> pSnMap, float pSn, bool pIsActivity = false);
    void SetAllianceTerritoryColor(ManorArray pPointsArray, Node *pParent);
    void DrawRealAllianceLines(Node *pParent);
    void LoadShader();
    void ReloadShader();
    int32 GetCurMaxSn();

    void UpdateMapPos(EventCustom* pEvent);
    void Toggle3D(EventCustom* pEvent);
    void UpdateLodLevel(EventCustom* pEvent);
    void UpdateInfo(EventCustom* pEvent);
    void UpdateLeagueManorInstance(EventCustom* pEvent);
    void ResetLeagueManorInstance(EventCustom* pEvent);
    void UpdateNodeInfoSelect(EventCustom* pEvent);
    void UpdateRelationChange(EventCustom* pEvent);
    
    GTuple<GHashMap<int32, int32>, int32, int32> InitSnMap(ManorArray pPointsArray, bool pOnlyShowSelf = false);
    bool IsInselfOrAllyLeagueManor(Vec2 pTilePoint, bool pIsCheckScore = false);
    bool IsInSelfLeagueManor(int32 LeagueID, Rect _SelfManorRect);
    bool IsInSelfHoldManor(int32 LeagueID, Rect _SelfManorRect);
    bool IsFullInOtherLeagueManor(int32 LeagueID, Rect _SelfManorRect, Rect pSelfBuildRect);
};