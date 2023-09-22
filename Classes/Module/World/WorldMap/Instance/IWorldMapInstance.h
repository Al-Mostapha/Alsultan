#pragma once
#include "WorldMapInstance.Lod.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/World/WorldMap/WorldMap.Enum.h"
#include "Module/World/WorldMap/Instance/WorldInstance.Enum.h"
#include "Module/CityResource/Resource.Enum.h"
#include "WorldInstance.Enum.h"
#include "WorldMapBuildEmoji.h"
#include "WorldMapBuildFireEffect.h"

class WorldMapCell;

struct RButtonTypeArray{
  EWorldMapTipButtonType _ButtonType;
  bool _IsButtonEnabled = true;
  GString _MsgTipsKey = "";
  struct {
    EWorldMapTipButtonType _DispatchType;
  } _Extra;
};

class IWorldMapInstance : public WorldMapInstanceLod, public WorldMapBuildEmoji, public WorldMapBuildFireEffect
{
public:
  GString _LeagueName;
  GString _PlayerName;
  GString _LeagueAbbrName;
  int32 _PlayerID;
  int32 _LeagueID;
  int32 _KingdomID;
  int32 _LeagueFlag;
  EMapObjTypeDef _InstanceType;
  EResource _ResourceClassID;
  int32 _InstanceLevel;
  Vec2 _TilePoint;
  Size _Size;
  Node *_TipsNode;


  template<typename T>
  static IWorldMapInstance *Create()
  { 
      auto lInstance = T::create(); 
      lInstance->Ctor();
      return lInstance;
  }

  
  virtual GTuple<UIBasePanel *, bool, Node*> OnClickInstance(Node *pNode);
  virtual GTuple<UIBasePanel *, bool, Node*> OnShowWorldMapTip(Node *pNode);
  virtual void PlayClickSound() = 0;
  virtual void AddCacheBefore() = 0;
  virtual GVector<RButtonTypeArray> GetInstanceOp(bool pIsSelfKingdom, bool pIsInWar){
    return GVector<RButtonTypeArray>();
  };

  void SetInstanceType(EMapObjTypeDef pInstanceType);
  void SetWorldMapCell(WorldMapCell *pWorldMapCell);
  void SetKingdomID(int32 pKingdomID);
  void SetMapTypeClass(EKingdomClassType pMapClassType);
  void SetInstanceID(int32 pInstanceID);
  void SetTilesArray(GVector<Vec2> pTilesArray);
  void SetTilePoint(Vec2 pTilePoint);
  void SetHoldInstace(int32 pHoldInstace);
  void ShowWarningTip(const GString &pTipInfo, const std::function<void()> &pCallback = nullptr, float pDelay = 0.f);

  virtual void SetBatchNodeGroupID(EGrouID pBatchNodeGroupID);
  
  virtual void Ctor(){}
  virtual void InitInstanceData(void *pObjData){}

  virtual void OnMessageListener(){}
  virtual void OnEnterOther(){}
  virtual GString GetFavoriteName(){ return ""; }

  virtual void InitInstanceData(int32 pClass, void *pObjData, int32 pObjID = 0){}
  //angle name e, w, n, s, wn ...etc
  virtual void InitInstanceData(int32 pClass, const GString &pAngleName, bool pIsFlipX, void *pObjData){}
  virtual void UpdateAllianceCounterAtkEffect(EventCustom *pEvent);

  GTuple<bool, int32> CheckHasArmy();
};