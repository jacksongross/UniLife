//
//  LibraryRooms.cpp
//  UniLife
//
//  Created by csci321ga2a on 9/09/2014.
//
//

#include "LibraryRoomsController.h"
#include "LibraryFoyer.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "MenuOptionScene.h"
#include <CCTransition.h>
#include <string>
#include <vector>
#include "MapScene.h"
#include "LogicGame.h"
#include "HUDHelper.h"
#include "Movement.h"
#include "EventScene.h"

USING_NS_CC;
extern PlayerModel pm;

Scene* LibraryRooms::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = LibraryRooms::create();
    layer->setName("libraryrooms");
    
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
bool LibraryRooms::init()
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
    LibraryRoomsController::CreateMainMenu(this, visibleSize, origin);
    
    HUDLayer::resumeTimer();
    
    return true;
}

void LibraryRooms::ToFoyer(Ref* pSender)
{
    HUDLayer::pauseTimer();
    
    auto scene = LibraryFoyer::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
    
}


void LibraryRooms::ToMeet1(Ref* pSender)
{
  
    log("You Went To Meeting Room 1");
    
    // get the character and door positions
    auto character = this->getScene()->getChildByName<SpriteBatchNode*>("test")->getChildByName<Sprite*>("bill");
    auto door = this->getScene()->getChildByName<LibraryRooms*>("libraryrooms")->getChildByName("menu")->getChildByName<cocos2d::Sprite*>("meet1");
    
    float destination = door->getPositionX();
    
    // get the character's sprite position
    float start = character->getPositionX();
    
    // move the character there
    auto moveCallback = CallFunc::create([this, start, destination](){
        Movement::moveCharacter(this->getScene(), start, destination);
    });
    
    // run the event screen
    auto eventCallback = CallFunc::create([](){
        
        auto event = EventScene::createScene("events/group_study.png");
        
        TransitionCrossFade *crossfade = TransitionCrossFade::create(0.5, event);
        Director::getInstance()->pushScene(crossfade);
    });
    
    this->runAction(Sequence::createWithTwoActions(moveCallback, eventCallback));
    
    HUDLayer::updateStats(1, 0, 1, -10, -5);
    
    
}


void LibraryRooms::ToMeet2(Ref* pSender)
{
    
    log("You Went To Meeting Room 2");
    
    // get the character and door positions
    auto character = this->getScene()->getChildByName<SpriteBatchNode*>("test")->getChildByName<Sprite*>("bill");
    auto door = this->getScene()->getChildByName<LibraryRooms*>("libraryrooms")->getChildByName("menu")->getChildByName<cocos2d::Sprite*>("meet2");
    
    float destination = door->getPositionX();
    
    // get the character's sprite position
    float start = character->getPositionX();
    
    // move the character there
    auto moveCallback = CallFunc::create([this, start, destination](){
        Movement::moveCharacter(this->getScene(), start, destination);
    });
    
    // run the event screen
    auto eventCallback = CallFunc::create([](){
        
        auto event = EventScene::createScene("events/study.png");
        
        TransitionCrossFade *crossfade = TransitionCrossFade::create(0.5, event);
        Director::getInstance()->pushScene(crossfade);
    });
    
    this->runAction(Sequence::createWithTwoActions(moveCallback, eventCallback));
    
    HUDLayer::updateStats(1, 0, 0, -10, -5);
    
}


