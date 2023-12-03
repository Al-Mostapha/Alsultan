#pragma once
#include "Base/Type/XVector.h"
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
#include "Type/XOptional.h"


#undef PlaySound

enum class EBuildingPlace;
enum class EBuilding;
enum class EBuildingIndex;
enum class EFactionType;
enum class EMsgBoxCallBack;
struct RViewOtherData; 
class UIBaseView;
class UIBasePanel;



namespace GBase {

struct RCreateLabelParm{
  GString _Text;
  GString FontName = "";
  float _FontSize;
  Size Dimensions = Size::ZERO;
  TextHAlignment hAlignment = TextHAlignment::LEFT;
  TextVAlignment vAlignment = TextVAlignment::TOP;
  Color4B Color = Color4B::WHITE;
  float x = 0;
  float y = 0;
  EUILabelType _UILabelType = EUILabelType::BMF;
};

int32 PlaySound();
int32 PlaySound(const char* p_SoundName, bool p_IsLoop = false, float p_delay = 0.0f);
int32 PlaySound(const char* p_SoundName,  const GString &pIndex, float p_delay = 0.0f, bool p_Tag3d = false);
int32 PlaySound(const char* p_SoundName,  int32 pIndex, float p_delay = 0.0f, bool p_Tag3d = false);
const char* getSoundPath(const char* p_SoundName);
void DFTarget(Node* p_node);
bool IsTouchOnNode(Vec2 p_Point, Node* p_Node);

float DGetAutoHeightLabel(ui::Text* p_Label, float p_Width = 0.0f);

float DGetAutoHeightLabelNew(ui::Text* p_Label, float p_Width = 0.0f, bool l_IsHtml = false);
void DSetTextWidthHeight(ui::Text* p_Label, Size p_Size);
void DSetTextWidthHeight(Label* p_Label, Size p_Size);
void DShowMsgTip(const GString& p_Message, const GString& p_Icon = "",  Node *p_Target = nullptr);



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


void DAddMessage(Node* p_Node, const char* p_EventId, const std::function<void(EventCustom*)>& p_Callback);

GString DConvertSecondToString(int p_Second);
RenderTexture* DCreateScreenShot(bool p_IsBlur = false);
GString DGetDefaultLanguage();
void DSetDefaultLanguage(bool p_IsNeedUpdate = false, bool p_IsNeedRefresh = false);
template <typename T> GOpt<T> DConfigGet(const char* p_Key, bool p_ByUid = false, bool p_ByLTID = false) { return {}; }
template <typename T> void DConfigSet(const char* p_Key, T p_Val, bool p_ByUid = false, bool p_ByLTID = false) {}
bool DFIsRA();
float DFSign(float p_Num);
void DNewChapterOpen(bool p_IsFromLogin = false);
void DShowCastleUnlockView();
uint32 DGetCastleLv();
uint32 DGetCastleWarLv();
void DShowCastleUPView();
void DShowRateStarView();
class UIPanelBase* DCurrentTopPanelFromManager();


void DMixtureGLONE(Sprite* p_Node);
void DMixtureGLONEByParent(Node* p_Node);
void DRemoveMessageByTarget(Node* p_Node);
void DRemoveMessageFromTargetByName(Node* p_Node, const char* p_EventId);

void DCloseLoading(Node* p_Parent = nullptr, const char* p_Mark = "", bool p_All = false);
Node *DGetLoading(Node* p_Parent = nullptr);

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
bool DCheckIsOpenBuildStar();
bool SoraDIsBraveOpen();

void DShowLordUPView();
UIBaseView *DCurrentSceneShowView(const char *p_NameView = "");
Node *DCreateCSBNode(const char *p_CSBName);
Label *DCreateLabel(RCreateLabelParm p_Parm);

void DFadeInOut(Node *p_Node/**Fade paramters*/);

struct RShowFixWindowOther{
  bool _IsHtml = false;
  bool _NoEmpty = false;
  bool _HideBtn = false;
  bool _ShowArrow = false;
  bool _AutoHeight = false;
  int32 _Height = 0;
};

void DShowFixWindow(GString pTitle, GVector<GString> pMsgtbl, Color3B pColor = {}, RShowFixWindowOther pOther = {});

};  // namespace GBase

