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
    
    
    // create the new game button and place onto screen
    auto resumeButton = MenuItemImage::create("new_game_off.png",
                                             "new_game_on.png",
                                             CC_CALLBACK_1(PauseMenu::resumeCallback, this));
    
    resumeButton->setPosition(Vec2(visibleSize.width / 2,
                                  visibleSize.height / 2));
    
    auto saveButton = MenuItemImage::create("new_game_off.png",
                                              "new_game_on.png",
                                              CC_CALLBACK_1(PauseMenu::saveCallback, this));
    
    saveButton->setPosition(Vec2(visibleSize.width / 2,
                                   visibleSize.height / 2 + 120));
    
    pMenuItems.pushBack(resumeButton);
    pMenuItems.pushBack(saveButton);
    
    auto menu = Menu::createWithArray(pMenuItems);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    

    
    return true;
}

void PauseMenu::resumeCallback(cocos2d::Ref *pSender)
{
    log("you have touched the resume button!");
    // transition to the load game scene
    //auto scene = MapScene::createScene(pm);
    //TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    //Director::getInstance()->replaceScene(crosssfade);
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



