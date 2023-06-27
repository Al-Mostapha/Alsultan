#pragma once
class WorldMapView;

class IWorldMapCompnant
{
  protected:
    WorldMapView *_Target;
  public:
    virtual void Init() = 0;
};