#include "CityBuildings.h"
#include "Module/Building/IBuilding.h"
#include "Module/UI/Part/City/Building/UIBuildingTipPanel.h"
#include "Module/City/City.Func.h"
void CityBuildings::BuildingButtonCallFun(
  ui::Widget* p_Build, Ref* p_Ref, ui::Widget::TouchEventType p_Touch
) { 
  static bool l_IsMoveOnBuild = false; 

  if(p_Touch == ui::Widget::TouchEventType::MOVED){
    auto l_TouchBeganPoint = p_Build->getTouchBeganPosition();
    auto l_TouchmovePoint = p_Build->getTouchMovePosition();
    if(std::abs(l_TouchBeganPoint.distance(l_TouchmovePoint)) > TOUCH_MOVED_ERROR_VALUE)
      l_IsMoveOnBuild = true;
  } else if (p_Touch == ui::Widget::TouchEventType::MOVED)
    l_IsMoveOnBuild = false;
  else if (p_Touch == ui::Widget::TouchEventType::CANCELED)
    l_IsMoveOnBuild = false;
  else if(p_Touch == ui::Widget::TouchEventType::ENDED){
    if(l_IsMoveOnBuild){
      l_IsMoveOnBuild = false;
      return;
    }
    _CurrentSelectBuild = p_Build;
    auto l_CityBuild = dynamic_cast<IBuilding *>(p_Build->getChildByName("buildName"));
    if(l_CityBuild){
      if(l_CityBuild->Clicked(p_Ref, p_Touch))
        return;
      if(!_CacheTip){
        _CacheTip = UIBuildingTipPanel::Create();
        _ContainerView->addChild(_CacheTip, 10000);
        _CacheTip->setGlobalZOrder(10000);
      }
        _CacheTip->setVisible(true);
        _CacheTip->SetRelyBuildBtnId(p_Build->getTag());
        _CacheTip->SetRelyBuildUId(l_CityBuild->getTag());
        _CurrentSelectTip = _CacheTip;
        _CacheTip->SetRelyBuildCfgId(l_CityBuild->GetBuildingId());
        _CacheTip->SetRelyBuildIid(l_CityBuild->GetBuildingIndex());
        _CacheTip->SetRelyBuildEntity(l_CityBuild);
        _CacheTip->InitView();
        // local x, y = build:getPosition()
        auto l_Vec = p_Build->getPosition();
        // local offset = cityBuildViewDef.getBuildTipOffset(bid)
        
        // panel:setPosition(cc.p(x + offset.x, y + offset.y))
        _CacheTip->setPosition(l_Vec);
        // self:ShowBuildTint(build)
        MainCityFunctions::Get()->ShowNodeTint(p_Build);
        // cityBuild:runAction(cca.seq({
        //   cca.delay(0.001),
        //   cca.callFunc(function()
        //     if gSoundDataList.innerbuildsound[cityBuild:getBuildBid()] then
        //       self:playSound("innerbuildsound", cityBuild:getBuildBid(), cityBuildConstDef.ActionTag.Tag_Play_Click_Build_Sound)
        //     end
        //   end)
        // }))
    }

  }
}