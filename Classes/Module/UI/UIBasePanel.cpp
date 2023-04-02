#include "UIBasePanel.h"
#include "UICCSView.h"
#include "Base/Common/Panel.Manger.h"
#include "Scene/Main/MainScene.h"

UIBasePanel* UIBasePanel::InitPanel(GString p_CCsFile, RBasePenelData *p_Data){
  m_Panel = UICCSView::Create(p_CCsFile);
  if(p_Data){
    m_Panel->setName(p_Data->FutureName);
  }
  m_Panel->Ctor();
  Ctor();
  return this;
}

UIBasePanel* UIBasePanel::Create(GString p_CCsFile, RBasePenelData *p_Data){
  UIBasePanel *l_Panel = UIBasePanel::create();
  l_Panel->m_Panel = UICCSView::Create(p_CCsFile);
  if(p_Data){
    l_Panel->m_Panel->setName(p_Data->FutureName);
  }
  l_Panel->m_Panel->Ctor();
  l_Panel->Ctor();
  return l_Panel;
}

UIBasePanel* UIBasePanel::InitPanel(Node *p_CCsFile, RBasePenelData *p_Data){
  m_Panel = UICCSView::Create(p_CCsFile);
  if(p_Data){
    m_Panel->setName(p_Data->FutureName);
  }
  m_Panel->Ctor();
  Ctor();
  return this;
}

void UIBasePanel::Ctor(){
  m_IsADShow = RechargeADRead::Get()->IsADOpen(m_Panel->getName());
  m_IsHaveTextField = false;
  m_IsHideCurrentSceneView = false;
  m_IsHidePrePanel = true;
  m_ShowPanelPowerValue = 1;
  m_FadeInDelay = 0.0f;
  m_ScaleActTarget = nullptr;
  m_NeedCallBack2SDK = false;
  m_IsAddToPopManager = false;
  m_IsCantCloseByReturn = false;
  DeviceFitOffset();
}

void UIBasePanel::BindBtnClose(){
  m_CloseButton = GBase::GetChildByName<ui::Button*>(m_Panel, "Button_close");
  if(m_CloseButton){
    m_CloseButton->addTouchEventListener([this](Ref *p_Ref, ui::Widget::TouchEventType p_Type){
      if(p_Type == ui::Widget::TouchEventType::ENDED){
        GBase::PlaySound("uicontrol", 1);
        if(this)
          ClosePanel();
      }
    });
  }
}

void UIBasePanel::CloseKeyBoard(){
  auto l_GlView = Director::getInstance()->getOpenGLView();
  if(l_GlView)
    l_GlView->setIMEKeyboardState(false);
}

void UIBasePanel::PanelFadeIn(){
  auto l_CCSView = m_Panel->getChildByName("ccsView");
  if(l_CCSView){
    l_CCSView->setOpacity(0);
    l_CCSView->runAction(FadeIn::create(m_FadeInDelay));
  }
}

void UIBasePanel::PanelScaleAct(){
  if(m_ScaleActTarget){
    m_ScaleActTarget->setScale(0.0f);
    m_ScaleActTarget->runAction(EaseBackOut::create(ScaleTo::create(0.3f, 1.0f)));
  }
}

void UIBasePanel::PanelScaleActBack(){
  if(m_ScaleActTarget){
    m_ScaleActTarget->setScale(1);
    m_ScaleActTarget->runAction(
      Sequence::create(
        EaseBackIn::create(ScaleTo::create(0.3f, 0.0f)),
        CallFunc::create([this](){
          if(this)
            m_Panel->removeFromParent();
        }), 
        nullptr
      )
    );
  }
}

