#include "City.Lib.h"
#include "Include/IncludeEngine.h"

CityLib *CityLib::Get(){
  static CityLib *l_Instance = new CityLib();
  return l_Instance;
}


void CityLib::ShowTintOnce(Node *p_Node){
  if(!p_Node)
    return;
  p_Node->stopActionByTag(77);
  p_Node->setColor(Color3B(100, 100, 100));
  auto l_ActionTint = TintBy::create(0.2,  0.6078431372549019*255, 0.6078431372549019*255, 0.6078431372549019*255);
  l_ActionTint->setTag(77);
  p_Node->runAction(l_ActionTint);
}

void CityLib::PlaySound(const char *p_Sound, EBuilding p_Building, EBuildingActionTag p_Tag){

}