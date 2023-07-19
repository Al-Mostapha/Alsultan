#include "WorldMap.Util.h"

WorldMapUtil *WorldMapUtil::Get()
{
  static WorldMapUtil * s_WorldMapUtil = new WorldMapUtil();
  return s_WorldMapUtil;
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