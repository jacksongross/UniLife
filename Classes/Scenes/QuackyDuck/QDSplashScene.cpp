#include "QDSplashScene.h"
#include "QDMainMenuScene.h"
#include "QDDefinitions.h"
USING_NS_CC;

Scene* QDSplashScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = QDSplashScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool QDSplashScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //Load splash screen
    this->scheduleOnce(schedule_selector(QDSplashScene::GoToMainMenuScene), DISPLAY_TIME_SPLASH_SCENE);
    
    auto backgroundSprite = Sprite::create("QuackyDuck/Splash Scene.png");
    backgroundSprite->setPosition(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y);
    
    this->addChild(backgroundSprite);
    
    return true;
}

void QDSplashScene::GoToMainMenuScene(float dt)
{
    auto scene = QDMainMenuScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
    
    
}