#include "ActivityShow.Ctrl.h"

ActivityShowCtrl::ActivityShowCtrl() {
  m_ActivityGroup[EActivityCenter::LegendHegemon] = {};
  m_ActivityGroup[EActivityCenter::LegendHegemon][EActivityTime::LegendHegemon_1] = true;
  m_ActivityGroup[EActivityCenter::LegendHegemon][EActivityTime::LegendHegemon_2] = true;
  m_ActivityGroup[EActivityCenter::LegendHegemon][EActivityTime::LegendHegemon_3] = true;
  m_ActivityGroup[EActivityCenter::LegendHegemon][EActivityTime::LegendHegemon_4] = true;
  m_ActivityGroup[EActivityCenter::LegendHegemon][EActivityTime::LegendHegemon_5] = true;
  m_ActivityGroup[EActivityCenter::LegendHegemon][EActivityTime::LegendHegemon_6] = true;
  m_ActivityGroup[EActivityCenter::SurprisedDrop] = {};
  m_ActivityGroup[EActivityCenter::SurprisedDrop][EActivityTime::SurprisedDropActivity_0] = true;
  m_ActivityGroup[EActivityCenter::SurprisedDrop][EActivityTime::SurprisedDropActivity_1] = true;
  m_ActivityGroup[EActivityCenter::SurprisedDrop][EActivityTime::SurprisedDropActivity_2] = true;
  m_ActivityGroup[EActivityCenter::SurprisedDrop][EActivityTime::SurprisedDropActivity_3] = true;
  m_ActivityGroup[EActivityCenter::SurprisedDrop][EActivityTime::SurprisedDrop_2_Activity_0] = true;
  m_ActivityGroup[EActivityCenter::SurprisedDrop][EActivityTime::SurprisedDrop_2_Activity_1] = true;
  m_ActivityGroup[EActivityCenter::SurprisedDrop][EActivityTime::SurprisedDrop_2_Activity_2] = true;
  m_ActivityGroup[EActivityCenter::SurprisedDrop][EActivityTime::SurprisedDrop_2_Activity_3] = true;
  
  m_ActivityGroup[EActivityCenter::GreatChallenge] = {};
  m_ActivityGroup[EActivityCenter::GreatChallenge][EActivityTime::GREAT_CHALLENGE_ACTIVITY_1] = true;
  m_ActivityGroup[EActivityCenter::GreatChallenge][EActivityTime::GREAT_CHALLENGE_ACTIVITY_2] = true;
  m_ActivityGroup[EActivityCenter::GreatChallenge][EActivityTime::GREAT_CHALLENGE_ACTIVITY_3] = true;
  m_ActivityGroup[EActivityCenter::GreatChallenge][EActivityTime::GREAT_CHALLENGE_ACTIVITY_4] = true;
  m_ActivityGroup[EActivityCenter::GreatChallenge][EActivityTime::GREAT_CHALLENGE_ACTIVITY_5] = true;
  m_ActivityGroup[EActivityCenter::GreatChallenge][EActivityTime::GREAT_CHALLENGE_ACTIVITY_6] = true;
  m_ActivityGroup[EActivityCenter::GreatChallenge][EActivityTime::GREAT_CHALLENGE_ACTIVITY_7] = true;
  m_ActivityGroup[EActivityCenter::GreatChallenge][EActivityTime::GREAT_CHALLENGE_ACTIVITY_8] = true;
  //   [gActivityCenterUIEnum.CRAZY_DROP] = {
  //     [gActivityTimeActivityID.CRAZY_DROP_ACTIVITY_0] = true,
  //     [gActivityTimeActivityID.CRAZY_DROP_ACTIVITY_1] = true,
  //     [gActivityTimeActivityID.CRAZY_DROP_ACTIVITY_2] = true,
  //     [gActivityTimeActivityID.CRAZY_DROP_ACTIVITY_3] = true
  //   },
  //   [gActivityCenterUIEnum.FIVE_ANNIVERSARY] = {},
  m_ActivityGroup[EActivityCenter::SultanBack] = {};
  m_ActivityGroup[EActivityCenter::SultanBack][EActivityTime::SULTAN_BACK_MAIN_ACTIVITY] = true;
  m_ActivityGroup[EActivityCenter::SultanBack][EActivityTime::SULTAN_BACK_LOGIN_ACTIVITY] = true;
  m_ActivityGroup[EActivityCenter::SultanBack][EActivityTime::SULTAN_WAR_QUEST_ACTIVITY] = true;
  m_ActivityGroup[EActivityCenter::SultanBack][EActivityTime::SULTAN_BACK_RETURN_ACTIVITY] = true;
  m_ActivityGroup[EActivityCenter::SultanBack][EActivityTime::SULTAN_BACK_LUXURYGIFT_ACTIVITY] = true;
  m_ActivityGroup[EActivityCenter::SultanBack][EActivityTime::SULTAN_BACK_REBATE_ACTIVITY] = true;
  m_ActivityGroup[EActivityCenter::SultanBack][EActivityTime::SULTAN_BACK_FRIEND_COMEBACK] = true;
  
  //   [gActivityCenterUIEnum.ARMYEXCHANGE_ACTIVITY] = {
  //     [gActivityTimeActivityID.BATTLEFIELD_TRAINING] = true,
  //     [gActivityTimeActivityID.PREFERENTIAL_SHOP_ACTIVITY] = true,
  //     [gActivityTimeActivityID.ARMY_TRANSFER_ACTIVTY] = true,
  //     [gActivityTimeActivityID.GEM_EXCHANGE_ACTIVITY] = true
  //   },
  //   [gActivityCenterUIEnum.NEWSERVERBACK_ACTIVITY] = {
  //     [gActivityTimeActivityID.NEW_START_EFFECT_ACTIVITY] = true,
  //     [gActivityTimeActivityID.NEW_START_REWARD_ACTIVITY] = true,
  //     [gActivityTimeActivityID.WEALTH_ACTIVITY] = true,
  //     [gActivityTimeActivityID.ROAD_TO_REVIVE_ACTIVITY] = true,
  //     [gActivityTimeActivityID.VICIOUS_PET_ACTIVITY] = true,
  //     [gActivityTimeActivityID.SUDAN_RISING_ACTIVITY] = true,
  //     [gActivityTimeActivityID.BACK_TO_TOP_ACTIVITY] = true
  //   }
}

ActivityShowCtrl* ActivityShowCtrl::Get()
{
  static auto s_Instance = new ActivityShowCtrl();
  return s_Instance;
}

EActivityState ActivityShowCtrl::SetStateByID(EActivityTime p_IdEvent)
{
  return EActivityState::None;
}

GHashMap<EActivityTime, bool> ActivityShowCtrl::GetActivityGroup(EActivityCenter p_IdGroup){
  if(!m_ActivityGroup.Contains(p_IdGroup))
    return {};
  return m_ActivityGroup[p_IdGroup];
}

RActivityShowData ActivityShowCtrl::GetCommunityInfo(EActivityTime p_IdEvent){
  return RActivityShowData();
}