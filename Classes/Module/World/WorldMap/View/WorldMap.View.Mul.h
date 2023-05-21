#pragma once

class WorldMapCell;

class WorldMapViewMul
{
public:
  WorldMapCell *_CurrentInMapViewCell;
  void InitMapCell_imp();
};