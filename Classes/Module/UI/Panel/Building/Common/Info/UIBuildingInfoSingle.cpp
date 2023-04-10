#include "UIBuildingInfoSingle.h"

UIBuildingInfoSingle *UIBuildingInfoSingle::Create(){
  auto l_Panel = Create("UiParts/Panel/Building/Common/buildInfoSingle.csb");
  return l_Panel;
}

void UIBuildingInfoSingle::Ctor(){
  UIBasePanel::Ctor();
  _ImgIcon = GBase::GetChildByName<ui::ImageView *>(this, "Image_icon");
  _LabelDes = GBase::GetChildByName<ui::Text *>(this, "Text_des");
  _LabelValue = GBase::GetChildByName<ui::Text *>(this, "Text_value");
  _LabelPlusValue = GBase::GetChildByName<ui::Text *>(this, "Text_plusValue");
  _BtnHelp = GBase::GetChildByName<ui::Button *>(this, "Button_help");
  // self.tableInfoSingleData = {}
  if(_BtnHelp)
    _BtnHelp->addTouchEventListener(CC_CALLBACK_2(BtnHelpCallBack, this));
  _LabelPlusValue->setVisible(false);
  _LabelValue->setVisible(false);
  _BtnHelp->setVisible(false);
}

void UIBuildingInfoSingle::InitData(){
  // self.tableInfoSingleData = buildInfoSingleData
  // self.tableInfoSingleData.bid = bid
  // if self.tableInfoSingleData.value then
  //   self.labelValue:setString(tostring(self.tableInfoSingleData.value))
  //   self.labelValue:setVisible(true)
  //   self.labelDes:setContentSize(cc.size(285, 45))
  // else
  //   self.labelDes:setContentSize(cc.size(480, 45))
  // end
  // if self.tableInfoSingleData.moreInfoType == 4 then
  //   local resDesRead = include("resDesRead")
  //   self.imgIcon:loadTexture(resDesRead.getIcon(self.tableInfoSingleData.title), ccui.TextureResType.plistType)
  //   self.labelDes:setString(resDesRead.getName(self.tableInfoSingleData.title))
  // else
  //   self.labelDes:setString(self.tableInfoSingleData.title)
  //   self.imgIcon:loadTexture("icon_building_research.png", ccui.TextureResType.plistType)
  // end
  // if self.tableInfoSingleData.plusValue then
  //   if type(self.tableInfoSingleData.plusValue) == "number" then
  //     if self.tableInfoSingleData.plusValue >= 0 then
  //       self.labelPlusValue:setString("+" .. string.formatnumberthousands(self.tableInfoSingleData.plusValue))
  //       self.labelPlusValue:setColor(display.COLOR_GREEN)
  //     else
  //       self.labelPlusValue:setString(string.formatnumberthousands(self.tableInfoSingleData.plusValue))
  //       self.labelPlusValue:setColor(display.COLOR_RED)
  //     end
  //   else
  //     self.labelPlusValue:setString(tostring(self.tableInfoSingleData.plusValue))
  //     self.labelPlusValue:setColor(display.COLOR_GREEN)
  //   end
  //   self.labelPlusValue:setVisible(true)
  //   self.labelPlusValue:setPositionX(self.labelValue:getPositionX() - SoraDFSign(self.labelValue:getContentSize().width + 10))
  // end
  // if self.tableInfoSingleData.infoDesType == 1 then
  //   self.btnHelp:setVisible(true)
  // end
  // if SoraDFIsRA() then
  //   if self.tableInfoSingleData.plusValue and self.tableInfoSingleData.infoDesType == 1 then
  //     SoraDAlignNodeArray({
  //       self.btnHelp,
  //       self.labelPlusValue,
  //       self.labelValue
  //     }, false, {15, 10})
  //   elseif self.tableInfoSingleData.plusValue then
  //     SoraDAlignNodeArrayOnLimitX({
  //       self.labelValue,
  //       self.labelPlusValue
  //     }, true, {10}, false, 0)
  //   end
  // elseif self.tableInfoSingleData.plusValue and self.tableInfoSingleData.infoDesType == 1 then
  //   SoraDAlignNodeArray({
  //     self.btnHelp,
  //     self.labelPlusValue,
  //     self.labelValue
  //   }, true, {15, 10})
  // elseif self.tableInfoSingleData.plusValue then
  //   SoraDAlignNodeArrayOnLimitX({
  //     self.labelValue,
  //     self.labelPlusValue
  //   }, false, {10}, true, 534)
  // end
}

void UIBuildingInfoSingle::InitWidget(){

}
