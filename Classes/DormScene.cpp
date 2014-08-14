//
//  DormScene.cpp
//  UniLife
//
//  Created by csci321ga2a on 8/14/14.
//
//
#include "MenuScene.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "MenuController.h"
#include "MenuOptionController.h"
#include "MenuOptionScene.h"
#include <vector>
#include "DormScene.h"
#include "DormController.h"

USING_NS_CC;

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
cocos2d::Scene* DormScene::createScene(PlayerModel player)
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = DormScene::create(player);
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// overloaded create method to take player data
DormScene* DormScene::create(PlayerModel player)
{
    DormScene *ds = new DormScene();
    
    if (ds->init())
    {
        ds->autorelease();
        ds->setPlayer(player);
    }
    else
        ds = NULL;
    
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
    
    // get the size of the screen that is visible
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    // create the dorm scene
    DormController::CreateDormRoom(this, visibleSize, origin);
    
    return true;
}


/********************************
            Getters
 *******************************/

PlayerModel DormScene::getPlayer()
{
    return this->player;
}

/********************************
            Setters
 *******************************/

void DormScene::setPlayer(PlayerModel player)
{
    this->player = player;
}
