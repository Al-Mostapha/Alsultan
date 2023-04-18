#include "Global.h"

namespace GBase{
  bool IEquals(const GString& a, const GString& b)
  {
      if(a.length() != b.length())
        return false;
      if(!a.length())
        return false;
      for(auto iii = 0; iii < a.length(); iii++)
        if(std::tolower(a[iii]) != std::tolower(a[iii]))
            return false;
      return true;
  }
}