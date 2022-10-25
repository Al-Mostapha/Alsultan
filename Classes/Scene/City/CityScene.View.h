#pragma once
#include "Include/IncludeBase.h"
#include "Include/IncludeEngine.h"
#include "Base/Containers/HashMap.h"
#include "Base/Base.View.h"

class MainCityView : public BaseView
{
GHashMap<GString, Node *> n_BufferNodeArray;
bool m_IsNeedFirstFight = false;
bool m_IsFinishInit = false;
public:
  void Ctor();
  void PreLoadImages();
  bool IsNeedFirstFight();
  void AddToBufferNodeArrayByName(const char *p_Name, Node *p_Node){
    if(!p_Node)
      return;
    n_BufferNodeArray[p_Name] = p_Node;
  }
  void FinishLoadImages();
  void OnMessageListener_FinishLoadImage();
  virtual void InitAfterCreate() = 0;
};