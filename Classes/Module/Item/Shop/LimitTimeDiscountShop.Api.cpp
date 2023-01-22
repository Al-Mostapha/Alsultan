#include "LimitTimeDiscountShop.Api.h"

LimitTimeDiscountShopApi *LimitTimeDiscountShopApi::Get(){
  static LimitTimeDiscountShopApi *s_LimitTimeDiscountShopApi = new LimitTimeDiscountShopApi();
  return s_LimitTimeDiscountShopApi;
}

bool LimitTimeDiscountShopApi::GetActivityStatus(){
  return false;
}

GTime LimitTimeDiscountShopApi::GetActivityRemainTime(){
  return 0;
}