#pragma once

#include "Include/IncludeBase.h"
struct RAllianceMember{
  Guid AllianceID;
  Guid MemberID;
  bool bIsFirstJoin = true;
};