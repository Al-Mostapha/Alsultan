#pragma once 
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UICommonSlider : public UIBasePanel
{
  public:

  struct RInitDataParam{
    int32 _MaxValue = 1;
    int32 _MinValue = 1;
    int32 _CurValue = 1;
  } _TableSliderData;
  // self.slider = SoraDGetChildByName(self, "Slider_slider")
  Node *_Slider = nullptr;
  // self.labelMax = SoraDGetChildByName(self, "Text_max")
  ui::Text *_LabelMax = nullptr;
  // self.btnUp = SoraDGetChildByName(self, "Button_up")
  ui::Button *_BtnUp = nullptr;
  // self.btnDown = SoraDGetChildByName(self, "Button_down")
  ui::Button *_BtnDown = nullptr;
  // self.newInput = nil
  // if self.btnUp then
  //   self.btnUp:addTouchEventListener(handler(self, self.OnSliderBtnClick))
  //   self.btnDown:addTouchEventListener(handler(self, self.OnSliderBtnClick))
  // end
  // self.labelInput = SoraDGetChildByName(self, "TextField_sliderInput")
  // if self.labelInput then
  //   self.labelInput:setTextHorizontalAlignment(cc.TEXT_ALIGNMENT_RIGHT)
  //   self.labelInput:setTextVerticalAlignment(cc.VERTICAL_TEXT_ALIGNMENT_CENTER)
  //   self.labelInput:addEventListener(handler(self, self.OnInputChangeEnd))
  // end
  // self.labelInputInit = false
  bool _LabelInputInit = false;
  // self.slider:addEventListener(handler(self, self.OnSliderChangeEnd))
  // self.slider:addTouchEventListener(handler(self, self.OnSliderTouchClick))
  // self.handleChangeBack = nil
  // self.scroll = nil
  // SoradCreateTimer(self, handler(self, self.update), true)
private:
  CREATE_FUNC(UICommonSlider);
  CreateUIPanel(UICommonSlider);
  CreateUICCSView(UICommonSlider);
public:

  static UICommonSlider *Create();
  void Ctor() override;
  void InitData(const RInitDataParam &p_Param){}
  void SetMask(Node *p_Parent, int32 p_ZOrder = 999){}
  void SetSliderCallBack(const std::function<void(float p_CurrentVal)> &p_CallBack){}
  int32 GetSliderCurValue() const { return 0; }
};
