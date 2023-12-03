#pragma once
#include "Base.Events.h"
#include <string>


typedef std::string GString;

typedef signed char int8;
typedef unsigned char uint8;

typedef signed short int int16;
typedef unsigned short int uint16;

typedef signed int int32;
typedef unsigned int uint32;

typedef signed long long int64;
typedef unsigned long long uint64;

typedef uint32 Guid;

typedef int64 GTime;


enum class ENullBool{
  Null,
  True,
  False
};