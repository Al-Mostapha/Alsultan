#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Science/Science.Enum.h"
#include "UICollegeScrollSingle.h"

class UICollegeScrollView : public UIBasePanel
{
  CREATE_FUNC(UICollegeScrollView);
  CreateUIPanel(UICollegeScrollView);
  CreateUICCSView(UICollegeScrollView);

  struct _RScienceIcon{
    EScience _Data;
    UICollegeScrollSingle *_Base;
    UICollegeScrollSingle *_Point;
  };

  EScienceType _TreeType;
  GVector<EScience> _TableTree;
  GVector<_RScienceIcon> _ArrTechnologyIcon;
  GVector<UICollegeScrollSingle *> _TableSpare;
  ui::ScrollView *_Scroll;
  DrawNode *_FrameLine;
  DrawNode *_FrameLineHl;
public: 
  static UICollegeScrollView* Create(const char *p_FileName);
  void Ctor() override;
  void InitData(EScienceType);
  void SetStateFree(){}
  void ScrollEventCallBack(Ref *p_Sender, ui::ScrollView::EventType p_Type);
  void InitCollegeList();
  UICollegeScrollSingle *GetCollegeSingleById(EScience p_Id);
  size_t JumpToTechnologyByID(EScience p_Id);
};