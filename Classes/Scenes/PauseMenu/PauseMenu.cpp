//
//  PauseMenu.cpp
//  UniLife
//
//  Created by Jackson Gross on 11/09/2014.
//
//

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

USING_NS_CC;

extern PlayerModel pm;

Scene* PauseMenu::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = PauseMenu::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems;
    
    auto label = Label::createWithSystemFont("Game Paused", "Helvetica", 74);
    
    label->setColor(Color3B(0, 0, 0));
    
    label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 0.90));
    
    layer->addChild(label, 0);
    
    ui::Text* resumeButton = ui::Text::create("Resume", "Arial", 88);
    resumeButton->addTouchEventListener(CC_CALLBACK_1(PauseMenu::resumeCallback, layer));
    resumeButton->setColor(Color3B::BLACK);
    resumeButton->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    resumeButton->setTouchEnabled(true);
    layer->addChild(resumeButton,5);
    
    ui::Text* saveButton = ui::Text::create("Save Game", "Arial", 88);
    saveButton->addTouchEventListener(CC_CALLBACK_1(PauseMenu::saveCallback, layer));
    saveButton->setColor(Color3B::BLACK);
    saveButton->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 * 0.60));
    saveButton->setTouchEnabled(true);
    layer->addChild(saveButton,5);
    
    ui::Text* quitButton = ui::Text::create("Quit Game", "Arial", 88);
    quitButton->addTouchEventListener(CC_CALLBACK_1(PauseMenu::quitCallback, layer));
    quitButton->setColor(Color3B::BLACK);
    quitButton->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 * 0.20));
    quitButton->setTouchEnabled(true);
    layer->addChild(quitButton,5);
    
    auto menu = Menu::createWithArray(pMenuItems);
    menu->setPosition(Vec2::ZERO);
    layer->addChild(menu, 1);

    
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool PauseMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if( !LayerColor::initWithColor(Color4B(255,255,255,100)) )
    {
        return false;
    }
    
    // this is needed so that all layers below the pause screen layer
    // don't take touch events!!
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(PauseMenu::touchBegan, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    return true;
}

// handles touches on the pause layer
bool PauseMenu::touchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
    log("touches on the layer!");
    return true;
}

void PauseMenu::resumeCallback(cocos2d::Ref *pSender)
{
    log("you have touched the resume button!");
    
    this->getParent()->removeChild(this);
    
    Director::getInstance()->resume();
}

void PauseMenu::saveCallback(cocos2d::Ref *pSender)
{
    log("you have touched the save button!");
    
    if(pm.getId() > 0)
    {
        SqlHelper::autosave(pm);
    }
    else
    {
        log("First time saving game!");
        SqlHelper::serialize(pm);
    }
    
    log("game saved!");
    
}

void PauseMenu::quitCallback(cocos2d::Ref *pSender)
{
    log("you have touched the quit button!");
    
    Director::getInstance()->resume();
    auto scene = MenuScene::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);

}



