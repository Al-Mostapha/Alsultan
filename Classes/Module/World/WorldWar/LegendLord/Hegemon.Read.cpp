#include "Hegemon.Read.h"

HegemonRead * HegemonRead::Get()
{
  static HegemonRead *sInstance = nullptr;
  if (sInstance == nullptr)
  {
    sInstance = new HegemonRead();
  }
  return sInstance;
}