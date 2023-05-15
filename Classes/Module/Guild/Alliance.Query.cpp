#include "Alliance.Query.h"

AllianceQuery *AllianceQuery::Get()
{
  static auto s_AllianceQuery = new AllianceQuery();
  return s_AllianceQuery;
}