//
//  TavernFoyerController.cpp
//  UniLife
//
//  Created by csci321ga2a on 1/09/2014.
//
//

#include "TavernFoyerController.h"
extern PlayerModel pm;
// create the buttons for the main menu
cocos2d::Vector<cocos2d::MenuItem*> TavernFoyerController::CreateMenuButtons(TavernFoyer *that, Size visibleSize, Vec2 origin)
{
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems;
    
    
    auto ToMap = MenuItemImage::create("map_background.png","map_background.png" , CC_CALLBACK_1(TavernFoyer::ToMap, that));
    ToMap->setPosition(Vec2(origin.x + visibleSize.width / 2 + 450, origin.y + (visibleSize.height / 2 + 275)));
    ToMap->setScale(0.15);
    pMenuItems.pushBack(ToMap);
    
    
    auto ToTavernRoom = MenuItemImage::create("Go_Left_Arrow.png","Go_Left_Arrow.png" , CC_CALLBACK_1(TavernFoyer::ToTavernRoom, that));
    ToTavernRoom->setPosition(Vec2(origin.x + visibleSize.width / 2 + 450 , origin.y + (visibleSize.height / 2 )));
    ToTavernRoom->setScale(0.25);
    ToTavernRoom->setRotation(180.0);
    pMenuItems.pushBack(ToTavernRoom);
    
    return pMenuItems;
    
}

// call this method in the main menu scene to create the main menu
void TavernFoyerController::CreateMainMenu(TavernFoyer *that, Size visibleSize, Vec2 origin)
{
    log("You Went to the EIS Foyer");
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems = CreateMenuButtons(that, visibleSize, origin);
    
    // create menu, it's an autorelease object
    auto menu = Menu::createWithArray(pMenuItems);
    menu->setPosition(Vec2::ZERO);
    that->addChild(menu, 3);
    
    // add "MenuScene" splash screen"
    auto sprite = Sprite::create("Tavern_background.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    that->addChild(sprite, 0);
    
    
    
    auto ToTavernRoom = MenuItemImage::create("Go_Left_Arrow.png","Go_Left_Arrow.png" , CC_CALLBACK_1(TavernFoyer::ToTavernRoom, that));
    ToTavernRoom->setPosition(Vec2(origin.x + visibleSize.width / 2 + 450 , origin.y + (visibleSize.height / 2 )));
    ToTavernRoom->setScale(0.25);
    ToTavernRoom->setRotation(180.0);
    pMenuItems.pushBack(ToTavernRoom);
    
    
    Sprite* barCounter = Sprite::create("Tavern_bar.png");
    barCounter->setPosition(Vec2(origin.x + visibleSize.width / 2 - 340, origin.y + visibleSize.height / 2 - 40 ));
    that->addChild(barCounter);
    
    
    Sprite* barTable = Sprite::create("Tavern_table.png");
    barTable->setPosition(Vec2(origin.x + visibleSize.width / 2 + 260, origin.y + visibleSize.height / 2 - 80));
    that->addChild(barTable,2);
    
    Sprite* barCouches = Sprite::create("Tavern_couches.png");
    barCouches->setPosition(Vec2(origin.x + visibleSize.width / 2 + 260, origin.y + visibleSize.height / 2 - 60));
    that->addChild(barCouches,1);
    
    
    
    
}


