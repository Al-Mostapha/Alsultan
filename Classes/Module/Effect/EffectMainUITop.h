#pragma once
#include "Base/BaseTypeDef.h"
#include "Include/IncludeGlobal.h"
#include "Module/Activity/LuckyBless/LuckyBLess.Enum.h"

struct RActivityShowData;

class EffectMainUITop{
  public: 
    static EffectMainUITop *Get();
    Node *LuckyBlessShow(ELuckyBlessEffect p_ShowType);
    void DispatchArmyEffect(int32 p_HP);
    void FullHPEffect();
    void LordSkillTransresEffect();
    ui::Button *GoldPackage();
    Node *CombatantGift();
    void WarStartVSEffect();
    void ShowLordPhysicalEffect(class UIMainTop *p_UIMainTop);
    void ShowLordPowerEXPEffect(class UIMainTop *p_UIMainTop, int32 p_AddPower, int32 p_AddEXP);
    void ShowLordEXPChange(class UIMainTop *p_UIMainTop, int32 p_AddPower);
    void ShowLordPowerChange(class UIMainTop *p_UIMainTop);
    ui::Button *LuckyRecharge();
    ui::Button *MonthOrWeeklyCard();
    ui::Button *CommunityCenter(RActivityShowData p_Info);
    ui::Button *Questionnaire(int32 p_Num);
    ui::Button *CreateLostRuinsBtn(int32 p_Num);
    ui::Button *CreateWindTowerBtn(int32 p_Num);
    ui::Button *CreateSnowWolfLostBtn(int32 p_Num);
    ui::Button *CreateCrazyTrioBtn(int32 p_Num);
    ui::Button *CreateCommonBtn(const GString &p_Icon, int32 p_Num);
    ui::Button *IranDownloadIcon();
    ui::Button *EnjoyLotteryBtn();
    ui::Button *ThanksGivingPartyBtn();
    ui::Button *TogetherTeamBtn();
    ui::Button *HarvestSeason();
};