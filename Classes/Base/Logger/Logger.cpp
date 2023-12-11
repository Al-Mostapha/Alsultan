#include "Logger.h"
#include "Base/Type/XEngine.h"

Logger *Logger::Get(){
  static Logger *lLogger = new Logger();
  return lLogger;
}


void Logger::Log(const GString &p_Msg, ELogLvl p_LogLvl, bool p_IsBackTrace){
  CCLOG("%s", p_Msg.c_str());
}

void Logger::LogJsonError(const std::exception &pException){
  CCLOG("Error in %s : %d  (function %s ) - %s", __FILE__, __LINE__, __FUNCTION__, " ", (pException).what());
}