//
//  MapScene.cpp
//  UniLife
//
//  Created by csci321ga2a on 8/14/14.
//
//

#include "MapScene.h"
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
#include "MapController.h"

USING_NS_CC;

Scene* MapScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MapScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// overloaded createScene to pass in player
cocos2d::Scene* MapScene::createScene(PlayerModel player)
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MapScene::create(player);
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// overloaded create method to take player data
MapScene* MapScene::create(PlayerModel player)
{
    MapScene *ds = new MapScene();
    
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
bool MapScene::init()
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
    MapController::CreateMapView(this, visibleSize, origin);
    
    return true;
}


/********************************
            Getters
 *******************************/

PlayerModel MapScene::getPlayer()
{
    return this->player;
}

/********************************
            Setters
 *******************************/

void MapScene::setPlayer(PlayerModel player)
{
    this->player = player;
}
