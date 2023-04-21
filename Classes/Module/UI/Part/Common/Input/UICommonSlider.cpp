#include "UICommonSlider.h"

UICommonSlider *UICommonSlider::Create(){
  auto l_Panel = Create("UiParts/Parts/Common/Input/commonSliderA.csb");
  return l_Panel;
}

void UICommonSlider::Ctor(){
//  self.tableSliderData = {
//     maxValue = 1,
//     minValue = 1,
//     curValue = 1
//   }
//   self.slider = SoraDGetChildByName(self, "Slider_slider")
_Slider = GBase::GetChildByName<Node *>(this, "slider");
CSLoader::createNode("UiParts/Parts/Common/Input/commonSliderA.csb");
//   self.labelMax = SoraDGetChildByName(self, "Text_max")
//   self.btnUp = SoraDGetChildByName(self, "Button_up")
//   self.btnDown = SoraDGetChildByName(self, "Button_down")
//   self.newInput = nil
//   if self.btnUp then
//     self.btnUp:addTouchEventListener(handler(self, self.OnSliderBtnClick))
//     self.btnDown:addTouchEventListener(handler(self, self.OnSliderBtnClick))
//   end
//   self.labelInput = SoraDGetChildByName(self, "TextField_sliderInput")
//   if self.labelInput then
//     self.labelInput:setTextHorizontalAlignment(cc.TEXT_ALIGNMENT_RIGHT)
//     self.labelInput:setTextVerticalAlignment(cc.VERTICAL_TEXT_ALIGNMENT_CENTER)
//     self.labelInput:addEventListener(handler(self, self.OnInputChangeEnd))
//   end
//   self.labelInputInit = false
//   self.slider:addEventListener(handler(self, self.OnSliderChangeEnd))
//   self.slider:addTouchEventListener(handler(self, self.OnSliderTouchClick))
//   self.handleChangeBack = nil
//   self.scroll = nil
//   SoradCreateTimer(self, handler(self, self.update), true)
}
