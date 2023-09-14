#include "WorldMapBoss.h"
#include "Module/World/Kingdom/KingdomMap.Enum.h"

class WorldMapProtectNode;

class WorldMapBossAtlantis : public WorldMapBoss{
  public:
    WorldMapProtectNode *_ImageProtect = nullptr;
    EKingdomWarStatusType _WarStatus = EKingdomWarStatusType::None;
    uint32 _ObjId = 0;
    void _InitData() override;
    void _InitUI() override;
    void updateData(const RWorldMapBossInit &pInitData) override;
    GTuple<UIBasePanel *, bool, Node*> OnClickInstance(Node *pNode) override;
    uint32 GetObjId();
    void UpdateSafeState();
};