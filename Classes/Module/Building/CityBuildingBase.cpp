#include "CityBuildingBase.h"

USING_NS_CC;

bool CityBuildingBase::init()
{

    if (!Node::init())
        return false;

    // setAnchorPoint(Vec2(0, 0));
    return true;
}

void CityBuildingBase::onEnter()
{
    Node::onEnter();

    // Do some initialization when this node becomes active.
}

void CityBuildingBase::setBuildingSprite()
{

    BuildingSprite = Sprite::createWithSpriteFrameName(BuildingSpriteImage);
    BuildingSprite->setPosition(this->BuildingSpriteOffset.x, this->BuildingSpriteOffset.y);
    addChild(BuildingSprite);
}

void CityBuildingBase::setUpgradeSprite()
{

    UpgradeSprite = Sprite::createWithSpriteFrameName("icon_main_build_lv.png");
    UpgradeSprite->setPosition(LvlBgOffset.x - 46, LvlBgOffset.y - 22);
    UpgradeSprite->setLocalZOrder(5);
    addChild(UpgradeSprite);
}

void CityBuildingBase::setBuildingLvBg()
{
    BuildingLvBg = Sprite::createWithSpriteFrameName("icon_main_build_upgrade.png");
    BuildingLvBg->setPosition(LvlBgOffset.x, LvlBgOffset.y);
    BuildingLvBg->setLocalZOrder(5);
    addChild(BuildingLvBg);
}

void CityBuildingBase::setBuildingLvlText()
{

    BuildingLvText = Label::createWithSystemFont("8", "Arial", 18);
    BuildingLvText->setSkewY(25);
    BuildingLvText->setAnchorPoint(Vec2(0.5, 0.5));
    BuildingLvText->setColor(Color3B(235, 255, 20));
    BuildingLvText->setPosition(LvlBgOffset.x - 20, LvlBgOffset.y - 1);
    BuildingLvText->setLocalZOrder(6);
    BuildingLvText->setAlignment(TextHAlignment::CENTER);
    addChild(BuildingLvText);
}

void CityBuildingBase::setBuildingSleepSprite()
{

    int32 offsetX = 50;
    int32 offsetY = 40;
    int32 oriX = 44;
    int32 oriY = 97;

    auto actionMoveTo = MoveTo::create(0, Vec2(oriX, oriY));
    auto actionFadeTo = FadeTo::create(0, 1);
    auto actionRotateTo = RotateTo::create(0, 0);
    auto actionMoveBy = MoveBy::create(1.6, Vec2(offsetX, offsetY));
    auto actionFadeTo2 = FadeTo::create(1.6, 0.5);
    auto actionRotateBy = RotateBy::create(1.6, 30);

    Spawn *actionSpawn = Spawn::create(actionMoveBy, actionFadeTo2, actionRotateBy, NULL);
    Sequence *sequenceAction = Sequence::create(actionMoveTo, actionFadeTo, actionRotateTo, actionSpawn, NULL);

    DelayTime *actionDelay1 = DelayTime::create(0.2);

    Sequence *actionSeq2 = Sequence::create(
        MoveTo::create(0, Vec2(oriX, oriY)),
        FadeTo::create(0, 1),
        RotateTo::create(0, 0),
        Spawn::create(
            MoveBy::create(1.6, Vec2(offsetX, offsetY)),
            FadeTo::create(1.6, 0.5),
            RotateBy::create(1.6, -30),
            NULL),
        NULL);

    DelayTime *actionDelay2 = DelayTime::create(0.2);

    Sequence *actionSeq3 = Sequence::create(
        MoveTo::create(0, Vec2(oriX, oriY)),
        FadeTo::create(0, 1),
        RotateTo::create(0, 0),
        Spawn::create(
            MoveBy::create(1.6, Vec2(offsetX, offsetY)),
            FadeTo::create(1.6, 0),
            RotateBy::create(1.6, 30),
            NULL),
        NULL);

    DelayTime *actionDelay3 = DelayTime::create(3.8);

    Sequence *actionSeq4 = Sequence::create(
        actionDelay1,
        actionSeq2,
        actionDelay2,
        actionSeq3,
        actionDelay3,
        NULL);

    RepeatForever *actionRepeat = RepeatForever::create(actionSeq4);

    auto SleepSprite = Sprite::createWithSpriteFrameName("z.png");
    SleepSprite->setPosition(oriX, oriY);
    SleepSprite->setLocalZOrder(5);
    addChild(SleepSprite);
    SleepSprite->runAction(actionRepeat);
}

void CityBuildingBase::setBuildingIconMiracle()
{

    auto SleepSprite2 = Sprite::createWithSpriteFrameName(BuildingIconMiracle);
    SleepSprite2->setPosition(80, 18);
    SleepSprite2->setLocalZOrder(3);
    addChild(SleepSprite2);
}

Vector<SpriteFrame *> CityBuildingBase::getAnimation(GString Frame, int32 start, int32 end)
{

    auto spritecache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame *> animFrames;
    char str[100];
    for (int i = start; i <= end; i++)
    {
        sprintf(str, Frame.c_str(), i);
        animFrames.pushBack(spritecache->getSpriteFrameByName(str));
    }
    return animFrames;
}

void CityBuildingBase::setBuildingParticle()
{
}

void CityBuildingBase::setBuildingAnimation()
{
}

void CityBuildingBase::setBuildingUnitData(DSCityBuildingUnit &_CBUD)
{
    BuildingUnitData = _CBUD;
}

void CityBuildingBase::setBuildingBtn()
{
}