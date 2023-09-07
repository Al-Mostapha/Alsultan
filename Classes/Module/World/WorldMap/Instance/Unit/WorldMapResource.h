#pragma once
#include "Module/CityResource/Resource.Enum.h"
#include "Module/World/WorldMap/Instance/IWorldMapInstance.h"
#include "Module/World/WorldMap/Instance/WorldInstance.Type.h"

class WorldMapProtectNode;




class WorldMapResource : public IWorldMapInstance
{
    bool _IsBeOccupyed = false;
    int32 _ResourceClassID = 0;
    EResourceType _ResourceType = EResourceType::None;
    int32 _ResourceLevel = 0;
    int32 _CurrentSourceNum = 0;
    int32 _SourceID = 0;
    bool _IsSafe = false;
    int32 _EmojiID = 0;


  Sprite *_ResourceImage;
  Sprite *_ImageLevel;
  Label *_ResourceLevelLabel;
  Sprite *_OccupyIcon;
  WorldMapProtectNode *_ImageProtect;
  Node *_ParticleNode;

  public:
    void Ctor() override;
    CREATE_FUNC(WorldMapResource);
  private:
    void _InitUI();
    void _InitData();
  public:
    void AddCacheBefore() override;
    void SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) override;
    void InitInstanceData(int32 pResourceID, void *pResourceData, int32 ObjID = 0) override;
    void UpdateData(const RResourceInitData &pResourceData);
    void OnMessageListener() override;
    void UpdateAllianceCounter(EventCustom *pEvent);
    void UpdateSafeState();
    void SetBeOccupyed();
    void CancelBeOccupyed();
    GString GetFavoriteName();
    GTuple<UIBasePanel *, bool, Node*> OnClickInstance(Node *pNode) override;
    void PlayClickSound() override;
    GVector<RButtonTypeArray> GetInstanceOp(bool pIsSelfKingdom, bool pIsInWar) override;
    void UpdateParticleNode();
    void AddParticleNode();
    void RemoveParticleNode();
};