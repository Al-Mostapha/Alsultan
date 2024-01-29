#include "UIBuildCreatePanel.h"
#include "Base/Base.Geometry.h"
#include "Base/Base.create.h"
#include "Base/Base.View.h"
#include "Base/Common/Common.Type.h"
#include "cocostudio/CocoStudio.h"
#include "Include/IncludeConfig.h"
#include "Module/UI/UI.Create.h"
#include "Base/Common/Common.Teml.h"
#include "Include/IncludeBuildingFunc.h"
#include "Module/UI/Part/UIWheelScrollView.h"
#include "Module/UI/Panel/Building/UIBuildCreateScrollSingle.h"
#include "Module/UI/Panel/Building/Common/Info/UIBuildingCreateInfoPanel.h"
#include "Game/Common/GamePanel.Mgr.h"
#include "Module/City/City.Func.Parm.h"


UIBuildCreatePanel *UIBuildCreatePanel::Create(){
  return Create(CsbUiFilePath::UIPanelCreatBuilding);
}

void UIBuildCreatePanel::Ctor(){
  BindBtnClose();
  m_LabelDes   = GBase::DGetChildByName<ui::Text *>(this, "Text_des");
  m_LabelCount = GBase::DGetChildByName<ui::Text *>(this,"Text_count");
  m_LabelNeed  = GBase::DGetChildByName<ui::Text *>(this,"Text_need");
  m_LabelName  = GBase::DGetChildByName<ui::Text *>(this,"Text_name");
  m_BackGround = GBase::DGetChildByName<ui::ImageView *>(this,"Image_bbg");
  m_BtnBuild   = GBase::DGetChildByName<ui::Button *>(this,"Button_build");
  m_NodeLeft   = GBase::DGetChildByName<ui::Layout *>(this,"Center_Panel_left");
  m_NodeRight  = GBase::DGetChildByName<ui::Layout *>(this,"Center_Panel_right");
  m_NodeTop    = GBase::DGetChildByName<ui::Layout *>(this,"Top_Panel");
  m_NodeBottom = GBase::DGetChildByName<ui::Layout *>(this,"Bottom_Panel");
  m_NodeCenter = GBase::DGetChildByName<Node *>(this,"Center_Node");
  m_LabelCount->setVisible(false);  
  m_LabelNeed->setVisible(false); 
  
  m_BackGround->setScale9Enabled(false);
  
  m_BtnBuild->setTitleText(Translate::i18n("common_text_042"));
  m_BtnBuild->addTouchEventListener(CC_CALLBACK_2(UIBuildCreatePanel::CreateButtonCallFunc, this));

  m_NodeTop->setContentSize(Size(640, Director::getInstance()->getVisibleSize().height - (m_NodeLeft->getPositionY() + 0.5 * m_NodeLeft->getContentSize().height)));
  m_NodeBottom->setContentSize(Size(640, m_NodeLeft->getPositionY() - 0.5 * m_NodeLeft->getContentSize().height));
  m_NodeLeft->setOpacity(0);
  m_NodeRight->setOpacity(0);
  m_NodeTop->setOpacity(0);
  m_NodeBottom->setOpacity(0);
  m_LabelDes->setOpacity(0);
  m_LabelCount->setOpacity(0);
  m_LabelNeed->setOpacity(0);

  // SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_BUILD_CREATE_POINT", function(target, data)
  //   if data.bid then
  //     self:selectWheelByBid(data.bid)
  //   elseif data.key and data.key == "wheel" then
  //     self:createWheelGuide()
  //   end
  // end)
  // SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_BUILD_CREATE_POINT_HIDE", function(target, data)
  //   local node = self.nodeCenter:getChildByName("wheelGuideEffectNode")
  //   if node then
  //     self.nodeCenter:removeChild(node, true)
  //   end
  // end)
  // SoraDAddMessage(self, "MESSAGE_SERVER_GUIDE_END", function(...)
  //   local node = self.nodeCenter:getChildByName("wheelGuideEffectNode")
  //   if node then
  //     self.nodeCenter:removeChild(node, true)
  //   end
  // end)
}

