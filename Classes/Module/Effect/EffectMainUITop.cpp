#include "EffectMainUITop.h"
#include "Module/UI/MainUI/UIMainTop.h"
#include "Module/Activity/Activity.Type.h"

EffectMainUITop *EffectMainUITop::Get(){
  static EffectMainUITop *l_Instance = new EffectMainUITop();
  return l_Instance;
}

Node *EffectMainUITop::LuckyBlessShow(ELuckyBlessActivityEffectType p_ShowType){
  // local gametop = gModuleMgr.getObject("gametop")
  // local luckyBlessCtrl = gametop.playertop_:getModule("luckyBlessCtrl")
  // local node = display.newNode()
  // node:setScale(0.6)
  // local button = ccui.Button:create("bg_transparent.png", "bg_transparent.png", "bg_transparent.png", ccui.TextureResType.plistType)
  // button:setContentSize(cc.size(110, 90))
  // button:ignoreContentAdaptWithSize(false)
  // button:addTouchEventListener(function(target, type)
  //   if type == ccui.TouchEventType.ended then
  //     SoraDPlaySound()
  //     if SoraDGetCastleLv() < CASTLE_LV6_LIMITED then
  //       SoraDShowMsgTip(i18n("common_text_1795", {num = CASTLE_LV6_LIMITED}))
  //     else
  //       SoraDCreatePanel("eventLuckyBlessView"):show()
  //     end
  //   end
  // end)
  // button:addTo(node)
  // local spriteBg = display.newSprite("#frame_recharge__sheer_time.png")
  // spriteBg:setPosition(cc.p(0, -50))
  // spriteBg:addTo(node, 5)
  // spriteBg:setScaleX(0.6)
  // local labelTime = ccui.Text:create("99:99:99", "", 20)
  // labelTime:addTo(node, 5)
  // labelTime:setColor(cc.c3b(196, 195, 157))
  // labelTime:setPosition(cc.p(0, -50))
  // labelTime:runAction(cca.repeatForever(cca.seq({
  //   cca.callFunc(function(target)
  //     local time, actTime = luckyBlessCtrl:getRealTime()
  //     if showType > 0 then
  //       target:setString(SoraDConvertSecondToString(time))
  //     else
  //       target:setString(SoraDConvertSecondToString(actTime))
  //     end
  //   end),
  //   cca.delay(1)
  // })))
  // local luckySpine = sp.SkeletonAnimation:create("spine/xingyunri.skel", "spine/xingyunri.atlas", 1)
  // luckySpine:setPosition(cc.p(1.21, -70))
  // luckySpine:addTo(node, 1)
  // if luckyBlessCtrl:getCurEffectType() == gLuckyBlessActivityEffectType.BUILD_UPGRADE then
  //   luckySpine:setAnimation(0, "activation01", true)
  // elseif luckyBlessCtrl:getCurEffectType() == gLuckyBlessActivityEffectType.TECHNOLOGY_RESEARCH then
  //   luckySpine:setAnimation(0, "activation02", true)
  // elseif luckyBlessCtrl:getCurEffectType() == gLuckyBlessActivityEffectType.TRAIN_SOLDIERS then
  //   luckySpine:setAnimation(0, "activation03", true)
  // elseif luckyBlessCtrl:getCurEffectType() == gLuckyBlessActivityEffectType.BUILD_STRENGTH then
  //   luckySpine:setAnimation(0, "activation04", true)
  // else
  //   luckySpine:setAnimation(0, "activation01", true)
  // end
  // return node
  return Node::create();
}

void EffectMainUITop::DispatchArmyEffect(int32 p_HP){
  // local hp = hp or 5
  // local parent = display.getRunningScene()
  // local mutiple = 0.5
  // local function parEffect()
  //   local beginPos = cc.p(display.cx, display.cy)
  //   local hpPos = cc.p(90, display.height)
  //   local effectNode = SoraDCreatAnimation("Node_Effect_tuiwei01", nil, false)
  //   effectNode:addTo(parent, 9)
  //   local sp_hp = SoraDGetChildByName(effectNode, "G_dh_Tex_XL_zlts02")
  //   sp_hp:setPosition(beginPos.x, beginPos.y)
  //   sp_hp:setVisible(true)
  //   local rotation = math.deg(math.atan((-hpPos.y + beginPos.y) / math.abs(-hpPos.x + beginPos.x))) + 180
  //   sp_hp:setRotation(rotation)
  //   effectNode:runAction(cca.seq({
  //     cca.delay(0.9),
  //     cca.removeSelf()
  //   }))
  // end
  // local phyNode = display.newNode()
  // phyNode:setVisible(false)
  // phyNode:setPosition(cc.p(display.cx, display.cy - 20))
  // phyNode:addTo(parent, 9)
  // local spritePhy = display.newSprite("#icon_lord_sp.png")
  // spritePhy:addTo(phyNode)
  // local labPhy = ccui.Text:create("-" .. hp, "", 24)
  // labPhy:setAnchorPoint(cc.p(0, 0.5))
  // labPhy:setColor(cc.c3b(255, 200, 100))
  // labPhy:setPosition(cc.p(35, 0))
  // labPhy:addTo(phyNode)
  // local seq = transition.sequence({
  //   cca.callFunc(parEffect),
  //   cca.delay(1 * mutiple),
  //   cca.callFunc(function()
  //     phyNode:setVisible(true)
  //   end),
  //   cca.moveBy(1.2 * mutiple, 0, 120),
  //   cca.callFunc(function()
  //     spritePhy:runAction(cca.fadeOut(0.5 * mutiple))
  //     labPhy:runAction(cca.fadeOut(0.5 * mutiple))
  //   end),
  //   cca.delay(0.5 * mutiple),
  //   cca.callFunc(function()
  //     phyNode:removeFromParent()
  //   end)
  // })
  // phyNode:runAction(seq)
}

