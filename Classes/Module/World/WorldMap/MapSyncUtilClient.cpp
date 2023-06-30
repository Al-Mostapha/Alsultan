#include "MapSyncUtilClient.h"

MapSyncUtilClient *MapSyncUtilClient::Get(){
  static auto l_Inst = new MapSyncUtilClient();
  return l_Inst;
}