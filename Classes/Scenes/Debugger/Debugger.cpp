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
#include "PopUpLayer.h"
#include "TutorialScene.h"
#include "QDSplashScene.h"
#include "PauseHelpScene.h"
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
    
    ui::Text* QDGame = ui::Text::create("QUACKY DUCK GAME", "Arial", 20);
    QDGame->addTouchEventListener(CC_CALLBACK_1(Debugger::gotoQuackyDuck, this));
    QDGame->setColor(Color3B::BLACK);
    QDGame->cocos2d::Node::setPosition(Point(visibleSize.width/2, visibleSize.height/2 + 100));
    QDGame->setTouchEnabled(true);
    this->addChild(QDGame,5);

    ui::Text* LGame = ui::Text::create("LOGIC GAME", "Arial", 20);
    LGame->addTouchEventListener(CC_CALLBACK_1(Debugger::gotoLogicGame, this));
    LGame->setColor(Color3B::BLACK);
    LGame->cocos2d::Node::setPosition(Point(visibleSize.width/2, visibleSize.height/2 ));
    LGame->setTouchEnabled(true);
    this->addChild(LGame,5);
    
    ui::Text* BBGame = ui::Text::create("BRICK BREAKER", "Arial", 20);
    BBGame->addTouchEventListener(CC_CALLBACK_1(Debugger::gotoBrickBreaker, this));
    BBGame->setColor(Color3B::BLACK);
    BBGame->cocos2d::Node::setPosition(Point(visibleSize.width/2, visibleSize.height/2 - 50));
    BBGame->setTouchEnabled(true);
    this->addChild(BBGame,5);

    ui::Text* PopUp = ui::Text::create("POPUP MENU", "Arial", 20);
    PopUp->addTouchEventListener(CC_CALLBACK_1(Debugger::gotoPopUp, this));
    PopUp->setColor(Color3B::BLACK);
    PopUp->cocos2d::Node::setPosition(Point(visibleSize.width/2, visibleSize.height/2 - 100));
    PopUp->setTouchEnabled(true);
    this->addChild(PopUp,5);
    
    ui::Text* Tutorial = ui::Text::create("TUTORIAL", "Arial", 20);
    Tutorial->addTouchEventListener(CC_CALLBACK_1(Debugger::gotoTutorial, this));
    Tutorial->setColor(Color3B::BLACK);
    Tutorial->cocos2d::Node::setPosition(Point(visibleSize.width/2, visibleSize.height/2 + 50));
    Tutorial->setTouchEnabled(true);
    this->addChild(Tutorial,5);
    
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
    TransitionCrossFade *crossfade = TransitionCrossFade::create(0.5, scene);
    Director::getInstance()->replaceScene(crossfade);
    
}

void Debugger::gotoTutorial(Ref* pSender){
    log("Tutorial Initalize");
    auto scene = TutorialScene::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
    
}

void Debugger::gotoQuackyDuck(Ref* pSender) {
    log("Quacky duck Initalize");
    auto scene = QDSplashScene::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
}


void Debugger::gotoPopUp(Ref* pSender){
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    isonreturn = true;
    log("PopupInit");
    
    cocos2d::Director::getInstance()->pause();
    cocos2d::log("Going to PopupMenu");
    
    //auto *p = PopUpLayer::createScene();
    ui::Button* defaultButt;
    vector<ui::Button*> list;
    for(int i = 0; i < 20; i++){
        defaultButt = ui::Button::create("options_off.png");
        list.push_back(defaultButt);
    }

    Rect a = Rect(visibleSize.width/2 - 350, visibleSize.height/2, 600, 300);
    
    auto *p = PopUpLayer::createScene(a,list);

    this->addChild(p, 10);
    
}