void UIBuildCreatePanel::SetBuildingTypeAndData(EBuildingPlace pType, EBuildingIndex pIndex){
  _BuildingIndex = pIndex;
  _BuildingType = pType;
  _BuildableList = BuildingLib::getCanBuildList(pType);
  if(_SelectWheel == nullptr){
    CreateWheelScrollView();
    _SelectWheel->setVisible(false);
    runAction(
      Sequence::create(
        CallFunc::create( [this](){
          this->m_BtnBuild->setScale(0.1f);
          this->m_NodeLeft->runAction( FadeIn::create(0.5));
          this->m_NodeRight->runAction(FadeIn::create(0.5));
          this->m_NodeTop->runAction(FadeIn::create(0.5));
          this->m_NodeBottom->runAction(FadeIn::create(0.5));
          this->m_LabelDes->runAction(FadeIn::create(0.5));
          this->m_LabelCount->runAction(FadeIn::create(0.5));
          this->m_LabelNeed->runAction(FadeIn::create(0.5));
          this->m_BtnBuild->runAction(Sequence::create(
            ScaleTo::create(0.3f, 1.2f),
            ScaleTo::create(0.1f, 1.0f),
            nullptr
          ));
        }),
        DelayTime::create(0.4f),
        CallFunc::create([this](){
          this->_SelectWheel->UnfoldAction(0.5);
          this->_SelectWheel->setVisible(true);
        }),
        DelayTime::create(0.6f),
        // this is Guid
        /**cca.callFunc(function(...)
            local guideStep = SoraDIsGameGuide()
            if guideStep then
              if guideStep == 2003 then
                print("\232\181\176\230\150\176\230\137\139\229\188\149\229\175\188\230\173\165\233\170\164 \229\187\186\231\173\145\229\187\186\233\128\160")
                SoraDSendMessage({
                  msg = "MESSAGE_SERVER_GUIDE_STEP_ON",
                  step = 2004
                })
              elseif guideStep == 2013 then
                SoraDSendMessage({
                  msg = "MESSAGE_SERVER_GUIDE_STEP_ON",
                  step = 2014
                })
              end
            end
            if GLOBAL_BUILD_PRE_BID then
              self:selectWheelByBid(GLOBAL_BUILD_PRE_BID)
              GLOBAL_BUILD_PRE_BID = nil
            end
          end)*/
        nullptr
      )// Sequance::Create
    ); // runAction
  }
}

// createButtonCallFun
void UIBuildCreatePanel::CreateButtonCallFunc(Ref *pSender, ui::Widget::TouchEventType pType){
  if(pType != Widget::TouchEventType::ENDED)
    return;
  GBase::PlaySound();
  _SelectWheel->selectedCellIndex(_CurrentIndex);
  auto lPanel = UIBuildingCreateInfoPanel::Create();
  lPanel->SetIsFromCreate(true);
  lPanel->InitBuildData({
    _CurrentBuilding.BuildingID,
    _CostBuildingUpgrade,
    {
      _BuildingType,
      _BuildingIndex
    }
  });
  lPanel->Show();
}

