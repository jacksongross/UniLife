//
//  SciMed-Foyer.cpp
//  UniLife
//
//  Created by csci321ga2a on 8/09/2014.
//
//

#include "SciMed-Foyer.h"
#include "SciMed-Hallway.h"
#include "SciMed-Foyer-Controller.h"
#include "SciMed-Hallway-Controller.h"
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

Scene* SciMedFoyer::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = SciMedFoyer::create();
    
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
bool SciMedFoyer::init()
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
    SciMedFoyerController::CreateMainMenu(this, visibleSize, origin);
    
    return true;
}

void SciMedFoyer::ToHallway(Ref* pSender)
{
    log("Going To SciMed Hallway!");
    
    auto scene = SciMedHallway::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
    
}


void SciMedFoyer::ToMap(Ref* pSender)
{
    log("Going To The Map!");
    
    auto scene = MapScene::createScene(pm);
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
    
}