void EffectMainUITop::FullHPEffect(){
  // local parent = display.getRunningScene()
  // local mutiple = 0.5
  // local parSprite = display.newSprite("#et_green_jianti_attack_01.png")
  // parSprite:setPosition(cc.p(display.cx, display.cy))
  // local rotation = math.deg(math.tan((90 - display.cx) / (display.height - 145 - display.cy)))
  // parSprite:setRotation(rotation - 90)
  // parent:addChild(parSprite, 9)
  // local frames = display.newFrames("et_green_jianti_attack_%.2d.png", 1, 9)
  // local animation = display.newAnimation(frames, mutiple * 1 / 9)
  // parSprite:playAnimationOnce(animation)
  // local seq = transition.sequence({
  //   cca.moveTo(1 * mutiple, 90, display.height - 145),
  //   cca.callFunc(function()
  //     parSprite:removeFromParent()
  //   end)
  // })
  // parSprite:runAction(seq)
}

void EffectMainUITop::LordSkillTransresEffect(){
  // local parent = display.getRunningScene()
  // local aniNode = SoraDCreatAnimationEx("Node_Effect_zyzh01", nil, false, 1, 0, 120)
  // parent:addChild(aniNode, 9)
  // aniNode:setPosition(cc.p(display.cx, display.cy))
  // local seq = transition.sequence({
  //   cca.delay(2),
  //   cca.callFunc(function()
  //     aniNode:removeFromParent()
  //   end)
  // })
  // aniNode:runAction(seq)
}

ui::Button *EffectMainUITop::GoldPackage(){
  auto l_Button = ui::Button::create(
    "bg_transparent.png", "bg_transparent.png",
    "bg_transparent.png", ui::Widget::TextureResType::PLIST
    );
  l_Button->setContentSize(Size(60, 52));
  l_Button->ignoreContentAdaptWithSize(false);
  auto l_BtnBg = GDisplay::Get()->NewSprite("icon_activity_gold_gift2.png");
  l_Button->addChild(l_BtnBg);
  l_BtnBg->setPosition(Vec2(
    l_Button->getContentSize().width/2,
    l_Button->getContentSize().height/2
  ));
  l_BtnBg->setName("btn_bg");
  return l_Button;
}

Node *EffectMainUITop::CombatantGift(){
  // local node = display.newNode()
  // local btn_bg = display.newSprite("#icon_king_war_attender.png")
  // btn_bg:addTo(node, 1)
  // local dh = display.newSprite("#dh_cszlb_01.png")
  // dh:addTo(node, 2)
  // SoraDFadeINOUT(dh)
  // local param = {
  //   [1] = {
  //     plist = "et_cszlb_01.plist",
  //     pos = {x = -13, y = -2},
  //     scale = 3.35
  //   }
  // }
  // local et_node = SoraDCreateEffectNode(param)
  // et_node:addTo(node, 3)
  // return node
  return Node::create();
}

void EffectMainUITop::WarStartVSEffect(){
  // local node = display.newNode()
  // local parent = display.getRunningScene().panelView
  // node:setPosition(cc.p(display.cx, display.cy + 100))
  // node:setScale(1.5)
  // node:addTo(parent, 99)
  // local sprite_V = display.newSprite("#v.png")
  // sprite_V:setAnchorPoint(cc.p(1, 0.5))
  // sprite_V:setPosition(cc.p(-display.cx, 0))
  // sprite_V:addTo(node)
  // local sprite_S = display.newSprite("#s.png")
  // sprite_S:setAnchorPoint(cc.p(0, 0.5))
  // sprite_S:setPosition(cc.p(display.cx, 0))
  // sprite_S:addTo(node)
  // SoraDPlaySound("pyramidBattle", 1)
  // local function showEffect()
  //   local param = {
  //     [1] = {
  //       plist = "et_sdVS_01.plist",
  //       scale = 2.57
  //     },
  //     [2] = {
  //       plist = "et_sdVS_02.plist",
  //       scale = {x = 0.36, y = 5.12},
  //       rotate = -90,
  //       pos = {x = 15, y = -23}
  //     },
  //     [3] = {
  //       plist = "et_sdVS_02.plist",
  //       scale = {x = 0.45, y = 5.67},
  //       rotate = 90,
  //       pos = {x = -30, y = 12}
  //     },
  //     [4] = {
  //       plist = "et_sdVS_03.plist",
  //       pos = {x = 3, y = -3}
  //     },
  //     [5] = {
  //       plist = "et_sdVS_04.plist",
  //       rotate = 90,
  //       pos = {x = 60, y = -3}
  //     },
  //     [6] = {
  //       plist = "et_sdVS_04.plist",
  //       rotate = -90,
  //       pos = {x = -65, y = -3}
  //     },
  //     [7] = {
  //       plist = "et_sdVS_05.plist",
  //       scale = {x = 2.3, y = 0.75},
  //       rotate = -60.37,
  //       pos = {x = -6, y = -2.5}
  //     }
  //   }
  //   local et_node = SoraDCreateEffectNode(param, nil, true)
  //   et_node:addTo(node)
  // end
  // local function vAction()
  //   local seq = cca.seq({
  //     cca.moveBy(0.11666666666666667, 170, 0),
  //     cca.moveBy(0.016666666666666666, 102, 0),
  //     cca.moveBy(0.016666666666666666, 68, 0),
  //     cca.moveBy(0.05, -5, 0),
  //     cca.moveBy(0.1, 5, 0)
  //   })
  //   sprite_V:runAction(seq)
  // end
  // local function sAction()
  //   local seq = cca.seq({
  //     cca.moveBy(0.11666666666666667, -170, 0),
  //     cca.moveBy(0.016666666666666666, -102, 0),
  //     cca.moveBy(0.016666666666666666, -68, 0),
  //     cca.moveBy(0.05, 5, 0),
  //     cca.moveBy(0.1, -5, 0)
  //   })
  //   sprite_S:runAction(seq)
  // end
  // local seq = cca.seq({
  //   cca.callFunc(vAction),
  //   cca.callFunc(sAction),
  //   cca.delay(0.15),
  //   cca.callFunc(showEffect),
  //   cca.delay(1),
  //   cca.callFunc(function()
  //     node:removeFromParent()
  //   end)
  // })
  // node:runAction(seq)
}

