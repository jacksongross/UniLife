//
//  LibraryRooms.cpp
//  UniLife
//
//  Created by csci321ga2a on 9/09/2014.
//
//

#include "LibraryRoomsController.h"
#include "LibraryFoyer.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "MenuOptionScene.h"
#include <CCTransition.h>
#include <string>
#include <vector>
#include "MapScene.h"
#include "LogicGame.h"
#include "HUDHelper.h"
USING_NS_CC;
extern PlayerModel pm;

Scene* LibraryRooms::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = LibraryRooms::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool LibraryRooms::init()
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
    LibraryRoomsController::CreateMainMenu(this, visibleSize, origin);
    HUDLayer newHUD;
    newHUD.create(this, pm);
    UpdateMeters(pm.getStats());
    
    return true;
}


void LibraryRooms::UpdateMeters(PlayerStatsModel updateModel)
{
    
    //Added an update for the HUD Stress & Energy Bars
    auto pgTimer = (cocos2d::ProgressTimer*)this->getChildByName("EnergyHUD");
    
    pgTimer->setScaleX(updateModel.getEnergy()/100.0);
    pgTimer->setAnchorPoint(Vec2(0.f,0.5f));
    log("%d",updateModel.getEnergy());
    
    auto pgTimer2 = (cocos2d::ProgressTimer*)this->getChildByName("StressHUD");
    
    pgTimer2->setScaleX(updateModel.getStress()/100.0);
    pgTimer2->setAnchorPoint(Vec2(0.f,0.5f));
    log("%d",updateModel.getStress());
    
}

void LibraryRooms::ToFoyer(Ref* pSender)
{
    log("Going To Library Foyer!");
    
    auto scene = LibraryFoyer::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
    
}


void LibraryRooms::ToMeet1(Ref* pSender){
  
    log("You Went To Meeting Room 1");
    
    
}


void LibraryRooms::ToMeet2(Ref* pSender){
    
    log("You Went To Meeting Room 2");
    
    
}


