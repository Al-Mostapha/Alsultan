#include "BuildingTips.Handle.h"
#include "Module/UI/Part/City/Building/UIBuildingTipPanel.h"

void BuildingTipsHandle::ButtonInfoCall(UIBuildingTipPanel* p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != ui::Widget::TouchEventType::ENDED)
    return;
  if(p_Ref->_RelyBuildCfgId == EBuilding::StarBraveStatue){
  //     local panel = SoraDCreatePanelByFixName("buildStatueBraveInfoPanel")
  //     panel:initData({
  //       bid = self.relyBuildCfgId,
  //       iid = self.relyBuildIid,
  //       btype = SoraDGetBuildTypeByBid(self.relyBuildCfgId),
  //       bstate = self:getBuildState(),
  //       buildEntity = self.relyBuildEntity
  //     })
  //     panel:show()
  } else {
  //     local panel = SoraDCreatePanel("buildInfoPanel")
  //     panel:initData({
  //       bid = self.relyBuildCfgId,
  //       iid = self.relyBuildIid,
  //       btype = SoraDGetBuildTypeByBid(self.relyBuildCfgId),
  //       bstate = self:getBuildState(),
  //       buildEntity = self.relyBuildEntity
  //     })
  //     panel:show()
  //     SoraDSendMessage({
  //       msg = "MESSAGE_MAINCITYVIEW_OFFSET_BUILD",
  //       offsetType = MAINCITYVIEW_OFFSET_TYPE_BUILD
  //     })
  }
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}