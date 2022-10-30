#include "UICommonShareButton.h"


UICommonShareButton::UICommonShareButton()
{
}

UICommonShareButton::~UICommonShareButton()
{
}

void UICommonShareButton::InitPanel(){
  // self.hiddleModel = 0.5
  m_HiddleModel = 0.5f;
  // self.btnBg = ccui.Button:create("bg_transparent.png", "bg_transparent.png", "bg_transparent.png", ccui.TextureResType.plistType)
  m_BtnBg = ui::Button::create("bg_transparent.png", "bg_transparent.png", "bg_transparent.png", ui::Widget::TextureResType::PLIST);
  m_BtnBg->ignoreContentAdaptWithSize(false);
  m_BtnBg->setAnchorPoint(Vec2(0, 0));
  m_BtnBg->setPosition(Vec2(0, 0));
  m_BtnBg->setContentSize(Size(GBase::Display::Get()->size()));
  this->addChild(m_BtnBg);
  m_BtnBg->setVisible(false);
  m_ImgBg = ui::ImageView::create("frame_jt_bjd.png", ui::Widget::TextureResType::PLIST);
  m_ImgBg->ignoreContentAdaptWithSize(false);
  m_ImgBg->setAnchorPoint(Vec2(0.5, 0.5));
  m_ImgBg->setPosition(Vec2(320, 480));
  m_ImgBg->setScale9Enabled(true);
  m_ImgBg->setCapInsets(Rect(5, 5, 45, 45));
  m_ImgBg->setOpacity(191.25f);
  m_ImgBg->setVisible(false);
  this->addChild(m_ImgBg);
  m_BtnMain = ui::Button::create("icon_jt_ps.png", "icon_jt_ps.png", "icon_jt_ps.png", ui::Widget::TextureResType::PLIST);
  m_BtnWidth = 0.5f * m_BtnMain->getContentSize().width;
  m_BtnMain->setPressedActionEnabled(false);
  m_BtnMain->setAnchorPoint(Vec2(0.5, 0.5));
  m_BtnMain->setPosition(Vec2(GBase::Display::Get()->size().width - 5 - m_BtnWidth, 480));
  m_BtnMain->setOpacity(m_HiddleModel * 255);
  this->addChild(m_BtnMain);
  if(SDKManager::Get()->IsSupportReplay())
    m_TableBtn.push_back({ "icon_jt_cx.png", "screen_btn_01", 1 });
  m_TableBtn = {
    { "icon_jt_kz.png", "screen_btn_02", 2 },
    { "icon_jt_sz.png", "common_text_713", 3 }
  };
  for(int i = 0; i < m_TableBtn.size(); i++){
    auto l_OneBtn = m_TableBtn[i];
    auto l_Btn = ui::Button::create("bg_transparent.png", "bg_transparent.png", "bg_transparent.png", ui::Widget::TextureResType::PLIST);
    l_Btn->setPressedActionEnabled(false);
    l_Btn->setVisible(false);
    this->addChild(l_Btn);
    l_Btn->setTag(l_OneBtn.tag);
    l_Btn->ignoreContentAdaptWithSize(false);
    l_Btn->setContentSize(Size(100, 120));
    l_Btn->addTouchEventListener(CC_CALLBACK_2(UICommonShareButton::BtnClickCallBack, this));
    l_Btn->setSwallowTouches(true);
    auto l_Sprite = Sprite::createWithSpriteFrameName(l_OneBtn.icon);
    l_Sprite->setName("Sprite_icon");
    l_Sprite->setPosition(Vec2(50, 80));
    l_Btn->addChild(l_Sprite);
    auto l_Sprite_2 = Sprite::createWithSpriteFrameName("icon_jt_5.png");
    l_Sprite_2->setName("Sprite_frame");
    l_Sprite_2->setPosition(Vec2(50, 80));
    l_Btn->addChild(l_Sprite_2);
    auto l_Label = ui::Text::create();
    l_Label->setFontSize(22);
    l_Label->setColor(Color3B::WHITE);
    l_Label->setAnchorPoint(Vec2(0.5, 0));
    l_Label->setName("Text_name");
    l_Label->setPosition(Vec2(50, 5));
    l_Label->ignoreContentAdaptWithSize(false);
    l_Label->setTextAreaSize(Size(100, 45));
    l_Label->setContentSize(Size(100, 45));
    l_Label->setString(Translate::i18n(l_OneBtn.key.c_str()));
    l_Label->setTextHorizontalAlignment(TextHAlignment::CENTER);
    l_Label->setTextVerticalAlignment(TextVAlignment::CENTER);
    l_Btn->addChild(l_Label);
    l_OneBtn.Btn = l_Btn;
  }

  m_BtnBg->addTouchEventListener(CC_CALLBACK_2(UICommonShareButton::BtnBgClickCallBack, this));
  m_BtnMain->addTouchEventListener(CC_CALLBACK_2(UICommonShareButton::BtnMainClickCallBack, this));
  ShowGuideAction();
  GBase::DAddMessage(this, "MESSAGE_MAIN_RECORD_SCREEN", CC_CALLBACK_1(UICommonShareButton::StartRecordScreen, this));
  GBase::DAddMessage(this, "MESSAGE_MAIN_STOP_RECORD_SCREEN", CC_CALLBACK_1(UICommonShareButton::StopRecordScreen, this));
}

