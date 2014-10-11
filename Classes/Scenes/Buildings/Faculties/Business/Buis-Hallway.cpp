//
//  Buis-Hallway.cpp
//  UniLife
//
//  Created by csci321ga2a on 8/09/2014.
//
//

#include "Buis-Foyer.h"
#include "Buis-Hallway.h"
#include "Buis-Foyer-Controller.h"
#include "Buis-Hallway-Controller.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "MenuOptionScene.h"
#include <CCTransition.h>
#include <string>
#include <vector>
#include "MapScene.h"
#include "HUDHelper.h"
USING_NS_CC;
extern PlayerModel pm;

Scene* BuisHallway::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = BuisHallway::create();
    
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
bool BuisHallway::init()
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
    BuisHallwayController::CreateMainMenu(this, visibleSize, origin);
    
    return true;
}

void BuisHallway::ToFoyer(Ref* pSender)
{
    log("Going To Buisness Hallway!");
    
    auto scene = BuisFoyer::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
    
}



void BuisHallway::ToLecture(Ref* pSender){
    log("Going To Buisness Lecture!");
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("dorm-door-opening.wav");
    
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


void BuisHallway::ToTutorial(Ref* pSender){
    log("Going To Buisness Tutorial!");
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("dorm-door-opening.wav");
    
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

