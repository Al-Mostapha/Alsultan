#pragma once
#include "Base/BaseTypeDef.h"
#include "Base/Type/XVector.h"
#include "Module/UI/UIBasePanel.h"
#include "Base/Utils/String.Util.h"
#include <type_traits>
USING_NS_CC;

namespace GBase {
  template <class T> GVector<T *>
  DGetChildsArrayByName(
    Node *, const char *, size_t, size_t = 0, bool = false,
    bool = false, bool = false);

  template <class T> T* 
  DGetExtendChildFromCCSByName(Node* p_Parent, const char* p_Name, bool p_NodeFitOffset = false, float p_Height = 0.0f);
  
  template <typename T> T DGetChildByName(Node* p_Node, const char* p_name) {
    if (!p_Node) return nullptr;
    if (p_Node->getName() == (std::string)p_name) return dynamic_cast<T>(p_Node);

    for (auto child : p_Node->getChildren()) {
      auto l_node = DGetChildByName<T>(child, p_name);
      if (l_node) return l_node;
    }

    return nullptr;
  }
};


template<typename T> GVector<T *> 
GBase::DGetChildsArrayByName(
  Node *p_Parent, const char *p_Name, size_t p_Num, size_t p_Begin,
  bool p_IsShow, bool p_IsExtendChild, bool p_NodeFitOffset){
  GVector<T *> l_Childs;
  if(!p_Parent || p_Num <= 0 || !p_Name){
    return l_Childs;
  }
  for(auto iii = p_Begin; iii < p_Num + p_Begin; ++iii){
    auto l_CName = GString(p_Name) + std::to_string(iii);
    T *l_Child = nullptr;
    if(p_IsExtendChild){
      if constexpr (std::is_base_of<UIBasePanel, T>::value){
        l_Child = GBase::DGetExtendChildFromCCSByName<T>(p_Parent, l_CName.c_str(), p_NodeFitOffset);
      }
    } else 
      l_Child = GBase::DGetChildByName<T *>(p_Parent, l_CName.c_str());
    if(l_Child){
      if(p_IsShow){
        l_Child->setVisible(true);
      }
      l_Childs.push_back(l_Child);
      
    }else{
      CCLOG("SoraDGetChildsArrayByName failed: %s is not found!", l_CName.c_str());
      return l_Childs;
    }
  }
  return l_Childs;
}


template <class T> T* 
  GBase::DGetExtendChildFromCCSByName(Node* p_Parent, const char* p_Name, bool p_NodeFitOffset, float p_Height) {
  auto l_child = DGetChildByName<Node *>(p_Parent, p_Name);
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
      Node *l_Parent = l_child->getParent();
      l_Inst->setName(l_child->getName());
      l_Inst->setPosition(l_child->getPosition());
      l_Inst->setScale(l_child->getScale());
      l_Inst->setAnchorPoint(l_child->getAnchorPoint());
      l_Inst->setRotation(l_child->getRotation());
      l_Inst->setLocalZOrder(l_child->getLocalZOrder());
      l_Inst->setTag(l_child->getTag());
      l_Inst->setUserData(l_child->getUserData());
      l_Inst->setUserObject(l_child->getUserObject());
      l_child->removeFromParentAndCleanup(true);
      GVector<Node *> l_Desendents;
      std::copy(l_child->getChildren().begin(), l_child->getChildren().end(), std::back_inserter(l_Desendents));
      for(auto l_Dec : l_Desendents){
        l_Dec->removeFromParentAndCleanup(true);
        l_Inst->addChild(l_Dec);
      }
      
      l_Parent->addChild(l_Inst);
      return l_Inst;
    }
  }
  return nullptr;
}