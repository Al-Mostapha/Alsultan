#include "UIHeroList.View.h"
#include "Base/Common/Common.Teml.h"
#include "Module/Hero/Hero.LtCtrl.h"
#include "Module/Hero/Hero.Ctrl.h"

UIHeroListView *UIHeroListView::Create()
{
  return Create("UiParts/Panel/Hero/Detail/heroListView.csb");
}

void UIHeroListView::Ctor(){

}

void UIHeroListView::Show()
{
  _IsHideCurrentSceneView = true;
  _Switcher = false;
  _RankIndex = 1;
  _CurClass = EHeroClass::All;
  _CurSortType = EHeroSortType::Quality;
  _NodeTitle = GBase::DGetExtendChildFromCCSByName<UICommonFramTitle>(this, "Top_CCS_commonFramTitle_heroDetail");
  _NodeTitle->SetTitle(Translate::i18n("hero_title_07"));
  _NodeTitle->SetBtnHelpClickCallBack([this](Ref *button, ui::Widget::TouchEventType eventType){
    if (eventType == ui::Widget::TouchEventType::ENDED){
      GBase::PlaySound();
      if (GBase::Const::Get()->IsArClient){
        //userSDKManager.showSingleFAQ(gSDKDef.FAQSingleType::HERO_SYS);
      }
      else{
        //userSDKManager.showFAQSection(gSDKDef::FAQSectionType::HERO_SYS);
      }
    }
  });
  _NodeTop = GBase::DGetChildByName<Node *>(this, "Top_Node");
  _BtnClass = GBase::DGetChildByName<ui::Button *>(this, "Button_class");
  _Scroll = GBase::DGetChildByName<ui::ScrollView *>(this, "Top_Size_ScrollView_heros");
  _NodeHave = GBase::DGetChildByName<Node *>(this, "Node_div_have");
  _NodeHave->getChildByName<ui::Text *>("Text_divTitle")->setString(Translate::i18n("common_text_102"));
  _NodeNoHave = GBase::DGetChildByName<Node *>(this, "Node_div_noHave");
  _NodeNoHave->getChildByName<ui::Text *>("Text_divTitle")->setString(Translate::i18n("hero_title_08"));
  _BottomNode = GBase::DGetChildByName<Node *>(this, "Bottom_Node");
  _NodeSort = GBase::DGetChildByName<Node *>(this, "Node_sort");
  _TextFriendNum = GBase::DGetChildByName<ui::Text *>(_NodeSort, "Text_friendNum");
  _TxtNum = GBase::DGetChildByName<ui::Text *>(_NodeSort, "Text_friendNum");
  _NodeChooseList = GBase::DGetChildByName<Node *>(_NodeSort, "Node_chooseList");
  _ImageBorder = GBase::DGetChildByName<ui::ImageView *>(_NodeChooseList, "Image_border");
  _TextChoose = GBase::DGetChildByName<ui::Text *>(_NodeChooseList, "Text_choose");
  _ButtonChoose = GBase::DGetChildByName<ui::Button *>(this, "Button_choose");
  _ButtonChoose->addTouchEventListener(CC_CALLBACK_2(UIHeroListView::OnChooseClick, this));
  _ButtonPower = GBase::DGetChildByName<ui::Button *>(this, "Button_power");
  _ButtonPower->setTitleText(Translate::i18n("hero_text_112"));
  _ButtonChoose->setTitleText(Translate::i18n("hero_text_112"));
  _ButtonPower->addTouchEventListener(CC_CALLBACK_2(UIHeroListView::OnPowerClick, this));
  _ButtonCastle = GBase::DGetChildByName<ui::Button *>(this, "Button_castle");
  _ButtonCastle->setTitleText(Translate::i18n("hero_text_113"));
  _ButtonCastle->addTouchEventListener(CC_CALLBACK_2(UIHeroListView::OnCastleClick, this));
  _ButtonRare = GBase::DGetChildByName<ui::Button *>(this, "Button_rare");
  _ButtonRare->setTitleText(Translate::i18n("hero_text_114"));
  _ButtonRare->addTouchEventListener(CC_CALLBACK_2(UIHeroListView::OnRareClick, this));
  _ButtonStory = GBase::DGetChildByName<ui::Button *>(this, "Button_story");
  _ButtonStory->setTitleText(Translate::i18n("Biography_text_11"));
  _ButtonStory->addTouchEventListener(CC_CALLBACK_2(UIHeroListView::OnStoryClick, this));
  _NodeRed = GBase::DGetChildByName<Node *>(_ButtonStory, "Node_red");
  _NodeRed->setVisible(false);
  _TextPoint = GBase::DGetChildByName<ui::Text *>(_NodeRed, "Text_point");
  InitBtns();
  SetSwitcher();
  if(_Btns.size() > 0)
  BtnClassClick(_Btns[_Btns.size() - 1], ui::Widget::TouchEventType::ENDED, true);
  UpdateHeroStory(nullptr);
}

