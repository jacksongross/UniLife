//
//  MapController.cpp
//  UniLife
//
//  Created by csci321ga2a on 8/14/14.
//
//

#include "MapController.h"

USING_NS_CC;

// create the buttons for the main menu
cocos2d::Vector<cocos2d::MenuItem*> MapController::CreateMapButtons(MapScene *that, Size visibleSize, Vec2 origin)
{
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems;
    
    
    
    auto GoNext = MenuItemImage::create("Go_Left_Arrow.png","Go_Left_Arrow.png" , CC_CALLBACK_1(MapScene::GoToDorm, that));
    GoNext->setPosition(Vec2(origin.x + visibleSize.width / 2 -450, origin.y + (visibleSize.height / 2 -275)));
    GoNext->setScale(0.3,0.3);
    pMenuItems.pushBack(GoNext);

    
    auto GoEIS = MenuItemImage::create("map-computing_engineering.png", "map-computing_engineering.png", CC_CALLBACK_1(MapScene::GoToEIS, that));
    GoEIS->setPosition(Vec2(origin.x + visibleSize.width / 2 + 375, origin.y + visibleSize.height / 2));
    GoEIS->setScale(0.5, 0.5);
    pMenuItems.pushBack(GoEIS);
    
    
    return pMenuItems;
    
}

// call this method in the main menu scene to create the main menu
void MapController::CreateMapView(MapScene *that, Size visibleSize, Vec2 origin)
{
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems = CreateMapButtons(that, visibleSize, origin);
    
    // create menu, it's an autorelease object
    auto menu = Menu::createWithArray(pMenuItems);
    menu->setPosition(Vec2::ZERO);
    that->addChild(menu, 1);
    
    // create dorm room
    auto sprite = Sprite::create("map_background.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    that->addChild(sprite, 0);
    
}