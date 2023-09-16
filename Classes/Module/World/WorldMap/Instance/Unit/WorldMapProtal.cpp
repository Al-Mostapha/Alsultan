#include "WorldMapProtal.h"
#include "Base/Common/Common.Teml.h"
#include "Base/Utils/MeshNode.h"
#include "Module/Activity/EndlessTrials/EndlessTrials.Ctrl.h"
#include "Module/World/WorldMap/WorldMap.Define.h"
#include "Module/UI/EventCenter/EventTemplate/EndlessTrials/UIEndlessTrialsProtal.h"

void WorldMapProtal::Ctor() {
  _Effect = GBase::DCreateAnimation("xueshan").First;
  addChild(_Effect, -1);
  _Effect->setPosition(-30, 25);
  _Effect->setScale(0.82f);
  GBase::DMixtureGLONEByParent(_Effect);
  
  _BgImage = GBase::DGetChildByName<Sprite *>(_Effect, "xueshan_2");
  _ImageName = GDisplay::Get()->NewSprite("frame_map_07.png");
  _ImageName->setAnchorPoint(Vec2(0.5f, 0.5f));
  _ImageName->setPosition(Vec2(_CenterPoint.x - 0, _CenterPoint.y - 80));
  addChild(_ImageName, 3);
  // self.image_name:setGroupID(GROU_ID.group_level_build)
  
  GBase::RCreateLabelParm lParm;
  _TextName = GBase::DCreateLabel(lParm);
  _TextName->setAnchorPoint(Vec2(0.5f, 0.5f));
  _TextName->setPosition(Vec2(_CenterPoint.x - 0, _CenterPoint.y - 85));
  _TextName->setColor(Color3B(255, 255, 255));
  addChild(_TextName, 4);
  // self.text_Name:setGroupID(GROU_ID.group_text)
  AddShaderEffect();
  // InitData();
}

void WorldMapProtal::InitInstanceData(int32 pClass, void *pObjData, int32 pObjID) {
  _BuildClassID = pClass;
  auto config = EndlessTrialsCtrl::Get()->GetMountainConfig(_BuildClassID);
  _TextName->setString(config._Name);
}

void WorldMapProtal::SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) {
  // self.bgImage:setGroupID(groupID)
}

GTuple<UIBasePanel *, bool, Node*> WorldMapProtal::OnClickInstance(Node *pNode) {
  if(WorldMapDefine::Get()->IsInKingdomBattle()) {
    GBase::DShowMsgTip(Translate::i18n("common_text_3302"));
    return {nullptr, false, nullptr};
  }
  PlayClickSound();
  auto lSelectShowPanel = UIEndlessTrialsProtal::Create();
  lSelectShowPanel->InitData(_BuildClassID, _TilePoint);
  lSelectShowPanel->Show();
  return {lSelectShowPanel, false, nullptr};
}

void WorldMapProtal::PlayClickSound() {
  GBase::PlaySound("worldmap", 5);
}

void WorldMapProtal::AddShaderEffect(){
  auto lNode = GDisplay::Get()->NewNode();
  _Effect->addChild(lNode);
  lNode->setPosition(50, 60);
  struct RTab {
    struct{
      GString _Vert;
      GString _Frag;
    } _Shader; 
    RMeshData _Mesh; 
    GString _Cfg; 
    Vec2 _Scale; 
    Vec2 _Pos;
  };
  // local tab = {
  //   [1] = {
  //     shader = include("rongyan1"),
  //     mesh = include("wind3_meshData"),
  //     cfg = include("wind3_shaderCfg"),
  //     scale = {x = 1.435527, y = 1.224584},
  //     pos = cc.p(4, 2)
  //   },
  //   [2] = {
  //     shader = include("rongyan1"),
  //     mesh = include("wind4_meshData"),
  //     cfg = include("wind4_shaderCfg"),
  //     scale = {x = 1.265592, y = 1.265592},
  //     pos = cc.p(4.5, 0)
  //   },
  //   [3] = {
  //     shader = include("rongyan1"),
  //     mesh = include("wind5_meshData"),
  //     cfg = include("wind5_shaderCfg"),
  //     scale = {x = 1.160811, y = 1.160812},
  //     pos = cc.p(3.5, 4)
  //   },
  //   [4] = {
  //     shader = include("wind12_shader"),
  //     mesh = include("wind12_meshData"),
  //     cfg = include("wind12_shaderCfg"),
  //     scale = {x = 1.586068, y = 1.586068},
  //     pos = cc.p(0, 5)
  //   }
  // }
  // for i, v in ipairs(tab) do
  //   local createData = {
  //     meshData = v.mesh,
  //     shader = {
  //       vertBytes = v.shader.vertBytes,
  //       fragBytes = v.shader.fragBytes
  //     },
  //     param = v.cfg.param,
  //     pos = v.pos or cc.p(0, 0),
  //     scale = {
  //       x = 0.15 * v.scale.x,
  //       y = 0.15 * v.scale.y
  //     }
  //   }
  //   local meshNode = SoraDCreateMeshNode(createData.meshData, createData.size, createData.shader, createData.param)
  //   meshNode:setPosition(cc.p(createData.pos))
  //   meshNode:setScale(createData.scale.x, createData.scale.y)
  //   meshNode:setBlendFunc(gl.ONE, gl.ONE)
  //   meshNode:addTo(node)
  // end
}

void WorldMapProtal::AddCacheBefore() {

}
