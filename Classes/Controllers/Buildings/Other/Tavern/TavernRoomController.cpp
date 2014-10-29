//
//  TavernRoomController.cpp
//  UniLife
//
//  Created by csci321ga2a on 8/09/2014.
//
//

#include "TavernRoomController.h"
extern PlayerModel pm;

// create the buttons for the main menu
cocos2d::Vector<cocos2d::MenuItem*> TavernRoomController::CreateMenuButtons(TavernRoom *that, Size visibleSize, Vec2 origin)
{
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems;
    
    
    auto ToFoyer = MenuItemImage::create("Go_Left_Arrow.png","Go_Left_Arrow.png" , CC_CALLBACK_1(TavernRoom::ToFoyer, that));
    ToFoyer->setPosition(Vec2(origin.x + visibleSize.width / 2 - 450, origin.y + (visibleSize.height / 2)));
    ToFoyer->setScale(0.25);
    pMenuItems.pushBack(ToFoyer);
    
    
    return pMenuItems;
    
}

// call this method in the main menu scene to create the main menu
void TavernRoomController::CreateMainMenu(TavernRoom *that, Size visibleSize, Vec2 origin)
{
    log("You Went to the EIS Foyer");
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems = CreateMenuButtons(that, visibleSize, origin);
    
    // create menu, it's an autorelease object
    auto menu = Menu::createWithArray(pMenuItems);
    menu->setPosition(Vec2::ZERO);
    that->addChild(menu, 1);
    
    // add "MenuScene" splash screen"
    auto sprite = Sprite::create("Tavern_background.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    that->addChild(sprite, 0);
    
    // pool table
    
    auto poolNPC = Sprite::create("fred_pool.png");
    poolNPC->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    that->addChild(poolNPC, 1);
    
    auto pooltable = Sprite::create("pool_table.png");
    pooltable->setPosition(Vec2(visibleSize.width * .35, visibleSize.height * .25));
    that->addChild(pooltable, 2);
    
    // dart board
    auto dartboard = Sprite::create("dartboard.png");
    dartboard->setPosition(Vec2(visibleSize.width * 0.8, visibleSize.height * 0.6));
    that->addChild(dartboard, 2);
}