void EffectMainUITop::ShowLordPhysicalEffect(UIMainTop *p_UIMainTop){
  // local self = target
  // local style = self.hpReduceStyle or 1
  // local hp = self.hpReduceValue or 5
  // local parent = display.getRunningScene().panelView
  // local mutiple = 0.5
  // if style == 1 then
  //   do
  //     local function parEffect()
  //       local beginPos = cc.p(display.cx, display.cy)
  //       local hpPos = cc.p(90, display.height)
  //       local effectNode = SoraDCreatAnimation("Node_Effect_tuiwei01", nil, false)
  //       effectNode:addTo(parent, 9)
  //       local sp_hp = SoraDGetChildByName(effectNode, "G_dh_Tex_XL_zlts02")
  //       sp_hp:setPosition(beginPos.x, beginPos.y)
  //       sp_hp:setVisible(true)
  //       local rotation = math.deg(math.atan((display.height - 145 - (display.cy - 20)) / (display.cx - 90))) + 90
  //       sp_hp:setRotation(rotation)
  //       effectNode:runAction(cca.seq({
  //         cca.delay(0.9),
  //         cca.removeSelf()
  //       }))
  //     end
  //     local phyNode = display.newNode()
  //     phyNode:setVisible(false)
  //     phyNode:setPosition(cc.p(display.cx, display.cy - 20))
  //     phyNode:addTo(parent, 9)
  //     local spritePhy = display.newSprite("#icon_lord_sp.png")
  //     spritePhy:addTo(phyNode)
  //     local labPhy = ccui.Text:create("-" .. hp, "", 24)
  //     labPhy:setAnchorPoint(cc.p(0, 0.5))
  //     labPhy:setColor(cc.c3b(255, 200, 100))
  //     labPhy:setPosition(cc.p(35, 0))
  //     labPhy:addTo(phyNode)
  //     local seq = transition.sequence({
  //       cca.callFunc(parEffect),
  //       cca.delay(1 * mutiple),
  //       cca.callFunc(function()
  //         phyNode:setVisible(true)
  //       end),
  //       cca.moveBy(1.2 * mutiple, 0, 120),
  //       cca.callFunc(function()
  //         spritePhy:runAction(cca.fadeOut(0.5 * mutiple))
  //         labPhy:runAction(cca.fadeOut(0.5 * mutiple))
  //       end),
  //       cca.delay(0.5 * mutiple),
  //       cca.callFunc(function()
  //         phyNode:removeFromParent()
  //         self.isUpdateHP = false
  //         self.isSetHPStyle = false
  //       end)
  //     })
  //     phyNode:runAction(seq)
  //   end
  // elseif style == 2 then
  //   do
  //     local beginPos = cc.p(display.cx, display.cy + 150)
  //     local hpPos = cc.p(90, display.height - 110)
  //     local effectNode = SoraDCreatAnimation("Node_Effect_tuiwei01", nil, false)
  //     effectNode:addTo(parent, 9)
  //     local sp_hp = SoraDGetChildByName(effectNode, "G_dh_Tex_XL_zlts02")
  //     sp_hp:setPosition(hpPos.x, hpPos.y)
  //     sp_hp:setVisible(true)
  //     local rotation = math.deg(math.atan((hpPos.y - beginPos.y) / math.abs(hpPos.x - beginPos.x))) - 90
  //     sp_hp:setRotation(rotation)
  //     effectNode:runAction(cca.seq({
  //       cca.delay(0.9),
  //       cca.callFunc(function()
  //         effectNode:removeFromParent()
  //         self.isUpdateHP = false
  //         self.isSetHPStyle = false
  //       end)
  //     }))
  //   end
  // end
}

