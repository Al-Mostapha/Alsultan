// Fill out your copyright notice in the Description page of Project Settings.


#include "CityBuildingTopTip.h"



CityBuildingTopTip::CityBuildingTopTip() {


}

bool CityBuildingTopTip::init() {

    Node::init();

    setTipBg();
    setTipAction();
   
    return true;
}



void CityBuildingTopTip::onEnter() {
    Node::onEnter();
}

void CityBuildingTopTip::setTipBg() {

	TipBg = Sprite::createWithSpriteFrameName("frame_main_receive.png");
    TipBg->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
	addChild(TipBg);
}


void CityBuildingTopTip::setTipIcon(const char* Icon) {

    TipIcon = Sprite::createWithSpriteFrameName(Icon);
    //TipIcon->setScaleX(TipBg->getContentSize().width / TipIcon->getContentSize().width);
    //TipIcon->setScaleY(TipBg->getContentSize().height / TipIcon->getContentSize().height);
    TipIcon->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
    addChild(TipIcon);
}


void CityBuildingTopTip::setTipAction() {
    
    auto rotateByRight = RotateBy::create(0.1, 15);
    auto rotateByToLeft = RotateBy::create(0.2, -30);
    auto rotateBack = RotateBy::create(0.1, 15);
    auto rotateByRight2 = RotateBy::create(0.08, 8);
    auto rotateByToLeft2 = RotateBy::create(0.16, -16);
    auto rotateBack2 = RotateBy::create(0.08, 8);
    auto rotateByRight3 = RotateBy::create(0.05, 5);
    auto rotateByToLeft3 = RotateBy::create(0.1, -10);
    auto rotateBack3 = RotateBy::create(0.05, 5);
    auto delayTime = DelayTime::create(2.5);
    auto seqA = Sequence::create(
        rotateByRight,
        rotateByToLeft,
        rotateBack,
        rotateByRight2,
        rotateByToLeft2,
        rotateBack2,
        rotateByRight3,
        rotateByToLeft3,
        rotateBack3,
        delayTime, NULL
    );

    auto repeatA = RepeatForever::create(seqA);
    runAction(repeatA);
}


CityBuildingTopTip* CityBuildingTopTip::tipTypeFree() {
    auto _Node = CityBuildingTopTip::create();
    return _Node;
}
CityBuildingTopTip* CityBuildingTopTip::tipHelpAll() {
    CityBuildingTopTip* _Node = CityBuildingTopTip::create();
    _Node->setTipIcon("icon_building_help.png");
    _Node->TipIcon->setPosition(-2, 0);
    _Node->TipIcon->setScale(0.8);
    return _Node;
}

CityBuildingTopTip* CityBuildingTopTip::tipReqHelp() { 
    CityBuildingTopTip* _Node = CityBuildingTopTip::create();
    _Node->setTipIcon("icon_building_askforhelp.png");
    _Node->TipIcon->setPosition(2, -10);
    _Node->TipIcon->setLocalZOrder(2);
    return _Node;
}
CityBuildingTopTip* CityBuildingTopTip::tipTypeTrainFinish() { 

    CityBuildingTopTip* _Node = CityBuildingTopTip::create();
    _Node->setTipIcon("icon_building_training_finish.png");
    _Node->TipIcon->setPosition(2, 2);
    _Node->TipIcon->setLocalZOrder(2);
    return _Node;
};

