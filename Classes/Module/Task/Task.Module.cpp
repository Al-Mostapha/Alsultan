#include "Task.Module.h"

TaskModule *TaskModule::Get(){
  static TaskModule *s_TaskModule =  new TaskModule();
  return s_TaskModule;
}

void TaskModule::Init(){
}

void TaskModule::StartGame(){
  // Load();
}