// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingFEpicBattle.h"
#include "Module/UI/Panel/Building/EpicWar/UIEpicWarView.h"
#include "Scene/CityScene.h"

BuildingFEpicBattle::BuildingFEpicBattle()
{

	BuildingSpriteImage = "altar.png";
	BuildingIconMiracle = "armyicon_s_10004711.png";
	BuildingSpriteOffset = {5, -8};
}

bool BuildingFEpicBattle::init()
{

	if (!CityBuildingBase::init())
		return false;
	setBuildingSprite();
	setBuildingSleepSprite();
	// setBuildingLvBg();
	// setUpgradeSprite();
	// setBuildingLvlText();
	// setBuildingIconMiracle();

	/*local circle1Shader = require("app.game.cityBuild.shader.shishitongshuai")
	local circle1MeshData = require("app.game.cityBuild.meshData.SM_Ring_sstshd_001_meshData")
	local circle1Param = require("app.game.cityBuild.shaderCfg.SM_Ring_sstshd_001_shaderCfg")
	local circle1CreateData = {
		meshData = circle1MeshData,
		size = cc.size(1, 1),
		shader = {
			vertBytes = circle1Shader.vertBytes,
			fragBytes = circle1Shader.fragBytes
		},
		param = circle1Param.param,
		pos = cc.p(-5, -150),
		scale = {x = 0.16, y = 0.16}
	}
	local circle1MeshNode = SoraDCreateMeshNode(circle1CreateData.meshData, circle1CreateData.size, circle1CreateData.shader, circle1CreateData.param)
	circle1MeshNode:setPosition(cc.p(circle1CreateData.pos))
	circle1MeshNode:setScale(circle1CreateData.scale.x, circle1CreateData.scale.y)
	circle1MeshNode:setBlendFunc(gl.ONE, gl.ONE)
	circle1MeshNode:setRotation3D({
		x = 0,
		y = 0,
		z = 0
	})
	circle1MeshNode:addTo(self)
	self.circle1MeshNode = circle1MeshNode
	local circle2Shader = require("app.game.cityBuild.shader.shishitongshuai")
	local circle2MeshData = require("app.game.cityBuild.meshData.SM_Ring_sstshd_002_meshData")
	local circle2Param = require("app.game.cityBuild.shaderCfg.SM_Ring_sstshd_002_shaderCfg")
	local circle2CreateData = {
		meshData = circle2MeshData,
		size = cc.size(1, 1),
		shader = {
			vertBytes = circle2Shader.vertBytes,
			fragBytes = circle2Shader.fragBytes
		},
		param = circle2Param.param,
		pos = cc.p(-5, -150),
		scale = {x = 0.16, y = 0.16}
	}
	local circle2MeshNode = SoraDCreateMeshNode(circle2CreateData.meshData, circle2CreateData.size, circle2CreateData.shader, circle2CreateData.param)
	circle2MeshNode:setPosition(cc.p(circle2CreateData.pos))
	circle2MeshNode:setScale(circle2CreateData.scale.x, circle2CreateData.scale.y)
	circle2MeshNode:setBlendFunc(gl.ONE, gl.ONE)
	circle2MeshNode:setRotation3D({
		x = 0,
		y = 0,
		z = 0
	})
	circle2MeshNode:addTo(self, -1)
	self.circle2MeshNode = circle2MeshNode*/

	return true;
}

void BuildingFEpicBattle::onEnter()
{

	CityBuildingBase::onEnter();
}

void BuildingFEpicBattle::Clicked(Touch *p_Touch, Event *p_Event){
  if(IsLocked()){
    GBase::DShowMsgTip(Translate::i18n("common_text_2122", {
      {"name", Translate::i18n("epicbattle_title_01")},
      {"lv", std::to_string(GBase::Const::Get()->CastleLvl7)}
    }));
    CityLib::Get()->ShowTintOnce(GBase::getChildByName<Node *>(this, "buildImg"));
    return;
  }

  auto l_Sequance = Sequence::create(
    CallFunc::create([](){
      CityLib::Get()->PlaySound(
        "innerbuildsound", EBuilding::Prison,
        EBuildingActionTag::TagPlayClickBuildSound
      );
    }),
    DelayTime::create(0.3),
    CallFunc::create([](){
      auto l_Panel = UIEpicWarView::Create();
      l_Panel->InitPanel();
      l_Panel->Show();
    }),
    DelayTime::create(0.3),
    CallFunc::create([](){
      if(!CityScene::Get())
        return;
      CityScene::Get()->ButtonEpicBattle->setEnabled(true);
      CityScene::Get()->ButtonEpicBattle->setSwallowTouches(false);
    }),
    nullptr
  );
  CityScene::Get()->runAction(l_Sequance);
  return;
}