#include "Building.Read.h"
#include "Building.Static.h"

BuildingRead* BuildingRead::Get()
{
  static BuildingRead* s_BuildingRead = new BuildingRead();
  return s_BuildingRead;
}

ETask BuildingRead::GetQueueType(EBuilding p_Building){
  return ETask::None;
}

GString BuildingRead::GetIcon(EBuilding p_Building){
  return BuildingStatic::getBuildingSpecs(p_Building).BuildingIcon;
}

GString BuildingRead::GetUpgradeStarDes(EBuilding p_Building){
  return Translate::i18n(BuildingStatic::getBuildingSpecs(p_Building).StarDescribe);
}

GString BuildingRead::GetUpgradeDes(EBuilding p_Building){
  return Translate::i18n(BuildingStatic::getBuildingSpecs(p_Building).UpgradeBrief);
}

GString BuildingRead::GetStarDes(EBuilding p_Building){
  return Translate::i18n(BuildingStatic::getBuildingSpecs(p_Building).StarDescribe);
}

GString BuildingRead::GetWarDes(EBuilding p_Building){
  return Translate::i18n(BuildingStatic::getBuildingSpecs(p_Building).WarDescribe);
}

GString BuildingRead::GetDes(EBuilding p_Building){
  auto l_Des = Translate::i18n(BuildingStatic::getBuildingSpecs(p_Building).Describe);
  if(p_Building == EBuilding::Embassy){
    if(GBase::DCheckIsOpenBuildStar()){
      l_Des += "\n" + Translate::i18n("common_text_4301");
    }
    if(GBase::SoraDIsBraveOpen()){
      l_Des += Translate::i18n("common_text_4302");
    }
  }
  return l_Des;
}

GString BuildingRead::GetBrief(EBuilding p_Building){
  return Translate::i18n(BuildingStatic::getBuildingSpecs(p_Building).BuildingBrief);
}

GString BuildingRead::GetName(EBuilding p_Building){
  return Translate::i18n(BuildingStatic::getBuildingSpecs(p_Building).BuildingName);
}

GString BuildingRead::GetName(int32 p_Building){
  return "BuildingName";
}
