#pragma once 
#include "IWorldMap.Com.h"
#include "IInstanceBuilder.h"
#include "Module/World/WorldMap/WorldMap.Enum.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#define MAX_SHOWINSTANCE 10
#define MAX_DELINSTANCE 20
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#define MAX_SHOWINSTANCE 4
#define MAX_DELINSTANCE 6
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#define MAX_SHOWINSTANCE 4
#define MAX_DELINSTANCE 6
#endif

struct RNewInstanceData{};

class WorldMapComInstance : public IWorldMapComponent{

  int32 _MaxInstanceDel = MAX_DELINSTANCE;
  int32 _MaxInstanceShow = MAX_SHOWINSTANCE;
  bool _LodPreview = false;
  bool _LodFocus = false;
  IInstanceBuilder *_Builder = nullptr;
  EWorldLodDef _LodView = EWorldLodDef::LOD1;
  public:
  void Init() override;
  void OnMessageListener() override;
  void Ctor();

  void Toggle3D(EventCustom *p_Event);
  void UpdateRelationChange(EventCustom *p_Event);
  void CheckAdddMapInstace(const RNewInstanceData &pData);
  void ServerMessageAddMapInstace(EventCustom *p_Event);
  

  void UpdateInfo(EventCustom *p_Event);
  void UpdateViewPieceIds(EventCustom *p_Event);
  void UpdateLodChange(EventCustom *p_Event);

};