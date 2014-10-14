//
//  Inside_EIS.cpp
//  UniLife
//
//  Created by csci321ga2a on 28/08/2014.
//
//

#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "Inside_EIS_Controller.h"
#include "EIS_Hallway.h"
#include "MenuOptionScene.h"
#include <CCTransition.h>
#include <string>
#include <vector>
#include "MapScene.h"
#include "HUDHelper.h"

USING_NS_CC;
extern PlayerModel pm;

Scene* Inside_EIS::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Inside_EIS::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    layer->setHUDScene(scene);
    
    // create the HUD
    HUDLayer::createHUD(scene);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Inside_EIS::init()
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
    Inside_EIS_Controller::CreateMainMenu(this, visibleSize, origin);
    
    return true;
}

void Inside_EIS::ToHallway(Ref* pSender)
{
    log("Going To EIS Hallway!");
    
    auto scene = EIS_Hallway::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
    
}


void Inside_EIS::ToMap(Ref* pSender)
{
    log("Going To The Map!");
    
    auto scene = MapScene::createScene(pm);
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
    
}


