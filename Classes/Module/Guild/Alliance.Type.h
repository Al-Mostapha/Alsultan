#pragma once

#include "Base/BaseTypeDef.h"
#include "Alliance.Enum.h"
struct RAllianceMember{
  Guid AllianceID;
  Guid MemberID;
  bool bIsFirstJoin = true;
};

struct RAllianceProperty{
  //   aid = 0,
  Guid AllianceID;
  GString Name;
  GString Abbr;
  Guid Leader;
  int32 Flag;
  int32 Language;
  int32 LimitCount;
  EARecruit RecruitType = EARecruit::Public;
  int32 bonus;
  GString Manifesto;
  GString Notice;
  GString R1Name;
  GString R2Name;
  GString R3Name;
  GString R4Name;
  GString R5Name;
  GTime CreateTime;
  int32 JoinLevel;
  int32 JoinPower;
  int32 OpenLevel = 3;
  bool bIsMigration = false;
  int32 SourceKID = 0;
  struct {
    EEscortAddState state = EEscortAddState::Close;
    GTime StartTime;
    GTime TotalTime = 0;
    int32 OpenTimes = 0;
  } EscortInfo;
  struct {
    GTime StartTime = 0;
    GTime TotalTime = 0;
  } BestAllianceInfo;
  struct {
    GTime StartTime = 0;
    GTime TotalTime = 0;
  } MobiBestAlliance;
  int32 TerrScore = 0;
  // kingPacksInfo = {}

};

struct $AlliancePrifeInfo{
  Guid AllianceID;
  GString AllianceName;
  GString LeaderName;
  Guid LeaderID;
  int32 iconID;
  GString Avatar;
  bool _Valid = false;
};

struct RAlliance {
  RAllianceProperty Property;
  GVector<RAllianceMember> MemberList;
  GVector<Guid> ApplyList;
  GVector<Guid> InviteList;

  // self.legionList = {}
  // self.inviteMoveCityList = {}
  // self.leaderName = ""
  // self.totalBattle = 0
  // self.migrationMemList = {}
  // if params then
  //   for key, var in pairs(params) do
  //     self:setProperty(key, var, false)
  //   end
  // end
  // self.queue = {}
  // self:addEventListener(tostring(gEscortAddState.OPENING), handler(self, self.escortOpeningTimeCb))
};


struct RAllianceBuildMainInfo {
  int32 _Id;
  int32 _Bid;
  EAllianceBuildingStatus _Status;
  int32 _HP;
  int32 _MaxHP;
  int32 _CurrentHP;
  GTime _RemainCDTime;
  int32 _BurningSpeed;
  int32 _RecoverSpeed;
};