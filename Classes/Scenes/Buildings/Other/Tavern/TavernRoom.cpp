//
//  TavernRoom.cpp
//  UniLife
//
//  Created by csci321ga2a on 8/09/2014.
//
//
#include "TavernFoyer.h"
#include "TavernRoom.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "TavernRoomController.h"
#include "EIS_Hallway.h"
#include "MenuOptionScene.h"
#include <CCTransition.h>
#include <string>
#include <vector>
#include "MapScene.h"
#include "HUDHelper.h"
USING_NS_CC;
extern PlayerModel pm;

Scene* TavernRoom::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = TavernRoom::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    layer->setHUDScene(scene);
    
    // create the HUD
    HUDLayer::createHUD(scene);
    HUDLayer::updateHUD(pm);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool TavernRoom::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    
    // get the size of the screen that is visible
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    // create the main menu
    TavernRoomController::CreateMainMenu(this, visibleSize, origin);
    
    return true;
}

void TavernRoom::ToFoyer(Ref* pSender)
{
    log("Going To The Map!");
    
    auto scene = TavernFoyer::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
    
}

