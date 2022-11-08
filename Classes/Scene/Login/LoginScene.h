#pragma once
#include "Include/IncludeBase.h"
#include "Include/IncludeEngine.h"
#include "Include/IncludeUiBase.h"
#include "Include/IncludeGlobal.h"
#include "Include/IncludeCommon.h"
#include "Include/IncludeFunc.h"
#include "Module/UI/Common/UICommonItemTips.h"


class LoginScene : public Scene
{
private:
  bool m_IsComeFromBackGroud = false;
  Scheduler *m_ForeBackGroudTimer = nullptr;
  EScene m_CurrentViewType = EScene::None;
  bool m_IsHiideMainUICount = 0;
  bool m_IsHideCurrentSceneViewCount = false;
  ui::Layout *m_IphoneXTop = nullptr;
  ui::Layout *m_IphoneXBottom = nullptr;
  // self.faceToDistanceNode = nil
  // self.gameGuideView = nil
  bool m_SwitcherViewIng = false;
  ui::Layout *m_PanelView = nullptr;
  UIPanelBase *m_LoginView = nullptr;
  UIPanelBase *m_ShareBtn = nullptr;
  UIPanelBase *m_MainUIView = nullptr;
  bool m_CommonTipRA = false;
  UIPanelBase *m_CurrentShowView = nullptr;

public:
  bool init() override;
  void onEnter() override;
  static LoginScene* getCityScene();
  void StartGame();
  void InitData();
  void CreatePanelView();
  void CreateLoginView(EScene p_Type = EScene::None, EKingdomClass p_Kingdom = EKingdomClass::None);
  void InitGRoot();
  void CleanPanelView();
  void ReleaseMainView();
  bool RemoveLoginView();
  void LuaWillReload();
  void UpdateShareButton(EventCustom *p_Event);
  void UpdateCommonIconTip(RCommonIconData p_IconData);
  void UpdateVoiceButton();
  void UpdateVoiceInviteButton();
  void ShowIphoneX();
  void CreateWorldResourceMap();
  void RemoveWorldResourceMap();
  void CreatMainView(EScene p_Type);
  void InitLoginSuccess();
  UIPanelBase *CurrentSceneShowView(){ return m_CurrentShowView; }
  CREATE_FUNC(LoginScene);
};
