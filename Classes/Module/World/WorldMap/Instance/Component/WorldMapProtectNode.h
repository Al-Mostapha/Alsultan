#pragma once
#include "Base/BaseTypeDef.h"
#include "Base/Type/XEngine.h"

class WorldMapProtectNode : public Node
{
  Node *CreateEffect();
  Node *CreateEffectNode();
  Node *CreateEffectNodeNew();
  CREATE_FUNC(WorldMapProtectNode);
  Node *_Effect = nullptr;
  bool _IsGreen = false;
  bool _IsGray = false;
  bool _IsNew = false;
public:
  static WorldMapProtectNode *Create(bool pIsGreen = false){
    auto lRet = WorldMapProtectNode::create();
    lRet->_IsGreen = pIsGreen;
    return lRet;
  }
  static WorldMapProtectNode *CreateNew(bool pIsGray = false){
    auto lRet = WorldMapProtectNode::create();
    lRet->_IsGreen = pIsGray;
    lRet->_IsNew = true;
    return lRet;
  }


  void setVisible(bool pIsVisible) override;
  void SetGreenColor(bool pIsGreen);
  void SetIsGray(bool pIsGray);
};