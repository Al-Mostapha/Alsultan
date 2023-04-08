#include "Common.Func.h"
#include "Engine/Display.h"

Node *GBase::DCreateEffectNode(
  const GVector<RCreatEffctParam> &p_Parm, const char *p_Folder, bool p_IsAutoRemoveOnfinish
    ){
  if(!p_Folder)
    p_Folder = "Particle/";
  auto l_ParticleNode = GDisplay::Get()->NewNode();
  for(auto l_OnePart : p_Parm){
    if(l_OnePart._FileType == RCreatEffctParam::FileType::Csb){
      //  local csbNode = SoraDCreateCSBNode(v.fileName)
      // if csbNode then
      //   if not v.pos then
      //     local pos = {x = 0, y = 0}
      //   end
      //   local rotate = v.rotate or 0
      //   local zorder = v.zorder or 0
      //   if not v.scale then
      //     local scale = {x = 1, y = 1}
      //   end
      //   if type(v.scale) == "number" then
      //     scale = {
      //       x = v.scale,
      //       y = v.scale
      //     }
      //   end
      //   csbNode:addTo(particle_node, zorder)
      //   csbNode:setRotation(rotate)
      //   csbNode:setPosition(cc.p(pos.x, pos.y))
      //   if scale.x then
      //     csbNode:setScaleX(scale.x)
      //   end
      //   if scale.y then
      //     csbNode:setScaleY(scale.y)
      //   end
      // end
      // if v.autocull ~= nil then
      //   local effectNode = SoraDGetChildByName(csbNode, "nodeEffect")
      //   if effectNode then
      //     local children = effectNode:getChildren()
      //     for _, cnode in ipairs(children) do
      //       if cnode.setAutoCull then
      //         cnode:setAutoCull(v.autocull)
      //       end
      //     end
      //   end
      // end
    } else if(l_OnePart._FileType == RCreatEffctParam::FileType::Frames){
      // local sp = display.newSprite(string.format("#%s", string.format(v.imgName, 1)))
      // frames = display.newFrames(v.imgName, 1, v.imagNum)
      // sp:stopAllActions()
      // local animation = display.newAnimation(frames, 1 / v.fNum)
      // sp:playAnimationForever(animation)
      // if not v.pos then
      //   local pos = {x = 0, y = 0}
      // end
      // if not v.scale then
      //   local scale = {x = 1, y = 1}
      // end
      // if type(v.scale) == "number" then
      //   scale = {
      //     x = v.scale,
      //     y = v.scale
      //   }
      // end
      // local zorder = v.zorder or 0
      // local rotate = v.rotate or 0
      // sp:setScale(scale.x, scale.y)
      // sp:setPosition(pos)
      // sp:setRotation(rotate)
      // if v.blendOne then
      //   sp:setBlendFunc(gl.ONE, gl.ONE)
      // end
      // if v.autocull ~= nil and sp.setAutoCull then
      //   sp:setAutoCull(v.autocull)
      // end
      // sp:addTo(particle_node, zorder)
    } else {
      //   local plist = folder .. v.plist
      auto l_PList = p_Folder + l_OnePart._PList;
      //   local posType = v.posType or cc.POSITION_TYPE_RELATIVE
      auto l_PartEff = ParticleSystemQuad::create(l_PList);
      //     particle_effect:setPosition(cc.p(pos.x, pos.y))
      l_PartEff->setPosition(l_OnePart._Pos);
      l_PartEff->setScaleX(l_OnePart._Scale.x);
      l_PartEff->setScaleY(l_OnePart._Scale.y);
      l_PartEff->setPositionType(l_OnePart._PosType);
      l_PartEff->setRotation(l_OnePart._Rotate);
      l_PartEff->setAutoRemoveOnFinish(p_IsAutoRemoveOnfinish);
      //     if v.autocull ~= nil and particle_effect.setAutoCull then
      //       particle_effect:setAutoCull(v.autocull)
      //     end
      if(l_OnePart._Tp > 0)
        l_PartEff->setTotalParticles(l_OnePart._Tp);
      else 
        l_PartEff->setTotalParticles(l_PartEff->getTotalParticles() * l_OnePart._TpScale);
      
      if(l_OnePart._Name != "")
        l_PartEff->setName(l_OnePart._Name);
      if(l_OnePart._Delay > 0){
        l_PartEff->stopSystem();
        auto l_Seq =  Sequence::create(
                        DelayTime::create(l_OnePart._Delay),
                        CallFunc::create([l_PartEff](){
                          l_PartEff->resetSystem();
                        }),
                        nullptr
                      );
        l_PartEff->runAction(l_Seq);
      }
      //     if v.blend then
      //       particle_effect:setBlendFunc(v.blend[1], v.blend[2])
      //     end
      l_ParticleNode->addChild(l_PartEff);
    }
  }
  return l_ParticleNode;
}