void EffectMainUITop::ShowLordPowerEXPEffect(UIMainTop *p_Self, int32  p_AddPower, int32 p_AddEXP){
  // local self = target
  // local addEXP = data.addEXP
  // local addPower = data.addPower
  // local function powerShake()
  //   local mutiple = 1
  //   local seq = cca.seq({
  //     cca.scaleTo(0.3 * mutiple, 1.05),
  //     cca.scaleTo(0.1 * mutiple, 1),
  //     cca.scaleTo(0.2 * mutiple, 1.2),
  //     cca.callFunc(function()
  //       SoraDCreateScoreLabel(self.labelPower, true):runScoreAnimation(self.oriPower, self.curPower, 1 * mutiple)
  //     end),
  //     cca.scaleTo(0.1 * mutiple, 1.05),
  //     cca.scaleTo(0.1 * mutiple, 1.2),
  //     cca.scaleTo(0.1 * mutiple, 1.05),
  //     cca.scaleTo(0.2 * mutiple, 1.2),
  //     cca.scaleTo(0.5 * mutiple, 1),
  //     cca.callFunc(function()
  //       self.oriPower = self.curPower
  //       self.oriEXP = self.curEXP
  //     end)
  //   })
  //   self.imgPower:stopAllActions()
  //   self.imgPower:runAction(seq)
  // end
  // if not SoraDCurrentSceneShowView("mainCityView") then
  //   print("\228\184\141\229\156\168\229\134\133\229\159\142")
  //   powerShake()
  //   return
  // end
  // local mutiple = 0.5
  // local parent = display.getRunningScene().panelView
  // local show_node = parent:getChildByName("show_node")
  // if show_node then
  //   show_node:stopAllActions()
  //   parent:removeChildByName("show_node", true)
  // end
  // local show_node = display.newNode()
  // show_node:setPosition(cc.p(display.cx, display.cy + 150))
  // show_node:setName("show_node")
  // show_node:setScaleY(0)
  // show_node:addTo(parent, 20)
  // local beginPos = cc.p(show_node:getPositionX(), show_node:getPositionY())
  // local bgSprite = display.newSprite("#frame_recharge__sheer_time.png")
  // bgSprite:setScaleY(3.6)
  // bgSprite:setScaleX(1.5)
  // bgSprite:addTo(show_node)
  // local node_power = display.newNode()
  // node_power:setPosition(cc.p(0, -25))
  // node_power:addTo(show_node, 1)
  // local spritePower = display.newSprite("#icon_lord_power.png")
  // spritePower:addTo(node_power, 2)
  // local labPower = ccui.Text:create(i18n("common_text_917", {power = addPower}), "", 22)
  // labPower:setColor(cc.c3b(255, 255, 0))
  // labPower:addTo(node_power, 2)
  // SoraDToCenter(node_power, 10, SoraDFIsRA())
  // local node_exp = display.newNode()
  // node_exp:setPosition(cc.p(0, 25))
  // node_exp:addTo(show_node, 1)
  // local spriteExp = display.newSprite("#icon_lord_exp.png")
  // spriteExp:setScale(1.2)
  // spriteExp:addTo(node_exp, 2)
  // local labExp = ccui.Text:create(i18n("common_text_918", {exp = addEXP}), "", 22)
  // labExp:setColor(cc.c3b(78, 205, 255))
  // labExp:addTo(node_exp, 2)
  // SoraDToCenter(node_exp, 10, SoraDFIsRA())
  // local function showEffect()
  //   if self.powerUp then
  //     self.powerUp = nil
  //   end
  //   self.powerUp = SoraDCreatAnimationEx("power_up", nil, false)
  //   self.powerUp:addTo(show_node, 2)
  // end
  // local function showPowerEXPFly()
  //   local powerPos = cc.p(display.cx, display.height - 85)
  //   local expPos = cc.p(90, display.height - 110)
  //   local effectNode = SoraDCreatAnimation("Node_Effect_tuiwei01", nil, false)
  //   effectNode:addTo(parent, 9)
  //   local sp_power = SoraDGetChildByName(effectNode, "G_dh_Tex_XL_zlts01")
  //   sp_power:setVisible(true)
  //   sp_power:setPosition(powerPos.x, powerPos.y)
  //   local rotation = math.deg(math.atan((powerPos.y - beginPos.y) / math.abs(powerPos.x - beginPos.x))) - 90
  //   sp_power:setRotation(rotation)
  //   local sp_exp = SoraDGetChildByName(effectNode, "G_dh_Tex_XL_zlts03")
  //   sp_exp:setPosition(expPos.x, expPos.y)
  //   sp_exp:setVisible(true)
  //   local rotation = math.deg(math.atan((expPos.y - beginPos.y) / math.abs(expPos.x - beginPos.x))) - 90
  //   sp_exp:setRotation(rotation)
  //   effectNode:runAction(cca.seq({
  //     cca.delay(0.9),
  //     cca.removeSelf()
  //   }))
  // end
  // local seq = cca.seq({
  //   cca.scaleTo(0.25, 1, 1),
  //   cca.delay(0.2),
  //   cca.callFunc(showEffect),
  //   cca.callFunc(showPowerEXPFly),
  //   cca.delay(0.5),
  //   cca.callFunc(powerShake),
  //   cca.scaleTo(0.25, 1, 0),
  //   cca.delay(0.5),
  //   cca.callFunc(function()
  //     self.isShowEXP = false
  //     parent:removeChildByName("show_node", true)
  //   end)
  // })
  // show_node:runAction(seq)
}

