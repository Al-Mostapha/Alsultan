#pragma once
#include "BaseTypeDef.h"
#include "Include/IncludeEngine.h"
#include "Base/Containers/Pair.h"
#include "Base/Containers/HashMap.h"
#undef PlaySound

enum class EBuildingPlace;
enum class EBuilding;
enum class EBuildingIndex;
enum class EFactionType;
namespace GBase{
  template <typename T>
  T getChildByName(Node* p_Node, const char* p_name){
    if(!p_Node)
      return nullptr;
    if(p_Node->getName() == (std::string) p_name)
      return static_cast<T>(p_Node);

    for(auto child : p_Node->getChildren()){
      Node *node = getChildByName<Node *>(child, p_name);
      if(node)
        return static_cast<T>(node);
    }
      
    return nullptr;
  }

  void PlaySound(const char* p_SoundName, bool p_IsLoop = false, float p_delay = 0.0f);
  const char *getSoundPath(const char *p_SoundName);
  void SoraDFTarget(Node *p_node);
  EBuildingPlace DGetBuildingTypeByIndex(EBuildingIndex p_Building);
  bool IsTouchOnNode(Vec2 p_Point, Node *p_Node);

  float DGetAutoHeightLabel(ui::Text *p_Label, float p_Width = 0.0f);
  void DSetTextWidthHeight(ui::Text *p_Label, Size p_Size);
  void DSetTextWidthHeight(Label *p_Label, Size p_Size);
  void DShowMsgTip(const GString &p_Message, const GString &p_Icon = "");
  GPair<GString, GString> DGetBuildWarLv(const uint32 p_BuildingLvl);
  Scheduler *DCreateTimer(Node *p_Target, ccSchedulerFunc p_SchedulerFunc);
  bool DRemoveTimer(Node *p_Target, Scheduler *p_Scheduler);
  // this calld when player click on a building black smith
  void DGetEquip();
  void DShowNameOnTouchEven(Node * p_Node, GPair<GString, Vec2> p_Data);

  Node *DPopItemAward();
  void DPushItemAward(Node *);
  bool DCloseLoginView();
  void DSendMessage(const char *p_EventId, void *p_Data = nullptr);
  bool DIsGameGuide();
  EFactionType DGetFactionType();
  void DCloseSwitcherView();
  void DManagerRemoveTimer(Scheduler *P_Timer);
  void DAddMessage(Node *p_Node, const char *p_EventId, const std::function<void(EventCustom *)> &p_Callback);
  GString DConvertSecondToString(int p_Second);
};


