#include "UIItemSingle.View.h"

UIItemSingleView *UIItemSingleView::Create(){
  auto l_Panel = create();
  l_Panel->Ctor();
  return l_Panel;
}

void UIItemSingleView::Ctor(){
  
  _BtnItem = ui::Button::create("frame_square_36.png", "frame_square_36.png", "frame_square_36.png", ui::Widget::TextureResType::PLIST);
  _BtnItem->setPosition(Vec2(76.5, -76.5));
  _BtnItem->setPressedActionEnabled(false);
  this->addChild(_BtnItem, 1);
  _ImgFrame = GDisplay::Get()->NewSprite("frame_square_15.png");
  _ImgFrame->setPosition(Vec2(_BtnItem->getContentSize().height / 2, _BtnItem->getContentSize().height / 2));
  _BtnItem->addChild(_ImgFrame, 1);
  _SpriteNew = GDisplay::Get()->NewSprite("frame_red_items_new.png");
  _SpriteNew->setVisible(false);
  if(!GBase::DFIsRA()){
    _SpriteNew->setPosition(Vec2(30, 128));
  }else{
    _SpriteNew->setPosition(Vec2(118, 128));
  }
  _BtnItem->addChild(_SpriteNew, 1);
  _SpriteNumBg = GDisplay::Get()->NewSprite("frame_sheer_black_01.png");
  _SpriteNumBg->setPosition(Vec2(76.5, -90));
  this->addChild(_SpriteNumBg, 2);
  _SpriteNumBg->setScaleX(0.2);
  _SpriteNumBg->setScaleY(0.6);
  _SpriteNumBg->setOpacity(204);
  _SpriteNumBg->setVisible(false);
  _LabNum = ui::Text::create();
  _LabNum->setColor(Color3B(255, 228, 0));
  _LabNum->setFontSize(20);
  _LabNum->setPosition(Vec2(76.5, -90));
  this->addChild(_LabNum, 3);
  _LabNum->setVisible(false);
  // self.item = nil
  // self.itemsManagerHandle = nil
  _BtnItem->setSwallowTouches(false);
  // if self.btnItem then
  //   self.btnItem:addTouchEventListener(handler(self, self.OnBtnItemClick))
  // end
  // self.itemClickCallback = nil
  // local labelTime = display.newBMFontLabel({
  //   text = "",
  //   font = "res/Default/defaultBMFont.fnt",
  //   align = cc.TEXT_ALIGNMENT_CENTER
  // })
  // labelTime:setVisible(false)
  // labelTime:setScale(0.8)
  // labelTime:setPosition(cc.p(76.5, -90))
  // labelTime:addTo(self, 3)
  // labelTime:setName("Text_Time")
  // labelTime:setColor(cc.c3b(255, 255, 255))
  // labelTime = SoraDCreateTimerLabel(self, labelTime)
  // labelTime:setTimeUpdateListener(function(leftTime)
  //   if leftTime < 1800 then
  //     labelTime:setColor(cc.c3b(200, 0, 0))
  //   else
  //     labelTime:setColor(cc.c3b(255, 255, 255))
  //   end
  // end)
}

void UIItemSingleView::InitData(RClassifyItem, Vec2){

}

void UIItemSingleView::InitWidget(){

}