void EffectMainUITop::ShowLordEXPChange(UIMainTop *p_UIMainTop, int32 p_AddPower){
  // local self = target
  // local addEXP = data.addEXP
  // local show_node = display.newNode()
  // show_node:setPosition(cc.p(display.cx, display.cy + 120))
  // show_node:setName("show_node_exp")
  // show_node:setScaleY(0)
  // local parent = display.getRunningScene().panelView
  // show_node:addTo(parent, 999)
  // local bgSprite = display.newSprite("#frame_recharge__sheer_time.png")
  // bgSprite:setScaleY(1.8)
  // bgSprite:setScaleX(1.5)
  // bgSprite:addTo(show_node)
  // local expNode = display.newNode()
  // expNode:addTo(show_node, 1)
  // local spriteEXP = display.newSprite("#icon_lord_exp.png")
  // spriteEXP:addTo(expNode)
  // local labEXP = ccui.Text:create(i18n("common_text_918", {exp = addEXP}), "", 22)
  // labEXP:setColor(cc.c3b(255, 255, 0))
  // labEXP:addTo(expNode)
  // SoraDToCenter(expNode, 10, SoraDFIsRA())
  // local function showEffect()
  //   if self.powerUp then
  //     self.powerUp = nil
  //   end
  //   self.powerUp = SoraDCreatAnimationEx("power_up", nil, false)
  //   self.powerUp:addTo(show_node, 2)
  // end
  // local function showEXPFly()
  //   local beginPos = cc.p(show_node:getPositionX(), show_node:getPositionY())
  //   local expPos = cc.p(90, display.height - 110)
  //   local effectNode = SoraDCreatAnimation("Node_Effect_tuiwei01", nil, false)
  //   effectNode:addTo(parent, 9)
  //   local sp_exp = SoraDGetChildByName(effectNode, "G_dh_Tex_XL_zlts03")
  //   sp_exp:setPosition(expPos.x, expPos.y)
  //   sp_exp:setVisible(true)
  //   local rotation = math.deg(math.atan((expPos.y - beginPos.y) / math.abs(expPos.x - beginPos.x))) - 90
  //   sp_exp:setRotation(rotation)
  //   effectNode:runAction(cca.seq({
  //     cca.delay(0.9),
  //     cca.removeSelf()
  //   }))
  // end
  // local seq = cca.seq({
  //   cca.scaleTo(0.25, 1, 1),
  //   cca.delay(0.2),
  //   cca.callFunc(showEffect),
  //   cca.delay(0.5),
  //   cca.callFunc(showEXPFly),
  //   cca.delay(1.2),
  //   cca.scaleTo(0.25, 1, 0),
  //   cca.callFunc(function()
  //     self.oriEXP = self.curEXP
  //     parent:removeChildByName("show_node_exp", true)
  //   end)
  // })
  // show_node:runAction(seq)
}

void EffectMainUITop::ShowLordPowerChange(UIMainTop *p_UIMainTop){
  // local self = target
  // local oriPower = self.oriPower
  // local curPower = self.curPower
  // if curPower == oriPower then
  //   return
  // end
  // local function powerShake()
  //   local mutiple = 1
  //   local seq = cca.seq({
  //     cca.scaleTo(0.3 * mutiple, 1.05),
  //     cca.scaleTo(0.1 * mutiple, 1),
  //     cca.scaleTo(0.2 * mutiple, 1.2),
  //     cca.callFunc(function()
  //       SoraDCreateScoreLabel(self.labelPower, true):runScoreAnimation(oriPower, curPower, 1 * mutiple)
  //     end),
  //     cca.scaleTo(0.1 * mutiple, 1.05),
  //     cca.scaleTo(0.1 * mutiple, 1.2),
  //     cca.scaleTo(0.1 * mutiple, 1.05),
  //     cca.scaleTo(0.2 * mutiple, 1.2),
  //     cca.scaleTo(0.3 * mutiple, 1)
  //   })
  //   self.imgPower:stopAllActions()
  //   self.imgPower:runAction(seq)
  // end
  // local function centerShine()
  //   if not SoraDCurrentSceneShowView("mainCityView") and not SoraDCurrentTopPanelFromManager() then
  //     return
  //   end
  //   local show_node = display.newNode()
  //   show_node:setPosition(cc.p(display.cx, display.cy + 120))
  //   show_node:setName("show_node_power")
  //   show_node:setScaleY(0)
  //   local parent = display.getRunningScene().panelView
  //   show_node:addTo(parent, 999)
  //   local bgSprite = display.newSprite("#frame_recharge__sheer_time.png")
  //   bgSprite:setScaleY(1.8)
  //   bgSprite:setScaleX(1.5)
  //   bgSprite:addTo(show_node)
  //   local powerNode = display.newNode()
  //   powerNode:addTo(show_node, 1)
  //   local spritePower = display.newSprite("#icon_lord_power.png")
  //   spritePower:addTo(powerNode)
  //   local changePower = curPower - oriPower
  //   local str = changePower
  //   if changePower > 0 then
  //     str = "+" .. changePower
  //   end
  //   local labPower = ccui.Text:create(i18n("common_text_1418", {power = str}), "", 22)
  //   labPower:setColor(cc.c3b(255, 255, 0))
  //   labPower:addTo(powerNode)
  //   SoraDToCenter(powerNode, 10, SoraDFIsRA())
  //   local function showEffect()
  //     if self.powerUp then
  //       self.powerUp = nil
  //     end
  //     self.powerUp = SoraDCreatAnimationEx("power_up", nil, false)
  //     self.powerUp:addTo(show_node, 2)
  //   end
  //   local seq = cca.seq({
  //     cca.scaleTo(0.25, 1, 1),
  //     cca.delay(0.2),
  //     cca.callFunc(showEffect),
  //     cca.delay(1.2),
  //     cca.scaleTo(0.25, 1, 0),
  //     cca.callFunc(function()
  //       parent:removeChildByName("show_node_power", true)
  //     end)
  //   })
  //   show_node:runAction(seq)
  // end
  // local seq = cca.seq({
  //   cca.callFunc(centerShine),
  //   cca.delay(0.5),
  //   cca.callFunc(powerShake)
  // })
  // self:runAction(seq)
}

