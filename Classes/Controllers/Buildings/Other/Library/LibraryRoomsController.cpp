//
//  LibraryRoomsController.cpp
//  UniLife
//
//  Created by csci321ga2a on 9/09/2014.
//
//

#include "LibraryRoomsController.h"
extern PlayerModel pm;
USING_NS_CC;

// create the buttons for the main menu
cocos2d::Vector<cocos2d::MenuItem*> LibraryRoomsController::CreateMenuButtons(LibraryRooms *that, Size visibleSize, Vec2 origin)
{
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems;
    
    auto ToFoyer = MenuItemImage::create("Go_Left_Arrow.png","Go_Left_Arrow.png" , CC_CALLBACK_1(LibraryRooms::ToFoyer, that));
    ToFoyer->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + (visibleSize.height / 2 + 275)));
    ToFoyer->setScale(0.3,0.3);
    ToFoyer->setRotation(180);
    pMenuItems.pushBack(ToFoyer);
    
    
    auto LectDoor = MenuItemImage::create("door.png","door_opened.png" , CC_CALLBACK_1(LibraryRooms::ToMeet1, that));
    LectDoor->setPosition(Vec2(origin.x + visibleSize.width / 2 + 424, origin.y + (visibleSize.height / 2 - 10)));
    pMenuItems.pushBack(LectDoor);
    
    auto TutDoor = MenuItemImage::create("door.png","door_opened.png" , CC_CALLBACK_1(LibraryRooms::ToMeet2, that));
    TutDoor->setPosition(Vec2(origin.x + visibleSize.width / 2 - 422, origin.y + (visibleSize.height / 2 - 10)));
    pMenuItems.pushBack(TutDoor);
    
    
    
    return pMenuItems;
    
}

// call this method in the main menu scene to create the main menu
void LibraryRoomsController::CreateMainMenu(LibraryRooms *that, Size visibleSize, Vec2 origin)
{
    log("You Went to the Library Meeting Rooms");
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems = CreateMenuButtons(that, visibleSize, origin);
    
    // create menu, it's an autorelease object
    auto menu = Menu::createWithArray(pMenuItems);
    menu->setPosition(Vec2::ZERO);
    that->addChild(menu, 1);
    
    // add "MenuScene" splash screen"
    auto sprite = Sprite::create("Library_Rooms.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    that->addChild(sprite, 0);
    
    
    
}

