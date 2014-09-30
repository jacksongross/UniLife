
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
#include "MenuLoadScene.h"
#include "SimpleAudioEngine.h"

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
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("background-music-aac.wav", true);
    
    
    //REMOVE THIS TO ACTIVATE SOUND
    CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0);
    //REMOVE THIS TO ACTIVATE SOUND
    
    
    // checks if the database initialisation has been run before
    // to ensure it gets seeded once
    bool isSeeded = UserDefault::getInstance()->getBoolForKey("seeded");
    
    if(isSeeded == false)
    {
        log("seeding the database!");
        SqlHelper::initDatabase();
        UserDefault::getInstance()->setBoolForKey("seeded", true);
    }
    
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
    TransitionPageTurn *crosssfade = CCTransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
}

void MenuScene::loadGameCallback(Ref* pSender)
{
    log("load game button pressed!");
    
    // transition to the load game scene
    auto scene = MenuLoadScene::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
}

void MenuScene::optionsCallback(Ref* pSender)
{
    log("options button pressed!");
    
    // transition to the menu options scene
    
    auto scene = MenuOptionScene::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
    
}
