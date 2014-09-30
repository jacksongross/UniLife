//
//  PopUpLayer.cpp
//  UniLife
//
//  Created by csci321ga2a on 30/09/2014.
//
//


#include "PopUpLayer.h"
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

Scene* PopUpLayer::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = PopUpLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems;
    
    auto label = Label::createWithSystemFont("OptionsMenu", "Helvetica", 74);
    label->setColor(Color3B(0, 0, 0));
    label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 0.90));
    layer->addChild(label, 0);

    
    
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool PopUpLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if( !LayerColor::initWithColor(Color4B(255,255,255,0)) )
    {
        return false;
    }
    
    
    createPopUp(Rect(0, 0, 100, 100),Vec2(100,100));
    

    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(PopUpLayer::touchBegan, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(PopUpLayer::touchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    return true;
    
  
}

bool PopUpLayer::touchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
    log("TouchBegan");
    auto *selected = (cocos2d::Sprite*)this->getChildByName("optBox");
    //selected->getPosition().getDistance(CCDirector::getInstance()->convertToGL(touch->getLocationInView())) < 100.0f
    if( touch && !(selected->getPosition().getDistance(touch->getLocation())<100.0f))
    {
        log("You Didnt touch Me Where I Wanted");
        this->getParent()->removeChild(this);
        Director::getInstance()->resume();
        return true;
    }
    return true;
    
}


void PopUpLayer::touchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
    log("Touchended");
    auto *selected = (cocos2d::Sprite*)this->getChildByName("optBox");
    //selected->getPosition().getDistance(CCDirector::getInstance()->convertToGL(touch->getLocationInView())) < 100.0f
    if( touch && selected->getPosition().getDistance(touch->getLocation())<100.0f)
    {
        log("You Touched Me in All The Right Places ;)");
        return;
    }else{
        _eventDispatcher->removeAllEventListeners();
    }
    return;
    
    
}


void PopUpLayer::createPopUp(Rect inRect, Vec2 inLoc){

    
    auto optBox = Sprite::create();
    optBox->setColor(Color3B::WHITE);
    optBox->setTextureRect(inRect);
    optBox->setVisible(true);
    optBox->setPosition(inLoc);
    optBox->setName("optBox");
    this->addChild(optBox, 10);
    
    auto optBorder = Sprite::create();
    optBorder->setColor(Color3B::WHITE);
    optBorder->setTextureRect(inRect);
    optBorder->setVisible(true);
    optBorder->setPosition(inLoc);
    optBorder->setName("optBox");
    this->addChild(optBorder, 10);
    
    
    
}


