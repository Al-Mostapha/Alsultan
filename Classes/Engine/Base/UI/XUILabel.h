#pragma once
#include "Base/BaseTypeDef.h"
#include "Engine/Display.h"

USING_NS_CC;

class XUILabel
{
  public:
  template <typename T = Label>
  static T *Create(const UIFontLabelParam &pParam);

};

 template <typename T>
T *XUILabel::Create(const UIFontLabelParam &pParam)
{
  if(pParam._UILabelType == GBase::EUILabelType::TTF)
    return GDisplay::Get()->NewTTFLabel<T>(pParam);
  else if(pParam._UILabelType == GBase::EUILabelType::BMF)
    return GDisplay::Get()->NewBMFontLabel<T>(pParam);
  else
    return nullptr;
}