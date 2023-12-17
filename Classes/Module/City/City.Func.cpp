#include "City.Func.h"
#include "Base/Base.Geometry.h"
#include "Module/Faction/Faction.Ctrl.h"
#include "Scene/City/CityScene.View.h"

MainCityFunctions* MainCityFunctions::Get() {
  static MainCityFunctions* l_Instance = new MainCityFunctions();
  return l_Instance;
}

void MainCityFunctions::UpdateLockArea(MainCityView* p_View) {
  // ...
}

void MainCityFunctions::AddBuild(MainCityView* p_MainCity, EBuilding p_BuildingId, EBuildingIndex p_BuildingIndex) {
  // local self = mainCity
  static int32 l_BaseUid = 100000000;
  auto l_Self = p_MainCity;
  // local buildButton = self:getBufferNodeByName("build_" .. buildBtnId)
  GString l_BuildingId = cocos2d::StringUtils::format("build_%d", static_cast<int32>(p_BuildingId));
  auto l_BuildButton = l_Self->GetBufferNodeByName(l_BuildingId.c_str());
  if (l_BuildButton) {
    //   local baseBuildCfg = naitonCtrl:getCityBuildBaseTipsCfg(buildCfgId)
    const auto l_BaseBuildCfg = FactionCtrl::Get()->GetCityBuildBaseTipsCfg(p_BuildingId);
    //   local buildItemInfo = {BuildingCfgId = buildCfgId}
    //   local buildContentNode = self:createBuildByCfgId(buildBtnId, buildItem)
  }
}

