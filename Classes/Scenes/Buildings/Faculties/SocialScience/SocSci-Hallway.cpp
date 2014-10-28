//
//  SocSci-Hallway.cpp
//  UniLife
//
//  Created by csci321ga2a on 8/09/2014.
//
//

#include "SocSci-Foyer.h"
#include "SocSci-Hallway.h"
#include "SocSci-Foyer-Controller.h"
#include "SocSci-Hallway-Controller.h"
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

Scene* SocSciHallway::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = SocSciHallway::create();
    layer->setName("socscihallway");
    
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
bool SocSciHallway::init()
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
    SocSciHallwayController::CreateMainMenu(this, visibleSize, origin);
    
    return true;
}

void SocSciHallway::ToFoyer(Ref* pSender)
{
    log("Going To Buisness Hallway!");
    
    auto scene = SocSciFoyer::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
    
}



void SocSciHallway::ToLecture(Ref* pSender){
    log("Going To Buisness Lecture!");
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("dorm-door-opening.wav");
    

    // get the character and door positions
    auto character = this->getScene()->getChildByName<SpriteBatchNode*>("test")->getChildByName<Sprite*>("bill");
    auto door = this->getScene()->getChildByName<SocSciHallway*>("socscihallway")->getChildByName("menu")->getChildByName<cocos2d::Sprite*>("lectdoor");
    
    float destination = door->getPositionX();
    
    // get the character's sprite position
    float start = character->getPositionX();
    
    // move the character there
    auto moveCallback = CallFunc::create([this, start, destination](){
        Movement::moveCharacter(this->getScene(), start, destination);
    });
    
    // run the event screen
    auto eventCallback = CallFunc::create([](){
        
        auto event = EventScene::createScene("events/social_science_lecture.png");
        
        TransitionCrossFade *crossfade = TransitionCrossFade::create(0.5, event);
        Director::getInstance()->pushScene(crossfade);
    });
    
    this->runAction(Sequence::createWithTwoActions(moveCallback, eventCallback));
    
    
}


void SocSciHallway::ToTutorial(Ref* pSender){
    log("Going To Buisness Tutorial!");
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("dorm-door-opening.wav");
    
    // get the character and door positions
    auto character = this->getScene()->getChildByName<SpriteBatchNode*>("test")->getChildByName<Sprite*>("bill");
    auto door = this->getScene()->getChildByName<SocSciHallway*>("socscihallway")->getChildByName("menu")->getChildByName<cocos2d::Sprite*>("tutdoor");
    
    float destination = door->getPositionX();
    
    // get the character's sprite position
    float start = character->getPositionX();
    
    // move the character there
    auto moveCallback = CallFunc::create([this, start, destination](){
        Movement::moveCharacter(this->getScene(), start, destination);
    });
    
    // run the event screen
    auto eventCallback = CallFunc::create([](){
        
        auto event = EventScene::createScene("events/social_science_tutorial.png");
        
        TransitionCrossFade *crossfade = TransitionCrossFade::create(0.5, event);
        Director::getInstance()->pushScene(crossfade);
    });
    
    this->runAction(Sequence::createWithTwoActions(moveCallback, eventCallback));
    
    
    
}

