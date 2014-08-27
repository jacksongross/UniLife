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
#include <vector>
#include <sstream>

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
    
    // add layer as a child to scene
    scene->addChild(layer);
    pm = inplayer;
    
    // Report on the loaded player object
    log("==========PLAYER IN DORM==========");
    log("NAME: %s", inplayer.getName().c_str());
    log("INT: %d", inplayer.getStats().getIntelligence());
    log("STA: %d", inplayer.getStats().getStamina());
    log("SOC: %d", inplayer.getStats().getSocial());
    log("DEGREE: %s", inplayer.getDegree().c_str());
    
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
    
    // get the size of the screen that is visible
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    // create the dorm scene
    DormController::CreateDormRoom(this, visibleSize, origin);
    
    this->schedule(schedule_selector(DormScene::UpdateTimer),1.0f);
    
    return true;
}

void DormScene::UpdateTimer(float dt)
{
    int hh, mm;
    std::string ampm;
    
    std::stringstream ss;
    ss << this->timer->getString();

    char s;
    
    ss >> hh >> s >> mm >> ampm;
    
    mm += 5;
    
    if(mm == 60)
    {
        mm = 0;
        hh++;
    }
    
    ampm == "pm" && hh == 12 ? ampm = "am" : ampm;
    ampm == "am" && hh == 12 ? ampm = "pm" : ampm;
    
    hh > 12 ? hh = 1 : hh;

    std::ostringstream stringStream;
    stringStream << hh << ":";
    
    if(mm < 10)
    {
        stringStream << "0" << mm << ampm;
    }
    else
    {
        stringStream << mm << ampm;
    }
    
    this->timer->setString(stringStream.str());
    
    
    
    
    //Added an update for the HUD Stress & Energy Bars
    auto engSprite = (ProgressTimer*)this->getChildByTag(1);
    engSprite->setPercentage(player.getStats().getEnergy());
    
    auto streSprite = (ProgressTimer*)this->getChildByTag(2);
    streSprite->setPercentage(player.getStats().getStress());
    
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
