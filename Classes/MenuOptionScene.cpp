//
//  MenuOptionScene.cpp
//  UniLife
//
//  Created by csci321ga2a on 8/12/14.
//
//

#include "MenuScene.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "MenuController.h"
#include "MenuOptionController.h"
#include "MenuOptionScene.h"
#include <vector>

USING_NS_CC;

Scene* MenuOptionScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MenuOptionScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MenuOptionScene::init()
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
    MenuOptionController::CreateMainMenu(this, visibleSize, origin);
    
    return true;
}

void MenuOptionScene::backButtonCallback(Ref* pSender)
{
    log("test!");
    
    auto scene = MenuScene::createScene();
    CCTransitionPageTurn *crosssfade = CCTransitionPageTurn::create(1,scene, true);
    CCDirector::sharedDirector()->replaceScene(crosssfade);
    
}
