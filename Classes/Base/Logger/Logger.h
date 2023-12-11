#pragma once
#include "Logger.Enum.h"
#include "Base/BaseTypeDef.h"

class Logger{
public:
  static Logger *Get();
  void Log(const GString &p_msg, ELogLvl p_LogLvl = ELogLvl::Debug, bool p_isBackTrace = false);
  void LogJsonError(const std::exception &pException);
};