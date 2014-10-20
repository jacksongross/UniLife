#include "QDMainMenuScene.h"
#include "QDGameScene.h"
#include "QDDefinitions.h"
USING_NS_CC;

Scene* QDMainMenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = QDMainMenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool QDMainMenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto backgroundSprite = Sprite::create("QuackyDuck/Background.png");
    backgroundSprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    this->addChild(backgroundSprite);

    auto titleSprite = Sprite::create( "QuackyDuck/Title.png" );
    titleSprite->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height - titleSprite->getContentSize( ).height ) );
    
    this->addChild( titleSprite );
    
    auto playItem = MenuItemImage::create("QuackyDuck/Play Button.png", "QuackyDuck/Play Button Clicked.png", CC_CALLBACK_1(QDMainMenuScene::GoToGameScene, this));
    playItem->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    auto menu = Menu::create(playItem, NULL);
    menu->setPosition(Point::ZERO);
    
    this->addChild(menu);
    
    return true;
}

void QDMainMenuScene::GoToGameScene(cocos2d::Ref *pSender)
{
    auto scene = QDGameScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create( TRANSITION_TIME, scene));
    
    
}