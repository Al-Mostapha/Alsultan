#pragma once
#include "IWorldMap.Com.h"
#include "Module/World/Kingdom/Kingdom.Type.h"


class WorldMapComNormalFog : public IWorldMapComponent
{
  float _TiledBgX = 0;
  float _TiledBgY = 0;
  Sprite *_TiledBg = nullptr;
  GOpt<RFogData> _FogData;
  int32 _MyKindomID = 0;
  GLProgram *_Program = nullptr;
  GLProgramState *_State = nullptr;
  Vec4 _Resolution;
  Vec4 _TileInfo;

public:
  void Init() override;
  void OnMessageListener() override;
  void Ctor() override ;

  void RefreshWarFog();
  void InitWarFog();
  void RefreshMapPos(Vec2 p_Pos);
  void ReloadTmxFogShader();

  void Toggle3D(EventCustom *p_Event);
  void UpdateMapPos(EventCustom *p_Event);
  void UpdateCellSwap(EventCustom *p_Event);
  void UpdateScaleZoom(EventCustom *p_Event);
  void UnLockWarFog(EventCustom *p_Event);
  void RefreshOtherKingdominfo(EventCustom *p_Event);

};