void UICommonShareButton::Show(){

}

void UICommonShareButton::StartRecordScreen(EventCustom *p_Event) {
  // local btn = self.tableBtn[1].btn
  if(m_TableBtn.size() == 0)
    return;
  auto l_Btn = m_TableBtn[0].Btn;
  GVector<Sprite*> l_ActSprite;
  l_ActSprite.push_back(l_Btn->getChildByName<Sprite*>("Sprite_icon"));
  l_ActSprite.push_back(l_Btn->getChildByName<Sprite*>("Sprite_frame"));
  for(auto l_Sprite : l_ActSprite){
    l_Sprite->runAction(
      RepeatForever::create(
        Sequence::create(FadeOut::create(0.5), FadeIn::create(0.5), nullptr)
      )
    );
  }
  if(!m_Timer){
    RecordTimeTick(Director::getInstance()->getDeltaTime());  
    m_Timer = GBase::DCreateTimer(this, CC_CALLBACK_1(UICommonShareButton::RecordTimeTick, this));
  }
  l_Btn->setTag(4);
  // userSDKManager.logEvent(gSDKDef.TDonEvent.share_button_record_open, {})
}

void UICommonShareButton::StopRecordScreen(EventCustom *p_Event) {
  if(m_TableBtn.size() == 0)
    return;
  auto l_Btn = m_TableBtn[0].Btn;
  GVector<Sprite *> l_ActSprite;
  l_ActSprite.push_back(l_Btn->getChildByName<Sprite*>("Sprite_icon"));
  l_ActSprite.push_back(l_Btn->getChildByName<Sprite*>("Sprite_frame"));
  for(auto l_Sprite : l_ActSprite){
    CCASSERT(l_Sprite, "l_Sprite is null");
    l_Sprite->stopAllActions();
    l_Sprite->setOpacity(255);
  }
  if(m_Timer){
    GBase::DManagerRemoveTimer(m_Timer);
    m_Timer = nullptr;
  }
  l_Btn->setTag(1);
  CCASSERT(l_Btn->getChildByName<ui::Text *>("Text_name"), "m_TableBtn size is error");
  if(l_Btn->getChildByName<ui::Text *>("Text_name"))
    l_Btn->getChildByName<ui::Text *>("Text_name")->setString(Translate::i18n("screen_btn_01"));
  // userSDKManager.logEvent(gSDKDef.TDonEvent.share_button_record_stop, {})
}

void UICommonShareButton::RecordTimeTick(float p_DeltaTime) {
  if(m_TableBtn.size() == 0)
    return;
  auto l_Btn = m_TableBtn[0].Btn;
  CCASSERT(l_Btn->getChildByName<ui::Text *>("Text_name"), "m_TableBtn size is error");
  l_Btn->getChildByName<ui::Text *>("Text_name")->setString(GBase::DConvertSecondToString(0));
}

void UICommonShareButton::FoldBG(){
  m_ImgBg->setContentSize(m_BtnMain->getContentSize());
  m_BtnBg->setVisible(false);
  m_ImgBg->setVisible(false);
  m_BtnMain->setVisible(true);
  for(auto l_OneBtn : m_TableBtn){
    l_OneBtn.Btn->setVisible(false);
  }
  StarMainBtnOpacity(false);

}

