#include "DateTime.h"
#include <time.h>

GTime GDateTime::Now(){
  return time(nullptr);
}