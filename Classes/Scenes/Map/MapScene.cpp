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
USING_NS_CC;

Scene* MapScene::createScene()
{
    log("\nCreated Without passed Player\n");
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MapScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
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
    
    
    // Report on the loaded player object
    log("==========PLAYER IN MAP==========");
    log("NAME: %s", inplayer.getName().c_str());
    log("INT: %d", inplayer.getStats().getIntelligence());
    log("STA: %d", inplayer.getStats().getStamina());
    log("SOC: %d", inplayer.getStats().getSocial());
    log("DEGREE: %s", inplayer.getDegree().c_str());
    
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
    
    return true;
}


void MapScene::GoToDorm(Ref* pSender)
{
    log("Going Back to Menu!");
    
    auto scene = DormScene::createScene(player);
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
    
}

void MapScene::GoToEIS(Ref* pSender)
{
    log("Going To Inside EIS Building!");
    
    auto scene = Inside_EIS::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
    
}

void MapScene::GoToTavern(Ref* pSender)
{
    log("Going To Tavern!");
    
    auto scene = TavernFoyer::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
    
}

void MapScene::GoToMedSci(Ref* pSender)
{
    log("Going To SciMed!");
    
    auto scene = SciMedFoyer::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
    
}

void MapScene::GoToBuis(Ref* pSender)
{
    log("Going To Buisness!");
    
    auto scene = BuisFoyer::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
    
}

void MapScene::GoToArt(Ref* pSender)
{
    log("Going To Art!");
    
    auto scene = ArtFoyer::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
    
}

void MapScene::GoToSocSci(Ref* pSender)
{
    log("Going To Social Science!");
    
    auto scene = SocSciFoyer::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
    
}

void MapScene::GoToLibrary(Ref* pSender)
{
    log("Going To Library!");
    
    //auto scene = SocSciFoyer::createScene();
    //TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    //Director::getInstance()->replaceScene(crosssfade);
    
}

void MapScene::GoToShop(Ref* pSender)
{
    log("Going To Shop!");
    
    //auto scene = SocSciFoyer::createScene();
    //TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    //Director::getInstance()->replaceScene(crosssfade);
    
}

void MapScene::GoToUniCentre(Ref* pSender)
{
    log("Going To UniCentre!");
    
    //auto scene = SocSciFoyer::createScene();
    //TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    //Director::getInstance()->replaceScene(crosssfade);
    
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
