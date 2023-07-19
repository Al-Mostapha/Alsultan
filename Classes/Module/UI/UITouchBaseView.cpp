#include "UITouchBaseView.h"

void UITouchBaseView::Ctor(){
  UIBasePanel::Ctor();
  setContentSize(GDisplay::Get()->realSize);
  setPosition(Vec2(GDisplay::Get()->rcx, GDisplay::Get()->rcy));
  _CcsView->setPositionY(GDisplay::Get()->iPhoneXBottom);
  _IsTranslucentView = true;
  SetBackGround(204);
  _IsHidePrePanel = false;
  _IsMsgBoxMode = false;
  addTouchEventListener(CC_CALLBACK_2(UITouchBaseView::LayerClickCallBack, this));
  _HandleCloseCallBack = nullptr;
  _TouchActionPanel = nullptr;
  _EnableTouchCloseSelf = false;
}

void UITouchBaseView::SetCloseCallBack(const std::function<void(EMsgBoxCallBack)> &pCloseCallBack){
  _HandleCloseCallBack = pCloseCallBack;
}

void UITouchBaseView::OpenMsgBoxMode(){
  _IsMsgBoxMode = true;
}

void UITouchBaseView::LayerClickCallBack(Ref *pSender, Widget::TouchEventType pType){
  if(pType == ui::Widget::TouchEventType::BEGAN){
    if(_IsMsgBoxMode){
      if(_EnableTouchCloseSelf){
        return;
      }
      setVisible(false);
      GBase::DSendMessage("MESSAGE_MAIN_IPHONEX_UPDATE");
      if(_HandleCloseCallBack)
        _HandleCloseCallBack(EMsgBoxCallBack::Cancel);
    }
  } else if(pType == ui::Widget::TouchEventType::ENDED){
    if(!_IsMsgBoxMode && _HandleCloseCallBack){
      _HandleCloseCallBack(EMsgBoxCallBack::Cancel);
    }
    if(_EnableTouchCloseSelf)
      return;
    
    GBase::PlaySound("uicontrol", 1);
    if(_TouchActionPanel){
    //     transition.execute(self.touchActionPanel, cca.scaleTo(0.3, 0.1), {
    //       easing = "IN",
    //       onComplete = function()
    //         self:close(layer, type)
    //       end
    //     })
      ClosePanel();
    }else{
      ClosePanel();
    }
  }
}