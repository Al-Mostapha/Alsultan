#include "UIWorldMapFaceToDistance.h"


UIWorldMapFaceToDistance *UIWorldMapFaceToDistance::Create()
{
  auto l_Panel = create();
  RBasePenelData l_Data;
  l_Data.FutureName = "worldMapFaceToDistance";
  l_Panel->InitPanel("UiParts/Parts/World/WorldMap/worldMapFaceToDistance.csb", &l_Data);
  return l_Panel;
}

void UIWorldMapFaceToDistance::AddSubViews(){
  addChild(m_Panel);
}

void UIWorldMapFaceToDistance::Ctor()
{
  UIBasePanel::Ctor();
  AddSubViews();
}