ui::Button *EffectMainUITop::LuckyRecharge(){

  auto l_Button = ui::Button::create("bg_transparent.png", "bg_transparent.png", "bg_transparent.png", ui::Widget::TextureResType::PLIST);
  l_Button->setContentSize(Size(60, 52));
  l_Button->ignoreContentAdaptWithSize(false);
  // local btn_bg = display.newSprite("#icon_main_luckyrecharge.png")
  auto l_BtnBg = GDisplay::Get()->NewSprite("icon_main_luckyrecharge.png");
  l_Button->addChild(l_BtnBg, 1);
  l_BtnBg->setPosition(Vec2(l_Button->getContentSize().width / 2, l_Button->getContentSize().height / 2));
  // button.btn_bg = btn_bg
  auto l_Yes = GDisplay::Get()->NewSprite("icon_yes.png");
  l_Button->addChild(l_Yes, 30);
  l_Yes->setPosition(Vec2(40, 10));
  // button.img_yes = yes
  auto l_Black = GDisplay::Get()->NewSprite("frame_sheer_black_01.png");
  l_Button->addChild(l_Black, 2);
  l_Black->setPosition(Vec2(30, 10));
  l_Black->setScale(0.14285714285714285, 0.5882352941176471);
  // button.img_black = black
  auto l_Label = ui::Text::create("$499.99", "", 20);
  l_Label->setScale(0.8);
  l_Button->addChild(l_Label, 5);
  l_Label->setColor(Color3B(0, 190, 30));
  l_Label->setPosition(Vec2(30, 10));
  // button.lab_target = label
  return l_Button;
  
}

ui::Button *EffectMainUITop::MonthOrWeeklyCard(){
  // local button = ccui.Button:create("bg_transparent.png", "bg_transparent.png", "bg_transparent.png", ccui.TextureResType.plistType)
  // button:setContentSize(cc.size(60, 52))
  // button:ignoreContentAdaptWithSize(false)
  // local btn_bg = display.newSprite("#icon_activity_weeklycard.png")
  // btn_bg:addTo(button, 1)
  // btn_bg:setPosition(cc.p(button:getContentSize().width / 2, button:getContentSize().height / 2))
  // button.btn_bg = btn_bg
  // local effectNode = SoraDCreatAnimation("zhouka")
  // effectNode:addTo(button, 2)
  // effectNode:setPosition(30, 25)
  // local sp = SoraDGetChildByName(effectNode, "Sprite_2")
  // if sp:isOpacityModifyRGB() then
  //   sp:setBlendFunc(gl.ONE, gl.ONE)
  // else
  //   sp:setBlendFunc(gl.SRC_ALPHA, gl.ONE)
  // end
  // return button
  return nullptr;
}

ui::Button *EffectMainUITop::CommunityCenter(RActivityShowData p_Info){
  // local id = info.param.show
  // local uiEnumBg = {
  //   [gActivityCenterUIEnum.COMMUNITY_CENTER_1] = "#btn_scommunity_center_facebook.png",
  //   [gActivityCenterUIEnum.COMMUNITY_CENTER_2] = "#btn_scommunity_center_instagram.png",
  //   [gActivityCenterUIEnum.COMMUNITY_CENTER_3] = "#btn_scommunity_center_twitter.png",
  //   [gActivityCenterUIEnum.COMMUNITY_CENTER_4] = "#btn_scommunity_center_community.png",
  //   [gActivityCenterUIEnum.COMMUNITY_CENTER_5] = "#btn_scommunity_center_live.png",
  //   [gActivityCenterUIEnum.COMMUNITY_CENTER_6] = "#btn_scommunity_center_live.png"
  // }
  // local button = ccui.Button:create("bg_transparent.png", "bg_transparent.png", "bg_transparent.png", ccui.TextureResType.plistType)
  // button:setContentSize(cc.size(60, 52))
  // button:ignoreContentAdaptWithSize(false)
  // local btn_bg = display.newSprite(uiEnumBg[id])
  // btn_bg:addTo(button, 1)
  // btn_bg:setPosition(cc.p(button:getContentSize().width / 2, button:getContentSize().height / 2))
  // button.btn_bg = btn_bg
  // if info.param.type == 1 then
  //   local labelTime = ccui.Text:create("99:99:99", "", 16)
  //   labelTime:setTextHorizontalAlignment(cc.TEXT_ALIGNMENT_CENTER)
  //   labelTime:setAnchorPoint(0.5, 0.5)
  //   labelTime:addTo(button, 5)
  //   labelTime:setColor(cc.c3b(255, 255, 255))
  //   labelTime:setPosition(cc.p(30, -15))
  //   SoraDSetTextWidthHeight(labelTime, cc.size(90, 60))
  //   labelTime:runAction(cca.repeatForever(cca.seq({
  //     cca.callFunc(function(target)
  //       local time = info.endtime - serviceFunctions.systemTime()
  //       target:setString(SoraDConvertSecondToString(time))
  //     end),
  //     cca.delay(1)
  //   })))
  // end
  // return button

  return nullptr;
}