void UICommonShareButton::UnFoldBG(){
  UpdateAP();
  m_BtnMain->setVisible(false);
  m_ImgBg->setVisible(true);
  m_ImgBg->setContentSize(Size(100 * m_TableBtn.size(), 120));
  m_BtnBg->setVisible(true);
}

void UICommonShareButton::UpdateAP(){
  auto l_Pos = m_BtnMain->getPosition();
  float l_Ax = 0, l_Ay = 0, l_Vec = 1;
  auto l_Size = m_ImgBg->getContentSize();
  if(l_Pos.x > GBase::Display::Get()->cx){
    l_Ax = 1;
    l_Vec = -1;
    l_Pos.x = l_Pos.x + l_Size.width * 0.5;
  }else{
    l_Pos.x = l_Pos.x - l_Size.width * 0.5;
  }
  if(l_Pos.y > GBase::Display::Get()->cy){
    l_Ay = 1;
    l_Pos.y = l_Pos.y + l_Size.height * 0.5;
  }else{
    l_Pos.y = l_Pos.y - l_Size.height * 0.5;
  }
  m_ImgBg->setAnchorPoint(Vec2(l_Ax, l_Ay));
  m_ImgBg->setPosition(l_Pos);
  for(int i = 0; i < m_TableBtn.size(); i++){
    CCASSERT(m_TableBtn[i].Btn, "m_TableBtn[i].Btn is null");
    m_TableBtn[i].Btn->setAnchorPoint(Vec2(l_Ax, l_Ay));
    m_TableBtn[i].Btn->setPosition(Vec2(l_Pos.x + l_Vec * (i - 1) * 100, l_Pos.y));
    m_TableBtn[i].Btn->setVisible(true);
  }
}

void UICommonShareButton::BtnBgClickCallBack(Ref* p_Sender, ui::Widget::TouchEventType p_Touch) {
  if(p_Touch == ui::Widget::TouchEventType::ENDED)
    FoldBG();
}

void UICommonShareButton::ShowGuideAction() {
  // if SoraDConfigGet("Game:Guide:shareButtonFirstShow~bool", {byUID = true}) then
  //   self.btnMain:stopAllActions()
  //   self.btnMain:runAction(cca.repeatForever(cca.seq({
  //     cca.fadeTo(1, self.hiddleModel * 0.75),
  //     cca.fadeTo(0.5, 1)
  //   })))
  // end
}

void UICommonShareButton::StarMainBtnOpacity(bool p_IsTouch) {
  m_BtnMain->stopAllActions();
  m_BtnMain->setOpacity(255);
  if(p_IsTouch)
    return;
  auto l_Pos = m_BtnMain->getPosition();
  auto l_Size = m_BtnMain->getContentSize();
  if(l_Pos.y + 0.5 * l_Size.height >= GBase::Display::Get()->height - l_Size.height){
    l_Pos.y = GBase::Display::Get()->height - 0.5 * l_Size.height - 5;
  }else if(l_Pos.y - 0.5 * l_Size.height <= l_Size.height){
    l_Pos.y = 0.5 * l_Size.height + 5;
  }else if(l_Pos.x >= GBase::Display::Get()->cx){
    l_Pos.x = GBase::Display::Get()->width - 0.5 * l_Size.width - 5;
  }else{
    l_Pos.x = 0.5 * l_Size.width + 5;
  }
  if(l_Pos.x +0.5*l_Size.width + 5 > GBase::Display::Get()->width){
    l_Pos.x = GBase::Display::Get()->width - 0.5 * l_Size.width - 5;
  }else if(l_Pos.x - 0.5 * l_Size.width - 5 < 0){
    l_Pos.x = 0.5 * l_Size.width + 5;
  }
  if(l_Pos.y + 0.5*l_Size.height + 5 > GBase::Display::Get()->height){
    l_Pos.y = GBase::Display::Get()->height - 0.5 * l_Size.height - 5;
  }else if(l_Pos.y - 0.5 * l_Size.height - 5 < 0){
    l_Pos.y = 0.5 * l_Size.height + 5;
  }
  ShowGuideAction();
  m_BtnMain->runAction(
    Sequence::create(
      MoveTo::create(0.2, l_Pos), 
      DelayTime::create(3.8),
      FadeTo::create(0.1, m_HiddleModel),
      nullptr
    )
  );
}

