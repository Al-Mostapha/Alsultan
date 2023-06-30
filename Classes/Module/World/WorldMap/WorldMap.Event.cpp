#include "WorldMap.Event.h"

WorldMapEvent *WorldMapEvent::Get(){
  static WorldMapEvent *l_WorldMapEvent = nullptr;
  if(l_WorldMapEvent == nullptr){
    l_WorldMapEvent = new WorldMapEvent();
  }
  return l_WorldMapEvent;
}