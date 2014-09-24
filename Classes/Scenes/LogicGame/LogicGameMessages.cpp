//
//  LogicGameMessages.cpp
//  UniLife
//
//  Created by csci321ga2a on 25/09/2014.
//
//

#include "LogicGameMessages.h"
#include "MenuScene.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "MenuController.h"
#include "MenuOptionScene.h"
#include "MenuNewGame.h"
#include <CCTransition.h>
#include <vector>
#include "DormScene.h"
#include "MenuLoadScene.h"
#include "box2D/box2D.h"

USING_NS_CC;

extern PlayerModel pm;

Scene* LogicGameMessages::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = LogicGameMessages::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems;
    
    auto bg = Sprite::create("background.png");
    
    // position the sprite on the center of the screen
    bg->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
    
    // add the sprite as a child to this layer
    layer->addChild(bg, 0);
    
    auto label = Label::createWithSystemFont("Game Paused", "Helvetica", 74);
    
    label->setColor(Color3B(0, 0, 0));
    
    label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 0.90));
    
    layer->addChild(label, 0);
    
    
    
    ui::Text* retryButton = ui::Text::create("Resume", "Arial", 50);
    retryButton->addTouchEventListener(CC_CALLBACK_1(LogicGameMessages::retryCallback, layer));
    retryButton->setColor(Color3B::BLACK);
    retryButton->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - 200));
    retryButton->setTouchEnabled(true);
    layer->addChild(retryButton,5);
    
    
    auto menu = Menu::createWithArray(pMenuItems);
    menu->setPosition(Vec2::ZERO);
    layer->addChild(menu, 1);
    
    
    
    // return the scene
    return scene;
}


Scene* LogicGameMessages::createScene(std::string inMessage)
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = LogicGameMessages::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems;
    
    auto bg = Sprite::create("background.png");
    
    // position the sprite on the center of the screen
    bg->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
    
    // add the sprite as a child to this layer
    layer->addChild(bg, 0);
    
    auto label = Label::createWithSystemFont(inMessage, "Helvetica", 74);
    
    label->setColor(Color3B(0, 0, 0));
    
    label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 0.90));
    
    layer->addChild(label, 0);
    
    
    
    ui::Text* retryButton = ui::Text::create("Retry", "Arial", 50);
    retryButton->addTouchEventListener(CC_CALLBACK_1(LogicGameMessages::retryCallback, layer));
    retryButton->setColor(Color3B::BLACK);
    retryButton->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - 200));
    retryButton->setTouchEnabled(true);
    layer->addChild(retryButton,5);
    
    
    auto menu = Menu::createWithArray(pMenuItems);
    menu->setPosition(Vec2::ZERO);
    layer->addChild(menu, 1);
    
    
    
    // return the scene
    return scene;
}



// on "init" you need to initialize your instance
bool LogicGameMessages::init()
{
    //////////////////////////////
    // 1. super init first
    if( !LayerColor::initWithColor(Color4B(255,255,255,100)) )
    {
        return false;
    }
    
    
    
    return true;
}

void LogicGameMessages::retryCallback(cocos2d::Ref *pSender)
{
    log("you have touched the resume button!");
    Director::getInstance()->popScene();
    Director::getInstance()->resume();
}
