#include "GamePanel.Mgr.h"
#include "Module/UI/UIBasePanel.h"

void GBase::DRemoveAllPrePanelFromManager(UIBasePanel *pPanel, bool p_NotCoverSelf){
  //   if not panel then
  //   return
  // end
  if(!pPanel)
    return;
  // local allNum = #SoraDPanelManager
  // local needBreak = false
  // for i = 1, allNum do
  //   local removePanel = SoraDPanelManager[1]
  //   if removePanel == nil or removePanel == panel and notCoverSelf then
  //     break
  //   end
  //   table.remove(SoraDPanelManager, 1)
  //   local isHideCurrentSceneView = removePanel.isHideCurrentSceneView
  //   if isHideCurrentSceneView then
  //     local hideData = {isHideCurrentSceneView = false, isHideMainUI = false}
  //     SoraDHideCurrentSceneViewAndMainUI(hideData)
  //   end
  //   if removePanel == panel then
  //     needBreak = true
  //   end
  //   removePanel:removeFromParent()
  //   if needBreak then
  //     break
  //   end
  // end
  // SoraDWhenRemovePanelFromManager()
  pPanel->removeFromParent();
}
