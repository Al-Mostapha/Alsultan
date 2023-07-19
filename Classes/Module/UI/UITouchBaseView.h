#pragma once
#include "UIBasePanel.h"
#include "Base/Common/Common.Enum.h"

class UITouchBaseView : public UIBasePanel
{
  bool _IsMsgBoxMode;
  std::function<void(EMsgBoxCallBack)> _HandleCloseCallBack;
  ui::Layout *_TouchActionPanel;
  bool _EnableTouchCloseSelf;
  public:
    virtual void Ctor() override;
    virtual void SetCloseCallBack(const std::function<void(EMsgBoxCallBack)> &pCloseCallBack);
    void OpenMsgBoxMode();
    void LayerClickCallBack(Ref *pSender, Widget::TouchEventType pType);
};