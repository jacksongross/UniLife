//
//  EIS_Hallway.cpp
//  UniLife
//
//  Created by csci321ga2a on 1/09/2014.
//
//

#include "EIS_Hallway.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "EIS_Hallway_Controller.h"
#include "MenuOptionScene.h"
#include <CCTransition.h>
#include <string>
#include <vector>
#include "MapScene.h"
#include "HUDHelper.h"

USING_NS_CC;
extern PlayerModel pm;

Scene* EIS_Hallway::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = EIS_Hallway::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    layer->setHUDScene(scene);
    
    // create the HUD
    HUDLayer::createHUD(scene);
    HUDLayer::updateHUD(pm);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool EIS_Hallway::init()
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
    EIS_Hallway_Controller::CreateMainMenu(this, visibleSize, origin);
    
    return true;
}

void EIS_Hallway::ToFoyer(Ref* pSender)
{
    log("Going To EIS Foyer!");
    
    auto scene = Inside_EIS::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
    
}


void EIS_Hallway::ToLecture(Ref* pSender){
    log("Going To EIS Lecture!");
    
    //Temporary Code for Debugging Purposes
    if(pm.getStats().getEnergy() < 5){
        log("Not Enough Energy To Go To A Lecture");
    }else if(pm.getStats().getStress() > 95){
        log("You are so Stressed, Man. I Think You Should Go Home & Relax.");
    }else{
        log("You Went To A Lecture (+1 INT, +10 Stress)");
        
        PlayerStatsModel updateStats;
        updateStats = pm.getStats();
        
        updateStats.setIntelligence(updateStats.getIntelligence() + 1);
        updateStats.setStress(updateStats.getStress() + 10);
        updateStats.setEnergy(updateStats.getEnergy() - 5);
        pm.setStats(updateStats);
        HUDLayer::updateHUD(pm);
    }
    
    
    
}


void EIS_Hallway::ToTutorial(Ref* pSender){
    log("Going To EIS Tutorial!");
    
    //Temporary Code for Debugging Purposes
    if(pm.getStats().getEnergy() < 5){
        log("Not Enough Energy To Go To A Lecture");
    }else if(pm.getStats().getStress() > 95){
        log("You are so Stressed, Man. I Think You Should Go Home & Relax.");
    }else{
        log("You Went To A Lecture (+1 INT, +10 Stress)");
        PlayerStatsModel updateStats;
        updateStats = pm.getStats();
        
        updateStats.setIntelligence(updateStats.getIntelligence() + 1);
        updateStats.setStress(updateStats.getStress() + 10);
        updateStats.setEnergy(updateStats.getEnergy() - 5);
        pm.setStats(updateStats);
        HUDLayer::updateHUD(pm);
    }
    
    
    
}


