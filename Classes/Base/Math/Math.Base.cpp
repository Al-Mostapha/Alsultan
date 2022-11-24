#include "Math.Base.h"

namespace GMath {

int32 Abs(int32 p_Int) { return std::abs(p_Int); }

float Abs(float p_Float) { return std::abs(p_Float); }

double Abs(double p_Double) { return std::abs(p_Double); }

int32 Min(int32 p_First, int32 p_Second) { return std::min(p_First, p_Second); }

float Min(float p_First, float p_Second) { return std::min(p_First, p_Second); }

double Min(double p_First, double p_Second) { return std::min(p_First, p_Second); }
GString DConvertNumberWithUnit(float p_Num){return "";}
}  // namespace GMath