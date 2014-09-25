//
//  SocSci-Hallway.cpp
//  UniLife
//
//  Created by csci321ga2a on 8/09/2014.
//
//

#include "SocSci-Foyer.h"
#include "SocSci-Hallway.h"
#include "SocSci-Foyer-Controller.h"
#include "SocSci-Hallway-Controller.h"
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

Scene* SocSciHallway::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = SocSciHallway::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    layer->setHUDScene(scene);
    
    // create the HUD
    HUDLayer::createHUD(scene, pm);
    HUDLayer::updateHUD(scene, pm);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SocSciHallway::init()
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
    SocSciHallwayController::CreateMainMenu(this, visibleSize, origin);
    
    return true;
}

void SocSciHallway::ToFoyer(Ref* pSender)
{
    log("Going To Buisness Hallway!");
    
    auto scene = SocSciFoyer::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
    
}



void SocSciHallway::ToLecture(Ref* pSender){
    log("Going To Buisness Lecture!");
    
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
        HUDLayer::updateHUD(this->getHUDScene(), pm);
    }
    
    
    
}


void SocSciHallway::ToTutorial(Ref* pSender){
    log("Going To Buisness Tutorial!");
    
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
        HUDLayer::updateHUD(this->getHUDScene(), pm);
    }
    
    
    
}

