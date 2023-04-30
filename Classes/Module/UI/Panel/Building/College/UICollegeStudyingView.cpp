#include "UICollegeStudyingView.h"

UICollegeStudyingView *UICollegeStudyingView::Create(){
  auto l_Panel = Create("UiParts/Panel/Building/View/College/collegeStudyingView.csb");
  return l_Panel;
}

void UICollegeStudyingView::Ctor(){
  UIBasePanel::Ctor();
  _IsHideCurrentSceneView = true;
  _Type = EScienceType::Resource;
  _NodeTop = GBase::DGetChildByName<Node *>(this, "Top_Node");
  _NodeTitle = GBase::DGetExtendChildFromCCSByName<UICommonFramTitle>(this, "CCS_commonFramTitle_studying");
  _NodeTitle->setLocalZOrder(1);
  _SizeImageShadow = GBase::DGetChildByName<Node *>(this, "Size_Image_shadow");
  _SizeImageShadow->setContentSize(Size(640, GDisplay::Get()->height - 328));
  _ImageL = GBase::DGetChildByName<ui::ImageView *>(this, "Image_l");
  _ImageL->setContentSize(Size(320, GDisplay::Get()->height - 400));
  _ImageR = GBase::DGetChildByName<ui::ImageView *>(this, "Image_r");
  _ImageR->setContentSize(Size(320, GDisplay::Get()->height - 400));
  _SizeImageBase = GBase::DGetChildByName<Node *>(this, "Size_Image_base");
  _SizeImageBase->setPositionY(-GDisplay::Get()->height);
  _BtnCloseRight = GBase::DGetChildByName<ui::Button *>(this, "Button_close_right");
  if(_BtnCloseRight){
    _BtnCloseRight->setLocalZOrder(2);
    _BtnCloseRight->addTouchEventListener([this](auto target, auto event){
      if(event == ui::Widget::TouchEventType::ENDED){
        GBase::DPlaySound();
        GBase::DRemoveAllPanelFromManager();
      }
    });
  }
  _Scroll = nullptr;
}

void UICollegeStudyingView::InitData(EScienceType p_Type){
// self.type = type
//   local singleData = {}
//   if not IsArClient then
//     singleData = {
//       [TECHNOLOGY_ATTR.military] = {
//         scroll = "collegeWarScrollView",
//         title = i18n("common_text_045")
//       },
//       [TECHNOLOGY_ATTR.cityDevelop] = {
//         scroll = "collegeDevelopScrollView",
//         title = i18n("common_text_331")
//       },
//       [TECHNOLOGY_ATTR.anchor] = {
//         scroll = "collegeDefScrollView",
//         title = i18n("common_text_332")
//       },
//       [TECHNOLOGY_ATTR.resource] = {
//         scroll = "collegeResScrollView",
//         title = i18n("common_text_123")
//       },
//       [TECHNOLOGY_ATTR.special] = {
//         scroll = "collegeSpecialScrollView",
//         title = i18n("common_text_1962")
//       },
//       [TECHNOLOGY_ATTR.soldier] = {
//         scroll = "collegeSoldierScrollView",
//         title = i18n("common_text_3772")
//       },
//       [TECHNOLOGY_ATTR.leader] = {
//         scroll = "collegeCommanderScrollView",
//         title = i18n("common_text_4055")
//       },
//       [TECHNOLOGY_ATTR.hero] = {
//         scroll = "collegeHeroScrollView",
//         title = i18n("common_name_01")
//       }
//     }
//   else
//     singleData = {
//       [TECHNOLOGY_ATTR.military] = {
//         scroll = "collegeWarScrollView",
//         title = i18n("common_text_045")
//       },
//       [TECHNOLOGY_ATTR.cityDevelop] = {
//         scroll = "collegeDevelopScrollView",
//         title = i18n("common_text_331")
//       },
//       [TECHNOLOGY_ATTR.anchor] = {
//         scroll = "collegeDefScrollView",
//         title = i18n("common_text_332")
//       },
//       [TECHNOLOGY_ATTR.resource] = {
//         scroll = "collegeResScrollView",
//         title = i18n("common_text_123")
//       },
//       [TECHNOLOGY_ATTR.special] = {
//         scroll = "collegeSpecialScrollView",
//         title = i18n("common_text_1962")
//       },
//       [TECHNOLOGY_ATTR.soldier] = {
//         scroll = "collegeSoldierScrollView",
//         title = i18n("common_text_3772")
//       },
//       [TECHNOLOGY_ATTR.leader] = {
//         scroll = "collegeCommanderScrollView",
//         title = i18n("common_text_4055")
//       },
//       [TECHNOLOGY_ATTR.hero] = {
//         scroll = "collegeHeroScrollView",
//         title = i18n("common_name_01")
//       },
//       [TECHNOLOGY_ATTR.advancedmilitary] = {
//         scroll = "collegeAdvancedMilitaryScrollView",
//         title = i18n("common_name_02")
//       }
//     }
//   end
//   self.scroll = SoraDCreatePanelByFixName(singleData[self.type].scroll)
//   self.scroll:initData(self.type)
//   self.scroll:setPosition(0, 880)
//   self.scroll:addTo(self.nodeTop, 0)
//   self.nodeTitle:setTitle(singleData[self.type].title)
}