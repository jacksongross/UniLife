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
    
    
    bedPressed(Rect(0, 0, 100, 100),Vec2(100,100));
    

    
    
    
    return true;
    
  
}



void PopUpLayer::bedPressed(Rect inRect, Vec2 inLoc){

    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    auto whoreBox = Sprite::create();
    whoreBox->setTextureRect(Rect(0,0,visibleSize.width*2,visibleSize.height*2));
    whoreBox->setVisible(true);
    whoreBox->setPosition(inLoc);
    whoreBox->setName("Whore");
    this->addChild(whoreBox, 10);
    
    
    
    auto optBox = Sprite::create();
    optBox->setColor(Color3B::WHITE);
    optBox->setTextureRect(inRect);
    optBox->setVisible(true);
    optBox->setPosition(inLoc);
    optBox->setName("optBox");
    this->addChild(optBox, 10);
    
    
}


