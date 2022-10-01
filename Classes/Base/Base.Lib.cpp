#include "Base.Lib.h"
#include "AudioEngine.h"

namespace GBase{

  void playSound(const char* p_SoundName, bool p_IsLoop, float p_delay)
  {
    Sequence::create(
      DelayTime::create(p_delay),
      CallFunc::create([=]() {
        AudioEngine::play2d(p_SoundName, p_IsLoop);
      }),
      nullptr
      );
  }

  const char *getSoundPath(const char *p_SoundName)
  {
    return StringUtils::format("Music/%s", p_SoundName).c_str();
  }

  void SoraDFTarget(Node *p_node){}
} // namespace






