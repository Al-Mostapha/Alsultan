#pragma once
#include "Base/BaseTypeDef.h"

namespace GMath {

int32 Abs(int32 p_Int);

float Abs(float p_Float);

double Abs(double p_Double);

int32 Min(int32 p_First, int32 p_Second);

float Min(float p_First, float p_Second);

double Min(double p_First, double p_Second);
float Max(float p_First, float p_Second);

float Rad(float p_Degree);

float Sin(float p_Rad);
float Cos(float p_Rad);

float Floor(float p_Float);

float Clamp(float p_Value, float p_Min, float p_Max);

GString  DConvertNumberWithUnit(float p_Num);
}  // namespace GMath