// Traps Train
CityBuildingTopTip* CityBuildingTopTip::tipTopTypeTrainTrap() { 
    CityBuildingTopTip* _Node = CityBuildingTopTip::create();
    _Node->setTipIcon("icon_building_trap_finish.png");
    _Node->TipIcon->setPosition(6, -2);
    _Node->TipIcon->setScale(0.8);
    _Node->TipIcon->setLocalZOrder(2);
    return _Node;
};
CityBuildingTopTip* CityBuildingTopTip::tipTypeCollectFood() { 
    CityBuildingTopTip* _Node = CityBuildingTopTip::create();
    _Node->setTipIcon("icon_middle_food.png");
    _Node->TipIcon->setPosition(0, 15);
    _Node->TipIcon->setLocalZOrder(2);
    return _Node;
};
CityBuildingTopTip* CityBuildingTopTip::tipTypeCollectWood() { 
    CityBuildingTopTip* _Node = CityBuildingTopTip::create();
    _Node->setTipIcon("icon_middle_wood.png");
    _Node->TipIcon->setPosition(2, 20);
    _Node->TipIcon->setLocalZOrder(2);
    return _Node;
};
CityBuildingTopTip* CityBuildingTopTip::tipTypeCollectIron() { 
    CityBuildingTopTip* _Node = CityBuildingTopTip::create();
    _Node->setTipIcon("icon_middle_iron.png");
    _Node->TipIcon->setPosition(2, 15);
    _Node->TipIcon->setLocalZOrder(2);
    return _Node;
};
CityBuildingTopTip* CityBuildingTopTip::tipTypeCollectCrystal() {
    CityBuildingTopTip* _Node = CityBuildingTopTip::create();
    _Node->setTipIcon("icon_middle_crystal.png");
    _Node->TipIcon->setPosition(2, 15);
    _Node->TipIcon->setLocalZOrder(2);
    return _Node;
};
CityBuildingTopTip* CityBuildingTopTip::tipTypeCollectSteel() { 
    CityBuildingTopTip* _Node = CityBuildingTopTip::create();
    _Node->setTipIcon("icon_middle_silver.png");
    _Node->TipIcon->setPosition(-2, 15);
    _Node->TipIcon->setLocalZOrder(2);
    return _Node;
};

// collect box  from harbor
CityBuildingTopTip* CityBuildingTopTip::tipTypeCollectGangkou() { 
    CityBuildingTopTip* _Node = CityBuildingTopTip::create();
    _Node->setTipIcon("icon_goods_box.png");
    _Node->TipIcon->setPosition(0, 10);
    _Node->TipIcon->setScale(0.8);
    _Node->TipIcon->setLocalZOrder(2);
    return _Node;
};
CityBuildingTopTip* CityBuildingTopTip::tipTypeCommunityBBS() { 
    CityBuildingTopTip* _Node = CityBuildingTopTip::create();
    _Node->setTipIcon("btn_community.png");
    _Node->TipIcon->setPosition(-2, 15);
    _Node->TipIcon->setScale(0.8);
    _Node->TipIcon->setLocalZOrder(2);
    return _Node;
};
CityBuildingTopTip* CityBuildingTopTip::tipTypeCommunityService() { 
    CityBuildingTopTip* _Node = CityBuildingTopTip::create();
    _Node->setTipIcon("btn_customer_service.png");
    _Node->TipIcon->setPosition(-2, 10);
    _Node->TipIcon->setScale(0.8);
    _Node->TipIcon->setLocalZOrder(2);
    return _Node;
};
CityBuildingTopTip* CityBuildingTopTip::tipTypeTrainEquip() {
    CityBuildingTopTip* _Node = CityBuildingTopTip::create();
    _Node->setTipIcon("icon_equip_box2.png");
    _Node->TipIcon->setPosition(0, 0);
    _Node->TipIcon->setScale(0.8);
    _Node->TipIcon->setLocalZOrder(2);
    return _Node;
};
CityBuildingTopTip* CityBuildingTopTip::tipTypeAllianceWar() {
    CityBuildingTopTip* _Node = CityBuildingTopTip::create();
    _Node->setTipIcon("icon_alliancewar.png");
    _Node->TipIcon->setPosition(2, 22);
    _Node->TipIcon->setScale(0.8);
    _Node->TipIcon->setLocalZOrder(2);
    return _Node;
};

CityBuildingTopTip* CityBuildingTopTip::tipTypeTrainMaterial() { 
    CityBuildingTopTip* _Node = CityBuildingTopTip::create();
    _Node->setTipIcon("icon_equip_box2.png");
    _Node->TipIcon->setPosition(0, 20);
    _Node->TipIcon->setScale(0.8);
    _Node->TipIcon->setLocalZOrder(2);
    Sprite* _Node2 = Sprite::createWithSpriteFrameName("icon_yes2.png");
    _Node2->setPosition(4, 64);
    _Node2->setScale(1.1);
    _Node2->setLocalZOrder(3);
    _Node->addChild(_Node2);
    return _Node;
};

