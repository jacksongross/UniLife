//
//  Inside_EIS.cpp
//  UniLife
//
//  Created by csci321ga2a on 28/08/2014.
//
//

#include "Inside_EIS.h"
#include "MenuDegreeSelect.h"
#include "MenuNewGame.h"
#include "MenuScene.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "Inside_EIS_Controller.h"
#include "MenuOptionScene.h"
#include "DormScene.h"
#include <CCTransition.h>
#include <string>
#include <vector>

USING_NS_CC;
extern PlayerModel pm;

Scene* Inside_EIS::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Inside_EIS::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Inside_EIS::init()
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
    
    // create the main menu
    Inside_EIS_Controller::CreateMainMenu(this, visibleSize, origin);
    
    
    return true;
}


void Inside_EIS::UpdateMeters()
{
    PlayerStatsModel oldStats;
    oldStats = pm.getStats();

    
    //Added an update for the HUD Stress & Energy Bars
    auto engSprite = (ProgressTimer*)this->getChildByTag(1);
    engSprite->setPercentage(oldStats.getEnergy() / 1.0);
    log("%f",oldStats.getEnergy() / 1.0 );
    
    auto streSprite = (ProgressTimer*)this->getChildByTag(2);
    streSprite->setPercentage(oldStats.getStress() / 1.0);
    log("%f",oldStats.getStress() / 1.0 );
}


void Inside_EIS::MinusEnergy(Ref* pSender)
{
    log("Lower Energeeezzeee");
    int newEnergy;
    PlayerStatsModel oldStats;
    oldStats = pm.getStats();
    
    
    newEnergy = pm.getStats().getEnergy();
    log("%d", newEnergy);
    newEnergy -= 5;
    oldStats.setEnergy(newEnergy);
    pm.setStats(oldStats);
    
    UpdateMeters();
    
}

void Inside_EIS:: PlusEnergy(Ref* pSender)
{
    log("Raise Energeeezzeee");
    int newEnergy;
    PlayerStatsModel oldStats;
    oldStats = pm.getStats();
    
    
    newEnergy = pm.getStats().getEnergy();
    log("%d", newEnergy);
    newEnergy += 5;
    oldStats.setEnergy(newEnergy);
    pm.setStats(oldStats);
    
    UpdateMeters();
}

