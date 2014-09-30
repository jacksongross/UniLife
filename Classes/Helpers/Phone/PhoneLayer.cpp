//
//  PhoneLayer.cpp
//  UniLife
//
//  Created by Jackson Gross on 30/09/2014.
//
//

#include "PhoneLayer.h"
#include "PauseMenu.h"
#include "MenuScene.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "MenuController.h"
#include "MenuOptionScene.h"
#include "MenuNewGame.h"
#include <CCTransition.h>
#include <vector>
#include "DormScene.h"
#include "MenuLoadScene.h"
#include "box2D/box2D.h"
#include "HUDHelper.h"

USING_NS_CC;

extern PlayerModel pm;

Scene* PhoneLayer::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = PhoneLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool PhoneLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if( !Layer::init() )
    {
        return false;
    }
    
    // this is needed so that all layers below the pause screen layer
    // don't take touch events!!
    //auto touchListener = EventListenerTouchOneByOne::create();
    //touchListener->setSwallowTouches(true);
    //touchListener->onTouchBegan = CC_CALLBACK_2(PauseMenu::touchBegan, this);
    
    //_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    return true;
}