void UIBuildCreatePanel::UpdateView(){

  m_LabelDes->setString(Translate::i18n(_CurrentBuilding.BuildingBrief.c_str()));
  m_LabelCount->setVisible(_CurrentBuilding.bType == EBuildingPlace::Outer);
  m_LabelNeed->setVisible(!_CurrentBuilding.isCanBuild);
  m_LabelName->setString(Translate::i18n(_CurrentBuilding.BuildingName.c_str()));
  m_BtnBuild->setTouchEnabled(_CurrentBuilding.isCanBuild);
  m_BtnBuild->setBright(_CurrentBuilding.isCanBuild);

  bool l_ISCanBuild  = BuildingLib::isCanBuild(_CurrentBuilding.BuildingID);
  if(!_CurrentBuilding.isCanBuild){
    m_LabelNeed->setString("");
  }

  auto l_IsCanBuild = BuildingLogic::Get()->IsCanBuild(_CurrentBuilding.BuildingID);
  _CostBuildingUpgrade = l_IsCanBuild.Second;

  if(!_CurrentBuilding.isCanBuild){
    m_LabelNeed->setString(Translate::i18n("common_text_763", {
      {"name", BuildingStatic::getBuildingSpecs(_CostBuildingUpgrade._CostBuilding[0].TypeReq).BuildingName},
      {"lvl",  std::to_string(_CostBuildingUpgrade._CostBuilding[0].lvlReq)},
    }));
  }

  if(_CurrentBuilding.bType == EBuildingPlace::Outer){
    m_LabelCount->setString(Translate::i18n("common_text_739", {
      {"cur", std::to_string(BuildingCtrl::Get()->getBuildingCount(_CurrentBuilding.BuildingID))},
      {"max",  std::to_string(_CurrentBuilding.maxCount)},
    }));
  }

  if(_BuildingIndex == EBuildingIndex::None)
    return;
    
  auto l_Index = _CurrentBuilding.index;
  auto l_BuildingType = _CurrentBuilding.BuildingID;
/*
  SoraDSendMessage({
    msg = "MESSAGE_MAINCITYVIEW_ADD_BUILD_PREVIEW",
    index = index,
    bid = bid
  })*/
}

void UIBuildCreatePanel::WheelScrollBack(const RBuildingSpecs& p_BuildingInfoUnit, size_t p_Index){
  _CurrentIndex = p_Index;
  _CurrentBuilding = p_BuildingInfoUnit;
  UpdateView();
}

void UIBuildCreatePanel::SelectWheelByBuildingType(EBuilding p_BuildingType){
  if(!_SelectWheel)
    return;
  
  auto l_CurIndex = 1;
  for(int l_I = 0; l_I < _BuildableList.size(); l_I++){
    if(p_BuildingType == _BuildableList[l_I].BuildingID){
      l_CurIndex = l_I;
    }
  }
  _SelectWheel->selectedCellIndex(l_CurIndex);
  _CurrentBuilding = _BuildableList[l_CurIndex];
  _CurrentIndex = l_CurIndex;
}

void UIBuildCreatePanel::CreateWheelScrollView(){

  GVector<UIBuildCreateScrollSingle *> l_ScrollViews;
  for(auto l_BuildingUnit : _BuildableList){
    if(l_BuildingUnit.BuildingID == EBuilding::None)
      continue;
    auto l_ScrollSingle = UIBuildCreateScrollSingle::Create();
    l_ScrollSingle->initData(l_BuildingUnit.BuildingID);
    l_ScrollViews.push_back(l_ScrollSingle);
  }
  if(l_ScrollViews.size() <= 0){
    return;
  }
  if(_SelectWheel){
    _SelectWheel->removeFromParent();
    _SelectWheel = nullptr;
  }
  UIWheelScrollViewArgs l_WheelScrollViewArgs;
  l_WheelScrollViewArgs.m_WidgetArray = *(GVector<ui::Widget *> *) &l_ScrollViews; 
  auto l_Size = Size(500, std::max(600.0f, Director::getInstance()->getVisibleSize().height - 270));
  l_WheelScrollViewArgs.m_CellHeight = 130;
  l_WheelScrollViewArgs.m_CircleRadius = 450;
  _SelectWheel =  UICreate::Get()->DCreateWheelScrollView(
    *(GVector<Node *> *) &l_ScrollViews, l_Size, 130.f, 450.f
  );
  if(_SelectWheel){
    _SelectWheel->SetItemSelectedListener([this](size_t p_Index, Node *p_Node){
      WheelScrollBack(_BuildableList[p_Index], p_Index);
    });

    m_NodeCenter->addChild(_SelectWheel, 0);
    _SelectWheel->setPosition(Vec2(0, std::min(-165.0f, 270.0f - m_NodeCenter->getPosition().y)));
    _SelectWheel->selectedCellIndex(std::min(_CurrentIndex, (int)l_ScrollViews.size()));
    _SelectWheel->setInertiaValue(0.1);
    GBase::DFTarget(_SelectWheel);
  }
  /*  This is Guide */
  // local curChapterID = newPlayerTaskCtrl:getCurChapterID()
  // for i, v in ipairs(self.tableBuildList) do
  //   if (curbid and curbid == v.bid or v.bid == BUILDID.MILITARY_TENT) and (curbid == BUILDID.MILITARY_TENT or not newPlayerTaskCtrl:isTaskFinish(4103203) and v.bid == BUILDID.MILITARY_TENT and curChapterID == 4103200) then
  //     self.tableCurIndex = i
  //     self.selectWheel:selectedCellIndex(self.tableCurIndex)
  //     mildGuideManager:starMildByNewPlayerQuestID(gNewPLayerTaskType.TO_BUILD_MILITARY_TENT)
  //   end
  // end

}

