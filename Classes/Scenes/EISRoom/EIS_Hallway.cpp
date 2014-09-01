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
    UpdateMeters(pm.getStats());
    
    return true;
}


void EIS_Hallway::UpdateMeters(PlayerStatsModel updateModel)
{
    
    //Added an update for the HUD Stress & Energy Bars
    auto pgTimer = (cocos2d::ProgressTimer*)this->getChildByTag(1);
    
    pgTimer->setScaleX(updateModel.getEnergy()/100.0);
    pgTimer->setAnchorPoint(Vec2(0.f,0.5f));
    log("%d",updateModel.getEnergy());
}

void EIS_Hallway::ToFoyer(Ref* pSender)
{
    log("Going To EIS Foyer!");
    
    auto scene = Inside_EIS::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
    
}