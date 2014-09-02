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
    that->addChild(menu, 1);
    
    // add "MenuScene" splash screen"
    auto sprite = Sprite::create("Tavern_background.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    that->addChild(sprite, 0);
    
    
    
    
    
    //Energy HUD
    cocos2d::ui::Text* engText = cocos2d::ui::Text::create("Energy ", "Verdana", 20);
    engText->setContentSize(Size(400, 40));
    engText->setPosition(Vec2(origin.x + visibleSize.width / 2 - 360, visibleSize.height / 2 + 310));
    engText->setColor(Color3B(0,0,0));
    that->addChild(engText, 1);
    
    
    Sprite* engSprite = Sprite::create("HUD_energy_bar.png");
    engSprite->setPosition(Vec2(origin.x + visibleSize.width / 2 - 475, origin.y + visibleSize.height / 2 + 300));
    engSprite->setAnchorPoint(Vec2(0.f,0.5f));
    ProgressTimer* pg = ProgressTimer::create(engSprite);
    engSprite->setScale(0.5 , 0.5);
    engSprite->setTag(1);
    pg->setBarChangeRate(Vec2(1, 0));
    pg->setScaleX(pm.getStats().getEnergy()/100.0);
    pg->setAnchorPoint(Vec2(0.f,0.5f));
    that->addChild(engSprite);
    that->addChild(pg);
    
    
    //Energy HUD
    cocos2d::ui::Text* streText = cocos2d::ui::Text::create("Stress ", "Verdana", 20);
    streText->setContentSize(Size(400, 40));
    streText->setPosition(Vec2(origin.x + visibleSize.width / 2 - 360, visibleSize.height / 2 + 275));
    streText->setColor(Color3B(0,0,0));
    that->addChild(streText, 1);
    
    
    
    Sprite* streSprite = Sprite::create("HUD_stress_bar.png");
    streSprite->setPosition(Vec2(origin.x + visibleSize.width / 2 - 475, origin.y + visibleSize.height / 2 + 265));
    streSprite->setAnchorPoint(Vec2(0.f,0.5f));
    ProgressTimer* pg2 = ProgressTimer::create(streSprite);
    pg2->setScaleX(pm.getStats().getStress()/100.0);
    streSprite->setScale(0.5 , 0.5);
    streSprite->setTag(2);
    pg->setBarChangeRate(Vec2(1, 0));
    pg->setAnchorPoint(Vec2(0.f,0.5f));
    that->addChild(streSprite);
    that->addChild(pg2);
    
    
    
    
    Sprite* barCounter = Sprite::create("Tavern_bar.png");
    barCounter->setPosition(Vec2(origin.x + visibleSize.width / 2 - 340, origin.y + visibleSize.height / 2 - 40 ));
    that->addChild(barCounter);
    
    
    Sprite* barTable = Sprite::create("Tavern_table.png");
    barTable->setPosition(Vec2(origin.x + visibleSize.width / 2 + 260, origin.y + visibleSize.height / 2 - 80));
    that->addChild(barTable,2);
    
    Sprite* barCouches = Sprite::create("Tavern_couches.png");
    barCouches->setPosition(Vec2(origin.x + visibleSize.width / 2 + 260, origin.y + visibleSize.height / 2 - 60));
    that->addChild(barCouches,1);
    
    
    
    
}


