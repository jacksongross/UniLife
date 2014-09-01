//
//  Inside_EIS_Controller.cpp
//  UniLife
//
//  Created by csci321ga2a on 28/08/2014.
//
//

#include "Inside_EIS_Controller.h"
#include "ExtensionMacros.h"
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
using namespace cocos2d::extension;


USING_NS_CC;

// create the buttons for the main menu
cocos2d::Vector<cocos2d::MenuItem*> Inside_EIS_Controller::CreateMenuButtons(Inside_EIS *that, Size visibleSize, Vec2 origin)
{
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems;
    
    
    auto ToHallway = MenuItemImage::create("Go_Left_Arrow.png","Go_Left_Arrow.png" , CC_CALLBACK_1(Inside_EIS::ToHallway, that));
    ToHallway->setPosition(Vec2(origin.x + visibleSize.width / 2 + 475, origin.y + (visibleSize.height / 2 )));
    ToHallway->setScale(0.3,0.3);
    ToHallway->setRotation(180);
    pMenuItems.pushBack(ToHallway);

    
    return pMenuItems;
    
}

// call this method in the main menu scene to create the main menu
void Inside_EIS_Controller::CreateMainMenu(Inside_EIS *that, Size visibleSize, Vec2 origin)
{
    log("The New Game Menu Was Loaded");
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems = CreateMenuButtons(that, visibleSize, origin);
    
    // create menu, it's an autorelease object
    auto menu = Menu::createWithArray(pMenuItems);
    menu->setPosition(Vec2::ZERO);
    that->addChild(menu, 1);
    
    // add "MenuScene" splash screen"
    auto sprite = Sprite::create("foyer.png");
    
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
    streSprite->setScale(0.5 , 0.5);
    streSprite->setTag(2);
    pg->setBarChangeRate(Vec2(1, 0));
    pg->setAnchorPoint(Vec2(0.f,0.5f));
    that->addChild(streSprite);
    that->addChild(pg2);
    
    
    
    Sprite *foyerDesk = Sprite::create("desk.png");
    foyerDesk->setPosition(Vec2(origin.x + visibleSize.width / 2 + 200, origin.y + visibleSize.height / 2 -125));
    foyerDesk->setScale(1.25);
    that->addChild(foyerDesk,2);
    
    Sprite *foyerBoard = Sprite::create("whiteboard.png");
    foyerBoard->setPosition(Vec2(origin.x + visibleSize.width / 2 - 300, origin.y + visibleSize.height / 2 + 100));
    foyerBoard->setScale(1);
    that->addChild(foyerBoard);
    
    cocos2d::ui::Text* LocName = cocos2d::ui::Text::create("Engineering & Information Sciences\n Notice Board", "Verdana", 15);
    LocName->setColor(Color3B(0,0,0));
    LocName->setTextHorizontalAlignment(cocos2d::TextHAlignment::CENTER);
    LocName->setPosition(Vec2(origin.x + visibleSize.width / 2 - 300, origin.y + visibleSize.height / 2 +165));
    that->addChild(LocName);
    
    Sprite *officePerson = Sprite::create("bill_inside.png");
    officePerson->setPosition(Vec2(origin.x + visibleSize.width / 2 + 200, origin.y + visibleSize.height / 2));
    that->addChild(officePerson, 1);
    
    
    
    
}


