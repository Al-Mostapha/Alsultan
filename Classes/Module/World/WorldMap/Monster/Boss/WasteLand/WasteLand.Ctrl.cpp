#include "WasteLand.Ctrl.h"


WasteLandCtrl* WasteLandCtrl::Get()
{
    static WasteLandCtrl* _Instance = nullptr;
    if (!_Instance)
    {
        _Instance = new WasteLandCtrl();
    }
    return _Instance;
}

RWasteLandBossData WasteLandCtrl::GetBossConfigByLv()
{
    RWasteLandBossData _Result;
    _Result._Release = 1800;
    return _Result;
}