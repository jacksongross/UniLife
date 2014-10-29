//
//  TavernFoyer.cpp
//  UniLife
//
//  Created by csci321ga2a on 1/09/2014.
//
//

#include "TavernFoyer.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "TavernFoyerController.h"
#include "MenuOptionScene.h"
#include <CCTransition.h>
#include <string>
#include <vector>
#include "MapScene.h"
#include "TavernRoom.h"
#include "HUDHelper.h"
#include "Movement.h"

USING_NS_CC;
extern PlayerModel pm;

Scene* TavernFoyer::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = TavernFoyer::create();
    
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
bool TavernFoyer::init()
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
    TavernFoyerController::CreateMainMenu(this, visibleSize, origin);
    
    HUDLayer::resumeTimer();
    
    return true;
}

void TavernFoyer::ToMap(Ref* pSender)
{
    HUDLayer::pauseTimer();
    
    auto scene = MapScene::createScene(pm);
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
    
}

void TavernFoyer::ToTavernRoom(Ref* pSender)
{
    HUDLayer::pauseTimer();
    
    auto scene = TavernRoom::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
    
}

void TavernFoyer::ShowSpeech(Ref* pSender) {
    
    auto sBubble = (Sprite*)this->getChildByName("sBubble");
    auto TalkText = (cocos2d::ui::Text*)this->getChildByName("Text");
    
    sBubble->setVisible(true);
    TalkText->setVisible(true);
}