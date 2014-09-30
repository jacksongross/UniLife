//
//  Debugger.cpp
//  UniLife
//
//  Created by csci321ga2a on 18/09/2014.
//
//

#include "Debugger.h"
#include "LogicGame.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include <CCTransition.h>
#include <vector>
#include "MenuScene.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "MenuController.h"
#include "MenuOptionScene.h"
#include "MenuNewGame.h"
#include "DormScene.h"
#include "MenuLoadScene.h"
#include "BrickBreaker.h"
#include "FCG_minigame.h"
USING_NS_CC;
using namespace cocos2d;

Scene* Debugger::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Debugger::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Debugger::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto sprite = Sprite::create("options-bg.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    
    
    
    SpawnList();
    
    
    return true;
}



void Debugger::SpawnList(){
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    
    ui::Text* LGame = ui::Text::create("LOGIC GAME", "Arial", 30);
    LGame->addTouchEventListener(CC_CALLBACK_1(Debugger::gotoLogicGame, this));
    LGame->setColor(Color3B::BLACK);
    LGame->cocos2d::Node::setPosition(Point(visibleSize.width/2, visibleSize.height/2 + 100));
    LGame->setTouchEnabled(true);
    this->addChild(LGame,5);
    
    ui::Text* BBGame = ui::Text::create("BRICK BREAKER", "Arial", 30);
    BBGame->addTouchEventListener(CC_CALLBACK_1(Debugger::gotoBrickBreaker, this));
    BBGame->setColor(Color3B::BLACK);
    BBGame->cocos2d::Node::setPosition(Point(visibleSize.width/2, visibleSize.height/2 - 100));
    BBGame->setTouchEnabled(true);
    this->addChild(BBGame,5);

    
    
    
    
}

void Debugger::gotoLogicGame(Ref* pSender){
    log("LogicGameInit");
    auto scene = FCGminigame::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
}

void Debugger::gotoBrickBreaker(Ref* pSender){
    log("BrickBreakInit");
    auto scene = BrickBreaker::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
    
}

