#include "Base/BaseTypeDef.h"

class IRequest;

class CityService
{
  public:
    static CityService *Get();
    void Init();
    IRequest *GetCityList();
    IRequest *GetCityInfo(int32 pCityId);
};