ui::Button *EffectMainUITop::Questionnaire(int32 p_Num){
  // local button = ccui.Button:create("bg_transparent.png", "bg_transparent.png", "bg_transparent.png", ccui.TextureResType.plistType)
  // button:setContentSize(cc.size(60, 52))
  // button:ignoreContentAdaptWithSize(false)
  // local btn_bg = display.newSprite("#icon_wjdc_questionnairet.png")
  // btn_bg:addTo(button)
  // btn_bg:setScale(0.53)
  // btn_bg:setPosition(cc.p(button:getContentSize().width / 2, button:getContentSize().height / 2))
  // button.btn_bg = btn_bg
  // local redIcon = display.newSprite("#icon_xiaobiao_red.png")
  // redIcon:addTo(button)
  // redIcon:setScale(0.5)
  // redIcon:setPosition(50, 50)
  // if num > 1 then
  //   local textNum = ccui.Text:create(num, "", 20)
  //   textNum:addTo(button)
  //   textNum:setPosition(50, 50)
  // end
  // return button
  return nullptr;
}

ui::Button *EffectMainUITop::CreateLostRuinsBtn(int32 p_Num){
  // local button = effectMainUITop.createCommonBtn("#btn_common_record.png", num)
  // local labelName = ccui.Text:create(i18n("lost_ruins_text_23"), "", 20)
  // labelName:addTo(button)
  // labelName:setPosition(cc.p(30, 0))
  // labelName:setScale(0.8)
  // SoraDSetTextWidthHeight(labelName, cc.size(80, 30))
  // button.labelName = labelName
  // button.redIcon:setVisible(num > 0)
  // if button.btn_bg then
  //   button.btn_bg:setScale(63 / button.btn_bg:getContentSize().width)
  // end
  // if not SoraDConfigGet("Game:lostRuinsMainView:firstFinger~bool", {byUID = true}) then
  //   button.fingerNode = SoraDFingerAction(true)
  //   button.fingerNode:setScale(0.7)
  //   button.fingerNode:addTo(button)
  //   button.fingerNode:setPosition(20, 10)
  //   SoraDConfigSet("Game:lostRuinsMainView:firstFinger~bool", true, {byUID = true})
  // end
  // return button
  return nullptr;
}

ui::Button *EffectMainUITop::CreateWindTowerBtn(int32 p_Num){
  // local button = effectMainUITop.createCommonBtn("#btn_common_record.png", num)
  // local labelName = ccui.Text:create(i18n("lost_ruins_text_23"), "", 20)
  // labelName:addTo(button)
  // labelName:setPosition(cc.p(30, 0))
  // labelName:setScale(0.8)
  // SoraDSetTextWidthHeight(labelName, cc.size(80, 30))
  // button.labelName = labelName
  // button.redIcon:setVisible(num > 0)
  // if button.btn_bg then
  //   button.btn_bg:setScale(63 / button.btn_bg:getContentSize().width)
  // end
  // if not SoraDConfigGet("Game:windTowerActivity:firstFinger~bool", {byUID = true}) then
  //   button.fingerNode = SoraDFingerAction(true)
  //   button.fingerNode:setScale(0.7)
  //   button.fingerNode:addTo(button)
  //   button.fingerNode:setPosition(20, 10)
  //   SoraDConfigSet("Game:windTowerActivity:firstFinger~bool", true, {byUID = true})
  // end
  // return button
  return nullptr;
}


ui::Button *EffectMainUITop::CreateSnowWolfLostBtn(int32 p_Num){
  // local button = effectMainUITop.createCommonBtn("#btn_common_record.png", num)
  // local labelName = ccui.Text:create(i18n("lost_ruins_text_23"), "", 20)
  // labelName:addTo(button)
  // labelName:setPosition(cc.p(30, 0))
  // labelName:setScale(0.8)
  // SoraDSetTextWidthHeight(labelName, cc.size(80, 30))
  // button.labelName = labelName
  // button.redIcon:setVisible(num > 0)
  // if button.btn_bg then
  //   button.btn_bg:setScale(63 / button.btn_bg:getContentSize().width)
  // end
  // if not SoraDConfigGet("Game:snowWolfLostActivity:firstFinger~bool", {byUID = true}) then
  //   button.fingerNode = SoraDFingerAction(true)
  //   button.fingerNode:setScale(0.7)
  //   button.fingerNode:addTo(button)
  //   button.fingerNode:setPosition(20, 10)
  //   SoraDConfigSet("Game:snowWolfLostActivity:firstFinger~bool", true, {byUID = true})
  // end
  // return button
  return nullptr;
}

ui::Button *EffectMainUITop::CreateCrazyTrioBtn(int32 p_Num){
  // local button = effectMainUITop.createCommonBtn("#btn_main_new_recharge_hero.png", math.min(1, num))
  // button.redIcon:setVisible(num > 0)
  // if button.btn_bg then
  //   button.btn_bg:setScale(63 / button.btn_bg:getContentSize().width)
  // end
  // if not SoraDConfigGet("Game:eventCrazyTrioNew:firstFinger~bool", {byUID = true}) then
  //   button.fingerNode = SoraDFingerAction(nil, nil, nil, true)
  //   button.fingerNode:setScale(0.7)
  //   button.fingerNode:addTo(button)
  //   button.fingerNode:setPosition(30, 26)
  //   SoraDConfigSet("Game:eventCrazyTrioNew:firstFinger~bool", true, {byUID = true})
  // end
  // return button
  return nullptr;
}

