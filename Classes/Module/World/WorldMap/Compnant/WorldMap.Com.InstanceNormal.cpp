#include "WorldMap.Com.InstanceNormal.h"
#include "Module/World/WorldMap/View/WorldMap.View.h"
#include "Module/World/WorldMap/Instance/WorldInstance.Builder.Normal.h"


void WorldMapComInstanceNormal::Ctor(){
  _Target->_Builder = WorldInstanceBuilderNormal::Create();
}

void WorldMapComInstanceNormal::Init(){

}

void WorldMapComInstanceNormal::OnMessageListener(){

} 