//
//  Buis-Hallway.cpp
//  UniLife
//
//  Created by csci321ga2a on 8/09/2014.
//
//

#include "Buis-Foyer.h"
#include "Buis-Hallway.h"
#include "Buis-Foyer-Controller.h"
#include "Buis-Hallway-Controller.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "MenuOptionScene.h"
#include <CCTransition.h>
#include <string>
#include <vector>
#include "MapScene.h"
#include "HUDHelper.h"
#include "Movement.h"
#include "EventScene.h"

USING_NS_CC;
extern PlayerModel pm;

Scene* BuisHallway::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = BuisHallway::create();
    layer->setName("buishallway");
    
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
bool BuisHallway::init()
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
    BuisHallwayController::CreateMainMenu(this, visibleSize, origin);
    
    return true;
}

void BuisHallway::ToFoyer(Ref* pSender)
{
    log("Going To Buisness Hallway!");
    
    auto scene = BuisFoyer::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
    
}



void BuisHallway::ToLecture(Ref* pSender)
{
    log("Going To Buisness Lecture!");
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("dorm-door-opening.wav");
    

    // get the character and door positions
    auto character = this->getScene()->getChildByName<SpriteBatchNode*>("test")->getChildByName<Sprite*>("bill");
    auto door = this->getScene()->getChildByName<BuisHallway*>("buishallway")->getChildByName("menu")->getChildByName<cocos2d::Sprite*>("lectdoor");
    
    float destination = door->getPositionX();
    
    // get the character's sprite position
    float start = character->getPositionX();
    
    // move the character there
    auto moveCallback = CallFunc::create([this, start, destination](){
        Movement::moveCharacter(this->getScene(), start, destination);
    });
    
    // run the event screen
    auto eventCallback = CallFunc::create([](){
        
        auto event = EventScene::createScene("events/business_lecture.png");
        
        TransitionCrossFade *crossfade = TransitionCrossFade::create(0.5, event);
        Director::getInstance()->pushScene(crossfade);
    });
    
    this->runAction(Sequence::createWithTwoActions(moveCallback, eventCallback));
    
    
}


void BuisHallway::ToTutorial(Ref* pSender)
{
    log("Going To Buisness Tutorial!");
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("dorm-door-opening.wav");
    
    // get the character and door positions
    auto character = this->getScene()->getChildByName<SpriteBatchNode*>("test")->getChildByName<Sprite*>("bill");
    auto door = this->getScene()->getChildByName<BuisHallway*>("buishallway")->getChildByName("menu")->getChildByName<cocos2d::Sprite*>("tutdoor");
    
    float destination = door->getPositionX();
    
    // get the character's sprite position
    float start = character->getPositionX();
    
    // move the character there
    auto moveCallback = CallFunc::create([this, start, destination](){
        Movement::moveCharacter(this->getScene(), start, destination);
    });
    
    // run the event screen
    auto eventCallback = CallFunc::create([](){
        
        auto event = EventScene::createScene("events/business_tutorial.png");
        
        TransitionCrossFade *crossfade = TransitionCrossFade::create(0.5, event);
        Director::getInstance()->pushScene(crossfade);
    });
    
    this->runAction(Sequence::createWithTwoActions(moveCallback, eventCallback));
    
    
    
}

