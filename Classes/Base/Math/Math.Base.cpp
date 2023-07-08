#include "Math.Base.h"

namespace GMath {

int32 Abs(int32 p_Int) { return std::abs(p_Int); }

float Abs(float p_Float) { return std::abs(p_Float); }

double Abs(double p_Double) { return std::abs(p_Double); }
int32 Min(int32 p_First, int32 p_Second) { return std::min(p_First, p_Second); }
float Min(float p_First, float p_Second) { return std::min(p_First, p_Second); }
double Min(double p_First, double p_Second) { return std::min(p_First, p_Second); }
float Max(float p_First, float p_Second) { return std::max(p_First, p_Second); }
GString DConvertNumberWithUnit(float p_Num){return "";}
float Rad(float p_Degree) { return p_Degree * 3.1415926f / 180.0f; }


}  // namespace GMath

float GMath::Sin(float p_Rad) { return sin(p_Rad); }
float GMath::Cos(float p_Rad) { return cos(p_Rad); }


float GMath::Floor(float p_Float){return std::floor(p_Float);}

float GMath::Clamp(float p_Value, float p_Min, float p_Max){
  return std::min(std::max(p_Value, p_Min), p_Max);
}