void MainCityFunctions::ReArrangeZorder(MainCityView* p_City) {
  //   print("aaabbb mainCityFunctions.reArrangeZorder", RAMADAN_SWITCH)
  //   local self = mainCity
  //   local zOrderIndex = 0
  auto l_ZOrderIndex = 0;
  auto BG_bulletin_board = p_City->GetBufferNodeByName("BG_bulletin_board");
  if (BG_bulletin_board) {
    BG_bulletin_board->setLocalZOrder(ECityTargetZOrder::Get()->drill);
    BG_bulletin_board->setVisible(false);
    auto l_buttonBulletInBoard = p_City->GetBufferNodeByName("Button_bulletin_board");
    if (l_buttonBulletInBoard) {
      l_buttonBulletInBoard->removeFromParent();
      p_City->DelBufferNodeByName("Button_bulletin_board");
    }
  }
  auto l_Market = p_City->GetBufferNodeByName("Node_market");
  if (l_Market) {
    l_Market->setLocalZOrder(ECityTargetZOrder::Get()->drill);
    auto l_Anim = GBase::DCreateAnimation("UiParts/Animation/City/CityBuilding/animationMatket.csb");
    l_Market->addChild(l_Anim.First);
  }

  auto l_CCSBg = p_City->GetBufferNodeByName("CCS_mainCityViewBG_bg");
  if (l_CCSBg) {
    for (auto l_OneChild : l_CCSBg->getChildren().at(0)->getChildren()) {
      auto l_nameTB = GStringUtils::Split(l_OneChild->getName(), "_");
      if (l_nameTB.size() < 1) continue;
      if (l_nameTB[1] == "MainCityBG") {
        l_OneChild->setAnchorPoint(Vec2(0, 0));
        l_OneChild->setPositionX(std::max(std::floor(l_OneChild->getPositionX()), 0.0f));
        l_OneChild->setPositionY(std::max(std::floor(l_OneChild->getPositionY()), 0.0f));
      }
    }
  }
  auto BG_zhuangjing_ros = p_City->GetBufferNodeByName("BG_zhuangjing_ros");
  if(BG_zhuangjing_ros)
    BG_zhuangjing_ros->setLocalZOrder(ECityTargetZOrder::Get()->bg);
  auto Img_pyramid_battle = p_City->GetBufferNodeByName("Img_pyramid_battle");
  if(Img_pyramid_battle)
    Img_pyramid_battle->setLocalZOrder(ECityTargetZOrder::Get()->tree);
  auto l_BgMoutain = p_City->GetBufferNodeByName("BG_mountain");
  if(l_BgMoutain)
    l_BgMoutain->setLocalZOrder(ECityTargetZOrder::Get()->drill);
  //   local Node_flag = self:getBufferNodeByName("Node_flag")
  //   if Node_flag then
  //     Node_flag:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.drill + 1)
  //     local spine_flag
  //     if SoraDGetFactionType() == FACTION_TYPE.FACTION_NORMAL then
  //       spine_flag = sp.SkeletonAnimation:create("spine/qizhi.skel", "spine/qizhi.atlas", 1)
  //     elseif SoraDGetFactionType() == FACTION_TYPE.FACTION_BYZANTINE then
  //       spine_flag = sp.SkeletonAnimation:create("spine/eft_jiaochang_byzantine.skel", "spine/eft_jiaochang_byzantine.atlas", 1)
  //       spine_flag:setPosition(cc.p(-80, -220))
  //       Node_flag:getChildByName("Img_Flag"):setVisible(false)
  //       Node_flag:getChildByName("ganyingzi"):setVisible(false)
  //     end
  //     spine_flag:setAnimation(0, "animation", true)
  //     spine_flag:addTo(Node_flag:getChildByName("Node_spine_flag"))
  //   end
  //   zOrderIndex = mainCityDefine.CITY_TARGET_ZORDER.inner_build
  //   for i = 1051, 1067 do
  //     local buildName = "build_" .. i
  //     local buildButton = self:getBufferNodeByName(buildName)
  //     if buildButton then
  //       if i == 1058 or i == 1059 or i == 1061 or i == 1055 then
  //         buildButton:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.drill + 1)
  //       elseif (i == 1064 or i == 1065 or i == 1067 or i == 1060) and SoraDGetFactionType() == FACTION_TYPE.FACTION_BYZANTINE then
  //         buildButton:setLocalZOrder(56)
  //       else
  //         buildButton:setLocalZOrder(zOrderIndex)
  //         zOrderIndex = zOrderIndex + 2
  //       end
  //     end
  //   end
  //   zOrderIndex = mainCityDefine.CITY_TARGET_ZORDER.wall
  //   local wallBtnArray = {}
  //   if SoraDGetFactionType() == FACTION_TYPE.FACTION_BYZANTINE then
  //     wallBtnArray = {
  //       "Sprite_Cq_1",
  //       "Sprite_Cq_2",
  //       "build_1054",
  //       "Sprite_Cq_3",
  //       "Sprite_Cq_4",
  //       "Sprite_Cq_5",
  //       "build_1053",
  //       "Sprite_Cq_6",
  //       "build_1052",
  //       "Sprite_Cq_7",
  //       "Sprite_Cq_8",
  //       "Sprite_Cq_9"
  //     }
  //   else
  //     wallBtnArray = {
  //       "Sprite_Cq_1",
  //       "build_1054",
  //       "Sprite_Cq_2",
  //       "build_1053",
  //       "Sprite_Cq_3",
  //       "build_1052",
  //       "Sprite_Cq_4"
  //     }
  //   end
  //   for k, v in ipairs(wallBtnArray) do
  //     local buildButton = self:getBufferNodeByName(v)
  //     if buildButton then
  //       buildButton:setLocalZOrder(zOrderIndex + 1)
  //       zOrderIndex = zOrderIndex + 2
  //     end
  //   end
  //   local btnBuildCastle = self:getBufferNodeByName("build_1050")
  //   if btnBuildCastle then
  //     btnBuildCastle:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.castle)
  //   end
  //   local btnBuildMastery = self:getBufferNodeByName("build_30008")
  //   if btnBuildMastery then
  //     btnBuildMastery:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.inner_build)
  //   end
  //   local dh_BG_tree_castle = self:getBufferNodeByName("dh_BG_tree_castle")
  //   if dh_BG_tree_castle then
  //     dh_BG_tree_castle:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.xunluo)
  //   end
  //   zOrderIndex = mainCityDefine.CITY_TARGET_ZORDER.outer_build
  //   for i = 1100, 1134 do
  //     local buildName = "build_" .. i
  //     local buildButton = self:getBufferNodeByName(buildName)
  //     if buildButton then
  //       buildButton:setLocalZOrder(zOrderIndex)
  //       zOrderIndex = zOrderIndex + 2
  //     end
  //   end
  //   for i = 1, 10 do
  //     local buildName = "kipchaks_" .. i
  //     local buildButton = self:getBufferNodeByName(buildName)
  //     if buildButton then
  //       buildButton:setLocalZOrder(zOrderIndex)
  //       zOrderIndex = zOrderIndex + 2
  //     end
  //   end
  //   local bg_wharf_mask = self:getBufferNodeByName("BG_wharf_mask")
  //   if bg_wharf_mask then
  //     bg_wharf_mask:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.flag)
  //   end
  //   local buildName = "build_" .. cityBuildConstDef.buildIndexDef.index_Miracle
  //   local buildButton = self:getBufferNodeByName(buildName)
  //   if buildButton then
  //     buildButton:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.miracle)
  //   end
  //   local btnBuild = self:getBufferNodeByName("build_" .. cityBuildConstDef.buildIndexDef.index_StarBraveStatue)
  //   if btnBuild then
  //     btnBuild:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.braveStatue)
  //   end
  //   local build_DH_path = SoraDGetChildByName(self.containerView, "build_DH_path")
  //   if build_DH_path then
  //     build_DH_path:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.castle_b_effect)
  //   end
  //   local buttonConquer = SoraDGetChildByName(self.containerView, "Button_conquer")
  //   if buttonConquer then
  //     buttonConquer:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.juying)
  //   end
  //   local buildName = "build_" .. cityBuildConstDef.buildIndexDef.index_ElitePalace
  //   local buildButton = self:getBufferNodeByName(buildName)
  //   if buildButton then
  //     buildButton:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.miracle)
  //   end
  //   local img_turret_lock_1052 = self:getBufferNodeByName("img_turret_lock_1052")
  //   local img_turret_lock_1054 = self:getBufferNodeByName("img_turret_lock_1054")
  //   if img_turret_lock_1054 then
  //     img_turret_lock_1054:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.drill)
  //   end
  //   if img_turret_lock_1052 then
  //     img_turret_lock_1052:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.drill)
  //   end
  //   local buildWallLowerLeft = self:getBufferNodeByName("BG_wall_LowerLeft")
  //   if buildWallLowerLeft then
  //     buildWallLowerLeft:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.lower_wall)
  //   end
  //   for i = 1, 3 do
  //     local lampItemName = "BG_lamp_" .. i
  //     local lampItem = self:getBufferNodeByName(lampItemName)
  //     if lampItem then
  //       if i == 1 then
  //         lampItem:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.tree)
  //       else
  //         lampItem:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.tree_other)
  //       end
  //     end
  //   end
  //   for i = 1, 2 do
  //     local drillItem = self:getBufferNodeByName("BG_DrillDh_0" .. i)
  //     if drillItem then
  //       drillItem:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.drill)
  //     end
  //   end
  //   for i = 1, 2 do
  //     local waterItem = self:getBufferNodeByName("BG_fuhuo_0" .. i)
  //     if waterItem then
  //       waterItem:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.drill)
  //     end
  //   end
  //   local bgLadderLeft = self:getBufferNodeByName("BG_ladder_left")
  //   if bgLadderLeft then
  //     bgLadderLeft:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.flag)
  //   end
  //   local bgLadderRight = self:getBufferNodeByName("BG_ladder_right")
  //   if bgLadderRight then
  //     bgLadderRight:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.louti_r)
  //   end
  //   local flowerbedLeft = self:getBufferNodeByName("BG_flowerbed_left")
  //   if flowerbedLeft then
  //     flowerbedLeft:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.louti_dl)
  //   end
  //   local flowerbedRight = self:getBufferNodeByName("BG_flowerbed_right")
  //   if flowerbedRight then
  //     flowerbedRight:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.louti_dr)
  //   end
  //   local img_merchant = self:getBufferNodeByName("Img_Lvxingshanren")
  //   if img_merchant then
  //     img_merchant:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.lvxing)
  //   end
  //   local dh_huodong_ex = self:getBufferNodeByName("dh_huodong_ex")
  //   if dh_huodong_ex then
  //     dh_huodong_ex:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.drill)
  //   end
  //   local dh_huodong = self:getBufferNodeByName("dh_huodong")
  //   if dh_huodong then
  //     dh_huodong:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.drill + 2)
  //   end
  //   local dh_floatBus_2 = self:getBufferNodeByName("dh_floatBus_2")
  //   if dh_floatBus_2 then
  //     dh_floatBus_2:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.louti_r)
  //   end
  //   local dh_gatelight_02 = self:getBufferNodeByName("dh_gatelight_02")
  //   if dh_gatelight_02 then
  //     dh_gatelight_02:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.lower_wall)
  //   end
  //   local img_Activity = self:getBufferNodeByName("Img_Activity")
  //   if img_Activity then
  //     img_Activity:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.drill + 1)
  //     if RAMADAN_SWITCH then
  //       img_Activity:setSpriteFrame("dh_7th_activity.png")
  //       img_Activity:setPosition(1846, 1774)
  //       local dh7 = self:getBufferNodeByName("dh_hdzx7_01_1")
  //       if dh7 then
  //         local frames = display.newFrames("dh_hdzx7_%02d.png", 1, 15)
  //         local animation = display.newAnimation(frames, 1.25 / #frames)
  //         dh7:setBlendFunc(gl.ONE, gl.ONE)
  //         dh7:playAnimationForever(animation, 0)
  //       end
  //     else
  //       img_Activity:setSpriteFrame("huodong.png")
  //       img_Activity:setPosition(1756.2, 1729.6)
  //       if SoraDGetFactionType() == FACTION_TYPE.FACTION_BYZANTINE then
  //         img_Activity:setSpriteFrame("BG_penquan_byzantine_01.png")
  //         img_Activity:setPosition(1667.5, 1572.5)
  //       end
  //     end
  //   end
  //   local baseArray = {
  //     "MainCityBG_01",
  //     "MainCityBG_02",
  //     "MainCityBG_03",
  //     "MainCityBG_04",
  //     "MainCityBG_06",
  //     "MainCityBG_07",
  //     "MainCityBG_08",
  //     "MainCityBG_09",
  //     "MainCityBG_13",
  //     "MainCityBG_21"
  //   }
  //   for k, v in ipairs(baseArray) do
  //     local baseTarget = SoraDGetChildByName(self, v)
  //     if baseTarget then
  //       baseTarget:setSpriteFrame(RAMADAN_SWITCH and v .. ".png" or v .. "_pre.png")
  //     end
  //   end
  //   if SoraDGetFactionType() == FACTION_TYPE.FACTION_BYZANTINE then
  //     local baseArray = {
  //       [1] = "BG_hall__01_2",
  //       [2] = "BG_hall__02_2",
  //       [3] = "BG_hall__03_2",
  //       [4] = "BG_hall__04_2",
  //       [7] = "BG_hall__07_2",
  //       [8] = "BG_hall__08_2",
  //       [9] = "BG_hall__09_2",
  //       [10] = "BG_hall__10_2",
  //       [14] = "BG_hall__14_2"
  //     }
  //     for k, v in pairs(baseArray) do
  //       local baseTarget = SoraDGetChildByName(self, v)
  //       if baseTarget then
  //         local png = RAMADAN_SWITCH and string.format("BG_byzantine_bingying_hall__%.2d_2.png", k) or
  //         string.format("BG_byzantine_bingying_hall__%.2d_2_pre.png", k) baseTarget:setSpriteFrame(png)
  //       end
  //     end
  //   end
  //   local dhArray = {
  //     "dh_wall_mt",
  //     "build_DH_gate",
  //     "build_DH_wall",
  //     "dh_bridge_L",
  //     "dh_bridge_R",
  //     "build_DH_zhuzi",
  //     "build_DH_lthp",
  //     "build_DH_hp",
  //     "build_DH_hq",
  //     "dh_cmzz_1",
  //     "dh_cmzz_2",
  //     "dh_hpzz",
  //     "BG_tree_byzantine",
  //     "BG_flower",
  //     "BG_chengqiang_byzantine_01_1",
  //     "dh_gate_01",
  //     "dh_gate_02",
  //     "dh_gatelight_01",
  //     "dh_lightzz_01",
  //     "dh_lightzz_02",
  //     "dh_popcorn_3",
  //     "dh_pbtz_01",
  //     "dh_cqjnh_01",
  //     "dh_cqjnh_02",
  //     "dh_xzmmzz",
  //     "dh_bridge_01",
  //     "dh_bridge_02",
  //     "dh_light_01",
  //     "dh_light_02",
  //     "dh_light_03",
  //     "dh_light_04",
  //     "dh_light_05",
  //     "dh_light_06",
  //     "dh_light_07",
  //     "dh_light_08",
  //     "tree01_01",
  //     "tree02_01",
  //     "tree03_01",
  //     "dh_zyzz_01",
  //     "dh_zyzz_02"
  //   }
  //   local spArray = {
  //     "dh_7th_zz_02",
  //     "dh_7th_zz_03",
  //     "dh_7th_zz_04",
  //     "dh_7th_zz_05",
  //     "dh_7th_zz_06",
  //     "dh_7th_zz_07",
  //     "dh_7th_zz_08",
  //     "dh_7th_zz_09",
  //     "dh_hdzx7_01_1"
  //   }
  //   for k, v in ipairs(dhArray) do
  //     local dh_target = self:getBufferNodeByName(v)
  //     if dh_target then
  //       dh_target:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.drill)
  //     end
  //   end
  //   for k, v in ipairs(spArray) do
  //     local dh_targetSp = self:getBufferNodeByName(v)
  //     if dh_targetSp then
  //       dh_targetSp:setVisible(RAMADAN_SWITCH)
  //       if "dh_hdzx7_01_1" == v then
  //         dh_targetSp:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.drill + 1)
  //       else
  //         dh_targetSp:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.drill)
  //       end
  //     end
  //   end
  //   local img_petBG = self:getBufferNodeByName("frame_chongwuguan_shadow_1")
  //   if img_petBG then
  //     img_petBG:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.inner_build - 1)
  //   end
  //   local img_petCube = self:getBufferNodeByName("BG_pet_shadow_1")
  //   if img_petCube then
  //     img_petCube:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.inner_build + 1)
  //   end
  //   local img_deng = self:getBufferNodeByName("zhaiyuedeng_58")
  //   if img_deng then
  //     img_deng:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.drill)
  //   end
  //   local Particle_activity = self:getBufferNodeByName("Particle_activity")
  //   if Particle_activity then
  //     Particle_activity:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.drill + 1)
  //   end
  //   local dh_fiveth_door2_0 = self:getBufferNodeByName("dh_fiveth_door2_0")
  //   if dh_fiveth_door2_0 then
  //     dh_fiveth_door2_0:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.drill + 10)
  //   end
  //   local BG_tree_03_activity = self:getBufferNodeByName("BG_tree_03_activity")
  //   if BG_tree_03_activity then
  //     BG_tree_03_activity:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.tree)
  //   end
  //   local BG_altar = self:getBufferNodeByName("BG_altar")
  //   if BG_altar then
  //     BG_altar:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.drill)
  //   end
  //   local BG_lion = self:getBufferNodeByName("BG_lion")
  //   if BG_lion then
  //     BG_lion:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.banyungong)
  //     BG_lion:setVisible(false)
  //   end
  //   local BG_beachStone = self:getBufferNodeByName("BG_beachStone")
  //   if BG_beachStone then
  //     BG_beachStone:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.drill)
  //   end
  //   local dh_bridge = self:getBufferNodeByName("dh_bridge")
  //   if dh_bridge then
  //     dh_bridge:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.drill)
  //   end
  //   local BG_Matou = self:getBufferNodeByName("BG_Matou")
  //   if BG_Matou then
  //     BG_Matou:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.drill)
  //   end
  //   for i = 30001, 30008 do
  //     local btnBuild = self:getBufferNodeByName("build_" .. i)
  //     if btnBuild then
  //       local zorder = mainCityDefine.CITY_TARGET_ZORDER.drill + 1
  //       if i == 30001 or i == 30002 or i == 30003 or i == 30007 then
  //         zorder = mainCityDefine.CITY_TARGET_ZORDER.inner_build
  //       end
  //       if i == 30005 then
  //         zorder = SoraDGetCastleLv() < CASTLE_LV25_LIMITED and mainCityDefine.CITY_TARGET_ZORDER.inner_build or
  //         mainCityDefine.CITY_TARGET_ZORDER.drill + 1
  //       end
  //       btnBuild:setLocalZOrder(zorder)
  //     end
  //   end
  //   for i = 1151, 1152 do
  //     local btnBuild = self:getBufferNodeByName("build_" .. i)
  //     if btnBuild then
  //       btnBuild:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.xunluo)
  //     end
  //   end
  // end
}

