#pragma once
#include "BaseTypeDef.h"
#include "Include/IncludeEngine.h"
#include "Base/Containers/Pair.h"
#include "Base/Containers/HashMap.h"
#include "Base/Utils/String.Util.h"
#undef PlaySound


enum class EBuildingPlace;
enum class EBuilding;
enum class EBuildingIndex;
enum class EFactionType;
enum class EMsgBoxCallBack;
namespace GBase{
  template <typename T>
  T GetChildByName(Node* p_Node, const char* p_name){
    if(!p_Node)
      return nullptr;
    if(p_Node->getName() == (std::string) p_name)
      return static_cast<T>(p_Node);

    for(auto child : p_Node->getChildren()){
      auto l_node = GetChildByName<Node *>(child, p_name);
      if(l_node)
        return static_cast<T>(l_node);
    }
      
    return nullptr;
  }

  template <class T>
  T *DGetExtendChildFromCCSByName(
    Node * p_Parent, const char *p_Name,
    bool p_NodeFitOffset = false, float p_Height = 0.0f){
    auto l_child = GetChildByName<Node *>(p_Parent, p_Name);
    if(!l_child)
      return nullptr;
    auto l_NameTabel = GStringUtils::Split(GString(p_Name), GString("_"));
    for(auto i = 0; i < (int32)l_NameTabel.size(); i++){
      auto l_OneName = l_NameTabel.at(i);
      if(l_OneName == "CCS"){
        auto l_ClassName = l_NameTabel.at(i + 1);
        auto l_Size = l_child->getContentSize();
        //if nodeFitOffset then
        //  SoraDDeviceFitOffset(childView, {futureName = className}, height)
        //end
        T *l_Inst = T::Create();
        l_Inst->InitPanel();
        return l_Inst;
      }
    }
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
  RenderTexture *DCreateScreenShot(bool p_IsBlur = false);
  GString DGetDefaultLanguage();
  template<typename T>
  T DConfigGet(const char *p_Key, bool p_ByUid = false, bool p_ByLTID = false){
    return T();
  }
  template<typename T>
  void DConfigSet(const char *p_Key, T p_Val ,bool p_ByUid = false, bool p_ByLTID = false){ }
  bool DFIsRA();
  void DNewChapterOpen(bool p_IsFromLogin = false);
  void DShowCastleUnlockView();
  uint32 DGetCastleLv();
  void DShowCastleUPView();
  void DShowRateStarView();
  class UIPanelBase *DCurrentTopPanelFromManager();
  //showMsg, yesBtnTitle, noBtnTitle, callBackHandle, data, align, noSound
  void DShowMsgBox(
    GString p_Msg, GString p_YesBtnTitle, GString p_NoBtnTitle,
    std::function<void(EMsgBoxCallBack)> p_CallBack, void *p_Data = nullptr,
    int p_Align = 0, bool p_NoSound = false);
  bool DIsBrave8Level();

};


