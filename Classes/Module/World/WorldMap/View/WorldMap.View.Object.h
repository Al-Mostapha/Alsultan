#pragma once
#include "Module/World/WorldMap/WorldMap.Type.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

class IWorldMapComponent;
class WorldMapView;
class WorldMapCell;
class UIWorldMapBottomPoint;
class WorldMapComLod;
class IWorldMapInstance;
class WorldMapViewObject
{
  protected:
    GVector<IWorldMapComponent *> _Components;
  public:
    WorldMapComLod *_WorldMapComLod;
    void AddComponents(RViewClass p_Config, WorldMapView *p_Target);
    template <typename T>
    T *GetComponent(const GString &p_Name){
      return nullptr;
    }
    void CallComFuncInit();
    void CallComFuncOnMessageListener();
    void CallComFuncRelogin();
    void CallComFuncDoRequest();
    void CallComFuncDoClearData();

    // worldMapComInstanceNormal:hasShowTilesData
    bool HasShowTilesData(){ return false; }
    //worldMapComMoveline:delUnshowMoveLine()
    void DelUnshowMoveLine(){}
    //worldMapComLod:getCurLod()
    EWorldLodDef GetCurLod(){ return EWorldLodDef::LOD1; }
    //worldMapComSelect:removeSelectShowPanel(target, data)
    bool RemoveSelectShowPanel(){ return false; }
    //function worldMapComSelect:removeLodClickTip(...)
    void RemoveLodClickTip(){}
    //worldMapComTransfer:isTransferShow()
    bool IsTransferShow(){ return false; }
    //worldMapComTransfer:resetTransferView(mapView, forceRemove)
    void ResetTransferView(WorldMapCell *p_MapView = nullptr, bool p_ForceRemove = false){}

    // worldMapComMoveline:checkClickMoveLine(pos)
    bool CheckClickMoveLine(Vec2 p_Pos){ return false; }
    //worldMapComSelect:showLodClickTip(data)
    void ShowLodClickTip(Vec2 p_TilePos, Vec2 p_TouchEnd, int32 KingdomId){}
    //worldMapComTransfer:isTransferTouchIn()
    bool IsTransferTouchIn(){ return false; }
    // worldMapComTransfer:moveTransferView(touchmovePoint, mapView)
    void moveTransferView(Vec2 p_TouchMovePoint, WorldMapCell *p_MapView){}

    //worldMapComUI:getBottomPointNode(...)
    UIWorldMapBottomPoint *GetBottomPointNode(){ return nullptr; }
    //worldMapComNormal:getButtonMonsterSearch(...)
    ui::Button *GetButtonMonsterSearch(){ return nullptr; }
    //worldMapComInstanceNormal:getShowInstance(pos)
    IWorldMapInstance *GetShowInstance(Vec2 pPos){ return nullptr; }
    //worldMapComManorData:getInstanceMapFromManager()
    GHashMap<int32, IWorldMapInstance *> GetInstanceMapFromManager(){
      return GHashMap<int32, IWorldMapInstance *> ();
    }
};