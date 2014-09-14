//
//  PauseMenu.cpp
//  UniLife
//
//  Created by Jackson Gross on 11/09/2014.
//
//

#include "PauseMenu.h"
#include "GameView.h"
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
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems;
    
    auto bg = Sprite::create("background.png");
    
    // position the sprite on the center of the screen
    bg->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
    
    // add the sprite as a child to this layer
    this->addChild(bg, 0);
    
    auto label = Label::createWithSystemFont("Game Paused", "Helvetica", 74);
    
    label->setColor(Color3B(0, 0, 0));
    
    label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 0.90));
    
    this->addChild(label, 0);
    
    
    auto resumeButton = MenuItemFont::create("Resume", CC_CALLBACK_1(PauseMenu::resumeCallback, this));
    
    auto saveButton = MenuItemFont::create("Save Game", CC_CALLBACK_1(PauseMenu::saveCallback, this));
    
    auto quitButton = MenuItemFont::create("Quit Game", CC_CALLBACK_1(PauseMenu::quitCallback, this));
    
    resumeButton->setFontSize(88);
    
    saveButton->setFontSize(88);
    
    quitButton->setFontSize(88);
    
    resumeButton->setColor(Color3B(0, 0, 0));
    
    saveButton->setColor(Color3B(0, 0, 0));
    
    quitButton->setColor(Color3B(0, 0, 0));
    
    resumeButton->setPosition(Vec2(visibleSize.width / 2,
                                   visibleSize.height / 2));
    
    saveButton->setPosition(Vec2(visibleSize.width / 2,
                                 visibleSize.height / 2 * 0.60));
    
    quitButton->setPosition(Vec2(visibleSize.width / 2,
                                 visibleSize.height / 2 * 0.20));
    
    
    
    pMenuItems.pushBack(resumeButton);
    pMenuItems.pushBack(saveButton);
    pMenuItems.pushBack(quitButton);
    
    auto menu = Menu::createWithArray(pMenuItems);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    

    
    return true;
}

void PauseMenu::resumeCallback(cocos2d::Ref *pSender)
{
    log("you have touched the resume button!");
    Director::getInstance()->popScene();
    Director::getInstance()->resume();
}

void PauseMenu::saveCallback(cocos2d::Ref *pSender)
{
    log("you have touched the save button!");
    
    SqlHelper::serialize(pm);
    
    log("game saved!");
    
    
    // transition to the load game scene
    //auto scene = MapScene::createScene(pm);
    //TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    //Director::getInstance()->replaceScene(crosssfade);
    //Director::getInstance()->popScene();
    //Director::getInstance()->resume();
}

void PauseMenu::quitCallback(cocos2d::Ref *pSender)
{
    log("you have touched the quit button!");
    
    Director::getInstance()->resume();
    auto scene = MenuScene::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);

}