void UIBasePanel::DeviceFitOffset(){
  auto l_PreViewHeight = m_Panel->getContentSize().height;
  auto l_Scale = m_Panel->GetPanelOffsetHeight() / l_PreViewHeight;
  if(l_PreViewHeight != 960 && l_PreViewHeight != 1136){
    m_Panel->setScale(l_Scale);
    return;
  }
  auto l_CCSView = m_Panel->getChildByName("ccsView");
  if(!l_CCSView)
    return;
  l_CCSView->setContentSize(GDisplay::Get()->size());
  m_Panel->setContentSize(GDisplay::Get()->size());
  auto l_AllChild = l_CCSView->getChildren();
  for(auto l_Child : l_AllChild){
    auto l_ChildName = l_Child->getName();
    auto l_NameTabel = GStringUtils::Split(l_ChildName, "_");
    GString l_OffsetType = "";
    if(l_NameTabel.size())
        l_OffsetType = l_NameTabel[0];
    for(auto i = 1; i < (int32)l_NameTabel.size(); i++){
      auto l_Value  = l_NameTabel[i];
      if(l_Value =="Size"){
        auto l_SetSize = Size(
          l_Child->getContentSize().width,
           l_Child->getContentSize().height + m_Panel->GetPanelOffsetHeight() - l_PreViewHeight);
        l_Child->setContentSize(l_SetSize);
      } else if(l_Value == "Tile"){
        //l_Child->setFillType(1);
      }else if(l_Value == "ySize"){
        auto l_SetSize = Size(l_Child->getContentSize().width + m_Panel->GetPanelOffsetHeight() - l_PreViewHeight, l_Child->getContentSize().height);
        l_Child->setContentSize(l_SetSize);
      }
    }
    if(l_ChildName == "Image_bg"){
      l_Child->setContentSize(GDisplay::Get()->size());
    }
    if(l_OffsetType == "Top"){
      if(m_IsADShow.ADType == 1 && l_NameTabel.size() >= 4 && l_NameTabel[3] == "commonFramTitle"){
        l_Child->setPositionY(GDisplay::Get()->height - (l_PreViewHeight - l_Child->getPositionY()));
        AddRechargeADNode(l_Child);
        m_IsADShow.ADType = 2;
      }else{
        l_Child->setPositionY(m_Panel->GetPanelOffsetHeight() - (l_PreViewHeight - l_Child->getPositionY()));
      }
      if(m_IsADShow.ADType == 1){
        auto l_TopNodeChild = l_Child->getChildren();
        for(auto l_TopChild : l_TopNodeChild){
          auto l_TopChildName = l_TopChild->getName();
          auto l_TopNameTabel = GStringUtils::Split(l_TopChildName, "_");
          if(l_TopNameTabel.size() >= 3 && l_TopNameTabel[2] == "commonFramTitle"){
            l_TopChild->setPositionY(l_TopChild->getPositionY() + (GDisplay::Get()->height - m_Panel->GetPanelOffsetHeight()));
            AddRechargeADNode(l_TopChild);
            m_IsADShow.ADType = 2;
            break;
          }
        }
      }
    }else if(l_OffsetType == "Center"){
      l_Child->setPositionY(l_Child->getPositionY() * l_Scale);
    }else if(l_OffsetType == "Bottom"){}
  }
}

UIRechargeTinyPageNode *UIBasePanel::AddRechargeADNode(Node *p_Node){
  //auto l_Node  = GBase::GetChildByName<UIRechargeTinyPageNode *>(this, "rechargeTinyPageNode");
  // if(l_Node == nullptr){
  //   l_Node = UIRechargeTinyPageNode::Create();
  //   p_Node->addChild(l_Node, -1);
  // }
  // l_Node->setPosition(Vec2(0, RECHARGE_AD_OFFSET_Y));
  // if(m_IsADShow.MenuID != 0)
  //   l_Node->SetMyGiftType(m_IsADShow.MenuID);
  return nullptr;
}

bool UIBasePanel::JudgeShowPanelPower(){
  auto l_ConfirmToPop = true;
  auto l_TopPanel = GPanelManger::Get()->DCurrentTopPanelFromManager();
  auto l_TopPanelPowerValue = 1;
  if(l_TopPanel)
    l_TopPanelPowerValue = l_TopPanel->m_ShowPanelPowerValue;
  if(l_TopPanelPowerValue == 1 && m_ShowPanelPowerValue == 1)
    return l_ConfirmToPop;
  if(l_TopPanelPowerValue < m_ShowPanelPowerValue){
    GPanelManger::Get()->DRemoveAllPanelFromManager();
  }else if(l_TopPanelPowerValue > m_ShowPanelPowerValue){
    l_ConfirmToPop = false;
  }
  return l_ConfirmToPop;
}

UIBasePanel *UIBasePanel::Show(Node *p_ParentNode, int32 p_ZOrder){
  auto l_CurrentScene = dynamic_cast<MainScene *>(Director::getInstance()->getRunningScene());
  if(p_ParentNode == nullptr && l_CurrentScene)
    p_ParentNode = l_CurrentScene->PanelView();
  if(!JudgeShowPanelPower())
    return nullptr;
  if(p_ParentNode){
    p_ParentNode->addChild(this, p_ZOrder);
    GPanelManger::Get()->DAddPanelToManager(this);
  }
  if(m_FadeInDelay)
    PanelFadeIn();
  EndShow();
  return this;
}

Node *UIBasePanel::GameGuide_getTarget(GString p_Name){
  return  GBase::GetChildByName<Node *>(m_Panel, p_Name.c_str());
}

void UIBasePanel::ClosePanel(){
  m_Panel->removeFromParent();
}

void UIBasePanel::onExit(){
  Node::onExit();
  if(m_IsHaveTextField)
    CloseKeyBoard();
  OnExitPanel();

  GPanelManger::Get()->DRemovePanelFromManager(this);
  // if self.needCallBack2SDK then
  //   userSDKManager.needCallBack2SDK(self.__cname)
  // end
  if(m_IsAddToPopManager)
    GPanelManger::Get()->DRemovePanelFromManager(this);
  // self:autoCheckTexMemary()
}
