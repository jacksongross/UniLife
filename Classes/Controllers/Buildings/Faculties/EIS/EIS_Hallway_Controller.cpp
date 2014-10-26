//
//  EIS_Hallway_Controller.cpp
//  UniLife
//
//  Created by csci321ga2a on 1/09/2014.
//
//

#include "EIS_Hallway_Controller.h"
extern PlayerModel pm;
USING_NS_CC;

// create the buttons for the main menu
cocos2d::Vector<cocos2d::MenuItem*> EIS_Hallway_Controller::CreateMenuButtons(EIS_Hallway *that, Size visibleSize, Vec2 origin)
{
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems;
    
    auto ToFoyer = MenuItemImage::create("Go_Left_Arrow.png","Go_Left_Arrow.png" , CC_CALLBACK_1(EIS_Hallway::ToFoyer, that));
    ToFoyer->setPosition(Vec2(origin.x + visibleSize.width / 2 + 475, origin.y + (visibleSize.height / 2 )));
    ToFoyer->setScale(0.3,0.3);
    ToFoyer->setRotation(180);
    pMenuItems.pushBack(ToFoyer);
    
    
    auto LectDoor = MenuItemImage::create("door.png","door_opened.png" , CC_CALLBACK_1(EIS_Hallway::ToLecture, that));
    LectDoor->setPosition(Vec2(origin.x + visibleSize.width / 2 + 50, origin.y + (visibleSize.height / 2 - 26)));
    LectDoor->setName("lectdoor");
    pMenuItems.pushBack(LectDoor);

    auto TutDoor = MenuItemImage::create("door.png","door_opened.png" , CC_CALLBACK_1(EIS_Hallway::ToTutorial, that));
    TutDoor->setPosition(Vec2(origin.x + visibleSize.width / 2 - 397, origin.y + (visibleSize.height / 2 - 26)));
    TutDoor->setName("tutdoor");
    pMenuItems.pushBack(TutDoor);

    
    
    return pMenuItems;
    
}

// call this method in the main menu scene to create the main menu
void EIS_Hallway_Controller::CreateMainMenu(EIS_Hallway *that, Size visibleSize, Vec2 origin)
{
    log("You Went to the EIS Hallway");
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems = CreateMenuButtons(that, visibleSize, origin);
    
    // create menu, it's an autorelease object
    auto menu = Menu::createWithArray(pMenuItems);
    menu->setPosition(Vec2::ZERO);
    menu->setName("menu");
    that->addChild(menu, 1);
    
    // add "MenuScene" splash screen"
    auto sprite = Sprite::create("EIS_Rooms.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    that->addChild(sprite, 0);
    
    
    
    
}

