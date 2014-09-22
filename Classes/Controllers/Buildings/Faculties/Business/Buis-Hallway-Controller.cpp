//
//  Buis-Hallway-Controller.cpp
//  UniLife
//
//  Created by csci321ga2a on 8/09/2014.
//
//
#include "Buis-Hallway-Controller.h"
extern PlayerModel pm;
USING_NS_CC;

// create the buttons for the main menu
cocos2d::Vector<cocos2d::MenuItem*> BuisHallwayController::CreateMenuButtons(BuisHallway *that, Size visibleSize, Vec2 origin)
{
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems;
    
    auto ToFoyer = MenuItemImage::create("Go_Left_Arrow.png","Go_Left_Arrow.png" , CC_CALLBACK_1(BuisHallway::ToFoyer, that));
    ToFoyer->setPosition(Vec2(origin.x + visibleSize.width / 2 + 475, origin.y + (visibleSize.height / 2 )));
    ToFoyer->setScale(0.3,0.3);
    ToFoyer->setRotation(180);
    pMenuItems.pushBack(ToFoyer);
    
    
    auto LectDoor = MenuItemImage::create("door.png","door_opened.png" , CC_CALLBACK_1(BuisHallway::ToLecture, that));
    LectDoor->setPosition(Vec2(origin.x + visibleSize.width / 2 + 50, origin.y + (visibleSize.height / 2 - 26)));
    pMenuItems.pushBack(LectDoor);
    
    auto TutDoor = MenuItemImage::create("door.png","door_opened.png" , CC_CALLBACK_1(BuisHallway::ToTutorial, that));
    TutDoor->setPosition(Vec2(origin.x + visibleSize.width / 2 - 397, origin.y + (visibleSize.height / 2 - 26)));
    pMenuItems.pushBack(TutDoor);
    
    
    
    return pMenuItems;
    
}

// call this method in the main menu scene to create the main menu
void BuisHallwayController::CreateMainMenu(BuisHallway *that, Size visibleSize, Vec2 origin)
{
    log("You Went to the Buisness Hallway");
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems = CreateMenuButtons(that, visibleSize, origin);
    
    // create menu, it's an autorelease object
    auto menu = Menu::createWithArray(pMenuItems);
    menu->setPosition(Vec2::ZERO);
    that->addChild(menu, 1);
    
    // add "MenuScene" splash screen"
    auto sprite = Sprite::create("Buis_Rooms.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    that->addChild(sprite, 0);
    
    
    
    
    
    
    
}

