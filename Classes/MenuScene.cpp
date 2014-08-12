#include "MenuScene.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
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
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems;
    
    
    // create the new game button and place onto screen
    auto newGameItem = MenuItemImage::create("new_game_off.png",
                                             "new_game_on.png",
                                             CC_CALLBACK_1(MenuScene::newGameCallback, this));
    
    newGameItem->setPosition(Vec2(origin.x + visibleSize.width / 2,
                                  origin.y + (visibleSize.height - newGameItem->getContentSize().height - 120)));
    
    
    // create the load game button and place onto screen
    auto loadGameItem = MenuItemImage::create("load_game_off.png",
                                             "load_game_on.png",
                                             CC_CALLBACK_1(MenuScene::loadGameCallback, this));
    
    loadGameItem->setPosition(Vec2(origin.x + visibleSize.width / 2,
                                  origin.y + (visibleSize.height - loadGameItem->getContentSize().height - newGameItem->getContentSize().height - 140)));
    
    // create the options button and place onto screen
    auto optionsItem = MenuItemImage::create("options_off.png",
                                              "options_on.png",
                                              CC_CALLBACK_1(MenuScene::optionsCallback, this));
    
    optionsItem->setPosition(Vec2(origin.x + visibleSize.width / 2,
                                   origin.y + (visibleSize.height - loadGameItem->getContentSize().height - newGameItem->getContentSize().height - newGameItem->getContentSize().height - 160)));
    
    // add menu items to array
    pMenuItems.pushBack(newGameItem);
    pMenuItems.pushBack(loadGameItem);
    pMenuItems.pushBack(optionsItem);

    // create menu, it's an autorelease object
                          
    auto menu = Menu::createWithArray(pMenuItems);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    // add "MenuScene" splash screen"
    auto sprite = Sprite::create("background.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    sprite = Sprite::create("title.png");
    sprite->setPosition(Vec2(origin.x + visibleSize.width / 2, visibleSize.height / 2 + 250));
    
    this->addChild(sprite, 0);
    
    return true;
}
                          
void MenuScene::quitCallBack(Ref* pSender)
{
    Director::getInstance()->end();
    
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        exit(0);
    #endif
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

void MenuScene::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
