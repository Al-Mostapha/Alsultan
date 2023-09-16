#pragma once
#include "Module/World/WorldMap/Instance/IWorldMapInstance.h"

struct RMineBuildInit{
  int32 _LeagueID;
};

class WorldMapMineBuild : public IWorldMapInstance
{
  public:
    int32 _Size;
    int32 _Radioation;
    int32 _ObjID = 0;
    int32 _BuildID = 0;
    int32 _TaskIndex = 0;
    Sprite *_ModelImage;
    Sprite *_ImageNameBg;
    Label *_TextName;
    Sprite *_SpriteBg;
    Sprite *_StatusImg;
    Node *_MineEffect;
    Node *_NodeProduce;
  public:
    CREATE_FUNC(WorldMapMineBuild);
    void Ctor() override;
    void _InitData();
    void _InitUI();
    void SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) override;
    void SetBuildSize(int32 pSize, int32 pRadioation);
    void InitInstanceData(int32 pClass, void *pObjData, int32 pObjID = 0) override;
    void InitMineEffect();
    int32 GetBuildClassID();
    void UpdateData(const RMineBuildInit &pData);
    void OnMessageListener() override;
    uint32 GetRamdanWorldTaskIndex();
    void UpdateStatusImg(EventCustom *pEvent = nullptr);
    void UpdatePlayerInfo();
    void ShowProduceAct();
    void HideProduceAct();
    GString GetFavoriteName();
    void PlayClickSound() override;
    GTuple<UIBasePanel *, bool, Node*> OnClickInstance(Node *pNode) override;
    GVector<RButtonTypeArray> GetInstanceOp(bool pIsSelfKingdom, bool pIsInWar) override;
    void AddCacheBefore() override;
};