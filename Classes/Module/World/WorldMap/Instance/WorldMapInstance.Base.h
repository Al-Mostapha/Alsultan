#pragma once
#include "cocos2d.h"

class WorldMapInstanceBase : virtual public cocos2d::Node
{
  virtual void OnMessageListener() = 0;
  virtual void OnEnterOther() = 0;
  void onEnter() override {
    Node::onEnter();
    OnMessageListener();
    OnEnterOther();
  };
  
  void onExit() override {
    Node::onExit();
    // SoraDRemoveMessageByTarget(self)
    // SoraDManagerRemoveTimerByTarget(self)
    // self:onExitOther()
  };
};