#include "AlliancePet.Read.h"

GHashMap<int32, RWorldMapAlliancePetOffset> AlliancePetRead::_WorldMapPetOffset = 
{
  {
    {1, {0.85f, Vec2(-10, 20)}},
    {2, {0.75f, Vec2(-10, 20)}},
    {3, {1.0f,  Vec2(0  , 20)}},
    {4, {0.95f, Vec2(-10, 20)}},
    {5, {1.0f,  Vec2(-10, 20)}},
    {6, {0.9f,  Vec2(-10, 20)}},
    {7, {0.8f,  Vec2(-10, 20)}},
    {8, {0.7f,  Vec2(-10, 20)}},
    {9, {1.0f,  Vec2(-10, 20)}}
  }
};

GString AlliancePetRead::GetWorldMapModel(int32 pPetType){
  return "ma";
}