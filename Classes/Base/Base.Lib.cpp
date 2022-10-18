#include "Base.Lib.h"
#include "AudioEngine.h"
#include "Module/Building/Building.Enum.h"
#include "Module/UI/Common/Message/UIMsgTip.h"

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

} // namespace






