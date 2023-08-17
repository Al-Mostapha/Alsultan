#include "WorldMap.Util.h"


WorldMapUtil *WorldMapUtil::Get()
{
  static WorldMapUtil * s_WorldMapUtil = nullptr;
  if (!s_WorldMapUtil)
  {
    s_WorldMapUtil = new WorldMapUtil();
    s_WorldMapUtil->Init();
  }
  return s_WorldMapUtil;
}



void WorldMapUtil::Init()
{
  _CastleModelCfg[8] = -140;
  _CastleModelCfg[9] = -140;
  _CastleModelCfg[10] = -140;
  _CastleModelCfg[11] = -140;
  _CastleModelCfg[12] = -140;
  _CastleModelCfg[13] = -70;
}



void WorldMapUtil::ResetConfig()
{
  // Do something
}

bool WorldMapUtil::IsLodOpen()
{
  return true;
}

RBorderLodScale WorldMapUtil::GetLodByScale(float p_Scale, RBorderLodScale p_Default){
  // local curLodConfig = config
  // while curLodConfig do
  //   if scale <= curLodConfig.scale then
  //     local nextLod = curLodConfig.nextLod
  //     if not nextLod or scale > nextLod.scale then
  //       break
  //     end
  //     curLodConfig = nextLod
  //   else
  //     if not curLodConfig.preLod then
  //       break
  //     end
  //     curLodConfig = curLodConfig.preLod
  //   end
  // end
  // return curLodConfig
  return p_Default;
}

bool WorldMapUtil::IsTroopPriority(){
  return true;
}