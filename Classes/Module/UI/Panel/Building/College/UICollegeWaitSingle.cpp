#include "Base/Common/Common.Teml.h"
#include "UICollegeWaitSingle.h"
#include "Module/Science/Science.Read.h"
#include "Module/Science/Science.Ctrl.h"

UICollegeWaitSingle *UICollegeWaitSingle::Create(){
  auto l_Panel = Create("UiParts/Panel/Building/View/College/collegeWaitSingle.csb");
  return l_Panel;
}

void UICollegeWaitSingle::Ctor(){
  InitWidget();
}


void UICollegeWaitSingle::InitWidget(){
  _NodeState1 = GBase::DGetChildByName<Node *>(this, "Node_state1");
  GBase::DGetChildByName<ui::Text *>(this, "Text_wait")->setString(Translate::i18n("privilege_text_83"));
  GBase::DGetChildByName<ui::Text *>(this, "Text_idle")->setString(Translate::i18n("herotrain_text_01"));
  _NodeState2 = GBase::DGetChildByName<Node *>(this, "Node_state2");
  _TextName = GBase::DGetChildByName<ui::Text *>(this, "Text_name");
  _TextPower = GBase::DGetChildByName<ui::Text *>(this, "Text_power");
  GBase::DGetChildByName<ui::Text *>(this, "Text_waiting")->setString(Translate::i18n("privilege_text_125"));
  _ButtonSub = GBase::DGetChildByName<ui::Button *>(this, "Button_sub");
  _ButtonSub->addTouchEventListener(CC_CALLBACK_2(UICollegeWaitSingle::BtnSubClick, this));
  _CCSWait = GBase::DGetExtendChildFromCCSByName<UICollegeScrollSingle>(this, "CCS_collegeScrollSingle_wait");
  _CCSWait->HideName();
  _CCSWait->RunEffect(false);
  _CCSWait->GetNodeLv()->setPosition(0, -45);
  _CCSWait->setScale(0.8);
}

void UICollegeWaitSingle::InitData(EScience p_Tid){
  // self.tableStuding = tableStuding
  // self.tid = self.tableStuding.technologyID
  // self.type = eType or collegeDesRead.getType(self.tid)
  auto l_Type = ScienceRead::Get()->GetType(p_Tid);
  SetStateWait();
  _CCSWait->InitData(p_Tid);
  _TextName->setString(ScienceRead::Get()->GetName(p_Tid));
  auto l_TableSingleData = ScienceCtrl::Get()->GetTechDataByID(p_Tid, l_Type);
  auto l_AddFighting = ScienceRead::Get()->GetFight(p_Tid, l_TableSingleData._CurrentLvl + 1) - ScienceRead::Get()->GetFight(p_Tid, l_TableSingleData._CurrentLvl);
  _TextPower->setString(
    Translate::i18n("common_text_128",
        {{"power", StringUtils::format("+%d", l_AddFighting)}}
      )
    );
}