void UICommonShareButton::BtnMainClickCallBack(Ref* p_Sender, ui::Widget::TouchEventType p_Touch) {
  CCASSERT(dynamic_cast<ui::Button *>(p_Sender), "p_Sender is not ui::Button");
  auto l_Button = dynamic_cast<ui::Button *>(p_Sender);
  static bool l_SingleIsMoved = false;
  if(p_Touch == ui::Widget::TouchEventType::ENDED){
    if(l_SingleIsMoved){
      l_SingleIsMoved = false;
      StarMainBtnOpacity(false);
      return;
    }
    //   SoraDConfigSet("Game:Guide:shareButtonFirstShow~bool", false, {byUID = true})
    GBase::PlaySound("");
    UnFoldBG();
    //   userSDKManager.logEvent(gSDKDef.TDonEvent.share_button_main, {})
  }else if(p_Touch == ui::Widget::TouchEventType::MOVED){
    auto l_TouchBeganPoint = l_Button->getTouchBeganPosition();
    auto l_TouchMovePoint = l_Button->getTouchMovePosition();
    auto l_Distance = l_TouchBeganPoint.distance(l_TouchMovePoint);
    if(l_Distance > TOUCH_MOVED_ERROR_VALUE)
      l_SingleIsMoved = true;
    if(l_SingleIsMoved){
      float l_Prolong = 0.5 * m_BtnWidth;
      float l_PosX = std::max(m_BtnWidth - l_Prolong, std::min(l_TouchMovePoint.x, GBase::Display::Get()->width - m_BtnWidth + l_Prolong));
      float l_PosY = std::max(m_BtnWidth - l_Prolong, std::min(l_TouchMovePoint.y, GBase::Display::Get()->height - m_BtnWidth + l_Prolong));
      auto l_Pos = convertToNodeSpace(Vec2(l_PosX, l_PosY));
      m_BtnMain->setPosition(l_Pos);
    }
  }else if(p_Touch == ui::Widget::TouchEventType::CANCELED){
    l_SingleIsMoved = false;
    StarMainBtnOpacity(false);
  }else if (p_Touch == ui::Widget::TouchEventType::BEGAN){
    StarMainBtnOpacity(true);
  }
}

