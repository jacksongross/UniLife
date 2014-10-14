//
//  Art-Foyer.cpp
//  UniLife
//
//  Created by csci321ga2a on 8/09/2014.
//
//

#include "Art-Foyer.h"
#include "Art-Hallway.h"
#include "Art-Foyer-Controller.h"
#include "Art-Hallway-Controller.h"
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

Scene* ArtFoyer::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = ArtFoyer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    layer->setHUDScene(scene);
    
    // create the HUD
    HUDLayer::createHUD(scene);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool ArtFoyer::init()
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
    ArtFoyerController::CreateMainMenu(this, visibleSize, origin);
     
    return true;
}

void ArtFoyer::ToHallway(Ref* pSender)
{
    log("Going To Art Hallway!");
    
    auto scene = ArtHallway::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
    
}


void ArtFoyer::ToMap(Ref* pSender)
{
    log("Going To The Map!");
    
    auto scene = MapScene::createScene(pm);
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
    
}

