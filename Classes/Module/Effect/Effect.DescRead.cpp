#include "Effect.DescRead.h"


EffectDecRead* EffectDecRead::Get(){
  static EffectDecRead *l_EffectDecRead = new EffectDecRead();
  return l_EffectDecRead;
}