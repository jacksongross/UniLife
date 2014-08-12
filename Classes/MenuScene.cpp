#include "MenuScene.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "MenuController.h"
#include <vector>

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
    
    std::stringstream strm;
    
    // run this once to create and seed tables
    SqlHelper::initDatabase();
    
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
}

void MenuScene::loadGameCallback(Ref* pSender)
{
    log("load game button pressed!");
}

void MenuScene::optionsCallback(Ref* pSender)
{
    log("options button pressed!");
}
