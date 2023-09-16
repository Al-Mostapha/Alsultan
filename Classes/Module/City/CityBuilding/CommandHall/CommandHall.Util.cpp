#include "CommandHall.Util.h"

CommandHallUtil *CommandHallUtil::Get(){
  static CommandHallUtil *lInstance = nullptr;
  if (lInstance == nullptr){
    lInstance = new CommandHallUtil();
  }
  return lInstance;
}

Node *CommandHallUtil::CreateTaskNode(){
  // local taskNode = display.newNode()
  // local bgSprite = display.newSprite("#img_commandhall_sign_01.png")
  // bgSprite:addTo(taskNode)
  // local iconSprite = display.newSprite("#bg_transparent.png")
  // iconSprite:addTo(taskNode)
  // iconSprite:setPosition(cc.p(0, 5))
  // function taskNode.setTaskID(target, taskID)
  //   local commandHallRead = include("commandHallRead")
  //   local quality = commandHallRead.getTaskQuality(taskID)
  //   local bgImage = commandHallRead.getQualityBgImage(quality)
  //   bgSprite:setSpriteFrame(bgImage)
  //   local taskType = commandHallRead.getTaskType(taskID)
  //   local taskIcon = commandHallRead.getTaskIcon(taskType)
  //   iconSprite:setSpriteFrame(taskIcon)
  // end
  // return taskNode
  return GDisplay::Get()->NewNode();
}