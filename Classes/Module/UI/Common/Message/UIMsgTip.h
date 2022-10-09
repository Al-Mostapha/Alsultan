#pragma once 
#include "Include/IncludeBase.h"
#include "Module/UI/Panel/UIPanelBase.h"

class UIMsgTip : public UIPanelBase {
private:
  float m_MaxHeight = 0;
  float m_DeltaHeight;
  void addHeight(float p_DeltaHeight = 0.0f);
  Sprite *m_ImageIconBg;
  ui::Text  *m_TextMessage;
  ui::ImageView  *m_ImageBgL;
  ui::ImageView  *m_ImageBgR;
  void Show();
  CREATE_FUNC(UIMsgTip)
public:
  void InitPanel() override;
  void ShowTip( GString p_Message, Node *p_Icon = nullptr);
  static UIMsgTip *Create();
  
};