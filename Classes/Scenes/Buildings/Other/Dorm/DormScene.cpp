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
#include "MapScene.h"
#include <vector>
#include <cmath>
#include <sstream>
#include "BrickBreaker.h"
#include "PauseMenu.h"
#include "SimpleAudioEngine.h"
#include "HUDHelper.h"
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
    pm.setStats(inplayer.getStats());
    
    layer->setHUDScene(scene);
    
    // create the HUD
    HUDLayer::createHUD(scene, pm);
    HUDLayer::updateHUD(scene, pm);
    
    
    // Report on the loaded player object
    log("==========PLAYER IN DORM==========");
    log("PLAYER ID: %d", inplayer.getId());
    log("NAME: %s", inplayer.getName().c_str());
    log("INT: %d", inplayer.getStats().getIntelligence());
    log("STA: %d", inplayer.getStats().getStamina());
    log("SOC: %d", inplayer.getStats().getSocial());
    log("DEGREE: %s", inplayer.getDegree().c_str());
    log("ENERGY: %d" , inplayer.getStats().getEnergy());
    log("STRESS: %d", inplayer.getStats().getStress());
    
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
    
    isPaused = false;
    
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
    std::string ampm;
    std::ostringstream stringStream;
    
    TimeHelper th = pm.getGameTime();
    
    // set some local variables for manipulation
    double hour = th.getHoursMinutes() + 0.5;
    int day = th.getDay();
    int week = th.getWeek();
    int semester = th.getSemester();
    
    if( hour > 11.5) // roll over to afternoon
    {
        ampm = "pm";
    }
    else
    {
        ampm = "am";
    }
    
    if(hour > 23.5) // roll over to new day
    {
        hour = 12;
        ampm = "am";
        
        if(day ==  7) // roll over to new week
        {
            day = 1;
            
            if(week == 16) // roll over to new semester
            {
                week = 1;
                
                if(semester == 6) // game over
                {
                    log("...GAME OVER...");
                }
                
                else semester++;
            }
            
            else week++;
        }
        
        else day++;
    }

    stringStream << (int)hour << ":";
    
    if((hour + 0.5) == ceil(hour))
    {
        stringStream << "30" << ampm;
    }
    else
    {
        stringStream << "00" << ampm;
    }
    
    // update the timer with the new time
    this->timer->setString(stringStream.str());
    
    // persist stat changes
    th.setHoursMinutes(hour);
    th.setDay(day);
    th.setWeek(week);
    th.setSemester(semester);
    
    // persist changes to player object
    pm.setGameTime(th);
    
    //Added an update for the HUD Stress & Energy Bars
    HUDLayer::updateHUD(this->getHUDScene(), pm);
    
}

void DormScene::DoorPressed(cocos2d::Ref *pSender)
{
    log("playing the door sound effect");
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("doorOpen.wav");
    log("you have touched the door!");
    // transition to the load game scene
    auto scene = MapScene::createScene(pm);
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
}

void DormScene::BedPressed(cocos2d::Ref *pSender)
{
    log("You will rest and restore all energy and decrease stress by 5");
    
    PlayerStatsModel updateStats;
    TimeHelper newTime;
    updateStats = pm.getStats();
    newTime = pm.getGameTime();
    
    if(updateStats.getStress() > 10)
        updateStats.setStress(updateStats.getStress() - 10);
    else
        updateStats.setStress(0);
    
    updateStats.setEnergy(100);
    newTime.setHoursMinutes(newTime.getHoursMinutes() + 8.0);
    pm.setStats(updateStats);
    pm.setGameTime(newTime);
    
    log("PLAYER ID: %d", pm.getId());
    log("NAME: %s", pm.getName().c_str());
    log("INT: %d", pm.getStats().getIntelligence());
    log("STA: %d", pm.getStats().getStamina());
    log("SOC: %d", pm.getStats().getSocial());
    log("DEGREE: %s", pm.getDegree().c_str());
    log("ENERGY: %d" , pm.getStats().getEnergy());
    log("STRESS: %d", pm.getStats().getStress());
    log("DAY: %d", pm.getGameTime().getDay());
    log("WEEK: %d", pm.getGameTime().getWeek());
    log("SEMESTER: %d", pm.getGameTime().getSemester());
    log("TIME: %f", pm.getGameTime().getHoursMinutes());
    
    HUDLayer::updateHUD(this->getHUDScene(), pm);

}

void DormScene::ShelfPressed(cocos2d::Ref *pSender)
{
    log("You touched the shelf");
}

void DormScene::DeskPressed(cocos2d::Ref *pSender)
{
    log("You touched the desk!");
}

void DormScene::ComputerPressed(cocos2d::Ref *pSender)
{
    log("You touched the computer!");
    // transition to the load game scene
    auto scene = BrickBreaker::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
}

/********************************
            Getters
 *******************************/

PlayerModel DormScene::getPlayer()
{
    return this->player;
}

Scene* DormScene::getHUDScene()
{
    return this->HUDScene;
}

/********************************
            Setters
 *******************************/

void DormScene::setPlayer(PlayerModel player)
{
    this->player = player;
}

void DormScene::setHUDScene(Scene* HUDScene)
{
    this->HUDScene = HUDScene;
}