void MainCityFunctions::CancelBuildTint(Node *p_Node){

}

void MainCityFunctions::ShowNodeTint(Node *p_Node){
  if(!p_Node)
    return;
  p_Node->stopActionByTag(77);
  p_Node->setColor(Color3B(100, 100, 100));
  auto l_ActionTintTo = TintBy::create(0.5f, 0.5f, 0.5f, 0.5f);
  auto l_Delay = DelayTime::create(0.3f);
  auto l_ActionTintBack = TintBy::create(0.5f, -0.5f, -0.5f, -0.5f);
  auto l_ActionRepeat = RepeatForever::create(
    Sequence::create(
      l_ActionTintTo,
      l_Delay,
      l_ActionTintBack,
      nullptr
    )
  );
  l_ActionRepeat->setTag(77);
  p_Node->runAction(l_ActionRepeat);
}

void MainCityFunctions::ShowNodeTintOnce(Node *p_Node){
  if(!p_Node)
    return;
  p_Node->stopActionByTag(77);
  p_Node->setColor(Color3B(100, 100, 100));
  auto l_ActionTint = TintBy::create(0.2,  0.607f*255, 0.607f*255, 0.607f*255);
  l_ActionTint->setTag(77);
  p_Node->runAction(l_ActionTint);
}


void MainCityFunctions::DoOffsetContainerWithSelectBuild(
  MainCityView *p_MainCity, Node *p_Building, float p_Scale, RDoOffestMoveParam p_Other){

  CCAssert(p_MainCity, "City View Cannot be Null");
  CCAssert(p_Building, "Building Cannot be Null");

  p_MainCity->StopScrollContainer();
  p_MainCity->_PreContainerOffset = p_MainCity->_ViewScrollView->getContentOffset();
  if(!p_Other._IgnorePreZoomScale)
    p_MainCity->_PreZoomScale = p_MainCity->_ViewScrollView->getZoomScale();
  if(p_Other._NoScaleDuration)
    p_MainCity->SetZoomScale(p_Scale, false, 0, true);
  else 
    p_MainCity->SetZoomScale(p_Scale, true, p_MainCity->_ZoomScaleDuration, true);
  auto l_ZoomScale = p_MainCity->GetZoomScale();
  auto l_PosX = GBase::DFPosX(GDisplay::Get()->size().width - 165, GDisplay::Get()->size().width);
  auto l_PosY = GDisplay::Get()->height * 0.5 + p_MainCity->_HUIBottom + GDisplay::Get()->iPhoneXBottom + 30;
  auto l_OffsetX =  -185;
  auto l_OffsetY = 70;
  l_PosX = GBase::DFPosX(GDisplay::Get()->size().width + l_OffsetX, GDisplay::Get()->size().width);
  l_PosY = GDisplay::Get()->rheight *0.5 + 70 + GDisplay::Get()->iPhoneXBottom;
  auto l_BuildingIndex = static_cast<EBuildingIndex>(p_Building->getTag());
  if(l_BuildingIndex == EBuildingIndex::MaterialWorkShop){
    l_PosX = GDisplay::Get()->size().width * 0.5;
    l_PosY = GDisplay::Get()->rheight * 0.5 + 20 + GDisplay::Get()->iPhoneXBottom;
  }
  if(p_Other._Offset != Vec2::ZERO){
    l_PosX = p_Other._Offset.x;
    l_PosY = p_Other._Offset.y;
  }

  auto l_ScrollOffset = p_MainCity->GetContainerOffsetWhenPosTarget(p_Building, Vec2(l_PosX, l_PosY), true, false);
  if(p_Other._Skip){
    //     local selfPos = cc.p(build:getPositionX(), build:getPositionY())
    //     local offsetPoint = self.viewScrollView:getContentOffset()
    //     local covertPoint = cc.p(display.cx - offsetPoint.x, display.cy - offsetPoint.y)
    //     local subPoint = cc.pSub(covertPoint, selfPos)
    //     local newOffsetPoint = cc.pAdd(offsetPoint, subPoint)
    //     local zoomScale = self.viewScrollView:getZoomScale()
    //     local moveX = 165
    //     if not SoraDFIsRA() then
    //       moveX = 0
    //     end
    //     scrollOffset = cc.p((newOffsetPoint.x + moveX) * self.defaultScale, newOffsetPoint.y * self.defaultScale)
    //     if scrollOffset.x < display.width - self.containerView:getContentSize().width then
    //       scrollOffset.x = display.width - self.containerView:getContentSize().width
    //     elseif 0 < scrollOffset.x then
    //       scrollOffset.x = 0
    //     end
    //     if scrollOffset.y < display.height - self.containerView:getContentSize().height then
    //       scrollOffset.y = display.height - self.containerView:getContentSize().height
    //     elseif 0 < scrollOffset.y then
    //       scrollOffset.y = 0
    //     end
  }
  if(p_Other._NoScaleDuration){
    p_MainCity->RunContainerViewMove(l_ScrollOffset);
    p_MainCity->DisableMoveForDuration(0.1);
  }else{
    p_MainCity->RunContainerViewMove(l_ScrollOffset, p_MainCity->_ZoomScaleDuration);
    p_MainCity->DisableMoveForDuration(p_MainCity->_ZoomScaleDuration);
  }
}
