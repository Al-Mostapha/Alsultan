#pragma once
#include "Base/BaseTypeDef.h"

USING_NS_CC;

class WorldMapBuildEmoji{
  public:
  int32 _OwnerUID;
  int32 _EmojiID;
  void UpdateEmojiByData(int32 pOwnerId, int32 pEmjoiId){}
  bool CanHasEmojiOperator(int32 pPlayerId = false){return false;}
  void ResetBuildEmoji(){}
  void UpdateEmoji(int32 pEmojiID){}
  bool IsHasEmoji(){return false;}
  void ShowEmoji(int32 pEmojiID){}
  void HideEmoji(){}
  void AddEmoji(int32 pEmojiId, Vec2 pPos){}
  void RemoveEmoji(){}
};