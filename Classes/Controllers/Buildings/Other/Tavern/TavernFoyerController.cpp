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
    
    
    auto ToMap = MenuItemImage::create("Map-marker.png","Map-marker.png" , CC_CALLBACK_1(TavernFoyer::ToMap, that));
    ToMap->setPosition(Vec2(visibleSize.width * 0.8, visibleSize.height * 0.9 ));
    ToMap->setScale(0.85);
    pMenuItems.pushBack(ToMap);
    
    
    auto ToTavernRoom = MenuItemImage::create("Go_Left_Arrow.png","Go_Left_Arrow.png" , CC_CALLBACK_1(TavernFoyer::ToTavernRoom, that));
    ToTavernRoom->setPosition(Vec2(origin.x + visibleSize.width / 2 + 450 , origin.y + (visibleSize.height / 2 )));
    ToTavernRoom->setScale(0.25);
    ToTavernRoom->setRotation(180.0);
    pMenuItems.pushBack(ToTavernRoom);
    
    auto bartender = MenuItemImage::create("bartender.png", "bartender.png", CC_CALLBACK_1(TavernFoyer::ShowSpeech, that));
    bartender->setPosition(Vec2(origin.x + visibleSize.width / 2 - 340, origin.y + visibleSize.height / 2 + 80 ));
    pMenuItems.pushBack(bartender);
    
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
    
    auto sBubble = Sprite::create("NPC/speech_small2.png");
    sBubble->setPosition(Vec2(visibleSize.width/2 + origin.x - 110, visibleSize.height/2 + origin.y + 155 ));
    sBubble->setScaleX(-1.0f);
    sBubble->setScaleY(.9);
    sBubble->setName("sBubble");
    sBubble->setVisible(false);
    that->addChild(sBubble, 11);
    
    auto introText = ui::Text::create("Hey! You're too\nyoung to be in\nhere!\nScram kid!", "Arial", 30);
    introText->setPosition(Vec2(visibleSize.width/2 + origin.x - 100, visibleSize.height/2 + origin.y + 160 ));
    introText->setColor(Color3B::BLACK);
    introText->setName("Text");
    introText->setVisible(false);
    that->addChild(introText, 11);
    
    Sprite* barCounter = Sprite::create("Tavern_bar.png");
    barCounter->setPosition(Vec2(origin.x + visibleSize.width / 2 - 300, origin.y + visibleSize.height / 2 - 40 ));
    that->addChild(barCounter, 10);
    
    Sprite* barTable = Sprite::create("Tavern_table.png");
    barTable->setPosition(Vec2(origin.x + visibleSize.width / 2 + 260, origin.y + visibleSize.height / 2 - 80));
    that->addChild(barTable,2);
    
    Sprite* barCouches = Sprite::create("Tavern_couches2.png");
    barCouches->setPosition(Vec2(origin.x + visibleSize.width / 2 + 260, origin.y + visibleSize.height / 2 + 10));
    that->addChild(barCouches,1);
    
    

}

