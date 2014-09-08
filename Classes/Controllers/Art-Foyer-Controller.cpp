//
//  Art-Foyer-Controller.cpp
//  UniLife
//
//  Created by csci321ga2a on 8/09/2014.
//
//

#include "Art-Foyer-Controller.h"
#include "ExtensionMacros.h"
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
using namespace cocos2d::extension;
extern PlayerModel pm;

USING_NS_CC;

// create the buttons for the main menu
cocos2d::Vector<cocos2d::MenuItem*> ArtFoyerController::CreateMenuButtons(ArtFoyer *that, Size visibleSize, Vec2 origin)
{
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems;
    
    
    auto ToHallway = MenuItemImage::create("Go_Left_Arrow.png","Go_Left_Arrow.png" , CC_CALLBACK_1(ArtFoyer::ToHallway, that));
    ToHallway->setPosition(Vec2(origin.x + visibleSize.width / 2 - 475, origin.y + (visibleSize.height / 2 )));
    ToHallway->setScale(0.3,0.3);
    pMenuItems.pushBack(ToHallway);
    
    
    auto ToMap = MenuItemImage::create("map_background.png","map_background.png" , CC_CALLBACK_1(ArtFoyer::ToMap, that));
    ToMap->setPosition(Vec2(origin.x + visibleSize.width / 2 + 450, origin.y + (visibleSize.height / 2 + 275)));
    ToMap->setScale(0.15);
    pMenuItems.pushBack(ToMap);
    
    
    
    return pMenuItems;
    
}

// call this method in the main menu scene to create the main menu
void ArtFoyerController::CreateMainMenu(ArtFoyer *that, Size visibleSize, Vec2 origin)
{
    log("You Went to the Art Foyer");
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems = CreateMenuButtons(that, visibleSize, origin);
    
    // create menu, it's an autorelease object
    auto menu = Menu::createWithArray(pMenuItems);
    menu->setPosition(Vec2::ZERO);
    that->addChild(menu, 1);
    
    // add "MenuScene" splash screen"
    auto sprite = Sprite::create("Art_Foyer.png");
    
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
    
    
    //Stress HUD
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
    pg2->setBarChangeRate(Vec2(1, 0));
    pg2->setAnchorPoint(Vec2(0.f,0.5f));
    that->addChild(streSprite);
    that->addChild(pg2);
    
    
    
    
    
    Sprite *foyerDesk = Sprite::create("desk.png");
    foyerDesk->setPosition(Vec2(origin.x + visibleSize.width / 2 + 200, origin.y + visibleSize.height / 2 -125));
    foyerDesk->setScale(1.25);
    that->addChild(foyerDesk,2);
    
    Sprite *foyerBoard = Sprite::create("whiteboard.png");
    foyerBoard->setPosition(Vec2(origin.x + visibleSize.width / 2 - 250, origin.y + visibleSize.height / 2 + 100));
    foyerBoard->setScale(1);
    that->addChild(foyerBoard);
    
    cocos2d::ui::Text* LocName = cocos2d::ui::Text::create("Art And Creative Sciences", "Verdana", 15);
    LocName->setColor(Color3B(0,0,0));
    LocName->setTextHorizontalAlignment(cocos2d::TextHAlignment::CENTER);
    LocName->setPosition(Vec2(origin.x + visibleSize.width / 2 - 250, origin.y + visibleSize.height / 2 +165));
    that->addChild(LocName);
    
    Sprite *officePerson = Sprite::create("bill_inside.png");
    officePerson->setPosition(Vec2(origin.x + visibleSize.width / 2 + 200, origin.y + visibleSize.height / 2));
    that->addChild(officePerson, 1);
    
    
    
    
}


