#pragma once
#include "Include/IncludeEngine.h"
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Building/Building.Enum.h"
#include "Module/Science/Science.Enum.h"
#include "Module/Science/Science.Type.h"

USING_NS_CC;

class IBuilding;
class ITask;
class UICommonFramTitle;
class UICommonEllipseBar;
class UICollegeScrollSingle;
class UICollegeWaitSingle;
class UICollegeMainSingle;

typedef cocostudio::timeline::ActionTimeline Anim;

class UICollegeView : public UIBasePanel
{

  CREATE_FUNC(UICollegeView);
  CreateUIPanel(UICollegeView);
  CreateUICCSView(UICollegeView);
  
  bool _IsHideCurrentSceneView = true;
  bool _IsEnter = true;
  EBuilding _Bid = EBuilding::Institute;
  RScienceDetail _TableStuding;
  EScienceType _StudyingType = EScienceType::None;
  //   self.type = nil
  GString _Timer = nullptr;
  GString _LuckyTimer = nullptr;
  GString _LuckyBlessTimer = nullptr;
  ITask *_Queue = nullptr;
  GHashMap<EScienceType, UICollegeMainSingle*> _TableBtn;
  //   self.tableLock = {}
  GVector<RScienceLvlSpecs> _RecommendData;
  UICommonFramTitle *_NodeTitle = nullptr;
  Node *_NodeBall = nullptr;
  Anim *_AnimationBall = nullptr;
  Node *_NodeLight = nullptr;
  Anim  *_AnimationLight = nullptr;
  Node *_NodeBase = nullptr;
  Anim  *_AnimationBase = nullptr;
  Node *_NodeCenter = nullptr;
  Anim  *_AnimationCenter = nullptr;
  Node *_NodeTechFront = nullptr;
  Node *_NodeFront = nullptr;
  Node *_TopNode = nullptr;
  ui::Text *_LabelNotice = nullptr;
  Node *_BottomNodeLucky = nullptr;
  ui::Text *_LabelLcukyDes = nullptr;
  Node *_BottomNode = nullptr;
  Node *_NodeTimer = nullptr;
  Node *_NodeTime = nullptr;
  UICommonEllipseBar *_TimeBar = nullptr;
  ui::Text *_TextTime= nullptr;
  Node *_CenterNodeTechInfo = nullptr;
  ui::Text *_LabelStudyName = nullptr;
  ui::Button *_ButtonDetail = nullptr;
  UICollegeScrollSingle *_CcsStudying = nullptr;
  Node *_Node_Title = nullptr;
  ui::Text *_TextTitle = nullptr;
  Node *_NodeRecommend_1 = nullptr;
  Node *_NodeRecommend_2 = nullptr;
  ui::Text *_TextNoRecommend = nullptr;
  UICollegeWaitSingle *_NodeWait = nullptr;
  bool _IsPrivilege = false;
  
public: 
  static UICollegeView* Create();
  void Ctor() override;
  void OnMessageListener();
  void SuitView();
  void InitData();
  void SetRecommendInfo(Node *p_Node, RScienceLvlSpecs p_Info);
  void InitRecommendData();
  void BtnDetailClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void BtnStudyClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void UpdateLuckyBless(EventCustom *p_Event);
  void RefreshWaitQueue(EventCustom *p_Event);
  void OpenLuckyTime(float p_Dt);

  void ShowAction(bool p_IsStudy);
  void TopStudyShow(bool p_IsStudy);
  void SetMainSingleEffect(bool p_Visible);
  void OnEnterGuide();
  void OpenTimeUp(float p_Dt);
};