#include "Audio.Engine.h"

GAudioEngine* GAudioEngine::Get()
{
  static GAudioEngine *s_AudioEngine = new GAudioEngine();
  return s_AudioEngine;
}


void GAudioEngine::PlayMusic(const char *p_FileName, bool p_Loop){}
void GAudioEngine::PlayEffect(const char *p_FileName, bool p_Loop){}
void GAudioEngine::Init(){}
void GAudioEngine::StopMusic(){}
void GAudioEngine::SetMusicVolume(float volume){}