#pragma once
#include "Include/IncludeBase.h"

struct UIWheelScrollViewArgs
{
  GVector<ui::Widget *> m_WidgetArray;
  Size m_Size = Size();
  float m_OffsetPosX = 0.0f;
  float m_CellHeight = 0.0f;
  float m_CircleRadius = 0.0f;
  bool  m_IsSound = true;
  bool  m_IgnoreOpacity = 0.0f;
};