#pragma once
#include "Include/IncludeEngine.h"
#include "Include/IncludeGlobal.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/World/WorldWar/WorldWar.Def.h"

USING_NS_TIMELINE;

struct EvArDownlodProgress{
  float m_Progress;
  float m_Total;
  float m_Downloaded;
};

struct RLoginRangeState{
  float ready;
  GString StartLang;
  GString LoadLang;
  GString DoneLang;
};

class UILoginView : public UIBasePanel
{
  GVector<GString> m_TestArrayImages;
  int32 m_InitFinishCount = 0;
  EScene m_ShowViewType = EScene::None;
  Sprite *n_LoginInitBg = nullptr;
  Sprite *n_LoginInitBg2 = nullptr;
  Node *n_NodeEvent = nullptr;
  Node *m_Logo = nullptr;
  Node *m_CCSLogo = nullptr;
  ui::Text *n_TxtPercent = nullptr;
  Node *m_AnimationLogo = nullptr;
  Node *m_BottomLoading = nullptr;
  Sprite *n_TxtWarTips = nullptr;
  Node *m_NodeFix = nullptr;
  ui::Layout *m_BtnUpdateFix = nullptr;
  ui::Text *m_TxtUpdateFix = nullptr;
  ui::Text *n_TxtNoteTip = nullptr;
  ui::Text *m_VersionLabel = nullptr;
  bool m_IsUpdateReload = false;
  bool m_LoadImageFinish = false;
  bool m_IsServerReturn = false;
  Scheduler *m_TimerKey = nullptr;
  GHashMap<ELoginRangeTbl, RLoginRangeState> m_LoginRangeState;
  ELoginRangeTbl m_CurLoadingRange = ELoginRangeTbl::None;
  ui::Layout *n_MaskPregress = nullptr;
  Sprite *n_ProgressbarBase = nullptr;
  Sprite *n_ProgressPoint = nullptr;
  Node *n_SpriteAnimationLuotuo = nullptr;
  Sprite *n_ProgressbarLogin = nullptr;
  ActionTimeline *n_AnimationLotuo = nullptr;
  ClippingNode *n_CliperNode = nullptr;
  ParticleSystemQuad *n_Loading = nullptr;
  ParticleSystemQuad *n_EtStar = nullptr;
  EKingdomClassType m_KingdomClass = EKingdomClassType::None;
  CREATE_FUNC(UILoginView);
public:
  static UILoginView *Create();
  void SetKingdomClass(EKingdomClassType p_KingdomClass);
  void SetShowViewType(EScene p_Type);
  void Ctor() override;
  void InitVars();
  void InitView();
  void InitROSView();
  void InitKOHView();
  void SetInitCliper();
  void InitUpdateInfo();
  void SetMainSenceMsgListener();
  void SetVersion2Top();
  void InitSpineAnimation();

  void OnClickUpdateFix(Ref *p_Sender, ui::Widget::TouchEventType p_Type);

  void OnEnterOther() override;
  void FinishLoadImages();
  void StartObbLoad();
  void SwitchNextLoading(ELoginRangeTbl p_Range);
  bool CheckObbExported();
  void StartValidateObb();
  void ValidateObbSuccess();
  void FinishRange(ELoginRangeTbl p_Range);
  void StartCheckUpdate(){}
  void StartPatchUpdate();
  void WaitForAttGranted();
  void OnAttGrantedComplete();
  void Start2CheckVersion();
  void SetKingdomClassTips();
  void OnReceiveObbMsg(EventCustom *p_Event);
  void OnDownloadProgress(EventCustom *p_Event);
  void OnPreDownloadProgress(EventCustom *p_Event);
  void OnPreDownloadProgressUNZip(EventCustom *p_Event);
  void LoadBar(float p_Percent);
  void UpdateSucess();
  void StartGame();
  void EnterGame();
  void LoadCommonImages();
  void LoadAudios();
  void StartTimer();
  void StopTimer();
  void CheckMaintainInfo();
  void ResetIceHuntingRecord();
  void ResetSearchMonsterRecord();
  void SetStarBuildMiracleLv();
  void LoginSuccess();
  void UpdateTime(float p_Delta);
  void LoadWhenTheRightRange(ELoginRangeTbl p_Range, float p_Cur);
  ELoginRangeTbl GetLoadRangeID();
  void SetPercent(float p_Percent);
  float GetPercent();
  void AutoLoadingBar(float  p_EPercent, float p_Frame);
  void LoadingBarEffect(float p_Percent);
  void SpineAction();
  void AddEffectLogin();
  void AddSubViews() override;

};


