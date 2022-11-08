#include "Global.h"

namespace GBase{
  bool IEquals(const GString& a, const GString& b)
  {
    return std::equal(a.begin(), a.end(),
                      b.begin(), b.end(),
        [](char a, char b) {
            return tolower(a) == tolower(b);
        });
  }
}