//
//  Inside_EIS.cpp
//  UniLife
//
//  Created by csci321ga2a on 28/08/2014.
//
//

#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "Inside_EIS_Controller.h"
#include "EIS_Hallway.h"
#include "MenuOptionScene.h"
#include <CCTransition.h>
#include <string>
#include <vector>
#include "MapScene.h"

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
    UpdateMeters(pm.getStats());
    
    return true;
}


void Inside_EIS::UpdateMeters(PlayerStatsModel updateModel)
{

    //Added an update for the HUD Stress & Energy Bars
    auto pgTimer = (cocos2d::ProgressTimer*)this->getChildByTag(1);

        pgTimer->setScaleX(updateModel.getEnergy()/100.0);
        pgTimer->setAnchorPoint(Vec2(0.f,0.5f));
        log("%d",updateModel.getEnergy());
    
    auto pgTimer2 = (cocos2d::ProgressTimer*)this->getChildByTag(2);
    
      pgTimer2->setScaleX(updateModel.getStress()/100.0);
      pgTimer2->setAnchorPoint(Vec2(0.f,0.5f));
      log("%d",updateModel.getStress());
    
}

void Inside_EIS::ToHallway(Ref* pSender)
{
    log("Going To EIS Hallway!");
    
    auto scene = EIS_Hallway::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
    
}


void Inside_EIS::ToMap(Ref* pSender)
{
    log("Going To The Map!");
    
    auto scene = MapScene::createScene(pm);
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
    
}


