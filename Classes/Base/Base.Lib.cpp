#include "Base.Lib.h"
#include "AudioEngine.h"
#include "Module/Building/Building.Enum.h"
#include "Module/UI/Common/Message/UIMsgTip.h"
#include "Global/Global.Enum.h"

namespace GBase{

  void PlaySound(const char* p_SoundName, bool p_IsLoop, float p_delay)
  {
    Sequence::create(
      DelayTime::create(p_delay),
      CallFunc::create([=]() {
        AudioEngine::play2d(p_SoundName, p_IsLoop);
      }),
      nullptr
      );
  }

  void PlaySound(const char* p_SoundName, int32 p_index, float p_delay, bool p_Tag3d) {  }

  const char *getSoundPath(const char *p_SoundName)
  {
    return StringUtils::format("Music/%s", p_SoundName).c_str();
  }

  void SoraDFTarget(Node *p_node){}

  EBuildingPlace DGetBuildingTypeByIndex(EBuildingIndex p_Building){
    return EBuildingPlace::Outer;
  }

  bool IsTouchOnNode(Vec2 p_Point, Node *p_Node){
    bool l_IsOnNode = false;
    if(!p_Node)
      return l_IsOnNode;
    auto l_Parent = p_Node->getParent();
    auto l_BoundingBox = p_Node->getBoundingBox();
    auto l_PosTouchToNode = l_Parent->convertToNodeSpace(p_Point);
    return l_BoundingBox.containsPoint(l_PosTouchToNode);
  }

  float  DGetAutoHeightLabel(ui::Text *p_Label, float p_Width){
    if(!p_Label)
      return 0;
    if(p_Width == 0)
      p_Width = p_Label->getContentSize().width;
    p_Label->ignoreContentAdaptWithSize(false);
    p_Label->setTextAreaSize(Size(p_Width, 0));
    auto l_Height = p_Label->getVirtualRendererSize().height;
    p_Label->setContentSize(Size(p_Width, l_Height));
    return l_Height;
  }


  void DSetTextWidthHeight(ui::Text *p_Text, Size p_Size){
    if(!p_Text)
    p_Text->ignoreContentAdaptWithSize(false);
    p_Text->setTextAreaSize(p_Size);
    p_Text->setContentSize(p_Size);
  }

  void DSetTextWidthHeight(Label *p_Label, Size p_Size){
    if(!p_Label)
      return;
    p_Label->setOverflow(Label::Overflow::SHRINK);
    p_Label->setDimensions(p_Size.width, p_Size.height);
    
  }

  void DShowMsgTip(const GString &p_Message, const GString &p_Icon){
    if(!GBase::GLobalSettings::ShowMsgTip)
      return;
    Sprite *l_IconSprite = nullptr;
    if(p_Icon != ""){
      l_IconSprite = BaseCreate::CreateSprite(p_Icon.c_str());
      l_IconSprite->setScale(100/l_IconSprite->getContentSize().width);
    }
    auto l_Panel = UIMsgTip::Create();
    l_Panel->InitPanel();
    l_Panel->ShowTip(p_Message, l_IconSprite);
  }

  GPair<GString, GString> DGetBuildWarLv(const uint32 p_BuildingLvl) {
    return GPair<GString, GString>::Make("war_lv_1", "war_lv_2");
  }
  GPair<int32, int32> DGetBuildStarLv(const EBuilding p_Building){
    return GPair<int32, int32>::Make(0, 0);
  }
  void DGetEquip(){}
  bool  DRemoveTimer(Node *p_Target, Scheduler *p_Scheduler){
    return false;
  }

  void DShowNameOnTouchEven(Node * p_Node, GPair<GString, Vec2> p_Data){

  }
  Node *DPopItemAward(){return nullptr;}
  void DPushItemAward(Node *){}
  bool DCloseLoginView(){return true;}
  void DSendMessage(const char *p_EventId, void *p_Data){}
  bool DIsGameGuide(){return false;}
  Scheduler *DCreateTimer(Node *p_Target, ccSchedulerFunc p_SchedulerFunc, bool p_Priority){ return nullptr; }
  EFactionType DGetFactionType(){ return EFactionType::Normal; }
  

  void DCloseSwitcherView(){}
  void DAddMessage(Node * p_Node, const char *p_EventId, const std::function<void(EventCustom *)> &p_Callback){}
  void DManagerRemoveTimer(Scheduler *P_Timer){}
  GString DConvertSecondToString(int p_Second){return "";}
  RenderTexture *DCreateScreenShot(bool p_IsBlur){
    auto l_Width = GBase::Display::Get()->size().width;
    auto l_Height= GBase::Display::Get()->size().height;
    //TODO: 35056
    auto l_RenderTexture = RenderTexture::create(l_Width, l_Height, PixelFormat::RGBA8888/*,35056*/);
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
    l_RenderTexture->setPosition(Vec2(GBase::Display::Get()->cx, GBase::Display::Get()->cy));
    // local renderSprite = renderTexture:getSprite()
    auto l_RenderSprite = l_RenderTexture->getSprite();
    // if isBlur then

    // end
    if(p_IsBlur){
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
      // l_State->setUniformVec2("resolution", Vec2(GBase::Display::Get()->size().width, GBase::Display::Get()->size().height));
      // l_State->setUniformFloat("blurRadius", 20);
      // l_State->setUniformFloat("sampleNum", 10);
      // l_RenderSprite->setGLProgramState(l_State);
    }
    // return renderTexture
    return l_RenderTexture;
  }

  GString DGetDefaultLanguage(){
    return "en";
  }
  void DSetDefaultLanguage(bool p_IsNeedUpdate, bool p_IsNeedRefresh){
    
  }

  //RA is RightAlignment
  bool DFIsRA(){return false;}

  void DNewChapterOpen(bool p_IsFromLogin){}

  void DShowCastleUnlockView(){}
  uint32 DGetCastleLv(){ return 0; }

  void DShowCastleUPView(){}
  void DShowRateStarView(){}
  class UIPanelBase *DCurrentTopPanelFromManager(){
    return nullptr;
  }

  UICommonPromptBox *DShowMsgBox(
    GString p_Msg, GString p_YesBtnTitle, GString p_NoBtnTitle,
    std::function<void(EMsgBoxCallBack)> p_CallBack, void *p_Data,
    int p_Align, bool p_NoSound){ return nullptr; }

  bool DIsBrave8Level(){ return false; }
  
  void DMixtureGLONE(Node *p_Node){}

  void DRemoveMessageByTarget(Node *p_Node){
    
  }

 void DRemoveMessageFromTargetByName(Node *p_Node, const char *p_EventId){}

  void DCloseLoading(Node *p_Parent, const char *p_Mark, bool p_All){}

  bool DPostCheckMaintain(int32 p_KingdomId){ return false; }
  GString DFValueSuit(GString p_Value, GString p_Sign = "+"){
    return p_Value + p_Sign;
  }

  GString GetCCSPath(const char *p_CCSName){
    return "";
  }

} // namespace






