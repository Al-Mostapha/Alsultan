#pragma once
#include "Base/BaseTypeDef.h"
#include "Base/Type/XVector.h"
#include "Base/Containers/Set.h"
#include <functional>

struct RHideMainUIEvtArg;

class BaseView{
  GSet<GString> m_ArrayImagesPath;
public:
  void LoadImages(GVector<GString> pArray, const std::function<void()> &pCallback);
};

namespace GBase{
  void DHideCurrentSceneViewAndMainUI(const RHideMainUIEvtArg &pArg);
};