#pragma once
#include "Include/IncludeBase.h"
#include "Module/UI/Panel/UIPanelBase.h"


class UICommonShareButton : public UIPanelBase
{
  struct TableBtn{
    GString icon;
    GString key;
    int tag;
    ui::Button* Btn;
  };

private:
  float m_HiddleModel = 0.5f;
  ui::Button *m_BtnBg;
  ui::ImageView *m_ImgBg;
  ui::Button *m_BtnMain;
  float m_BtnWidth = 0.0f;
  GVector<TableBtn> m_TableBtn;
  Scheduler *m_Timer = nullptr;
public:
  UICommonShareButton();
  ~UICommonShareButton();
  void InitPanel() override;
  void Show() override;
  CREATE_FUNC(UICommonShareButton);

  void BtnClickCallBack(Ref* p_Sender, ui::Widget::TouchEventType p_Touch);
  void BtnBgClickCallBack(Ref* p_Sender, ui::Widget::TouchEventType p_Touch);
  void BtnMainClickCallBack(Ref* p_Sender, ui::Widget::TouchEventType p_Touch);
  void ShowGuideAction();
  void StartRecordScreen(EventCustom *p_Event);
  void StopRecordScreen(EventCustom *p_Event);
  void RecordTimeTick(float p_Delta);
  void FoldBG();
  void UnFoldBG();
  void StarMainBtnOpacity(bool p_IsTouch);
  void UpdateAP();
};