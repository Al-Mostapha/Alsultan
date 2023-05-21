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

#include "Include/IncludeBase.h"
#include "Include/IncludeEngine.h"
#include "Main/MainScene.h"
USING_NS_CC;

struct RShowMainCityView;

class TestScrollViewDelegate : public Ext::ScrollViewDelegate {
  public:
  /**
   * @js NA
   * @lua NA
   */
  ~TestScrollViewDelegate() {}
  /**
   * @js NA
   * @lua NA
   */
  void scrollViewDidScroll(Ext::ScrollView* view) { printf("Error -------------------------------------- loading: "); };
  /**
   * @js NA
   * @lua NA
   */
  void scrollViewDidZoom(Ext::ScrollView* view) { CCLOG("**************"); };
};

class CityScene : public MainScene {
  public:
  static CityScene* Get();
  Node* _ContainerView;
  Node* CityFloorLayer;
  Node* CityBuildingLayer;
  Node* containerView;
  Node* batchNodeXiyiNpc;
  Node* batchNodeNpc;
  Node* batchNodeSoldierGuards;
  Node* CityDecoreLayer;
  Node* CityUiLayer;
  Map<std::string, Node*> bufferNodeArray;
  Node* TipBoxGuardSoldier;
  Node* ButtonMerchante;
  ui::Button* ButtonEpicBattle;
  ui::Button* ButtonMonument;

  bool IsMoving() { return false; }
  static cocos2d::Scene* createScene();
  template <typename T> T GetNode(const char* p_NodeName) { return nullptr; };

  Ext::ScrollView* BaseScrollLayer;
  Ext::ScrollView* _ScrollLayer;
  class MainCityView* _MainCityView;

  virtual bool init();
  void initDraggingEvent();
  void initCityLayers();
  void menuCloseCallback(cocos2d::Ref* pSender);
  void onEnter();
  void LoadAsset();
  void ShowView(EventCustom *p_Event);
  static CityScene* getCityScene();

  // implement the "static create()" method manually
  CREATE_FUNC(CityScene);
  private:
  void SwitcherView(RShowMainCityView *p_Data);
};

#endif  // __CITYSCENE_H_
