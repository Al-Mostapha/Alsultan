#pragma once
#include "Include/IncludeBase.h"

struct UIWheelScrollViewArgs
{
  GVector<ui::Widget *> m_WidgetArray;
  Size m_Size;
  float m_OffsetPosX = 0;
  float m_CellHeight;
  float m_CircleRadius;
  bool  m_IsSound = true;
  bool  m_IgnoreOpacity;
};