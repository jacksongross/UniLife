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
    
    
    auto ToMap = MenuItemImage::create("map_background.png","map_background.png" , CC_CALLBACK_1(LibraryFoyer::ToMap, that));
    ToMap->setPosition(Vec2(origin.x + visibleSize.width / 2 + 450, origin.y + (visibleSize.height / 2 + 275)));
    ToMap->setScale(0.15);
    pMenuItems.pushBack(ToMap);
    
    
    auto ToTavernRoom = MenuItemImage::create("Go_Left_Arrow.png","Go_Left_Arrow.png" , CC_CALLBACK_1(LibraryFoyer::ToMeetingRoom, that));
    ToTavernRoom->setPosition(Vec2(origin.x + visibleSize.width / 2 - 450 , origin.y + (visibleSize.height / 2 )));
    ToTavernRoom->setScale(0.25);
    pMenuItems.pushBack(ToTavernRoom);
    
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
    that->addChild(menu, 3);
    
    // add "MenuScene" splash screen"
    auto sprite = Sprite::create("Library_Foyer.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    that->addChild(sprite, 0);
    
    
    Sprite *desksprite = Sprite::create("desk.png");
    desksprite->setPosition(Vec2(origin.x + visibleSize.width / 2 + 350, origin.y + visibleSize.height / 2 - 125));
    that->addChild(desksprite,2);
    
    Sprite *shelfsprite = Sprite::create("Library_book_shelf.png");
    shelfsprite->setPosition(Vec2(origin.x + visibleSize.width / 2 - 170, origin.y + visibleSize.height / 2 + 60));
    shelfsprite->setScale(1.5);
    that->addChild(shelfsprite);
    
    /*
    Sprite *couchsprite = Sprite::create("Library_couch.png");
    couchsprite->setPosition(Vec2(origin.x + visibleSize.width / 2 - 350, origin.y + visibleSize.height / 2 - 100));
    that->addChild(couchsprite);
    */
    
    Sprite *librarystaff = Sprite::create("bill_inside.png");
    librarystaff->setPosition(Vec2(origin.x + visibleSize.width / 2 + 350, origin.y + visibleSize.height / 2));
    that->addChild(librarystaff, 1);
    
    std::string tmpstring = "LIBRARY";
    cocos2d::ui::Text *libbanner = cocos2d::ui::Text::create(tmpstring, "Verdana", 20);
    libbanner->setPosition(Vec2(origin.x + visibleSize.width / 2 + 275, origin.y + visibleSize.height / 2 + 250));
    libbanner->setColor(cocos2d::Color3B::BLACK);
    that->addChild(libbanner);
    
}


