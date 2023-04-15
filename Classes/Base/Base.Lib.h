#pragma once
#include "Base/Containers/HashMap.h"
#include "Base/Containers/Pair.h"
#include "Base/Utils/String.Util.h"
#include "BaseTypeDef.h"
#include "Include/IncludeEngine.h"
#include "Common/Timer.Mgr.h"
#include "Type/EventArg/Lord.EvtArg.h"
#include "Module/World/WorldMap/WorldMap.Enum.h"
#include "Global/Global.Enum.h"
#include "Base/DateTime.h"

#undef PlaySound

enum class EBuildingPlace;
enum class EBuilding;
enum class EBuildingIndex;
enum class EFactionType;
enum class EMsgBoxCallBack;
class UICommonPromptBox;
struct RViewOtherData; 
class UIBaseView;



namespace GBase {

struct RCreateLabelParm{
  GString Txt;
  GString FontName = "";
  float fontSize;
  Size Dimensions = Size::ZERO;
  TextHAlignment hAlignment = TextHAlignment::LEFT;
  TextVAlignment vAlignment = TextVAlignment::TOP;
  Color4B Color = Color4B::WHITE;
  float x = 0;
  float y = 0;
};

template <typename T> T GetChildByName(Node* p_Node, const char* p_name) {
  if (!p_Node) return nullptr;
  if (p_Node->getName() == (std::string)p_name) return dynamic_cast<T>(p_Node);

  for (auto child : p_Node->getChildren()) {
    auto l_node = GetChildByName<T>(child, p_name);
    if (l_node) return l_node;
  }

  return nullptr;
}

template <class T> T* DGetExtendChildFromCCSByName(Node* p_Parent, const char* p_Name, bool p_NodeFitOffset = false, float p_Height = 0.0f) {
  auto l_child = GetChildByName<Node *>(p_Parent, p_Name);
  if (!l_child) return nullptr;
  auto l_NameTabel = GStringUtils::Split(GString(p_Name), GString("_"));
  for (auto i = 0; i < (int32)l_NameTabel.size(); i++) {
    auto l_OneName = l_NameTabel.at(i);
    if (l_OneName == "CCS") {
      auto l_ClassName = l_NameTabel.at(i + 1);
      auto l_Size = l_child->getContentSize();
      // if nodeFitOffset then
      //  SoraDDeviceFitOffset(childView, {futureName = className}, height)
      // end
      T* l_Inst = T::Create();
      return l_Inst;
    }
  }
  return nullptr;
}
void PlaySound();
void PlaySound(const char* p_SoundName, bool p_IsLoop = false, float p_delay = 0.0f);
void PlaySound(const char* p_SoundName, int32 p_index, float p_delay = 0.0f, bool p_Tag3d = false);
const char* getSoundPath(const char* p_SoundName);
void SoraDFTarget(Node* p_node);
EBuildingPlace DGetBuildingTypeByIndex(EBuildingIndex p_Building);
bool IsTouchOnNode(Vec2 p_Point, Node* p_Node);

float DGetAutoHeightLabel(ui::Text* p_Label, float p_Width = 0.0f);
float DGetAutoHeightLabelNew(ui::Text* p_Label, float p_Width = 0.0f, bool l_IsHtml = false);
void DSetTextWidthHeight(ui::Text* p_Label, Size p_Size);
void DSetTextWidthHeight(Label* p_Label, Size p_Size);
void DShowMsgTip(const GString& p_Message, const GString& p_Icon = "",  Node *p_Target = nullptr);

GPair<GString, GString> DGetBuildWarLv(const uint32 p_BuildingLvl);
GPair<int32, int32> DGetBuildStarLv(const EBuilding p_Building);

Scheduler* DCreateTimer(Node* p_Target, ccSchedulerFunc p_SchedulerFunc, bool p_Priority = false);
Scheduler* DCreateTimerEx(Node* p_Target, ccSchedulerFunc p_SchedulerFunc, uint32 p_Time = 0);
bool DRemoveTimer(Node* p_Target, Scheduler* p_Scheduler);
// this calld when player click on a building black smith
void DGetEquip();
void DShowNameOnTouchEven(Node* p_Node, GPair<GString, Vec2> p_Data);

Node* DPopItemAward();
void DPushItemAward(Node*);
bool DCloseLoginView();

void DSendMessage(const char* p_EventId, void* p_Data = nullptr);
bool DIsGameGuide();
EFactionType DGetFactionType();
void DCloseSwitcherView();
void DManagerRemoveTimer(Scheduler* P_Timer);

void DAddMessage(Node* p_Node, const char* p_EventId, const std::function<void(EventCustom*)>& p_Callback);

GString DConvertSecondToString(int p_Second);
RenderTexture* DCreateScreenShot(bool p_IsBlur = false);
GString DGetDefaultLanguage();
void DSetDefaultLanguage(bool p_IsNeedUpdate = false, bool p_IsNeedRefresh = false);
template <typename T> T DConfigGet(const char* p_Key, bool p_ByUid = false, bool p_ByLTID = false) { return T(); }
template <typename T> void DConfigSet(const char* p_Key, T p_Val, bool p_ByUid = false, bool p_ByLTID = false) {}
bool DFIsRA();
float DFSign(float p_Num);
void DNewChapterOpen(bool p_IsFromLogin = false);
void DShowCastleUnlockView();
uint32 DGetCastleLv();
void DShowCastleUPView();
void DShowRateStarView();
class UIPanelBase* DCurrentTopPanelFromManager();
// showMsg, yesBtnTitle, noBtnTitle, callBackHandle, data, align, noSound
UICommonPromptBox* DShowMsgBox(GString p_Msg,
                              GString p_YesBtnTitle,
                              GString p_NoBtnTitle,
                              std::function<void(EMsgBoxCallBack)> p_CallBack,
                              void* p_Data = nullptr,
                              int p_Align = 0,
                              bool p_NoSound = false);
bool DIsBrave8Level();
void DMixtureGLONE(Node* p_Node);
void DRemoveMessageByTarget(Node* p_Node);
void DRemoveMessageFromTargetByName(Node* p_Node, const char* p_EventId);

void DCloseLoading(Node* p_Parent, const char* p_Mark = "", bool p_All = false);

bool DPostCheckMaintain(int32 p_KingdomId = 0, GTime p_Time = GDateTime::Now());
GString DFValueSuit(const GString& p_Value, const GString& p_Sign = "+");
GString GetCCSPath(const char* p_CCSName);

void DClearItemAwards();
void DShowSwitcherView(RViewOtherData p_Data);
void DShowPowerChange(RUpdatePowerEvtArg p_Arg, bool p_IsOnlyGet = false);
void DShowEXPChange(int32 p_Exp);
void DDelayCallOnce(GString p_UniqueKey, ccSchedulerFunc p_Func, float p_Time = 0.001, bool p_CheckHandle = true);
UIBaseView *DSearchPanelFromManagerByName(const char* p_Name);
void DStartLoginServerAndCheckVersion();
void DShowLoginView(EScene p_Scene = EScene::City, EKingdomClassType p_KingdomClassType = EKingdomClassType::Normal);
UICommonPromptBox *DShowLoginFailBox(const char *p_FailType, GString p_ShowMsg, bool p_HaveCancelBtn, std::function<void()> p_CallBack);
bool DCheckIsOpenBuildStar();
bool SoraDIsBraveOpen();

void DShowLordUPView();
UIBaseView *DCurrentSceneShowView(const char *p_NameView = "");
Node *DCreateCSBNode(const char *p_CSBName);
Label *DCreateLabel(RCreateLabelParm p_Parm);

void DFadeInOut(Node *p_Node/**Fade paramters*/);


};  // namespace GBase
