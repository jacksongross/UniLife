//
//  SciMed-Hallway.cpp
//  UniLife
//
//  Created by csci321ga2a on 8/09/2014.
//
//

#include "SciMed-Hallway.h"
#include "SciMed-Foyer-Controller.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "SciMed-Hallway-Controller.h"
#include "MenuOptionScene.h"
#include <CCTransition.h>
#include <string>
#include <vector>
#include "MapScene.h"
#include "HUDHelper.h"
#include "Movement.h"

USING_NS_CC;
extern PlayerModel pm;

Scene* SciMedHallway::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = SciMedHallway::create();
    layer->setName("scimedhallway");
    
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
bool SciMedHallway::init()
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
    SciMedHallwayController::CreateMainMenu(this, visibleSize, origin);
    
    return true;
}

void SciMedHallway::ToFoyer(Ref* pSender)
{
    log("Going To SciMed Foyer!");
    
    auto scene = SciMedFoyer::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
    
}


void SciMedHallway::ToLecture(Ref* pSender){
    log("Going To SciMed Lecture!");
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("dorm-door-opening.wav");
    

    // get the character and door positions
    auto character = this->getScene()->getChildByName<SpriteBatchNode*>("test")->getChildByName<Sprite*>("bill");
    auto staff = this->getScene()->getChildByName<SciMedHallway*>("scimedhallway")->getChildByName("menu")->getChildByName<cocos2d::Sprite*>("lectdoor");
    
    float destination = staff->getPositionX();
    
    // get the character's sprite position
    float start = character->getPositionX();
    
    // move the character there
    Movement::moveCharacter(this->getScene(), start, destination);
    
    
}


void SciMedHallway::ToTutorial(Ref* pSender){
    log("Going To SciMed Tutorial!");
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("dorm-door-opening.wav");

    // get the character and door positions
    auto character = this->getScene()->getChildByName<SpriteBatchNode*>("test")->getChildByName<Sprite*>("bill");
    auto staff = this->getScene()->getChildByName<SciMedHallway*>("scimedhallway")->getChildByName("menu")->getChildByName<cocos2d::Sprite*>("tutdoor");
    
    float destination = staff->getPositionX();
    
    // get the character's sprite position
    float start = character->getPositionX();
    
    // move the character there
    Movement::moveCharacter(this->getScene(), start, destination);
    
    
}


