#include "Base.Lib.h"
#include "AudioEngine.h"


void GBase::playSound(const char* p_SoundName, bool p_IsLoop, float p_delay)
{
  Sequence::create(
    DelayTime::create(p_delay),
    CallFunc::create([=]() {
      AudioEngine::play2d(p_SoundName, p_IsLoop);
    }),
    nullptr
    );
}


const char *GBase::getSoundPath(const char *p_SoundName)
{
  return StringUtils::format("Music/%s", p_SoundName).c_str();
}


