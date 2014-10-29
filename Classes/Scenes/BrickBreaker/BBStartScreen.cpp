//
//  BBStartScreen.cpp
//  UniLife
//
//  Created by Jackson Gross on 16/10/2014.
//
//

#include "BBStartScreen.h"
#include "PauseMenu.h"
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
#include "box2D/box2D.h"
#include "HUDHelper.h"
#include "BrickBreaker.h"

USING_NS_CC;

cocos2d::Scene* BBStartScreen::createScene()
{
    // 'scene' is an autorelease object
    auto scene = cocos2d::Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = BBStartScreen::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    
    auto bg = Sprite::create("brickbreaker-bg.jpg");
    
    bg->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    
    layer->addChild(bg);
    
    
    auto label = cocos2d::Label::createWithSystemFont("Brick Breaker", "Helvetica", 74);
    
    //label->setColor(cocos2d::Color3B(0, 0, 0));
    
    label->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height * 0.90));
    
    layer->addChild(label, 0);
    
    ui::Text* playButton = cocos2d::ui::Text::create("Play", "Arial", 88);
    
    playButton->addTouchEventListener(CC_CALLBACK_1(BBStartScreen::playCallback, layer));
    //playButton->setColor(cocos2d::Color3B::BLACK);
    playButton->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    playButton->setTouchEnabled(true);
    layer->addChild(playButton, 5);
    
    ui::Text* quitButton = ui::Text::create("Quit", "Arial", 88);
    quitButton->addTouchEventListener(CC_CALLBACK_1(BBStartScreen::quitCallback, layer));
    //quitButton->setColor(cocos2d::Color3B::BLACK);
    quitButton->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 * 0.60));
    quitButton->setTouchEnabled(true);
    layer->addChild(quitButton, 5);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool BBStartScreen::init()
{
    //////////////////////////////
    // 1. super init first
    if( !LayerColor::initWithColor(Color4B(255,255,255,255)) )
    {
        return false;
    }
    
    // this is needed so that all layers below the pause screen layer
    // don't take touch events!!
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(BBStartScreen::touchBegan, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    return true;
}

// handles touches on the pause layer
bool BBStartScreen::touchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
    return true;
}

void BBStartScreen::playCallback(cocos2d::Ref *pSender)
{
    
    // transition to the load game scene
    auto scene = BrickBreaker::createScene();
    TransitionCrossFade *crossfade = TransitionCrossFade::create(0.5, scene);
    Director::getInstance()->replaceScene(crossfade);
    
}

void BBStartScreen::quitCallback(cocos2d::Ref *pSender)
{
    auto scene = DormScene::createScene();
    TransitionCrossFade *crosssfade = TransitionCrossFade::create(.5,scene);
    Director::getInstance()->replaceScene(crosssfade);

}