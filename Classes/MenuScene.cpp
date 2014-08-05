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
    
    for(int i=0; i < playersList.size(); i++)
    {
        strm << "Player data: " << playersList[i].getName() << "','" << playersList[i].getDegree() << "'," << playersList[i].getStats().getIntelligence() << "," << playersList[i].getStats().getStamina() << "," << playersList[i].getStats().getSocial() << "," << playersList[i].getStats().getMoney() << "," << playersList[i].getStats().getEnergy() << "," << playersList[i].getStats().getStress() << ",'" << playersList[i].getScene() << "'," << playersList[i].getGameTime().getDay() << "," << playersList[i].getGameTime().getWeek() << "," << playersList[i].getGameTime().getSemester() << "," << playersList[i].getGameTime().getHoursMinutes() << ")";
        
        std::string sql = strm.str();
        strm.clear();
        
        cocos2d::log(sql.c_str());
        cocos2d::log("\n");
    }
    
    // get a specific player
    PlayerModel p = SqlHelper::getPlayer(8);
    
    strm << "Player data: " << p.getName() << "','" << p.getDegree() << "'," << p.getStats().getIntelligence() << "," << p.getStats().getStamina() << "," << p.getStats().getSocial() << "," << p.getStats().getMoney() << "," << p.getStats().getEnergy() << "," << p.getStats().getStress() << ",'" << p.getScene() << "'," << p.getGameTime().getDay() << "," << p.getGameTime().getWeek() << "," << p.getGameTime().getSemester() << "," << p.getGameTime().getHoursMinutes() << ")";
    
    std::string sql = strm.str();
    
    cocos2d::log(sql.c_str());
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems;
    
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(MenuScene::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
    
    auto quitItem = MenuItemFont::create("Quit the Game", CC_CALLBACK_1(MenuScene::quitCallBack, this));
    
    quitItem->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2 - quitItem->getContentSize().height - 200));
                          
                          
    // add menu items to array
    pMenuItems.pushBack(quitItem);

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
    exit(0);
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
