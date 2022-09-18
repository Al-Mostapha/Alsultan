#pragma once 
#include "Include/IncludeBase.h"
#include <utility>

template <class K, class V>
struct GPair : public std::pair<K, V>{
  static GPair Make(K p_Key, V p_Value){
    return static_cast<GPair>(std::make_pair(p_Key, p_Value));
  }
};
