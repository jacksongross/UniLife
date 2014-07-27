#include "HelloWorldScene.h"
#include "sqlite3.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    // create and open the db
    cocos2d::CCFileUtils *file;
    
    std::string path = file->getWritablePath() + "save.db3";
    
    sqlite3 *pdb=NULL;
    
    std::string sql;
    int result;
    result=sqlite3_open(path.c_str(),&pdb);
    if(result!=SQLITE_OK)
        log("open database failed,  number%d",result);
    
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems;
    
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
    
    auto quitItem = MenuItemFont::create("Quit the Game", CC_CALLBACK_1(HelloWorld::quitCallBack, this));
    
    quitItem->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - quitItem->getContentSize().height));
                          
                          
    // add menu items to array
    pMenuItems.pushBack(quitItem);

    // create menu, it's an autorelease object
                          
    auto menu = Menu::createWithArray(pMenuItems);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("Menu-bg.jpg");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width + origin.x, visibleSize.height + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    return true;
}
                          
void HelloWorld::quitCallBack(Ref* pSender)
{
    Director::getInstance()->end();
    exit(0);
}


void HelloWorld::menuCloseCallback(Ref* pSender)
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
