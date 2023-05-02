#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Science/Science.Type.h"
#include "Module/UI/Common/Timer/UITimerLabel.h"

class UICollegeScrollSingle : public UIBasePanel
{
  CREATE_FUNC(UICollegeScrollSingle);
  CreateUIPanel(UICollegeScrollSingle);
  CreateUICCSView(UICollegeScrollSingle);
  EScience _Tid  = EScience::None;
  EScienceType _Type = EScienceType::None;
  RScienceTypeData _TableSingleData;
  RScienceDetail _TableSingleDetails;
  ui::ScrollView *_Scroll = nullptr;
  bool _SingleIsMoved = false;
  Sprite *_SpriteLock = nullptr;
  ui::Button *_BtnBg = nullptr;
  ui::ImageView *_ImageTechBg = nullptr;
  ui::ImageView *_ImageIcon = nullptr;
  Node *_NodeName = nullptr;
  ui::Text *_LabelName = nullptr;
  Node *_NodeLv = nullptr;
  ui::Text *_LabelLv = nullptr;
  Node *_NodeEffectBg = nullptr;
  Node *_NodeEffectFg = nullptr;
  UITimerLabel *_TextTime = nullptr;
public: 
  static UICollegeScrollSingle* Create();
  void Ctor() override;
  void InitData(EScience p_TechId, EScienceType p_TechType = EScienceType::None);
  void HideName();
  void HideNameLv();
  void UpdateView(EventCustom *p_Event);
  void SetTimeVisble(bool);
  void UpdateOtherUI();
  bool CanStudy();
  void RunEffect(bool p_IsShow);
  void SetIconStateGrey(bool p_IsGrey);
  void SetScroll(ui::ScrollView *p);
  void BtnClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type);



};