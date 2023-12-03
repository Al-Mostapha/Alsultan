#pragma once
#include "Common.Type.h"
#include "Base/Type/XVector.h"
#include "ui/CocosGUI.h"
#include "Module/CityResource/Resource.Enum.h"

class UIWorldMapFaceToDistance;
namespace GBase{
  Node *DCreateEffectNode(
    const GVector<RCreatEffctParam> &p_Parm, 
    const char *p_Folder = nullptr, 
    bool p_IsAutoRemoveOnfinish = false);
  void DSetGray(Node *p_Node, bool p_IsGray, bool p_Rec = false);
  void DSetNodeGray(Node *p_Node, bool p_IsGray);
  void DCreateGraySprite(Node *p_Node);
  void DNormalSprite(Node *p_Node);
  bool DIsNodeVisibleOnScroll(ui::Widget *p_Node, ui::ScrollView *p_Scroll = nullptr, ui::Widget::TouchEventType p_Type = ui::Widget::TouchEventType::ENDED);
  bool DEnoughWarBadge(int32 p_NeedBadge, int32 p_BadgeID, bool p_NotShow = false);
  bool DEnoughGold(int32 p_GoldNeeded, bool p_NotShow = false);
  bool DResIsLock(EResource p_ResId);
  void DResetEffectNode(Node *p_Node);
  void DStopEffectNode(Node *p_Node);
  UIWorldMapFaceToDistance *DGetWorldMapFaceToDistanceNode();
  void DFadeINOUT(Node *p_Node, const RFadeInOutParam &p_Param);
};