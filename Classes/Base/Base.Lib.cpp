#include "Base.Lib.h"
#include "Base/Common/Common.Enum.h"
#include "Base/Common/Common.Teml.h"
#include "AudioEngine.h"
#include "Global/Global.Enum.h"
#include "Include/IncludeEngine.h"
#include "Include/IncludeGlobal.h"
#include "Module/Building/Building.Enum.h"
#include "Module/UI/Common/Message/UIMsgTip.h"
#include "Module/UI/MainUI/UISwitcher.h"
#include "Scene/Login/LoginScene.h"


typedef std::function<void(EventCustom*)> FMsgCallBack;
GHashMap<GString, GQueue<FMsgCallBack>> _tMsgvectorList;
GHashMap<Node*, GHashMap<GString, bool>> _tMsgObjListionerList;

namespace GBase {

int32 PlaySound() {
    return -1;
}
int32 PlaySound(const char* p_SoundName, bool p_IsLoop, float p_delay) {
  Sequence::create(DelayTime::create(p_delay), CallFunc::create([=]() { 
    //AudioEngine::play2d(p_SoundName, p_IsLoop); 
    }), nullptr);
    return -1;
}

int32 PlaySound(const char* p_SoundName, int32 p_index, float p_delay, bool p_Tag3d) {
  return -1;
}

const char* getSoundPath(const char* p_SoundName) { return StringUtils::format("Music/%s", p_SoundName).c_str(); }

void DFTarget(Node* p_node) {}

EBuildingPlace DGetBuildingTypeByIndex(EBuildingIndex p_Building) { return EBuildingPlace::Outer; }

bool IsTouchOnNode(Vec2 p_Point, Node* p_Node) {
  bool l_IsOnNode = false;
  if (!p_Node) return l_IsOnNode;
  auto l_Parent = p_Node->getParent();
  auto l_BoundingBox = p_Node->getBoundingBox();
  auto l_PosTouchToNode = l_Parent->convertToNodeSpace(p_Point);
  return l_BoundingBox.containsPoint(l_PosTouchToNode);
}

float DGetAutoHeightLabel(ui::Text* p_Label, float p_Width) {
  if (!p_Label) return 0;
  if (p_Width == 0) p_Width = p_Label->getContentSize().width;
  p_Label->ignoreContentAdaptWithSize(false);
  p_Label->setTextAreaSize(Size(p_Width, 0));
  auto l_Height = p_Label->getVirtualRendererSize().height;
  p_Label->setContentSize(Size(p_Width, l_Height));
  return l_Height;
}

float DGetAutoHeightLabelNew(ui::Text* p_Label, float p_Width, bool l_IsHtml){
  // if width == nil then
  //   width = label:getContentSize().width
  // end
  if(p_Width == 0)
    p_Width = p_Label->getContentSize().width;
  // local txtContentInfo = {
  //   fontName = "",
  //   fontSize = label:getFontSize(),
  //   fontAlignmentH = label:getTextHorizontalAlignment(),
  //   fontAlignmentV = label:getTextVerticalAlignment(),
  //   fontDimensions = cc.size(width, 0),
  //   isHtml = isHtml
  // }
  // local measureSize = cc.Device:measureText(label:getString(), txtContentInfo)
  return DGetAutoHeightLabel(p_Label, p_Width);
  // label:setTextAreaSize(measureSize)
  // return measureSize.height
}

void DSetTextWidthHeight(ui::Text* p_Text, Size p_Size) {
  if (!p_Text) p_Text->ignoreContentAdaptWithSize(false);
  p_Text->setTextAreaSize(p_Size);
  p_Text->setContentSize(p_Size);
}

void DSetTextWidthHeight(Label* p_Label, Size p_Size) {
  if (!p_Label) return;
  p_Label->setOverflow(Label::Overflow::SHRINK);
  p_Label->setDimensions(p_Size.width, p_Size.height);
}

void DShowMsgTip(const GString& p_Message, const GString& p_Icon, Node *p_Target) {
  if (!GBase::GLobalSettings::ShowMsgTip) return;
  Sprite* l_IconSprite = nullptr;
  if (p_Icon != "") {
    l_IconSprite = BaseCreate::CreateSprite(p_Icon.c_str());
    l_IconSprite->setScale(100 / l_IconSprite->getContentSize().width);
  }
  auto l_Panel = UIMsgTip::Create();
  l_Panel->InitPanel();
  l_Panel->ShowTip(p_Message, l_IconSprite);
}

GPair<GString, GString> DGetBuildWarLv(const uint32 p_BuildingLvl) { return GPair<GString, GString>::Make("war_lv_1", "war_lv_2"); }
GPair<int32, int32> DGetBuildStarLv(const EBuilding p_Building) { return GPair<int32, int32>::Make(0, 0); }
void DGetEquip() {}
bool DRemoveTimer(Node* p_Target, Scheduler* p_Scheduler) { return false; }

void DShowNameOnTouchEven(Node* p_Node, GPair<GString, Vec2> p_Data) {}
Node* DPopItemAward() { return nullptr; }
void DPushItemAward(Node*) {}

bool DCloseLoginView() {
  auto l_CurrentScene = Director::getInstance()->getRunningScene();
  if (!l_CurrentScene) return false;
  auto l_MainScene = dynamic_cast<LoginScene*>(l_CurrentScene);
  if (!l_MainScene) return false;
  return l_MainScene->RemoveLoginView();
}

void DSendMessage(const char* p_EventId, void* p_Data) {
  // if content and content.clientData then
  //   data.clientData = content.clientData
  // end
  auto l_listioner = _tMsgvectorList.find(p_EventId);
  if (l_listioner == _tMsgvectorList.end()) return;
  auto l_list = l_listioner->second;
  while (!l_list.empty()) {
    auto l_CallBack = l_list.front();
    EventCustom l_Event(p_EventId);
    l_Event.setUserData(p_Data);
    l_CallBack(&l_Event);
    l_list.pop();
  }
}
bool DIsGameGuide() { return false; }

EFactionType DGetFactionType() { return EFactionType::Normal; }

void DCloseSwitcherView() {
  auto l_Scene = Director::getInstance()->getRunningScene();
  if (!l_Scene) return;
  auto l_Switcher = l_Scene->getChildByName("switcherView");
  if (!l_Switcher) l_Switcher = l_Scene->getChildByName("switcherView_fa");
  if (!l_Switcher) return;
  auto l_SwitcherView = dynamic_cast<UISwitcher*>(l_Switcher);
  if (!l_SwitcherView) return;
  l_SwitcherView->CloseSwitcher();
}

void DAddMessage(Node* p_Node, const char* p_EventId, const std::function<void(EventCustom*)>& p_Callback) {
  if (!p_Callback) return;
  if (!_tMsgObjListionerList.Contains(p_Node)) _tMsgObjListionerList[p_Node] = GHashMap<GString, bool>();
  _tMsgObjListionerList[p_Node][p_EventId] = true;
  if (!_tMsgvectorList.Contains(p_EventId)) _tMsgvectorList[p_EventId] = GQueue<FMsgCallBack>();
  _tMsgvectorList[p_EventId].push(p_Callback);
}

GString DConvertSecondToString(int p_Second) { return ""; }
RenderTexture* DCreateScreenShot(bool p_IsBlur) {
  auto l_Width = GDisplay::Get()->size().width;
  auto l_Height = GDisplay::Get()->size().height;
  // TODO: 35056
  auto l_RenderTexture = RenderTexture::create((int32)l_Width, (int32)l_Height, Texture2D::PixelFormat::RGBA8888 /*,35056*/);
  // renderTexture:setKeepMatrix(true)
  l_RenderTexture->begin();
  l_RenderTexture->setKeepMatrix(true);
  // renderTexture:beginWithClear(0, 0, 0, 0, 1, 0)
  l_RenderTexture->beginWithClear(0, 0, 0, 0, 1, 0);
  // cc.Director:getInstance():getRunningScene():visit()
  Director::getInstance()->getRunningScene()->visit();
  // renderTexture:endToLua()
  l_RenderTexture->end();
  // renderTexture:setPosition(cc.p(display.cx, display.cy))
  l_RenderTexture->setPosition(Vec2(GDisplay::Get()->cx, GDisplay::Get()->cy));
  // local renderSprite = renderTexture:getSprite()
  auto l_RenderSprite = l_RenderTexture->getSprite();
  // if isBlur then

  // end
  if (p_IsBlur) {
    //   local program = cc.GLProgram:createWithFilenames("Shaders/blur.vsh", "Shaders/blur.fsh")
    //   local state = cc.GLProgramState:create(program)
    //   state:setUniformVec2("resolution", {
    //     x = display.size.width,
    //     y = display.size.height
    //   })
    //   state:setUniformFloat("blurRadius", 20)
    //   state:setUniformFloat("sampleNum", 10)
    //   renderSprite:setGLProgramState(state)
    // auto l_State = GLProgramState::create(l_Program);
    // l_State->setUniformVec2("resolution", Vec2(GDisplay::Get()->size().width, GDisplay::Get()->size().height));
    // l_State->setUniformFloat("blurRadius", 20);
    // l_State->setUniformFloat("sampleNum", 10);
    // l_RenderSprite->setGLProgramState(l_State);
  }
  // return renderTexture
  return l_RenderTexture;
}

GString DGetDefaultLanguage() { return "en"; }
void DSetDefaultLanguage(bool p_IsNeedUpdate, bool p_IsNeedRefresh) {}

// RA is RightAlignment
bool DFIsRA() { return true; }

float DFSign(float p_Num){
  if(DGetLayoutAlignment() == ELayoutAlignment::Right)
    return p_Num;
  else 
    return -p_Num;
}

void DNewChapterOpen(bool p_IsFromLogin) {}

void DShowCastleUnlockView() {}
uint32 DGetCastleLv() { return 0; }

void DShowCastleUPView() {}
void DShowRateStarView() {}
class UIPanelBase* DCurrentTopPanelFromManager() {
  return nullptr;
}


bool DIsBrave8Level() { return false; }

void DMixtureGLONE(Sprite* p_Node) {
  if(!p_Node) return;
  if(p_Node->isOpacityModifyRGB()){
    p_Node->setBlendFunc({GL_ONE, GL_ONE});
  }else{
    p_Node->setBlendFunc({GL_SRC_ALPHA, GL_ONE});
  }
}

void DRemoveMessageByTarget(Node* p_Node) {}

void DRemoveMessageFromTargetByName(Node* p_Node, const char* p_EventId) {}

void DCloseLoading(Node* p_Parent, const char* p_Mark, bool p_All) {
  if (!p_Parent) p_Parent = Director::getInstance()->getRunningScene();
  auto l_PreLoading = p_Parent->getChildByName("commonLoading");
  if (l_PreLoading)
    l_PreLoading->removeFromParent();
  else if (p_All) {
    l_PreLoading = GBase::DGetChildByName<Node*>(p_Parent, "commonLoading");
    if (l_PreLoading) l_PreLoading->removeFromParent();
  }
}

Node *DGetLoading(Node* p_Parent){
  if(!p_Parent) p_Parent = Director::getInstance()->getRunningScene();
  return p_Parent->getChildByName("commonLoading");
}

bool DPostCheckMaintain(int32 p_KingdomId, GTime p_Time) { return false; }
GString DFValueSuit(const GString& p_Value, const GString& p_Sign) { return p_Value + p_Sign; }

GString GetCCSPath(const char* p_CCSName) { return ""; }

void DClearItemAwards() {}

void DShowSwitcherView(RViewOtherData p_Data) {
  // local currentScene = display.getRunningScene()
  // local switcherName = "switcherView"
  // if userSDKManager.getChannel() == "fa" then
  //   switcherName = "switcherView_fa"
  // end
  // if currentScene then
  //   local switcher = currentScene:getChildByName(switcherName)
  //   if switcher then
  //     switcher:removeFromParent()
  //   end
  //   switcher = include(switcherName).new(params)
  //   if switcher then
  //     switcher:showSwitcher(currentScene)
  //   end
  // end
}

void DDelayCallOnce(GString p_UniqueKey, ccSchedulerFunc p_Func, float p_Time, bool p_CheckHandle) {
  if (p_CheckHandle && DManagerFindTimerByTarget(p_UniqueKey)) return;
  auto l_SharedScheduler = Director::getInstance()->getScheduler();
  DManagerRemoveTimerByTarget(p_UniqueKey);
  l_SharedScheduler->schedule(
          [&p_UniqueKey, &p_Func](float p_Delta) {
            auto l_SharedScheduler = Director::getInstance()->getScheduler();
            l_SharedScheduler->unschedule(p_UniqueKey, Director::getInstance());
            p_Func(p_Delta);
          },
          Director::getInstance(), p_Time, false, p_UniqueKey);
  DManagerAddTimer(p_UniqueKey);
}

void DShowPowerChange(RUpdatePowerEvtArg p_Arg, bool p_IsOnlyGet) {}

void DShowEXPChange(int32 p_Exp) {
  //   local currentScene = display.getRunningScene()
  // local expUpNode
  // if currentScene.name == "MainScene" then
  //   expUpNode = currentScene.expUpNode
  //   if not expUpNode then
  //     expUpNode = include("Node_EXPUp").new()
  //     expUpNode:setPosition(cc.p(display.cx, display.cy + 100))
  //     expUpNode:setVisible(false)
  //     expUpNode:addTo(currentScene, 6)
  //     currentScene.expUpNode = expUpNode
  //   end
  //   if not expUpNode:isVisible() then
  //     expUpNode:playAct(addEXP)
  //   end
  // end
  // return expUpNode
}

UIBaseView* DSearchPanelFromManagerByName(const char* p_Name) { return nullptr; }

void DStartLoginServerAndCheckVersion() {}

void DShowLoginView(EScene p_Scene, EKingdomClassType p_KingdomClassType) {}

bool DCheckIsOpenBuildStar() { return true; }
bool SoraDIsBraveOpen() { return false; }

void DShowLordUPView() {}

UIBaseView* DCurrentSceneShowView(const char* p_ViewName) { return nullptr; }

Node* DCreateCSBNode(const char* p_CSBName) { return CSLoader::createNode(p_CSBName); }

Label* DCreateLabel(RCreateLabelParm p_Parm) {
  auto l_Text = p_Parm.Txt;
  auto l_Font = p_Parm.FontName.empty() ? p_Parm.FontName : GDisplay::Get()->DefaultTTFFont;
  auto l_Size = p_Parm.fontSize = 0 ? p_Parm.fontSize : GDisplay::Get()->DefaultTTFFontSize;
  auto l_Color = p_Parm.Color != Color4B::WHITE ? p_Parm.Color : Color4B::WHITE;
  auto l_TextAlign = p_Parm.hAlignment != TextHAlignment::LEFT ? p_Parm.hAlignment : TextHAlignment::LEFT;
  auto l_TextValign = p_Parm.vAlignment != TextVAlignment::TOP ? p_Parm.vAlignment : TextVAlignment::TOP;
  auto l_X = p_Parm.x;
  auto l_Y = p_Parm.y;

  auto l_Label = Label::createWithSystemFont(l_Text, l_Font, l_Size, p_Parm.Dimensions, l_TextAlign, l_TextValign);
  if (l_Label) {
    l_Label->setColor(Color3B(l_Color));
    if (l_X && l_Y) {
      l_Label->setPosition(l_X, l_Y);
    }
  }
  return l_Label;
}

void DFadeInOut(Node* p_Node /**, float p_Time, float p_Delay, std::function<void()> p_CallBack*/) {
  // if(!p_Node) return;
  // p_Node->setOpacity(0);
  // p_Node->runAction(Sequence::create(
  //   DelayTime::create(p_Delay),
  //   FadeIn::create(p_Time),
  //   CallFunc::create(p_CallBack),
  //   nullptr
  // ));
}  // namespace
}  // namespace GBase
