#pragma once 
#include "Include/IncludeBase.h"
#include <utility>

template <class K, class V>
struct GPair{
  K first;
  V second;
  GPair(K p_First, V p_Second) : first(p_First), second(p_Second){}
  static GPair Make(K p_Key, V p_Value){
    return *(new GPair(p_Key, p_Value));
  }
};