void UICommonShareButton::BtnClickCallBack(Ref* p_Sender, ui::Widget::TouchEventType p_Touch) {
  CCASSERT(dynamic_cast<ui::Button *>(p_Sender), "p_Sender is not ui::Button");
  if(p_Touch == ui::Widget::TouchEventType::ENDED){
    FoldBG();
    auto l_Tag = dynamic_cast<ui::Button *>(p_Sender)->getTag();
    if(l_Tag == 1){
    GBase::PlaySound("");
      //userSDKManager.startRecording()
    }else if(l_Tag == 2){
      //     self.btnMain:setVisible(false)
      m_BtnMain->setVisible(false);
      //       local panel = SoraDCreatePanel("commonSharePic")
      //       panel:initData(SoraDCreateScreenShot(), 1)
      //       panel:show(self)
      m_BtnMain->setVisible(true);
      auto l_View = ui::Layout::create();
      l_View->setContentSize(GBase::Display::Get()->size());
      l_View->setBackGroundColorType(ui::Layout::BackGroundColorType::SOLID);
      l_View->setBackGroundColor(Color3B::WHITE);
      l_View->setBackGroundColorOpacity(255);
      l_View->setAnchorPoint(Vec2(0.5, 0.5));
      l_View->setPosition(Vec2(GBase::Display::Get()->cx, GBase::Display::Get()->cy));
      addChild(l_View, 1);
      l_View->runAction(
        Sequence::create(
          DelayTime::create(0.2),
          FadeOut::create(0.2),
          CallFunc::create([=](){
            l_View->removeFromParent();
          }),
          nullptr
        )
      );
    }else if(l_Tag == 3){
      GBase::PlaySound("");
      //     local panel = SoraDCreatePanel("gameOptionsView")
      //     panel:jumpByName("CCS_gameSettingCommonPanel_share")
      //     panel:show()
      //     userSDKManager.logEvent(gSDKDef.TDonEvent.share_button_set, {})
    }else if(l_Tag == 4){
        GBase::PlaySound("");
        GBase::DSendMessage("MESSAGE_MAIN_STOP_RECORD_SCREEN");
    }
  }
}
/**function CommonShareButton.createSnapshootButton(bigDataType, fromTarget, preCallBack, postCallBack, closeCallBack)
  local btn = ccui.Button:create("bg_transparent.png", "bg_transparent.png", "bg_transparent.png", ccui.TextureResType.plistType)
  btn:setPressedActionEnabled(false)
  btn:setAnchorPoint(cc.p(0.5, 0.5))
  btn:ignoreContentAdaptWithSize(false)
  btn:setContentSize(cc.size(70, 70))
  btn:addTouchEventListener(function(button, type)
    if type == ccui.TouchEventType.ended then
      button:setVisible(false)
      if preCallBack then
        preCallBack()
      end
      SoraDSendMessage({
        msg = "MESSAGE_SERVER_OPTION_SHARE_BTN_UPDATE",
        otherPic = false
      })
      do
        local panel = SoraDCreatePanel("commonSharePic")
        panel:initData(SoraDCreateScreenShot(), bigDataType, closeCallBack)
        panel:show()
        if fromTarget then
          panel:setLocalZOrder(fromTarget:getLocalZOrder())
        end
        button:setVisible(true)
        if postCallBack then
          postCallBack()
        end
        SoraDSendMessage({
          msg = "MESSAGE_SERVER_OPTION_SHARE_BTN_UPDATE",
          otherPic = true
        })
        local view = ccui.Layout:create()
        view:setContentSize(display.size)
        view:setBackGroundColorType(1)
        view:setBackGroundColor(display.COLOR_WHITE)
        view:setBackGroundColorOpacity(255)
        view:setAnchorPoint(0.5, 0.5)
        view:setPosition(display.cx, display.cy)
        view:addTo(panel:getParent(), 1)
        view:runAction(cca.seq({
          cca.delay(0.2),
          cca.fadeOut(0.2),
          function(...)
            view:removeFromParent()
          end
        }))
      end
    end
  end)
  btn:setSwallowTouches(true)
  local sprite = display.newSprite("#frame_main_common.png")
  sprite:addTo(btn)
  sprite:setScale(0.7)
  sprite:setPosition(35, 35)
  sprite = display.newSprite("#icon_jt_kz.png")
  sprite:addTo(btn)
  sprite:setPosition(35, 35)
  return btn
end
function CommonShareButton.createSnapshootWithButton(button, bigDataType, fromTarget, preCallBack, postCallBack, closeCallBack)
  print("\194\183feaawefawwfawe\194\183", button, bigDataType)
  button:addTouchEventListener(function(button, type)
    print("\232\135\170\229\174\154\228\185\137\230\139\141\231\133\167\230\140\137\233\146\174")
    if type == ccui.TouchEventType.ended then
      if preCallBack then
        preCallBack()
      end
      SoraDSendMessage({
        msg = "MESSAGE_SERVER_OPTION_SHARE_BTN_UPDATE",
        otherPic = false
      })
      do
        local panel = SoraDCreatePanel("commonSharePic")
        panel:initData(SoraDCreateScreenShot(), bigDataType, closeCallBack)
        panel:show()
        if fromTarget then
          panel:setLocalZOrder(fromTarget:getLocalZOrder())
        end
        if postCallBack then
          postCallBack()
        end
        SoraDSendMessage({
          msg = "MESSAGE_SERVER_OPTION_SHARE_BTN_UPDATE",
          otherPic = true
        })
        local view = ccui.Layout:create()
        view:setContentSize(display.size)
        view:setBackGroundColorType(1)
        view:setBackGroundColor(display.COLOR_WHITE)
        view:setBackGroundColorOpacity(255)
        view:setAnchorPoint(0.5, 0.5)
        view:setPosition(display.cx, display.cy)
        view:addTo(panel:getParent(), 1)
        view:runAction(cca.seq({
          cca.delay(0.2),
          cca.fadeOut(0.2),
          function(...)
            view:removeFromParent()
          end
        }))
      end
    end
  end)
end
function CommonShareButton:onExit()
  print(self.__cname, " exit")
  SoraDRemoveMessageByTarget(self)
  SoraDManagerRemoveTimerByTarget(self)
end*/