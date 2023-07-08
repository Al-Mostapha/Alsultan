#include "WorldMap.Com.AllianceMark.h"
#include "Module/Player/Player.Top.h"
#include "Module/World/WorldMap/View/WorldMap.Cell.h"
#include "Module/World/WorldMap/WorldMap.Event.h"
#include "Module/World/WorldMap/View/WorldMap.View.h"
#include "Module/UI/Scene/World/Alliance/UIWorldMapAllianceMark.h"
#include "Module/World/WorldMap/CollectMap/CollectMap.Ctrl.h"


void WorldMapComAllianceMark::Init(){
  _MyKindomID = PlayerTop::Get()->GetMapID();
  _WorldMapCell = _Target->_CurrentInMapViewCell;
  InitAllianceMark();
}

void WorldMapComAllianceMark::OnMessageListener(){
  auto l_WorldMapEvent = WorldMapEvent::Get();
  AddEventListener(l_WorldMapEvent->EVENT_SCROLL_ZOOM, CC_CALLBACK_1(WorldMapComAllianceMark::UpdateScaleZoom, this));
  AddEventListener(l_WorldMapEvent->EVENT_SCROLL_LOD_CHANGE, CC_CALLBACK_1(WorldMapComAllianceMark::UpdateLodLevel, this));
  AddEventListener(l_WorldMapEvent->EVENT_CELL_SWAP, CC_CALLBACK_1(WorldMapComAllianceMark::UpdateCellSwap, this));
  AddEventListener(l_WorldMapEvent->EVENT_TOOGLE_3D, CC_CALLBACK_1(WorldMapComAllianceMark::Toggle3D, this));
  Toggle3D(nullptr);
  GBase::DAddMessage(_Target, "MESSAGE_SERVER_ALLIANCE_MARK_REFRESH", CC_CALLBACK_1(WorldMapComAllianceMark::RefreshAllianceMark, this));
  GBase::DAddMessage(_Target, "MESSAGE_SERVER_CAMP_MARK_REFRESH", CC_CALLBACK_1(WorldMapComAllianceMark::RefreshCampMark, this));
}

void WorldMapComAllianceMark::Toggle3D(EventCustom *p_Event){
  for(auto [l_Key, l_UIWorldMapAllianceMark] : _NodeList){
    l_UIWorldMapAllianceMark->Toggle3D();
  }
  for(auto [l_Key, l_UIWorldMapAllianceMark] : _CampMarkList){
    l_UIWorldMapAllianceMark->Toggle3D();
  }
}

void WorldMapComAllianceMark::InitAllianceMark(){
  auto l_Node = GDisplay::Get()->NewNode();
  _WorldMapCell->addChild(l_Node, static_cast<int32>(EWorldMapZOrder::selectView));
  // node:setGroupID(GROU_ID.group_animate_object_top)
  l_Node->setName("Node_AllianceMark");
  // node:setGroupAuto(true)
  _NodeAllianceMark = l_Node;
  RefreshAllianceMark(nullptr);
  RefreshCampMark(nullptr);
  UpdateLodLevel(nullptr);
}

void WorldMapComAllianceMark::UpdateScaleZoom(EventCustom *p_Event){
  if(!p_Event)
    return;
  if(p_Event->getUserData())
    return;
  auto l_Scale = *static_cast<float *>(p_Event->getUserData());
  for(auto [l_Key, l_UIWorldMapAllianceMark] : _NodeList){
    l_UIWorldMapAllianceMark->UpdateScaleZoom(l_Scale);
  }
  for(auto [l_Key, l_UIWorldMapAllianceMark] : _CampMarkList){
    l_UIWorldMapAllianceMark->UpdateScaleZoom(l_Scale);
  }
}

void WorldMapComAllianceMark::UpdateLodLevel(EventCustom *p_Event){
  auto l_LodLevel = _Target->GetCurLod();
  if(_CurLod == l_LodLevel)
    return;
  _CurLod = l_LodLevel;
  for(auto [l_Key, l_UIWorldMapAllianceMark] : _NodeList){
    l_UIWorldMapAllianceMark->UpdateLodLevel(_CurLod);
  }
  for(auto [l_Key, l_UIWorldMapAllianceMark] : _CampMarkList){
    l_UIWorldMapAllianceMark->UpdateLodLevel(_CurLod);
  }
}

