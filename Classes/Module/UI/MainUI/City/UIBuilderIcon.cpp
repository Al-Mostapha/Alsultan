#include "UIBuilderIcon.h"

UIBuilderIcon *UIBuilderIcon::Create()
{
  auto l_Parent = Create("UiParts/MainUi/builderIcon.csb");
  return l_Parent;
}


void UIBuilderIcon::InitData(ETask p_BuildingTypeQueue){
  
}

ETask UIBuilderIcon::GetBuilderType(){
  return ETask::None;
}

void UIBuilderIcon::InitPanel(){}