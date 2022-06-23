#pragma once
#include <string>
#include "cocos2d.h"
#include "external/json/document.h"

typedef std::string GString;
typedef signed char int8;
typedef unsigned char uint8;

typedef signed short int int16;
typedef unsigned short int uint16;

typedef signed int int32;
typedef unsigned int uint32;

typedef signed long int int64;
typedef unsigned long int uint64;

typedef rapidjson::Document GJsonObject;

template <class T>
using GArray = cocos2d::Vector<T>;