void WorldMapComAllianceMark::UpdateCellSwap(EventCustom *p_Event){
  RefreshAllianceMarkNode();
}

void WorldMapComAllianceMark::RefreshAllianceMarkNode(){
  if(!_NodeAllianceMark)
    return;
  auto l_CurrentInMapViewCell = _Target->_CurrentInMapViewCell;
  auto l_Node = _NodeAllianceMark;
  if(l_Node->getParent() != l_CurrentInMapViewCell){
    l_Node->retain();
    l_Node->removeFromParentAndCleanup(false);
    l_CurrentInMapViewCell->addChild(l_Node);
    l_Node->release();
  }
  RefreshAllianceMark(nullptr);
}

void WorldMapComAllianceMark::RefreshAllianceMark(EventCustom *p_Event){
  auto l_CurrentInMapViewCell = _Target->_CurrentInMapViewCell;
  auto l_CurMapID = l_CurrentInMapViewCell->_KingdomID;
  auto l_AllianceMarkData = CollectMapCtrl::Get()->GetAllianceMarkData();
  auto l_CurScale = _Target->_ViewScrollView->getZoomScale();
  auto l_RevertScale = 1 / l_CurScale;
  auto l_CurLod = _Target->GetCurLod();
  for(const auto &[l_Key, l_OneMark] : l_AllianceMarkData){
    if(l_OneMark._MapId == l_CurMapID){
      if(!_NodeList.Contains(l_Key)){
        auto l_Node = UIWorldMapAllianceMark::Create();
        _NodeAllianceMark->addChild(l_Node);
        l_Node->UpdateLodLevel(l_CurLod);
        l_Node->UpdateScaleZoom(l_RevertScale);
        l_Node->Toggle3D();
        _NodeList[l_Key] = l_Node;
      }else{
        auto l_Node = _NodeList[l_Key];
        l_Node->setVisible(true);
      }
      _NodeList[l_Key]->InitData(l_OneMark);
      auto l_Position = l_OneMark._Position;
      auto l_InstancePoint = _WorldMapCell->GetPointWithTile(l_Position);
      _NodeList[l_Key]->setPosition(l_InstancePoint);
    }else if(_NodeList.Contains(l_Key)){
      _NodeList[l_Key]->setVisible(false);
    }
  }

  for (auto it = _NodeList.cbegin(); it != _NodeList.cend() /* not hoisted */; /* no increment */)
  {
    if (!l_AllianceMarkData.Contains(it->first))
    {
      if(it->second)
        it->second->removeFromParent();
      _NodeList.erase(it++);    // or "it = m.erase(it)" since C++11
    }
    else
    {
      ++it;
    }
  }
}

void WorldMapComAllianceMark::RefreshCampMark(EventCustom *p_Event){
  //   local campMarkList = nebulaActivityCtrl:getCampMarkList()
  // local curScale = self.target_.viewScrollView:getZoomScale()
  // local revertScale = 1 / curScale
  // local curLod = self.target_:getCurLod()
  // for k, v in pairs(campMarkList) do
  //   local node = self.campMarkList[k] and self.campMarkList[k].point
  //   if not node then
  //     node = SoraDCreatePanel("worldMapAllianceMark")
  //     node:addTo(self.Node_AllianceMark)
  //     node:updateScaleZoom(revertScale)
  //     node:updateLodLevel(curLod)
  //     node:toggle3D()
  //     self.campMarkList[k] = {point = node}
  //   else
  //     node:setVisible(true)
  //   end
  //   node:initData({
  //     name = v.name,
  //     markType = tonumber(k),
  //     collectType = gCollectType.nebulaCamp
  //   })
  //   local instancePoint = self.worldMapCell:getPointWithTile(cc.p(v.x, v.y))
  //   node:setPosition(instancePoint)
  // end
  // for k, v in pairs(self.campMarkList) do
  //   if v.point and not campMarkList[k] then
  //     v.point:removeFromParent()
  //     v.point = nil
  //   end
  // end
}

void WorldMapComAllianceMark::Ctor(){}

