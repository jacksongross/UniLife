//
//  LibraryFoyerController.cpp
//  UniLife
//
//  Created by csci321ga2a on 9/09/2014.
//
//

#include "LibraryFoyerController.h"

extern PlayerModel pm;
// create the buttons for the main menu
cocos2d::Vector<cocos2d::MenuItem*> LibraryFoyerController::CreateMenuButtons(LibraryFoyer *that, Size visibleSize, Vec2 origin)
{
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems;
    
    
    auto ToMap = MenuItemImage::create("Map-marker.png","Map-marker.png" , CC_CALLBACK_1(LibraryFoyer::ToMap, that));
    ToMap->setPosition(Vec2(visibleSize.width * 0.8, visibleSize.height * 0.9 ));
    ToMap->setScale(0.85);
    pMenuItems.pushBack(ToMap);
    
    
    auto ToTavernRoom = MenuItemImage::create("Go_Left_Arrow.png","Go_Left_Arrow.png" , CC_CALLBACK_1(LibraryFoyer::ToMeetingRoom, that));
    ToTavernRoom->setPosition(Vec2(visibleSize.width * 0.2, visibleSize.height * 0.8));
    ToTavernRoom->setScale(0.25);
    ToTavernRoom->setName("totavern");
    pMenuItems.pushBack(ToTavernRoom);
    
    
    auto libraryStaff = MenuItemImage::create("glen.png", "glen.png", CC_CALLBACK_1(LibraryFoyer::staffTouched, that));
    libraryStaff->setPosition(Vec2(origin.x + visibleSize.width / 2 + 350, origin.y + visibleSize.height / 2));
    libraryStaff->setName("staff");
    pMenuItems.pushBack(libraryStaff);
    
    
    
    return pMenuItems;
    
}

// call this method in the main menu scene to create the main menu
void LibraryFoyerController::CreateMainMenu(LibraryFoyer *that, Size visibleSize, Vec2 origin)
{
    log("You Went to the Library Foyer");
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems = CreateMenuButtons(that, visibleSize, origin);
    
    // create menu, it's an autorelease object
    auto menu = Menu::createWithArray(pMenuItems);
    menu->setPosition(Vec2::ZERO);
    menu->setName("menu");
    that->addChild(menu, 1);
    
    auto sprite = Sprite::create("Library_Foyer.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    that->addChild(sprite, 0);
    
    
    Sprite *desksprite = Sprite::create("desk.png");
    desksprite->setPosition(Vec2(origin.x + visibleSize.width / 2 + 350, origin.y + visibleSize.height / 2 - 125));
    desksprite->setName("desk");
    that->addChild(desksprite, 2);
    
    Sprite *shelfsprite = Sprite::create("Library_book_shelf_full.png");
    shelfsprite->setPosition(Vec2(visibleSize.width * 0.5, origin.y + visibleSize.height * 0.51));
    shelfsprite->setScale(1);
    shelfsprite->setName("shelf");
    that->addChild(shelfsprite);
    
    Sprite *couchsprite = Sprite::create("Library_couch.png");
    couchsprite->setPosition(Vec2(visibleSize.width * 0.17, visibleSize.height * 0.41));
    that->addChild(couchsprite);
    
    
    
}


