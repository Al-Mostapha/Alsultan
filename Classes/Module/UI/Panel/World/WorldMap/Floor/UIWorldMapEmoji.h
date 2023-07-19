#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIWorldMapEmoji : public UIBaseView
{

  CREATE_FUNC(UIWorldMapEmoji);
  CreateUIPanel(UIWorldMapEmoji);
  CreateUICCSView(UIWorldMapEmoji);

  
public: 
  static UIWorldMapEmoji* Create();
  void Ctor() override;  
  void SetEmoji(int32 pEmojiID){}
  void ShowAction(bool pIsShow){}
  void HideAction(){}
};