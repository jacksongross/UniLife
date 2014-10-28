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
#include "Movement.h"

USING_NS_CC;
extern PlayerModel pm;

Scene* Inside_EIS::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Inside_EIS::create();
    layer->setName("insideeis");
    
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
    
    HUDLayer::resumeTimer();
    
    return true;
}

void Inside_EIS::ToHallway(Ref* pSender)
{
    HUDLayer::pauseTimer();
    
    auto scene = EIS_Hallway::createScene();
    TransitionCrossFade *crosssfade = TransitionCrossFade::create(0.5,scene);
    Director::getInstance()->replaceScene(crosssfade);
    
}


void Inside_EIS::ToMap(Ref* pSender)
{
    HUDLayer::pauseTimer();
    
    auto scene = MapScene::createScene(pm);
    TransitionCrossFade *crosssfade = TransitionCrossFade::create(0.5,scene);
    Director::getInstance()->replaceScene(crosssfade);
    
}

void Inside_EIS::staffTouched(Ref* pSender)
{
    log("staff member touched");
    
    // get the character and staff positions
    auto character = this->getScene()->getChildByName<SpriteBatchNode*>("test")->getChildByName<Sprite*>("bill");
    auto staff = this->getScene()->getChildByName<Inside_EIS*>("insideeis")->getChildByName("menu")->getChildByName<cocos2d::Sprite*>("staff");
    
    float destination = staff->getPositionX();
    
    // get the character's sprite position
    float start = character->getPositionX();
    
    // move the character there
    Movement::moveCharacter(this->getScene(), start, destination);
}


