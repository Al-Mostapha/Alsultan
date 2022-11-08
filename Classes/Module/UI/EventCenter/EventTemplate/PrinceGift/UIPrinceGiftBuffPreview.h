#pragma once 
#include "Include/IncludeBase.h"

#include "Include/IncludeEngine.h"
#include "Module/UI/Panel/UIPanelBase.h"


class UIPrinceGiftBuffPreview : public UIPanelBase
{

private:
  CREATE_FUNC(UIPrinceGiftBuffPreview);
public:
  UIPrinceGiftBuffPreview(){};
  ~UIPrinceGiftBuffPreview(){};
  void InitPanel() override{};
  void Show() override {};
  static UIPrinceGiftBuffPreview *Create() {return create();};
};
