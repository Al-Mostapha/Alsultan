#include "Building.Read.h"
#include "Building.Static.h"
#include "Module/Translation/Translate.h"

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
  return Translate::i18n(BuildingStatic::getBuildingSpecs(p_Building).StarDescribe.c_str());
}

GString BuildingRead::GetUpgradeDes(EBuilding p_Building){
  return Translate::i18n(BuildingStatic::getBuildingSpecs(p_Building).UpgradeBrief.c_str());
}

GString BuildingRead::GetStarDes(EBuilding p_Building){
  return Translate::i18n(BuildingStatic::getBuildingSpecs(p_Building).StarDescribe.c_str());
}

GString BuildingRead::GetWarDes(EBuilding p_Building){
  return Translate::i18n(BuildingStatic::getBuildingSpecs(p_Building).WarDescribe.c_str());
}

GString BuildingRead::GetDes(EBuilding p_Building){
  auto l_Des = Translate::i18n(BuildingStatic::getBuildingSpecs(p_Building).Describe.c_str());
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
  return Translate::i18n(BuildingStatic::getBuildingSpecs(p_Building).BuildingBrief.c_str());
}

GString BuildingRead::GetName(EBuilding p_Building){
  return Translate::i18n(BuildingStatic::getBuildingSpecs(p_Building).BuildingName.c_str());
}

GString BuildingRead::GetName(int32 p_Building){
  return "BuildingName";
}


GVector<RBuildingMoreInfoData> BuildingRead::GetMoreInfoData(EBuildingIndex p_Building){
  auto l_Data = GVector<RBuildingMoreInfoData>();
  auto l_OneData = RBuildingMoreInfoData();
  l_OneData._Value = "capacity";
  l_OneData._PlusValue = "15%";
  l_OneData._MoreInfoType = 4;
  l_OneData._MoreInfoType = 1;
  l_Data.emplace_back(l_OneData);
  l_Data.emplace_back(l_OneData);
  l_Data.emplace_back(l_OneData);
  l_Data.emplace_back(l_OneData);
  l_Data.emplace_back(l_OneData);
  l_Data.emplace_back(l_OneData);
  return l_Data;
}

GVector<RBuildingMoreInfoData> BuildingRead::GetUpgradeInfoData(EBuildingIndex p_Building, bool l_IsStar){
  auto l_Data = GVector<RBuildingMoreInfoData>();
  auto l_OneData = RBuildingMoreInfoData();
  l_OneData._Value = "capacity";
  l_OneData._PlusValue = "15%";
  l_OneData._MoreInfoType = 4;
  l_OneData._MoreInfoType = 1;
  l_Data.emplace_back(l_OneData);
  l_Data.emplace_back(l_OneData);
  l_Data.emplace_back(l_OneData);
  l_Data.emplace_back(l_OneData);
  l_Data.emplace_back(l_OneData);
  l_Data.emplace_back(l_OneData);
  return l_Data;
}