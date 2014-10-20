//
//  PhoneLayer.cpp
//  UniLife
//
//  Created by Jackson Gross on 30/09/2014.
//
//

#include "PhoneLayer.h"
#include "PauseMenu.h"
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
#include "HUDHelper.h"

USING_NS_CC;

extern PlayerModel pm;

Scene* PhoneLayer::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = PhoneLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    
    // create the background for the phone layer
    auto bg = Sprite::create("phone.png");
    bg->setPosition(visibleSize.width / 2, visibleSize.height / 2);
    layer->addChild(bg);
    
    // create the buttons for the phone
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems;
    
    // player, objectives, subject, stats
    auto playerButton = MenuItemImage::create("phone_selection.png", "phone_selection.png", CC_CALLBACK_1(PhoneLayer::playerInfoCallback, layer));
    auto objectivesButton = MenuItemImage::create("phone_selection.png", "phone_selection.png", CC_CALLBACK_1(PhoneLayer::objectivesCallBack, layer));
    auto subjectButton = MenuItemImage::create("phone_selection.png", "phone_selection.png", CC_CALLBACK_1(PhoneLayer::subjectsCallBack, layer));
    auto progressButton = MenuItemImage::create("phone_selection.png", "phone_selection.png", CC_CALLBACK_1(PhoneLayer::progressCallBack, layer));
    auto closeButton = MenuItemImage::create("power-off-100.png", "power-off-100.png", CC_CALLBACK_1(PhoneLayer::closeCallBack, layer));

    closeButton->setScale(0.7);
    
    playerButton->setPosition(Vec2(10 + 174, playerButton->getContentSize().height));
    objectivesButton->setPosition(Vec2(10 + playerButton->getPositionX() + playerButton->getContentSize().width, playerButton->getContentSize().height));
    subjectButton->setPosition(Vec2(10 + objectivesButton->getPositionX() + playerButton->getContentSize().width, playerButton->getContentSize().height));
    progressButton->setPosition(Vec2(10 + subjectButton->getPositionX() + playerButton->getContentSize().width, playerButton->getContentSize().height));
    closeButton->setPosition(Vec2(visibleSize.width * .92, visibleSize.height * .85));
    
    // add menu items to array
    pMenuItems.pushBack(playerButton);
    pMenuItems.pushBack(objectivesButton);
    pMenuItems.pushBack(subjectButton);
    pMenuItems.pushBack(progressButton);
    pMenuItems.pushBack(closeButton);
    
    auto menu = Menu::createWithArray(pMenuItems);
    menu->setPosition(Vec2::ZERO);
    layer->addChild(menu, 1);
    
    // create the labels for the buttons
    auto playerLabel = Label::createWithSystemFont(pm.getName(), "Verdana", 32);
    auto objectivesLabel = Label::createWithSystemFont("Objectives", "Verdana", 32);
    auto subjectLabel = Label::createWithSystemFont("Subjects", "Verdana", 32);
    auto progressLabel = Label::createWithSystemFont("Progress", "Verdana", 32);
    
    playerLabel->setPosition(Vec2(visibleSize.width * 0.15, visibleSize.height * 0.2));
    objectivesLabel->setPosition(Vec2(visibleSize.width * 0.38, visibleSize.height * 0.2));
    subjectLabel->setPosition(Vec2(visibleSize.width * 0.62, visibleSize.height * 0.2));
    progressLabel->setPosition(Vec2(visibleSize.width * 0.84, visibleSize.height * 0.2));
    
    playerLabel->setTextColor(Color4B(0, 0, 0, 0));
    objectivesLabel->setTextColor(Color4B(0, 0, 0, 0));
    subjectLabel->setTextColor(Color4B(0, 0, 0, 0));
    progressLabel->setTextColor(Color4B(0, 0, 0, 0));
    
    layer->addChild(playerLabel, 10);
    layer->addChild(objectivesLabel, 10);
    layer->addChild(subjectLabel, 10);
    layer->addChild(progressLabel, 10);
    
    

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool PhoneLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if( !Layer::init() )
    {
        return false;
    }
    
    return true;
}

void PhoneLayer::playerInfoCallback(Ref* pSender)
{
    cocos2d::log("pressed the info button");
}

void PhoneLayer::objectivesCallBack(Ref* pSender)
{
    cocos2d::log("pressed the objectives button");
}

void PhoneLayer::subjectsCallBack(Ref* pSender)
{
    cocos2d::log("pressed the subjects button");
}

void PhoneLayer::progressCallBack(Ref* pSender)
{
    cocos2d::log("pressed the progress button");
}

void PhoneLayer::closeCallBack(Ref* pSender)
{
    this->getParent()->removeChild(this);
}

