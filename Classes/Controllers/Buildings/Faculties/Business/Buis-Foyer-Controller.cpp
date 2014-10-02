//
//  Buis-Foyer-Controller.cpp
//  UniLife
//
//  Created by csci321ga2a on 8/09/2014.
//
//

#include "Buis-Foyer-Controller.h"
#include "ExtensionMacros.h"
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
using namespace cocos2d::extension;
extern PlayerModel pm;

USING_NS_CC;

// create the buttons for the main menu
cocos2d::Vector<cocos2d::MenuItem*> BuisFoyerController::CreateMenuButtons(BuisFoyer *that, Size visibleSize, Vec2 origin)
{
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems;
    
    
    auto ToHallway = MenuItemImage::create("Go_Left_Arrow.png","Go_Left_Arrow.png" , CC_CALLBACK_1(BuisFoyer::ToHallway, that));
    ToHallway->setPosition(Vec2(origin.x + visibleSize.width / 2 - 475, origin.y + (visibleSize.height / 2 )));
    ToHallway->setScale(0.3,0.3);
    pMenuItems.pushBack(ToHallway);
    
    
    auto ToMap = MenuItemImage::create("Map-marker.png","Map-marker.png" , CC_CALLBACK_1(BuisFoyer::ToMap, that));
    ToMap->setPosition(Vec2(origin.x + visibleSize.width / 2 + 450, origin.y + (visibleSize.height / 2 + 275)));
    ToMap->setScale(0.15);
    pMenuItems.pushBack(ToMap);
    
    
    
    return pMenuItems;
    
}

// call this method in the main menu scene to create the main menu
void BuisFoyerController::CreateMainMenu(BuisFoyer *that, Size visibleSize, Vec2 origin)
{
    log("You Went to the Buisness Foyer");
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems = CreateMenuButtons(that, visibleSize, origin);
    
    // create menu, it's an autorelease object
    auto menu = Menu::createWithArray(pMenuItems);
    menu->setPosition(Vec2::ZERO);
    that->addChild(menu, 1);
    
    // add "MenuScene" splash screen"
    auto sprite = Sprite::create("Buis_Foyer.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    that->addChild(sprite, 0);
    
    
    Sprite *foyerDesk = Sprite::create("desk.png");
    foyerDesk->setPosition(Vec2(origin.x + visibleSize.width / 2 + 200, origin.y + visibleSize.height / 2 -125));
    foyerDesk->setScale(1.25);
    that->addChild(foyerDesk,2);
    
    Sprite *foyerBoard = Sprite::create("whiteboard.png");
    foyerBoard->setPosition(Vec2(origin.x + visibleSize.width / 2 - 250, origin.y + visibleSize.height / 2 + 100));
    foyerBoard->setScale(1);
    that->addChild(foyerBoard);
    
    cocos2d::ui::Text* LocName = cocos2d::ui::Text::create("Buisness & Commerce Building!", "Verdana", 15);
    LocName->setColor(Color3B(0,0,0));
    LocName->setTextHorizontalAlignment(cocos2d::TextHAlignment::CENTER);
    LocName->setPosition(Vec2(origin.x + visibleSize.width / 2 - 250, origin.y + visibleSize.height / 2 +165));
    that->addChild(LocName);
    
    Sprite *officePerson = Sprite::create("bill_inside.png");
    officePerson->setPosition(Vec2(origin.x + visibleSize.width / 2 + 200, origin.y + visibleSize.height / 2));
    that->addChild(officePerson, 1);
    
    
    
    
}


