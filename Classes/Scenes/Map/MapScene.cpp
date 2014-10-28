//
//  MapScene.cpp
//  UniLife
//
//  Created by csci321ga2a on 8/14/14.
//
//

#include "MapScene.h"
#include "MenuScene.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "MenuController.h"
#include "MenuOptionController.h"
#include "MenuOptionScene.h"
#include <vector>
#include "DormScene.h"
#include "DormController.h"
#include "MapController.h"
#include "Inside_EIS.h"
#include "TavernFoyer.h"
#include "SciMed-Foyer.h"
#include "Buis-Foyer.h"
#include "Art-Foyer.h"
#include "SocSci-Foyer.h"
#include "LibraryFoyer.h"
#include "UniCenterScene.h"
#include "ShopScene.h"
#include "HUDHelper.h"

USING_NS_CC;

extern PlayerModel pm;

Scene* MapScene::createScene()
{
    log("\nCreated Without passed Player\n");
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MapScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    HUDLayer::createHUD(scene);
    
    // return the scene
    return scene;
}

// overloaded createScene to pass in player
Scene* MapScene::createScene(PlayerModel inplayer)
{
    log("\nCreated With passed Player\n");
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MapScene::create(inplayer);
    
    // add layer as a child to scene
    scene->addChild(layer);
    pm = inplayer;
    pm.setStats(inplayer.getStats());
    
    HUDLayer::createHUD(scene);
    
    // return the scene
    return scene;
}

// overloaded create method to take player data
MapScene* MapScene::create(PlayerModel inplayer)
{
    MapScene *ds = new MapScene();
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
bool MapScene::init()
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
    
    // create the dorm scene
    MapController::CreateMapView(this, visibleSize, origin);
    
    
    //HUDLayer::resumeTimer();
    
    return true;
}


void MapScene::GoToDorm(Ref* pSender)
{
    
    HUDLayer::pauseTimer();
    
    auto scene = DormScene::createScene(pm);
    TransitionCrossFade *crosssfade = TransitionCrossFade::create(.5,scene);
    Director::getInstance()->replaceScene(crosssfade);
    
}

void MapScene::GoToEIS(Ref* pSender)
{
    HUDLayer::pauseTimer();
    
    auto scene = Inside_EIS::createScene();
    TransitionCrossFade *crosssfade = TransitionCrossFade::create(.5,scene);
    Director::getInstance()->replaceScene(crosssfade);
    
}

void MapScene::GoToTavern(Ref* pSender)
{
    HUDLayer::pauseTimer();
    
    auto scene = TavernFoyer::createScene();
    TransitionCrossFade *crosssfade = TransitionCrossFade::create(.5,scene);
    Director::getInstance()->replaceScene(crosssfade);
    
}

void MapScene::GoToMedSci(Ref* pSender)
{
    HUDLayer::pauseTimer();
    
    auto scene = SciMedFoyer::createScene();
    TransitionCrossFade *crosssfade = TransitionCrossFade::create(.5,scene);
    Director::getInstance()->replaceScene(crosssfade);
    
}

void MapScene::GoToBuis(Ref* pSender)
{
    HUDLayer::pauseTimer();
    
    auto scene = BuisFoyer::createScene();
    TransitionCrossFade *crosssfade = TransitionCrossFade::create(.5,scene);
    Director::getInstance()->replaceScene(crosssfade);
    
}

void MapScene::GoToArt(Ref* pSender)
{
    HUDLayer::pauseTimer();
    
    auto scene = ArtFoyer::createScene();
    TransitionCrossFade *crosssfade = TransitionCrossFade::create(.5,scene);
    Director::getInstance()->replaceScene(crosssfade);
    
}

void MapScene::GoToSocSci(Ref* pSender)
{
    HUDLayer::pauseTimer();
    
    auto scene = SocSciFoyer::createScene();
    TransitionCrossFade *crosssfade = TransitionCrossFade::create(.5,scene);
    Director::getInstance()->replaceScene(crosssfade);
    
}

void MapScene::GoToLibrary(Ref* pSender)
{
    HUDLayer::pauseTimer();
    
    auto scene = LibraryFoyer::createScene();
    TransitionCrossFade *crosssfade = TransitionCrossFade::create(.5,scene);
    Director::getInstance()->replaceScene(crosssfade);
    
}

void MapScene::GoToShop(Ref* pSender)
{
    HUDLayer::pauseTimer();
    
    auto scene = ShopScene::createScene();
    TransitionCrossFade *crosssfade = TransitionCrossFade::create(.5,scene);
    Director::getInstance()->replaceScene(crosssfade);
    
}

void MapScene::GoToUniCentre(Ref* pSender)
{
    HUDLayer::pauseTimer();
    
    auto scene = UniCenterScene::createScene();
    TransitionCrossFade *crosssfade = TransitionCrossFade::create(.5,scene);
    Director::getInstance()->replaceScene(crosssfade);
    
}

/********************************
            Getters
 *******************************/

PlayerModel MapScene::getPlayer()
{
    return this->player;
}

/********************************
            Setters
 *******************************/

void MapScene::setPlayer(PlayerModel inplayer)
{
    this->player = inplayer;
}