void UIBuildCreatePanel::OnExitPanel(){
  GBase::DRemoveMessageFromTargetByName(this, "MESSAGE_RESOURCE_UPDATE");
  GBase::DRemoveMessageFromTargetByName(this, "MESSAGE_ITEM_COUNT_CHANGE_BAG_BACK");
  static RDoOffestMoveParam l_Param;
  l_Param._OffsetType = EMainCityViewOffsetType::Recover;
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_OFFSET_BUILD", &l_Param);
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_PREVIEW", &_BuildingIndex);
  GBase::DHideCurrentSceneViewAndMainUI({false, false});
  // if SoraDIsGameGuide() == 12001 then
  //   SoraDSendMessage({
  //     msg = "MESSAGE_SERVER_CLOSE_GUIDE"
  //   })
  // end
}

void UIBuildCreatePanel::ClickEffect(Node *p_Target){
  auto l_PartNode = BaseCreate::createParticle("et_dianji_display.plist", Vec2(), Vec2(), 0.0f);
  l_PartNode->setName("particle_click_node");
  l_PartNode->setPosition(p_Target->getContentSize().width / 2 -30, p_Target->getContentSize().height / 2 - 30);
  p_Target->addChild(l_PartNode, -1);
}

void UIBuildCreatePanel::CreateWheelAction(){

  auto l_GuideNode = m_NodeCenter->getChildByName("wheelGuideEffectNode");
  if(!l_GuideNode)
    return;
  auto l_SpriteHand =l_GuideNode->getChildByName("spriteHand");
  if(!l_SpriteHand)
    return;
  /*if not (self.tableCurBuild.bid <= BUILDID.SAWMILL) or not SoraDFPoint(185, 345, -10) then
    end
    if not (self.tableCurBuild.bid <= BUILDID.SAWMILL) or not SoraDFPoint(185, 205, -10) then
    end
    if not (self.tableCurBuild.bid <= BUILDID.SAWMILL) or not SoraDFPoint(180, 135, -10) then
    end*/
  auto l_HandAction = Sequence::create(
    CallFunc::create([&](){
      /*if not (self.tableCurBuild.bid <= BUILDID.SAWMILL) or not SoraDFPoint(265, 395, -10) then
        end*/
      l_SpriteHand->setVisible(true);
      //spriteHand:setPosition((SoraDFPoint(180, 135, -10)))
      l_SpriteHand->setPosition(180, 135);
    }),
    FadeIn::create(0.2f),
    ScaleTo::create(0.2f, 1.2f),
    ScaleTo::create(0.2f, 1.0f),
    DelayTime::create(0.5),
    BezierTo::create(1.0, {
      GBase::DFPoint(185, 205, -10),
      GBase::DFPoint(185, 345, -10),
      GBase::DFPoint(265, 395, -10)
    }),
    DelayTime::create(0.5),
    FadeOut::create(0.5),
    CallFunc::create([&](){
      l_SpriteHand->setVisible(false);
    }),
    DelayTime::create(0.5),
    CallFunc::create([this](){
      this->CreateWheelAction();
    }),
    nullptr
  );
  l_SpriteHand->runAction(l_HandAction);
}

