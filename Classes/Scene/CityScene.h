/****************************************************************************
    Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
    http://www.cocos2d-x.org
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:
    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
 ****************************************************************************/

#ifndef __CITYSCENE_H_
#define __CITYSCENE_H_

#include "cocos2d.h"

#include "ui/CocosGUI.h"
USING_NS_CC;
class CityScene : public cocos2d::Scene {
public:
  static CityScene* Get();
  Node* CityFloorLayer;
  Node* CityBuildingLayer;
  Node* containerView;
  Node* batchNodeXiyiNpc;
  Node* batchNodeNpc;
  Node* batchNodeSoldierGuards;
  Node* CityDecoreLayer;
  Node* CityUiLayer;
  cocos2d::Map<std::string, Node*> bufferNodeArray;
  Node *TipBoxGuardSoldier;
  Node *ButtonMerchante;
  ui::Button *ButtonEpicBattle;
  ui::Button *ButtonMonument;

  bool IsMoving(){ return false;}
  static cocos2d::Scene* createScene();
  template<typename T>
  T GetNode(const char *p_NodeName){
    return nullptr;
  };

  cocos2d::ui::ScrollView* BaseScrollLayer;

  virtual bool init();
  void initDraggingEvent();
  void initCityLayers();
  void menuCloseCallback(cocos2d::Ref* pSender);
  void onEnter();
  static CityScene* getCityScene();

  // implement the "static create()" method manually
  CREATE_FUNC(CityScene);
};

#endif  // __CITYSCENE_H_
