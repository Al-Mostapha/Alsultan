#pragma once
#include "Include/IncludeBase.h"

enum class ELayoutAlignment {Left = 0, Right = 1};

namespace GBase{
  Vec2 DFPoint(double p_X, double p_Y, double p_Target);
  float DFPosX(float p_X, float p_Target);
  ELayoutAlignment DGetLayoutAlignment();
};