/* Daily Reward*/
CityBuildingTopTip* CityBuildingTopTip::tipTypeHuochuang() { 
    CityBuildingTopTip* _Node = CityBuildingTopTip::create();
    _Node->setTipIcon("btn_dailyreward.png");
    _Node->TipIcon->setPosition(0, 10);
    _Node->TipIcon->setScale(1);
    _Node->TipIcon->setLocalZOrder(2);
    return _Node;
};


CityBuildingTopTip* CityBuildingTopTip::tipTypeBulletInBoard() { 
    CityBuildingTopTip* _Node = CityBuildingTopTip::create();
    _Node->setTipIcon("icon_notice_board_limit.png");
    _Node->TipIcon->setPosition(-2, 26);
    _Node->TipIcon->setScale(0.8);
    _Node->TipIcon->setLocalZOrder(2);
    return _Node;
};
CityBuildingTopTip* CityBuildingTopTip::tipTypeActivity() {
    CityBuildingTopTip* _Node = CityBuildingTopTip::create();
    _Node->setTipIcon("icon_goods_box.png");
    _Node->TipIcon->setPosition(0, 7);
    _Node->TipIcon->setScale(0.48);
    _Node->TipIcon->setLocalZOrder(2);
    return _Node;
};
CityBuildingTopTip* CityBuildingTopTip::tipTypePrompt() {
    CityBuildingTopTip* _Node = CityBuildingTopTip::create();
    _Node->setTipIcon("icon_saleRoom_symbol.png");
    _Node->TipIcon->setPosition(3, 10);
    _Node->TipIcon->setScale(0.65);
    _Node->TipIcon->setLocalZOrder(2);
    return _Node;
};
CityBuildingTopTip* CityBuildingTopTip::tipTypeGold() {
    CityBuildingTopTip* _Node = CityBuildingTopTip::create();
    _Node->setTipIcon("icon_building_gold_speedup.png");
    _Node->TipIcon->setPosition(3, -10);
    _Node->TipIcon->setScale(1);
    _Node->TipIcon->setLocalZOrder(2);
    return _Node;
};
CityBuildingTopTip* CityBuildingTopTip::tipTypePremiumVipMall() {
    CityBuildingTopTip* _Node = CityBuildingTopTip::create();
    _Node->setTipIcon("icon_wharf_Extreme_shop.png");
    _Node->TipIcon->setPosition(0, 10);
    _Node->TipIcon->setScale(0.65);
    _Node->TipIcon->setLocalZOrder(2);
    return _Node;
};
CityBuildingTopTip* CityBuildingTopTip::tipTypeNpcTip() {
    CityBuildingTopTip* _Node = CityBuildingTopTip::create();
    _Node->setTipIcon("icon_assistant_npc.png");
    _Node->TipIcon->setPosition(0, -5);
    _Node->TipIcon->setScale(0.65);
    _Node->TipIcon->setLocalZOrder(2);
    return _Node;
};
CityBuildingTopTip* CityBuildingTopTip::tipTypeAllianceTreasureTip() { 
    CityBuildingTopTip* _Node = CityBuildingTopTip::create();
    _Node->setTipIcon("allitreas_box_01.png");
    _Node->TipIcon->setPosition(0, 10);
    _Node->TipIcon->setScale(0.5);
    _Node->TipIcon->setLocalZOrder(2);
    return _Node;
};
CityBuildingTopTip* CityBuildingTopTip::tipEndlessTreasure() { 
    CityBuildingTopTip* _Node = CityBuildingTopTip::create();
    _Node->setTipIcon("icon_coinbox_close.png");
    _Node->TipIcon->setPosition(0, 10);
    _Node->TipIcon->setScale(0.5);
    _Node->TipIcon->setLocalZOrder(2);
    return _Node;
};
CityBuildingTopTip* CityBuildingTopTip::tipTypeCastleGiftTip() {
    CityBuildingTopTip* _Node = CityBuildingTopTip::create();
    _Node->setTipIcon("icon_castleLv_privilege.png");
    _Node->TipIcon->setPosition(-5, 10);
    _Node->TipIcon->setScale(0.65);
    _Node->TipIcon->setLocalZOrder(2);
    return _Node;
};
CityBuildingTopTip* CityBuildingTopTip::tipArenaTip() { 
    CityBuildingTopTip* _Node = CityBuildingTopTip::create();
    _Node->setTipIcon("icon_building_gold_speedup.png");
    _Node->TipIcon->setPosition(3, 10);
    _Node->TipIcon->setScale(1);
    _Node->TipIcon->setLocalZOrder(2);
    return _Node;
};
CityBuildingTopTip* CityBuildingTopTip::tipPetUnlock() {
    CityBuildingTopTip* _Node = CityBuildingTopTip::create();
    _Node->setTipIcon("icon_pet_unlock.png");
    _Node->TipIcon->setPosition(0, 0);
    _Node->TipIcon->setScale(1);
    _Node->TipIcon->setLocalZOrder(2);
    return _Node;
};
CityBuildingTopTip* CityBuildingTopTip::tipPetSkillSend() {
    CityBuildingTopTip* _Node = CityBuildingTopTip::create();
    _Node->setTipIcon("icon_pet_skillreceice.png");
    _Node->TipIcon->setPosition(0, 0);
    _Node->TipIcon->setScale(1);
    _Node->TipIcon->setLocalZOrder(2);
    return _Node;
};
CityBuildingTopTip* CityBuildingTopTip::tipEpicwarFull(){
    CityBuildingTopTip* _Node = CityBuildingTopTip::create();
    _Node->setTipIcon("3106.png");
    _Node->TipIcon->setPosition(0, 10);
    _Node->TipIcon->setScale(0.6);
    _Node->TipIcon->setLocalZOrder(2);
    return _Node;
};
CityBuildingTopTip* CityBuildingTopTip::tipFriendApply(){
    CityBuildingTopTip* _Node = CityBuildingTopTip::create();
    _Node->setTipIcon("3106.png");
    _Node->TipIcon->setPosition(0, 10);
    _Node->TipIcon->setScale(0.6);
    _Node->TipIcon->setLocalZOrder(2);
    return _Node;
};
CityBuildingTopTip* CityBuildingTopTip::tipTypePromote(){
    CityBuildingTopTip* _Node = CityBuildingTopTip::create();
    _Node->setTipIcon("icon_bzjs.png");
    _Node->TipIcon->setPosition(0, 12);
    _Node->TipIcon->setScale(0.95);
    _Node->TipIcon->setLocalZOrder(2);
    return _Node;
};
CityBuildingTopTip* CityBuildingTopTip::tipTypeHasPrisoner() {
    CityBuildingTopTip* _Node = CityBuildingTopTip::create();
    _Node->setTipIcon("btn_hero_prison_01.png");
    _Node->TipIcon->setPosition(0, 0);
    _Node->TipIcon->setScale(1);
    _Node->TipIcon->setLocalZOrder(2);
    return _Node;
};
CityBuildingTopTip* CityBuildingTopTip::tipTypeHeroReward() {
    CityBuildingTopTip* _Node = CityBuildingTopTip::create();
    _Node->setTipIcon("icon_saleRoom_symbol.png");
    _Node->TipIcon->setPosition(3, 10);
    _Node->TipIcon->setScale(0.65);
    _Node->TipIcon->setLocalZOrder(2);
    return _Node;
};
CityBuildingTopTip* CityBuildingTopTip::tipTypeDefendEmptySite() {
    CityBuildingTopTip* _Node = CityBuildingTopTip::create();
    _Node->setTipIcon("icon_saleRoom_symbol.png");
    _Node->TipIcon->setPosition(3, 10);
    _Node->TipIcon->setScale(0.65);
    _Node->TipIcon->setLocalZOrder(2);
    return _Node;
};
CityBuildingTopTip* CityBuildingTopTip::tipTypeMonument() {
    CityBuildingTopTip* _Node = CityBuildingTopTip::create();
    _Node->setTipIcon("icon_saleRoom_symbol.png");
    _Node->TipIcon->setPosition(3, 10);
    _Node->TipIcon->setScale(0.65);
    _Node->TipIcon->setLocalZOrder(2);
    return _Node;
};
