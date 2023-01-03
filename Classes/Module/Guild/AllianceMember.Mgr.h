#pragma once
#include "Include/IncludeBase.h"
#include "Alliance.Type.h"

class AllianceMemberManager{
public: 
  static AllianceMemberManager * Get();
  RAllianceMember GetMember(Guid MemberID);
  RAllianceMember GetOwnMember();
};