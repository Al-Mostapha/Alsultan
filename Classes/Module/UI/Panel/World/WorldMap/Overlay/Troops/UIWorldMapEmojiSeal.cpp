#include "UIWorldMapEmojiSeal.h"

UIWorldMapEmojiSeal *UIWorldMapEmojiSeal::Create()
{
  return Create("UiParts/Panel/World/WorldMap/worldMapEmojiSeal.csb");
}

void UIWorldMapEmojiSeal::Ctor(){
  UITouchBaseView::Ctor();
}

void UIWorldMapEmojiSeal::InitData(IWorldMapInstance *pInstance, int32 pMoveLineId){
  
}
