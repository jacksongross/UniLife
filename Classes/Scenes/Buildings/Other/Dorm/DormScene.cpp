//
//  DormScene.cpp
//  UniLife
//
//  Created by Jackson Gross on 8/14/14.
//
//
#include "MenuScene.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "MenuController.h"
#include "MenuOptionController.h"
#include "MenuOptionScene.h"
#include "DormScene.h"
#include "DormController.h"
#include "MapScene.h"
#include <vector>
#include <cmath>
#include <sstream>
#include "BrickBreaker.h"
#include "PauseMenu.h"
#include "SimpleAudioEngine.h"
#include "HUDHelper.h"
#include "Movement.h"

USING_NS_CC;

PlayerModel pm;

Scene* DormScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = DormScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// overloaded createScene to pass in player
cocos2d::Scene* DormScene::createScene(PlayerModel inplayer)
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = DormScene::create(inplayer);
    layer->setName("dorm");
    
    // add layer as a child to scene
    scene->addChild(layer);
    pm = inplayer;
    pm.setStats(inplayer.getStats());
    
    layer->setHUDScene(scene);
    
    // create the HUD
    HUDLayer::createHUD(scene);
    HUDLayer::updateHUD(pm);
    
    // Report on the loaded player object
    log("==========PLAYER IN DORM==========");
    log("PLAYER ID: %d", inplayer.getId());
    log("NAME: %s", inplayer.getName().c_str());
    log("INT: %d", inplayer.getStats().getIntelligence());
    log("STA: %d", inplayer.getStats().getStamina());
    log("SOC: %d", inplayer.getStats().getSocial());
    log("DEGREE: %s", inplayer.getDegree().c_str());
    log("ENERGY: %d" , inplayer.getStats().getEnergy());
    log("STRESS: %d", inplayer.getStats().getStress());
    
    // load the character
    //Movement::loadSpriteFrames(scene);
    
    // return the scene
    return scene;
}

// overloaded create method to take player data
DormScene* DormScene::create(PlayerModel inplayer)
{
    DormScene *ds = new DormScene();
    if (ds->init())
    {
        ds->autorelease();
        ds->setPlayer(inplayer);
    }
    else{
        ds = NULL;
    }
    return ds;
}

// on "init" you need to initialize your instance
bool DormScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    isPaused = false;
    
    // get the size of the screen that is visible
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    // create the dorm scene
    DormController::CreateDormRoom(this, visibleSize, origin);
    
    return true;
}

void DormScene::DoorPressed(cocos2d::Ref *pSender)
{
    log("playing the door sound effect");
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("doorOpen.wav");
    log("you have touched the door!");
    // transition to the load game scene
    auto scene = MapScene::createScene(pm);
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
}

void DormScene::BedPressed(cocos2d::Ref *pSender)
{
    log("You will rest and restore all energy and decrease stress by 5");
    
    PlayerStatsModel updateStats;
    TimeModel newTime;
    updateStats = pm.getStats();
    newTime = pm.getGameTime();
    
    if(updateStats.getStress() > 10)
        updateStats.setStress(updateStats.getStress() - 10);
    else
        updateStats.setStress(0);
    
    updateStats.setEnergy(100);
    newTime.setHoursMinutes(newTime.getHoursMinutes() + 8.0);
    pm.setStats(updateStats);
    pm.setGameTime(newTime);
    
    log("PLAYER ID: %d", pm.getId());
    log("NAME: %s", pm.getName().c_str());
    log("INT: %d", pm.getStats().getIntelligence());
    log("STA: %d", pm.getStats().getStamina());
    log("SOC: %d", pm.getStats().getSocial());
    log("DEGREE: %s", pm.getDegree().c_str());
    log("ENERGY: %d" , pm.getStats().getEnergy());
    log("STRESS: %d", pm.getStats().getStress());
    log("DAY: %d", pm.getGameTime().getDay());
    log("WEEK: %d", pm.getGameTime().getWeek());
    log("SEMESTER: %d", pm.getGameTime().getSemester());
    log("TIME: %f", pm.getGameTime().getHoursMinutes());
    
    // get the character and bed positions
    auto character = this->getScene()->getChildByName<SpriteBatchNode*>("test")->getChildByName<Sprite*>("bill");
    auto bed = this->getScene()->getChildByName<DormScene*>("dorm")->getChildByName("menu")->getChildByName<cocos2d::Sprite*>("bed");
    
    float destination = bed->getPositionX();
    
    // get the character's sprite position
    float start = character->getPositionX();
    
    // move the character there
    Movement::moveCharacter(this->getScene(), start, destination);
    
    HUDLayer::updateHUD(pm);
    
}

void DormScene::ShelfPressed(cocos2d::Ref *pSender)
{
    log("You touched the shelf");
    // get the character and bed positions
    auto character = this->getScene()->getChildByName<SpriteBatchNode*>("test")->getChildByName<Sprite*>("bill");
    auto shelf = this->getScene()->getChildByName<DormScene*>("dorm")->getChildByName("menu")->getChildByName<cocos2d::Sprite*>("shelf");
    
    float destination = shelf->getPositionX();
    
    // get the character's sprite position
    float start = character->getPositionX();
    
    // move the character there
    Movement::moveCharacter(this->getScene(), start, destination);
}

void DormScene::DeskPressed(cocos2d::Ref *pSender)
{
    log("You touched the desk!");
    
    // get the character and desk positions
    auto character = this->getScene()->getChildByName<SpriteBatchNode*>("test")->getChildByName<Sprite*>("bill");
    auto desk = this->getScene()->getChildByName<DormScene*>("dorm")->getChildByName("menu")->getChildByName<cocos2d::Sprite*>("desk");
    
    float destination = desk->getPositionX();
    
    // get the character's sprite position
    float start = character->getPositionX();
    
    // move the character there
    Movement::moveCharacter(this->getScene(), start, destination);
    
}

void DormScene::ComputerPressed(cocos2d::Ref *pSender)
{
    log("You touched the computer!");
    
    // get the character and computer positions
    auto character = this->getScene()->getChildByName<SpriteBatchNode*>("test")->getChildByName<Sprite*>("bill");
    auto computer = this->getScene()->getChildByName<DormScene*>("dorm")->getChildByName("menu")->getChildByName<cocos2d::Sprite*>("computer");
    
    float destination = computer->getPositionX();
    
    // get the character's sprite position
    float start = character->getPositionX();
    
    // move the character there
    Movement::moveCharacter(this->getScene(), start, destination);
    
    // transition to the load game scene
    auto scene = BrickBreaker::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
}

/********************************
            Getters
 *******************************/

PlayerModel DormScene::getPlayer()
{
    return this->player;
}

Scene* DormScene::getHUDScene()
{
    return this->HUDScene;
}

/********************************
            Setters
 *******************************/

void DormScene::setPlayer(PlayerModel player)
{
    this->player = player;
}

void DormScene::setHUDScene(Scene* HUDScene)
{
    this->HUDScene = HUDScene;
}
