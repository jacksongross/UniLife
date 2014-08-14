#include "MenuScene.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "MenuController.h"
#include "MenuOptionScene.h"
#include "MenuNewGame.h"
#include <CCTransition.h>
#include <vector>
#include "DormScene.h"

USING_NS_CC;

Scene* MenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    // run this once to create and seed tables
    //SqlHelper::initDatabase();
    
    // get a list of all players in the database
    std::vector<PlayerModel> playersList = SqlHelper::getAllPlayers();

    // get a specific player
    PlayerModel p = SqlHelper::getPlayer(1);
    
    // get the size of the screen that is visible
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    // create the main menu
    MenuController::CreateMainMenu(this, visibleSize, origin);
    
    return true;
}
                             
void MenuScene::newGameCallback(Ref* pSender)
{
    log("new game button pressed!");
    auto scene = MenuNewGame::createScene();
    CCTransitionPageTurn *crosssfade = CCTransitionPageTurn::create(1,scene, true);
    CCDirector::sharedDirector()->replaceScene(crosssfade);
}

void MenuScene::loadGameCallback(Ref* pSender)
{
    log("load game button pressed!");
    
    // transition to the load game scene
    auto scene = MenuOptionScene::createScene();
    CCTransitionPageTurn *crosssfade = CCTransitionPageTurn::create(1,scene, true);
    CCDirector::sharedDirector()->replaceScene(crosssfade);
}

void MenuScene::optionsCallback(Ref* pSender)
{
    log("options button pressed!");
    
    // transition to the menu options scene
    
    PlayerModel p;
    p.setName("Jackson Gross");
    
    log(p.getName().c_str());
    
    auto scene = DormScene::createScene(p);
    CCTransitionPageTurn *crosssfade = CCTransitionPageTurn::create(1,scene, true);
    CCDirector::sharedDirector()->replaceScene(crosssfade);
    
}
