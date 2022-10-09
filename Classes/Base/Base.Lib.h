#pragma once
#include "BaseTypeDef.h"
#include "Include/IncludeEngine.h"
#undef PlaySound

enum class EBuildingInteractivity;
enum class EBuilding;
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
  EBuildingInteractivity DGetBuildingTypeByIndex(EBuilding p_Building);
  bool IsTouchOnNode(Vec2 p_Point, Node *p_Node);

  float DGetAutoHeightLabel(ui::Text *p_Label, float p_Width = 0.0f);
  void DSetTextWidthHeight(ui::Text *p_Label, Size p_Size);
  void DSetTextWidthHeight(Label *p_Label, Size p_Size);
  void DShowMsgTip(const GString &p_Message, const GString &p_Icon = "");
};


