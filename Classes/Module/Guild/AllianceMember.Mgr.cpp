#include "AllianceMember.Mgr.h"
#include "Module/Player/Player.Top.h"

AllianceMemberManager * AllianceMemberManager::Get(){
  static AllianceMemberManager * _AllianceMemberManager = nullptr;
  if(_AllianceMemberManager == nullptr){
    _AllianceMemberManager = new AllianceMemberManager();
  }
  return _AllianceMemberManager;
}

RAllianceMember AllianceMemberManager::GetMember(Guid MemberID){
  return RAllianceMember();
}

RAllianceMember AllianceMemberManager::GetOwnMember(){
  auto l_PlayerId = PlayerTop::Get()->GetPlayerID();
  return  GetMember(l_PlayerId);
}