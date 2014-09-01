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
    GoEIS->setPosition(Vec2(origin.x + visibleSize.width / 2 + 325, origin.y + visibleSize.height / 2 + 75));
    GoEIS->setScale(0.8);
    pMenuItems.pushBack(GoEIS);
    
    
    auto GoTavern = MenuItemImage::create("map-tavern.png", "map-tavern.png", CC_CALLBACK_1(MapScene::GoToTavern, that));
    GoTavern->setPosition(Vec2(origin.x + visibleSize.width / 2 + 300, origin.y + visibleSize.height / 2 - 50));
    GoTavern->setScale(0.9);
    pMenuItems.pushBack(GoTavern);
    
    
    
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
    
    Sprite *mpHolder = Sprite::create("map-art.png");
    mpHolder->setPosition(Vec2(origin.x + visibleSize.width / 2 -240, origin.y + visibleSize.height / 2 - 185));
    mpHolder->setScale(0.9);
    that->addChild(mpHolder,2);
    
    Sprite *mpHolder2 = Sprite::create("map-business.png");
    mpHolder2->setPosition(Vec2(origin.x + visibleSize.width / 2 - 400, origin.y + visibleSize.height / 2 + 105));
    mpHolder2->setScale(0.9);
    that->addChild(mpHolder2,2);
    
    Sprite *mpHolder3 = Sprite::create("map-library.png");
    mpHolder3->setPosition(Vec2(origin.x + visibleSize.width / 2 - 190, origin.y + visibleSize.height / 2));
    mpHolder3->setScale(0.9);
    that->addChild(mpHolder3,2);
    
    Sprite *mpHolder4 = Sprite::create("map-science_medicine.png");
    mpHolder4->setPosition(Vec2(origin.x + visibleSize.width / 2 - 20, origin.y + visibleSize.height / 2 + 180));
    mpHolder4->setScale(0.9);
    that->addChild(mpHolder4,2);
    
    Sprite *mpHolder5 = Sprite::create("map-shop.png");
    mpHolder5->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2 - 200));
    mpHolder5->setScale(1.1);
    that->addChild(mpHolder5,2);
    
    Sprite *mpHolder6 = Sprite::create("map-social_science.png");
    mpHolder6->setPosition(Vec2(origin.x + visibleSize.width / 2 - 400, origin.y + visibleSize.height / 2 - 60));
    mpHolder6->setScale(0.9);
    that->addChild(mpHolder6,2);
    
    Sprite *mpHolder7 = Sprite::create("map-sun.png");
    mpHolder7->setPosition(Vec2(origin.x + visibleSize.width / 2 - 425, origin.y + visibleSize.height / 2 + 280));
    mpHolder7->setScale(0.9);
    that->addChild(mpHolder7,2);
    
    
    Sprite *mpHolder9 = Sprite::create("map-uni_centre.png");
    mpHolder9->setPosition(Vec2(origin.x + visibleSize.width / 2 + 320, origin.y + visibleSize.height / 2 - 200));
    mpHolder9->setScale(0.9);
    that->addChild(mpHolder9,2);
    
    
}