void UIHeroListView::OnMessageListener(){
  // SoraDAddMessage(self, "MESSAGE_ITEM_CHANGE_TYPE", handler(self, self.recevieItemChangeMsg))
  // SoraDAddMessage(self, "MESSAGE_ITEM_SPEED_UP_BACK", handler(self, self.bindData))
  // SoraDAddMessage(self, "MESSAGE_SERVER_HERO_RECRUITSUCCESS", handler(self, self.bindData))
  // SoraDAddMessage(self, "MESSAGE_SERVER_HERO_STARTUPGRADE", handler(self, self.bindData))
  // SoraDAddMessage(self, "MESSAGE_SERVER_HERO_RESURGENCESUCCESS", handler(self, self.bindData))
  // SoraDAddMessage(self, "MESSAGE_UI_HERO_REFRESHLISTVIEW", handler(self, self.bindData))
  // SoraDAddMessage(self, "MESSAGE_SERVER_HERO_NOTICEHERO", handler(self, self.bindData))
  // SoraDAddMessage(self, "MESSAGE_SERVER_HERO_STORY_UPDATE", handler(self, self.updateHeroStory))
  // SoraDAddMessage(self, "MESSAGE_SERVER_HERO_DRESS_UPDATE", handler(self, self.bindData))
}

void UIHeroListView::UpdateHeroStory(EventCustom *p_Event){
  // local num = heroBiographyCtrl:getUnlockHeroStoryNum()
  // self.Node_red:setVisible(num > 0)
  // self.Text_point:setString(num)
}

void UIHeroListView::InitBtns(){
  
  auto l_HeroClassesInfo = HeroLtCtrl::Get()->_HeroClassesInfo.Keys();
  l_HeroClassesInfo.push_back(EHeroClass::All);
  for(size_t iii = 0 ; iii < l_HeroClassesInfo.size(); iii++){

    auto v = l_HeroClassesInfo[iii];
    auto l_Btn = dynamic_cast<ui::Button *>(_BtnClass->clone());
    auto l_Width = (GDisplay::Get()->width - 80) / l_HeroClassesInfo.size();
    l_Btn->setPositionX(GBase::DFSign(iii * l_Width - l_Width / 2 + 40));
    if(static_cast<int32>(v) > 0){
      auto l_SpImageName = HeroLtCtrl::Get()->_HeroClassesInfo[v].Icon;
      auto l_SpRes = GBase::DGetChildByName<Sprite *>(l_Btn, "icon_class");
      l_SpRes->setSpriteFrame(l_SpImageName);
      GBase::DGetChildByName<ui::Text *>(l_Btn, "Text_all_bg")->setVisible(false);
    }else{
      auto l_SpRes = GBase::DGetChildByName<Sprite *>(l_Btn, "icon_class");
      l_SpRes->setVisible(false);
      GBase::DGetChildByName<ui::Text *>(l_Btn, "Text_all")->setString(Translate::i18n("common_text_635"));
    }
    l_Btn->setTag(static_cast<int32>(v));
    _NodeTop->addChild(l_Btn, -1);
    l_Btn->addTouchEventListener([this](Ref *p_Sender, ui::Widget::TouchEventType p_Type){
      this->BtnClassClick(p_Sender, p_Type);
    });
    _Btns.push_back(l_Btn);
  }
  _BtnClass->setVisible(false);
  _BottomNode->setVisible(GBase::DGetCastleLv() >= GBase::Const::Get()->CastleLvl40);
  if(!_BottomNode->isVisible()){
    auto l_ScrollViewSize = _Scroll->getContentSize();
    _Scroll->setContentSize(Size(l_ScrollViewSize.width, l_ScrollViewSize.height + 75));
  }
}

