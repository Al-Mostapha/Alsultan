#include "AtlantisWar.Util.h"

AtlantisWarUtil* AtlantisWarUtil::Get(){
  static AtlantisWarUtil* s_AtlantisWarUtil = nullptr;
  if(s_AtlantisWarUtil == nullptr){
    s_AtlantisWarUtil = new AtlantisWarUtil();
  }
  return s_AtlantisWarUtil;
}

void AtlantisWarUtil::RemoveWorldMapAtlantisWarInfo(){
}