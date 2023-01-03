#include "Alliance.Mgr.h"

AllianceManager *AllianceManager::Get(){
    static AllianceManager *instance = nullptr;
    if(instance == nullptr){
        instance = new AllianceManager();
    }
    return instance;
}

Guid AllianceManager::HasJoinAlliance(bool p_IsTeam){
    return 0;
}