ui::Button *EffectMainUITop::CreateCommonBtn(const GString &p_Icon, int32 p_Num){
  // local button = ccui.Button:create("bg_transparent.png", "bg_transparent.png", "bg_transparent.png", ccui.TextureResType.plistType)
  // button:setContentSize(cc.size(60, 52))
  // button:ignoreContentAdaptWithSize(false)
  // local btn_bg = display.newSprite(icon)
  // btn_bg:addTo(button)
  // btn_bg:setPosition(cc.p(button:getContentSize().width / 2, button:getContentSize().height / 2))
  // button.btn_bg = btn_bg
  // local redIcon = display.newSprite("#icon_xiaobiao_red.png")
  // redIcon:addTo(button)
  // redIcon:setScale(0.5)
  // redIcon:setPosition(50, 50)
  // button.redIcon = redIcon
  // num = num or 0
  // if num > 1 then
  //   local textNum = ccui.Text:create(num, "", 20)
  //   textNum:addTo(button)
  //   textNum:setPosition(50, 50)
  // end
  // return button
  return nullptr;
}

ui::Button *EffectMainUITop::IranDownloadIcon(){
  // local button = ccui.Button:create("bg_transparent.png", "bg_transparent.png", "bg_transparent.png", ccui.TextureResType.plistType)
  // button:setContentSize(cc.size(60, 52))
  // button:ignoreContentAdaptWithSize(false)
  // local btn_bg = display.newSprite("#Icon_Irandownload.png")
  // btn_bg:addTo(button, 2)
  // btn_bg:setPosition(cc.p(30, 30))
  // button.btn_bg = btn_bg
  // local black = display.newSprite("#frame_main_common.png")
  // black:addTo(button)
  // black:setPosition(cc.p(button:getContentSize().width / 2, button:getContentSize().height / 2))
  // button.img_black = black
  // return button
  return nullptr;
}

ui::Button *EffectMainUITop::EnjoyLotteryBtn(){
  //   local button = ccui.Button:create("bg_transparent.png", "bg_transparent.png", "bg_transparent.png", ccui.TextureResType.plistType)
  // button:setContentSize(cc.size(60, 52))
  // button:ignoreContentAdaptWithSize(false)
  // local btn_bg = display.newSprite("#icon_main_enjoylottery.png")
  // btn_bg:addTo(button, 1)
  // btn_bg:setPosition(cc.p(button:getContentSize().width / 2, button:getContentSize().height / 2))
  // local param = {
  //   [1] = {
  //     plist = "et_chongzhi_active12_01.plist",
  //     pos = {x = 9, y = 39},
  //     scale = 1.2
  //   },
  //   [2] = {
  //     plist = "et_chongzhi_active12_02.plist",
  //     pos = {x = 6, y = 72},
  //     scale = 1.2
  //   }
  // }
  // local et_node = SoraDCreateEffectNode(param)
  // et_node:addTo(button, 2)
  // et_node:setPosition(cc.p(20, -10))
  // return button
  return nullptr;
}

ui::Button *EffectMainUITop::ThanksGivingPartyBtn(){
  // local button = effectMainUITop.createCommonBtn("#icon_gnsrh_5th2.png")
  // if button.redIcon then
  //   button.redIcon:setVisible(false)
  // end
  // if button.btn_bg then
  //   button.btn_bg:setScale(63 / button.btn_bg:getContentSize().width)
  // end
  // local labelTime = ccui.Text:create("99:99:99", "", 20)
  // local labelTime = SoraDCreateTimerLabel(nil, labelTime)
  // labelTime:addTo(button)
  // labelTime:setPosition(cc.p(30, 0))
  // labelTime:setScale(0.8)
  // SoraDSetTextWidthHeight(labelTime, cc.size(80, 30))
  // button.labelTime = labelTime
  // return button
  return nullptr;
}


ui::Button *EffectMainUITop::TogetherTeamBtn(){
  // local button = effectMainUITop.createCommonBtn("#icon_together_invite.png")
  // if button.redIcon then
  // end
  // if button.btn_bg then
  //   button.btn_bg:setScale(63 / button.btn_bg:getContentSize().width)
  // end
  // local labelTime = ccui.Text:create("99:99:99", "", 20)
  // local labelTime = SoraDCreateTimerLabel(nil, labelTime)
  // labelTime:addTo(button)
  // labelTime:setPosition(cc.p(30, 0))
  // labelTime:setScale(0.8)
  // SoraDSetTextWidthHeight(labelTime, cc.size(80, 30))
  // button.labelTime = labelTime
  // return button
  return nullptr;
}

ui::Button *EffectMainUITop::HarvestSeason(){
  // local button = effectMainUITop.createCommonBtn("#icon_together_invite.png")
  // if button.btn_bg then
  //   button.btn_bg:setScale(63 / button.btn_bg:getContentSize().width)
  // end
  // local labelTime = ccui.Text:create("xxd 99:99:99", "", 20)
  // local labelTime = SoraDCreateTimerLabel(nil, labelTime)
  // labelTime:addTo(button)
  // labelTime:setPosition(cc.p(30, 0))
  // labelTime:setScale(0.8)
  // SoraDSetTextWidthHeight(labelTime, cc.size(80, 30))
  // button.labelTime = labelTime
  // return button
  return nullptr;
}