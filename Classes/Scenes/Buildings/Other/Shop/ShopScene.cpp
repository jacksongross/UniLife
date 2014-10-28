//
//  ShopScene.cpp
//  UniLife
//
//  Created by Jackson Gross on 28/10/2014.
//
//

#include "ShopScene.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include <CCTransition.h>
#include <string>
#include <vector>
#include "MapScene.h"
#include "HUDHelper.h"
#include "Movement.h"

USING_NS_CC;
extern PlayerModel pm;

Scene* ShopScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = ShopScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    layer->setHUDScene(scene);
    
    // create the HUD
    HUDLayer::createHUD(scene);
    
    // load the sprite into the scene
    Movement::loadSpriteFrames(scene);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool ShopScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    HUDLayer::resumeTimer();
    
    // get the size of the screen that is visible
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    // create the shop screen
    auto bg = Sprite::create("shop/background.png");
    bg->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    
    auto bar = Sprite::create("shop/bar.png");
    bar->setPosition(Vec2(visibleSize.width * 0.7, visibleSize.height * 0.3));
    
    auto fridge = Sprite::create("shop/fridge.png");
    fridge->setPosition(Vec2(visibleSize.width * 0.2, visibleSize.height * 0.4));
    fridge->setScale(0.75);
    
    auto clerk = Sprite::create("NPC/fred_1.png");
    clerk->setPosition(Vec2(visibleSize.width * .72, visibleSize.height * .42));
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems;
    
    auto ToMap = MenuItemImage::create("Map-marker.png","Map-marker.png" , CC_CALLBACK_1(ShopScene::toMap, this));
    ToMap->setPosition(Vec2(visibleSize.width * 0.8, visibleSize.height * 0.9 ));
    ToMap->setScale(0.85);
    pMenuItems.pushBack(ToMap);
    
    // create menu, it's an autorelease object
    auto menu = Menu::createWithArray(pMenuItems);
    menu->setPosition(Vec2::ZERO);
    menu->setName("menu");
    this->addChild(menu, 1);
    
    this->addChild(bg);
    this->addChild(bar, 2);
    this->addChild(fridge, 2);
    this->addChild(clerk);
    
    
    return true;
}

void ShopScene::toMap(cocos2d::Ref *pSender)
{
    HUDLayer::pauseTimer();
    
    auto scene = MapScene::createScene();
    TransitionCrossFade *crosssfade = TransitionCrossFade::create(.5,scene);
    Director::getInstance()->replaceScene(crosssfade);
}