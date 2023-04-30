#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Science/Science.Enum.h"

class UICollegeMainSingle : public UIBasePanel
{
  CREATE_FUNC(UICollegeMainSingle);
  CreateUIPanel(UICollegeMainSingle);
  CreateUICCSView(UICollegeMainSingle);

  ui::Button *_BtnStudy;
  Sprite *_SpriteIcon;
  ui::ImageView *_ImgGear;
  ui::Text *_LabelName;
  ui::ImageView *_ImageTechBg;
  Node *_NodeStudyingBottom;
  Node *_NodeStudyingTop;
  Sprite *_SpriteLock;
  ui::ScrollView *_PScroll;
  float _Scale;
public: 
  EScienceType _Type = EScienceType::None;
  static UICollegeMainSingle* Create();
  void Ctor() override;
  void SetScale(float p_Scale);
  void SetEffectVisible(bool p_IsVisible);
  void RunFadeInAct(float p_PosX, float p_PosY);
  void InitData(EScienceType p_Science);
  bool Unlock();
  void InitScroll(ui::ScrollView *p_Scroll);

  void BtnClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type);

};