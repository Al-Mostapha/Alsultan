#pragma once
#include "Include/IncludeBase.h"
#include "Base/Containers/Set.h"

class BaseView{
  GSet<GString> m_ArrayImagesPath;
public:
  void LoadImages(GVector<GString> p_Array, const std::function<void()> &p_Callback);
};