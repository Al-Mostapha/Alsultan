#include "AllianceStrongholdMine.Read.h"


AllianceStrongholdMineRead *AllianceStrongholdMineRead::Get(){
  static AllianceStrongholdMineRead *s_AllianceStrongholdMineRead = nullptr;
  if (s_AllianceStrongholdMineRead == nullptr){
    s_AllianceStrongholdMineRead = new AllianceStrongholdMineRead();
  }
  return s_AllianceStrongholdMineRead;
}
EResource AllianceStrongholdMineRead::GetMineOutputId(int32 pMineLevel){
  return EResource::Food;
}
int32 AllianceStrongholdMineRead::GetMineOutputNum(int32 pMineLevel){
  return 1000;
}

GString AllianceStrongholdMineRead::GetMineImage(int32 pMineLevel){
  return "map_build_stronghold_wood.png";
}
GString AllianceStrongholdMineRead::GetMineName(int32 pMineLevel){
  return "GetMineName";
}

GOpt<RStrongholdBuildConfig> AllianceStrongholdMineRead::GetGateClientCfg(int32 pMineID){
  RStrongholdBuildConfig rStrongholdBuildConfig;

  rStrongholdBuildConfig._ID = 5002;
  rStrongholdBuildConfig._Name = "stronghold_build_name_02";
  rStrongholdBuildConfig._Size = 2;
  rStrongholdBuildConfig._Image = "map_build_stronghold_01.png";
  rStrongholdBuildConfig._Effects = 1;
  rStrongholdBuildConfig._Leader = "icon_boss_01.png";
  rStrongholdBuildConfig._Bosstroops1 = "icon_xiaoguai_04.png";
  rStrongholdBuildConfig._Bosstroops2 = "icon_xiaoguai_02.png";
  rStrongholdBuildConfig._Bosstroops3 = "icon_xiaoguai_03.png";
  rStrongholdBuildConfig._IconLod = "lod_stronghold_tower.png";
  rStrongholdBuildConfig._ImageLod = "lod_build_stronghold_01.png";

  return rStrongholdBuildConfig;
}

uint32 AllianceStrongholdMineRead::GetGateLv(int32 pMineID){
  return 1;
}