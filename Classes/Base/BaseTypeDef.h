#pragma once
#include "Base.Events.h"
#include <string>
#include <vector>
#include "cocos2d.h"
#include "external/json/document.h"
#include <time.h>
#include <optional>
#include <variant>


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

typedef rapidjson::Document GJsonObject;
typedef int64 GTime;


template <class T>
using GVector = std::vector<T>;




template <class K>
using GFunc = std::function<K>;

template <class K>
using GOpt = std::optional<K>;

template <typename... Args>
using GVar = std::variant<Args...>;

enum class ENullBool{
  Null,
  True,
  False
};

// template <class K>
// using GOptional = std::optional<K>;