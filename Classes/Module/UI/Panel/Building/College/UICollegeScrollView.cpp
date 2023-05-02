#include "UICollegeScrollView.h"
#include "Module/Science/Science.Read.h"
#include "Module/Science/Science.Ctrl.h"
#include "WarTech/UIWarTechnologyScrollLine.h"
#include "Base/Common/Common.Teml.h"

UICollegeScrollView *UICollegeScrollView::Create(const char *p_FileName){
  auto l_Panel = Create(StringUtils::format("UiParts/Panel/Building/View/College/ScienceView/%s.csb", p_FileName));
  return l_Panel;
}

void UICollegeScrollView::Ctor(){
  UIBasePanel::Ctor();
  _TreeType = EScienceType::Resource;
  _Scroll = GBase::DGetChildByName<ui::ScrollView *>(this, "Size_ScrollView");
  _Scroll->addEventListener(CC_CALLBACK_2(UICollegeScrollView::ScrollEventCallBack, this));
  _FrameLine = DrawNode::create();
  _Scroll->addChild(_FrameLine, -2);
  _FrameLineHl = DrawNode::create();
  _Scroll->addChild(_FrameLineHl, -2);
}

void UICollegeScrollView::InitData(EScienceType p_Type){
  _TreeType = p_Type;
  ScienceRead::Get()->GetTree(_TreeType);
  auto l_TableIconList = GBase::DGetChildsArrayByName<UICollegeScrollSingle>(this, "CCS_collegeScrollSingle_", _TableTree.size(), 0);
  auto l_CurLineIndex = 1;
  struct l_RPos{
    EScience _Data;
    Node *_Base;
  };
  GHashMap<EScience, l_RPos> l_TablePos;
  for(size_t iii = 0; iii < l_TableIconList.size(); iii++){
    auto l_V = l_TableIconList[iii];
    _RScienceIcon l_OneIcone;
    l_OneIcone._Data = _TableTree[iii];
    l_OneIcone._Base = l_V;
    l_OneIcone._Point = nullptr;
    _ArrTechnologyIcon.push_back(l_OneIcone);
    l_TablePos[_TableTree[iii]] = { _TableTree[iii], l_V };
    auto l_SingleDetails = ScienceCtrl::Get()->GetTechDetails(_TableTree[iii], 0);
    for(size_t jjj = 0; jjj < l_SingleDetails._Tech.size(); jjj++){
      auto l_NeedTech = l_SingleDetails._Tech[jjj];
      auto l_Node = l_TablePos[l_NeedTech._Tid]._Base;
      if(l_Node){
        auto l_Line = UIWarTechnologyScrollLine::Create();
        _Scroll->addChild(l_Line, -1);
        l_Line->setPosition(l_V->getPosition());
        auto l_PosX = l_Node->getPositionX() - l_V->getPositionX();
        auto l_PosY = l_Node->getPositionY() - l_V->getPositionY();
        UIWarTechnologyScrollLine::RSkillLineData l_Data;
        l_Data._Id = _TableTree[iii];
        l_Data._ToId = l_TablePos[l_NeedTech._Tid]._Data;
        l_Data._Type = _TreeType;
        l_Data._PosX = l_PosX;
        l_Data._PosY = l_PosY;
        l_Line->InitData(l_Data, _FrameLine, _FrameLineHl, true);
      }
    }
  }
  InitCollegeList();
}

void UICollegeScrollView::InitCollegeList(){
  auto l_ScrollInner = _Scroll->getInnerContainer();
  auto l_OffsetY = -l_ScrollInner->getPositionY();
  auto l_ScrollH = _Scroll->getContentSize().height;
  auto l_BeginY = std::max(0.0f, l_OffsetY - 0.5f * l_ScrollH);
  auto l_EndY = l_OffsetY + 1.5f * l_ScrollH;
  for(auto l_V : _ArrTechnologyIcon){
    if(l_V._Point){
      if(l_V._Base->getPositionY() < l_BeginY || l_V._Base->getPositionY() > l_EndY){
        l_V._Point->setVisible(false);
        _TableSpare.push_back(l_V._Point);
        l_V._Point = nullptr;
      }
    }else if(l_BeginY <= l_V._Base->getPositionY() && l_EndY >= l_V._Base->getPositionY()){
      UICollegeScrollSingle *l_Single = nullptr;
      if(_TableSpare.size() > 0){
        l_Single = _TableSpare.back();
        _TableSpare.pop_back();
        l_Single->setVisible(true);
      }else{
        l_Single = UICollegeScrollSingle::Create();
        l_Single->SetScroll(_Scroll);
        _Scroll->addChild(l_Single);
      }
      l_Single->SetTimeVisble(true);
      l_Single->InitData(l_V._Data, _TreeType);
      l_Single->setPosition(l_V._Base->getPosition());
      l_Single->setLocalZOrder(l_V._Base->getLocalZOrder());
      l_V._Point = l_Single;
    }
  }
}

void UICollegeScrollView::ScrollEventCallBack(Ref *p_Sender, ui::ScrollView::EventType p_Type){
  if(p_Type == ui::ScrollView::EventType::CONTAINER_MOVED){
    InitCollegeList();
  }
}

UICollegeScrollSingle *UICollegeScrollView::GetCollegeSingleById(EScience p_Id){

  auto l_CurI = JumpToTechnologyByID(p_Id);
  if(_ArrTechnologyIcon.size() <= l_CurI)
      return nullptr;
  if(_ArrTechnologyIcon[l_CurI]._Point)
    return _ArrTechnologyIcon[l_CurI]._Point;
  return nullptr;
}

size_t UICollegeScrollView::JumpToTechnologyByID(EScience p_Id){
  auto l_CurI = 0;
  for(size_t iii = 0; iii < _TableTree.size(); iii++){
    if(p_Id == _TableTree[iii]){
      auto l_ScrollInner = _Scroll->getInnerContainer();
      auto l_ScrollH = _Scroll->getContentSize().height;
      auto l_SingleY = _ArrTechnologyIcon[iii]._Base->getPositionY();
      auto l_OffsetY = std::max(std::min(0.0f, 0.6f * l_ScrollH - l_SingleY), l_ScrollH - l_ScrollInner->getContentSize().height);
      l_ScrollInner->setPositionY(l_OffsetY);
      l_CurI = iii;
      break;
    }
  }
  InitCollegeList();
  return l_CurI;
}