void UIHeroListView::SetSwitcher(){}

void UIHeroListView::BtnClassClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type, bool p_NodSound){}


void UIHeroListView::OnChooseClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type){

}



void UIHeroListView::InitData(EHeroClass p_Class, EHeroSortType p_SortType, bool p_NoJump){
  _HaveHeros = HeroCtrl::Get()->GetHaveHerosListByRule(p_SortType);
  _NoHaveHeros = HeroCtrl::Get()->GetNoHaveHerosListByRule();
  if(static_cast<int32>(p_Class) > 0){
    _HaveHeros = HeroLtCtrl::Get()->FilterHeroClass(p_Class, _HaveHeros);
    _NoHaveHeros = HeroLtCtrl::Get()->FilterHeroClass(p_Class, _NoHaveHeros);
  }
  
  auto l_ComStr = Translate::i18n("common_text_318") + std::to_string(_HaveHeros.size()) + "/" + std::to_string( _NoHaveHeros.size() + _HaveHeros.size());
  _TxtNum->setString(l_ComStr);
  PrepareScrollData(p_NoJump);
}

void UIHeroListView::PrepareScrollData(bool p_NoJump){

  CleanOld();
  auto l_TotalH = 0.f;
  auto l_LineNum = 3;
  if(_HaveHeros.size() > 0){
    l_TotalH += 40;
    l_TotalH += std::ceil(_HaveHeros.size() / l_LineNum) * 280;
  }
  
  auto l_sSize = _Scroll->getContentSize();
  l_TotalH = GMath::Max(l_sSize.height, l_TotalH);
  auto l_Sh = l_TotalH;
  _Scroll->setInnerContainerSize(Size(l_sSize.width, l_Sh));
  if(_HaveHeros.size()){
    _NodeHave->setVisible(true);
    _NodeHave->setPosition(Vec2(l_sSize.width / 2, l_TotalH - 10));
    l_TotalH -= 40;
    for(auto iii = 0; iii < _HaveHeros.size(); iii++){
      auto v = _HaveHeros[iii];
      _TableSingle.push_back(GPair{v, Vec2((iii % l_LineNum) * 210 + 110, l_TotalH)});
      if(iii > 1 && iii % l_LineNum == 0){
        l_TotalH -= 280;
      }
    }
    if(_HaveHeros.size() % l_LineNum != 0){
      l_TotalH -= 280;
    }
  }else{
    _NodeHave->setVisible(false);
  }

  if(_NoHaveHeros.size() > 0){
    _NodeNoHave->setVisible(true);
    _NodeNoHave->setPosition(Vec2(l_sSize.width / 2, l_TotalH - 10));
    l_TotalH = l_TotalH - 40;
    for(auto iii = 0; iii < _NoHaveHeros.size(); iii++){
      auto v = _NoHaveHeros[iii];
      _TableSingle.push_back(GPair{v, Vec2((iii % l_LineNum) * 210 + 110, l_TotalH)});
      if(iii > 1 && iii % l_LineNum == 0){
        l_TotalH -= 320;
      }
    }
  } else {
    _NodeNoHave->setVisible(false);
  }
  InitScrollList();
  // if not self.initScrollEvent then
  //   self.scroll:addEventListener(handler(self, self.scrollEventCallBack))
  //   self.initScrollEvent = true
  // end
  // if not noJump then
  //   self.scroll:jumpToTop()
  // end
  // if SoraDIsGameGuide() then
  //   local posY = self.tableSingle[#self.haveHeros + 1].posY
  //   self.scroll:jumpToPercentVertical(100 * (self.scroll:getInnerContainerSize().height - posY) / self.scroll:getInnerContainerSize().height)
  // end
}