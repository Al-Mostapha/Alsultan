#pragma once
#include "Include/IncludeBase.h"
#include "Include/IncludeEngine.h"

class GAudioEngine
{
public: 
  static GAudioEngine* Get();
  void PlayMusic(const char *p_FileName, bool p_Loop = false);
  void PlayEffect(const char *p_FileName, bool p_Loop = false);
  void Init();
  void StopMusic();
  void SetMusicVolume(float volume);
};