#pragma once
#include "Include/IncludeEngine.h"
#include "Module/UI/Panel/UIPanelBase.h"
#include "Module/UI/UIBasePanel.h"
#include "Include/IncludeGlobal.h"
#include "UIMainTop.h"
#include "UIMainBottom.h"


class UIMain : public UIPanelBase
{
  EScene m_CurrentViewType;
  UIBasePanel *m_TopArea;
  UIPanelBase *m_PandectView;
  UIPanelBase *m_BottomArea;
private:
  CREATE_FUNC(UIMain);
public:
  UIMain();
  ~UIMain();
  void InitPanel() override;
  void Show() override {};
  void BindTest();
  void ButtonCheatSendClick(Ref *Sender,  ui::Widget::TouchEventType p_Type);
  void ButtonTestSendClick(Ref *Sender,  ui::Widget::TouchEventType p_Type);
  void OnEnterOther();
  void OnExitOther();
  void OnMessageListener();
  void SetMainUIHiddle(EventCustom *p_Event);
  void ListenerKeyPad();
  void OnEnterForeground();
  void OnEnterBackground();
  
  //Messages 
  void ReLoginFinish(EventCustom *p_Event);
  void ChangeMainScene(EventCustom *p_Event);
  void LordSkillEffect(EventCustom *p_Event);
  void MsgNoticeCumuReward(EventCustom *p_Event);
  void ShowEveluationView(EventCustom *p_Event);
  void ShowHalloweenActionView(EventCustom *p_Event);
  void UpdateStyle(EventCustom *p_Event);
  void ShowAgreementBox(EventCustom *p_Event);
  void MsgCastleGift(EventCustom *p_Event);
  void CastleLevelUp(EventCustom *p_Event);
  void RefreshEventModule(EventCustom *p_Event);
  void NewDayReset(EventCustom *p_Event);
  void NewChapterTaskOpen(EventCustom *p_Event);
  GVector<class UIPanelBase *> GetCheckViewList();

  UIMainTop *GetMainUITop(){ return dynamic_cast<UIMainTop *>(m_TopArea); }
  UIMainBottom *GetMainUIBottom(){ return dynamic_cast<UIMainBottom *>(m_BottomArea); }
  Node *gameGuide_getTarget(const char *p_ItemName){return nullptr;}
  static UIMain *Create() {return create();};
};


