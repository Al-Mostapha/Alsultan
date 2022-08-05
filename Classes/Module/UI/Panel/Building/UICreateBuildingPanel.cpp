#include "UICreateBuildingPanel.h"
#include "cocostudio/CocoStudio.h"
#include "Include/IncludeConfig.h"


UICreateBuildingPanel::UICreateBuildingPanel(){
  
}

UICreateBuildingPanel::~UICreateBuildingPanel(){

}

void UICreateBuildingPanel::initPanel(){
 

  Node *panel = CSLoader::createNode(CsbUiFilePath::UIPanelCreatBuilding);
  addChild(panel);

  //CSLoader::createNode(&CsbUiFilePath::UIPanelCreatBuilding);

}