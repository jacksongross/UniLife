#include "QDGameOverScene.h"
#include "QDGameScene.h"
#include "QDMainMenuScene.h"
#include "QDDefinitions.h"
#include "Debugger.h"
#include "MapScene.h"

USING_NS_CC;

unsigned int score;

Scene* QDGameOverScene::createScene(unsigned int tempScore)
{
    
    score = tempScore;
    
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = QDGameOverScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool QDGameOverScene::init()
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
    
    auto mainMenuItem = MenuItemImage::create("QuackyDuck/Menu Button.png", "QuackyDuck/Menu Button Clicked.png", CC_CALLBACK_1(QDGameOverScene::GoToMainMenuScene, this));
    mainMenuItem->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/4 * 1));
    
    //auto menu = Menu::create(retryItem, mainMenuItem, NULL);
    auto menu = Menu::create(mainMenuItem, NULL);

    menu->setPosition(Point::ZERO);
    
    this->addChild(menu);
    
    __String *tempScoreString = __String::createWithFormat( "%i", score );

    auto currentScore = Label::createWithTTF( tempScoreString->getCString( ), "QuackyDuck/Marker Felt.ttf", visibleSize.height * SCORE_FONT_SIZE );
    currentScore->setColor(Color3B::RED);
    currentScore->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height /2 + origin.y ) );
    
    this->addChild(currentScore);
    
    return true;
}

void QDGameOverScene::GoToMainMenuScene(cocos2d::Ref *pSender)
{
    auto scene = MapScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}


