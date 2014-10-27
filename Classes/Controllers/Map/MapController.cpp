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
    
    
    
    auto GoToDorm = MenuItemImage::create("dorm.png","dorm.png" , CC_CALLBACK_1(MapScene::GoToDorm, that));
    GoToDorm->setPosition(Vec2(origin.x + visibleSize.width / 2 -450, origin.y + (visibleSize.height / 2 -275)));
    GoToDorm->setScale(0.3,0.3);
    pMenuItems.pushBack(GoToDorm);

    
    auto GoToEIS = MenuItemImage::create("map-computing_engineering.png", "map-computing_engineering.png", CC_CALLBACK_1(MapScene::GoToEIS, that));
    GoToEIS->setPosition(Vec2(origin.x + visibleSize.width / 2 + 325, origin.y + visibleSize.height / 2 + 75));
    GoToEIS->setScale(0.8);
    pMenuItems.pushBack(GoToEIS);
    
    auto GoToSciMed = MenuItemImage::create("map-science_medicine.png", "map-science_medicine.png", CC_CALLBACK_1(MapScene::GoToMedSci, that));
    GoToSciMed->setPosition(Vec2(origin.x + visibleSize.width / 2 - 20, origin.y + visibleSize.height / 2 + 180));
    GoToSciMed->setScale(0.8);
    pMenuItems.pushBack(GoToSciMed);
    
    auto GoToTavern = MenuItemImage::create("map-tavern.png", "map-tavern.png", CC_CALLBACK_1(MapScene::GoToTavern, that));
    GoToTavern->setPosition(Vec2(origin.x + visibleSize.width / 2 + 300, origin.y + visibleSize.height / 2 - 50));
    GoToTavern->setScale(0.9);
    pMenuItems.pushBack(GoToTavern);
    
    auto GoToBuis = MenuItemImage::create("map-business.png", "map-business.png", CC_CALLBACK_1(MapScene::GoToBuis, that));
    GoToBuis->setPosition(Vec2(origin.x + visibleSize.width / 2 - 400, origin.y + visibleSize.height / 2 + 105));
    GoToBuis->setScale(0.9);
    pMenuItems.pushBack(GoToBuis);
    
    auto GoToArt = MenuItemImage::create("map-art.png", "map-art.png", CC_CALLBACK_1(MapScene::GoToArt, that));
    GoToArt->setPosition(Vec2(origin.x + visibleSize.width / 2 -240, origin.y + visibleSize.height / 2 - 185));
    GoToArt->setScale(0.9);
    pMenuItems.pushBack(GoToArt);
    
    auto GoToSocSci = MenuItemImage::create("map-social_science.png", "map-social_science.png", CC_CALLBACK_1(MapScene::GoToSocSci, that));
    GoToSocSci->setPosition(Vec2(origin.x + visibleSize.width / 2 - 400, origin.y + visibleSize.height / 2 - 60));
    GoToSocSci->setScale(0.9);
    pMenuItems.pushBack(GoToSocSci);
    
    auto GoToLibrary = MenuItemImage::create("map-library.png", "map-library.png", CC_CALLBACK_1(MapScene::GoToLibrary, that));
    GoToLibrary->setPosition(Vec2(origin.x + visibleSize.width / 2 - 190, origin.y + visibleSize.height / 2));
    GoToLibrary->setScale(0.9);
    pMenuItems.pushBack(GoToLibrary);
    
    auto GoToShop = MenuItemImage::create("map-shop.png", "map-shop.png", CC_CALLBACK_1(MapScene::GoToShop, that));
    GoToShop->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2 - 200));
    GoToShop->setScale(1.1);
    pMenuItems.pushBack(GoToShop);
    
    auto GoToUniCentre = MenuItemImage::create("map-uni_centre.png", "map-uni_centre.png", CC_CALLBACK_1(MapScene::GoToUniCentre, that));
    GoToUniCentre->setPosition(Vec2(origin.x + visibleSize.width / 2 + 320, origin.y + visibleSize.height / 2 - 200));
    GoToUniCentre->setScale(0.9);
    pMenuItems.pushBack(GoToUniCentre);
    
    
    
    
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
    
    
    
    Sprite *mpHolder7 = Sprite::create("map-sun.png");
    mpHolder7->setPosition(Vec2(origin.x + visibleSize.width / 2 - 425, origin.y + visibleSize.height / 2 + 280));
    mpHolder7->setScale(0.9);
    that->addChild(mpHolder7,2);
    

    
    
}