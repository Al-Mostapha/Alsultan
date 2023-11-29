#include "Logger.h"

Logger *Logger::Get(){
  static Logger *lLogger = new Logger();
  return lLogger;
}


void Logger::Log(const GString &p_Msg, ELogLvl p_LogLvl, bool p_IsBackTrace){

}