// function BuildCreatePanel:gameGuide_getTarget(itemName, parameters)
//   if itemName == "Button_build" then
//     return SoraDGetChildByName(self, itemName)
//   elseif itemName == "tent" then
//     for i, v in ipairs(self.selectWheel.itemArray) do
//       if v.tableSingleData.bid == BUILDID.MILITARY_TENT then
//         return SoraDGetChildByName(v, "Image_lock")
//       end
//     end
//   else
//     return SoraDGetChildByName(self, itemName)
//   end
//   return nil
// end
// function BuildCreatePanel:createWheelGuide()
//   if SoraDIsGameGuide() == 850101 and self.tableCurIndex == 2 then
//     SoraDSendMessage({
//       msg = "MESSAGE_SERVER_GUIDE_STEP_END",
//       step = 850101
//     })
//     return
//   end
//   local effectNode = display.newNode()
//   effectNode:setName("wheelGuideEffectNode")
//   effectNode:addTo(self.nodeCenter, 99)
//   local wheelBg = display.newSprite("#frame_build_orbit.png", 245, 270)
//   wheelBg:setRotation(SoraDFSign(20))
//   wheelBg:addTo(effectNode)
//   local spriteHand = SoraDFingerAction()
//   spriteHand:setPosition(cc.p(300, 400))
//   spriteHand:setName("spriteHand")
//   spriteHand:addTo(effectNode)
//   SoraDFTarget(effectNode)
//   SoraDFTarget(wheelBg, nil, true)
//   SoraDFTarget(spriteHand)
//   self:createWheelAction()
//   self.btnBuild:setTouchEnabled(false)
//   self.btnBuild:setBright(false)
// end
// function BuildCreatePanel:createWheelAction()
//   if self.nodeCenter:getChildByName("wheelGuideEffectNode") == nil then
//     return
//   end
//   local spriteHand = self.nodeCenter:getChildByName("wheelGuideEffectNode"):getChildByName("spriteHand")
//   if spriteHand then
//     if not (self.tableCurBuild.bid <= BUILDID.SAWMILL) or not SoraDFPoint(185, 345, -10) then
//     end
//     if not (self.tableCurBuild.bid <= BUILDID.SAWMILL) or not SoraDFPoint(185, 205, -10) then
//     end
//     if not (self.tableCurBuild.bid <= BUILDID.SAWMILL) or not SoraDFPoint(180, 135, -10) then
//     end
//     local newAction = cca.seq({
//       cca.callFunc(function(...)
//         if not (self.tableCurBuild.bid <= BUILDID.SAWMILL) or not SoraDFPoint(265, 395, -10) then
//         end
//         spriteHand:setPosition((SoraDFPoint(180, 135, -10)))
//         spriteHand:setVisible(true)
//       end),
//       cca.fadeIn(0.2),
//       cca.scaleTo(0.2, 1.2),
//       cca.scaleTo(0.2, 1),
//       cca.delay(0.5),
//       cc.BezierTo:create(1, {
//         SoraDFPoint(185, 205, -10),
//         SoraDFPoint(185, 345, -10),
//         (SoraDFPoint(265, 395, -10))
//       }),
//       cca.delay(0.5),
//       cca.fadeOut(0.5),
//       cca.callFunc(function(...)
//         spriteHand:setVisible(false)
//       end),
//       cca.delay(0.5),
//       cca.callFunc(function(...)
//         self:createWheelAction()
//       end)
//     })
//     spriteHand:runAction(newAction)
//   end
// end