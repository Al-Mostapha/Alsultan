#include "CommandHall.Read.h"

CommandHallRead *CommandHallRead::Get(){
  static CommandHallRead *lInstance = nullptr;
  if(!lInstance){
    lInstance = new CommandHallRead();
  }
  return lInstance;
}

GString CommandHallRead::GetTaskNpcResource(ECommandHallTaskType pTaskType){
  return "Map_commandHallNpc_06.png";
}

ECommandHallTaskType CommandHallRead::GetTaskType(ECommandHallTaskType pTaskID){
  return ECommandHallTaskType::NONE;
}
