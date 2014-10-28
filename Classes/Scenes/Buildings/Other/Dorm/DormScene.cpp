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
#include "BBStartScreen.h"
#include "EventScene.h"

USING_NS_CC;

PlayerModel pm;

Scene* DormScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = DormScene::create();
    layer->setName("dorm");
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // create the HUD
    HUDLayer::createHUD(scene);
    
    // load the character
    Movement::loadSpriteFrames(scene);
    
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
    layer->setPlayer(inplayer);
    
    // create the HUD
    HUDLayer::createHUD(scene);
    HUDLayer::setPlayer(inplayer);
    HUDLayer::updateHUD(pm);
    
    // load the character
    Movement::loadSpriteFrames(scene);
    
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
    
    //HUDLayer::resumeTimer();
    
    return true;
}

void DormScene::DoorPressed(cocos2d::Ref *pSender)
{
    log("playing the door sound effect");
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("dorm-door-opening.wav");
    log("you have touched the door!");
    
    HUDLayer::pauseTimer();
    
    // transition to the load game scene
    auto scene = MapScene::createScene(pm);
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);

}

void DormScene::BedPressed(cocos2d::Ref *pSender)
{    
    // get the character and bed positions
    auto character = this->getScene()->getChildByName<SpriteBatchNode*>("test")->getChildByName<Sprite*>("bill");
    auto bed = this->getScene()->getChildByName<DormScene*>("dorm")->getChildByName("menu")->getChildByName<cocos2d::Sprite*>("bed");
    
    float destination = bed->getPositionX();
    
    // get the character's sprite position
    float start = character->getPositionX();
    
    // move the character there
    auto moveCallback = CallFunc::create([this, start, destination](){
         Movement::moveCharacter(this->getScene(), start, destination);
    });
    
    // run the event screen
    auto eventCallback = CallFunc::create([](){
        
        auto event = EventScene::createScene("events/bed-event.png");
        
        TransitionCrossFade *crossfade = TransitionCrossFade::create(0.5, event);
        Director::getInstance()->pushScene(crossfade);
    });
    
    this->runAction(Sequence::createWithTwoActions(moveCallback, eventCallback));
    
    HUDLayer::updateTime(8);
    
    
    
}

void DormScene::ShelfPressed(cocos2d::Ref *pSender)
{
    // get the character and bed positions
    auto character = this->getScene()->getChildByName<SpriteBatchNode*>("test")->getChildByName<Sprite*>("bill");
    auto shelf = this->getScene()->getChildByName<DormScene*>("dorm")->getChildByName("menu")->getChildByName<cocos2d::Sprite*>("shelf");
    
    float destination = shelf->getPositionX();
    
    // get the character's sprite position
    float start = character->getPositionX();
    
    auto moveCallback = CallFunc::create([this, start, destination]()
    {
        // move the character
        Movement::moveCharacter(this->getScene(), start, destination);
    });
    
    auto callback = CallFunc::create([](){
        log("You touched the shelf");
    });

    // run the actions!
    this->runAction(Sequence::createWithTwoActions(moveCallback, callback));
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
    
    HUDLayer::pauseTimer();
    
    // get the character and computer positions
    auto character = this->getScene()->getChildByName<SpriteBatchNode*>("test")->getChildByName<Sprite*>("bill");
    auto computer = this->getScene()->getChildByName<DormScene*>("dorm")->getChildByName("menu")->getChildByName<cocos2d::Sprite*>("computer");
    
    float destination = computer->getPositionX();
    
    // get the character's sprite position
    float start = character->getPositionX();
    
    // move the character there
    Movement::moveCharacter(this->getScene(), start, destination);
    
    auto *p = BBStartScreen::createScene();
    TransitionCrossFade *crossfade = TransitionCrossFade::create(0.5, p);
    Director::getInstance()->pushScene(crossfade);
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
