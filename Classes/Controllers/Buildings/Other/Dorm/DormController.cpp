//
//  DormController.cpp
//  UniLife
//
//  Created by csci321ga2a on 8/14/14.
//
//

#include "DormController.h"
#include "MapScene.h"
#include "MapController.h"
#include "CCActionInterval.h"
#include "CCAction.h"

extern PlayerModel pm;

USING_NS_CC;

// create the buttons for the main menu
cocos2d::Vector<cocos2d::MenuItem*> DormController::CreateDormButtons(DormScene *that, Size visibleSize, Vec2 origin)
{
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems;
    
    // animate the menu button to spin
    auto pauseButton = MenuItemImage::create("cog-110.png", "cog-110.png", CC_CALLBACK_1(DormScene::PausedPressed, that));
    
    pauseButton->setPosition(Vec2(visibleSize.width * .95, visibleSize.height * .90));
    
    auto rotate = RotateBy::create(5.0f, 360);
    
    // run this forever so it keeps on spinning
    auto action = RepeatForever::create(rotate);
    
    pauseButton->runAction(action);
    
    // create dorm room
    auto bg = Sprite::create("dorm-background.png");
    
    // position the sprite on the center of the screen
    bg->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    that->addChild(bg, 0);
    
    // add bill to the screen
    auto player2 = Sprite::create("bill_inside.png");
    
    player2->setPosition(Vec2(visibleSize.width / 2 - 130, visibleSize.height / 2 - 135 ));
    
    that->addChild(player2, 6);
    
    // add the door
    
    auto doorSprite = MenuItemImage::create("dorm-door.png", "dorm-door.png", CC_CALLBACK_1(DormScene::DoorPressed, that));
    
    doorSprite->setPosition(Vec2(visibleSize.width / 2 - origin.x - doorSprite->getContentSize().width - 39, visibleSize.height / 2 + origin.y - 10));
    
    doorSprite->setTag(8);
    
    // add the bed
    auto bedSprite = MenuItemImage::create("dorm-bed.png", "dorm-bed.png", CC_CALLBACK_1(DormScene::BedPressed, that));

    
    bedSprite->setPosition(Vec2(visibleSize.width - origin.x - bedSprite->getContentSize().width + 202, visibleSize.height - bedSprite->getContentSize().height - 220));
    
    
    // add the book shelf
    auto shelfSprite = MenuItemImage::create("dorm-book_shelf.png", "dorm-book_shelf.png", CC_CALLBACK_1(DormScene::ShelfPressed, that));
    
    
    shelfSprite->setPosition(Vec2(visibleSize.width - shelfSprite->getContentSize().width - 333, visibleSize.height / 2 + origin.y - 91));
    
    // add the desk
    auto deskSprite = MenuItemImage::create("dorm-desk.png", "dorm-desk.png", CC_CALLBACK_1(DormScene::DeskPressed, that));
    
    deskSprite->setPosition(Vec2(origin.x + deskSprite->getContentSize().width / 2 + 11, visibleSize.height / 2 - 120));
    
    // add the computer
    auto computerSprite = MenuItemImage::create("dorm-computer.png", "dorm-computer.png", CC_CALLBACK_1(DormScene::ComputerPressed, that));
    
    computerSprite->setPosition(Vec2(origin.x + computerSprite->getContentSize().width / 2 + 12, visibleSize.height / 2 + 58));
    
    // add the stool
    auto sprite = Sprite::create("dorm-stool.png");
    
    sprite->setPosition(Vec2(origin.x + sprite->getContentSize().width / 2 + 15, origin.y + sprite->getContentSize().height / 2));
    
    that->addChild(sprite, 5);
    
    // set up the timer
    
    that->timer = Label::createWithSystemFont("", "Verdana", 64);
    
    that->timer->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - 22));
    
    that->addChild(that->timer);
    
    
    // push the sprites onto the scene
    pMenuItems.pushBack(pauseButton);
    pMenuItems.pushBack(doorSprite);
    pMenuItems.pushBack(bedSprite);
    pMenuItems.pushBack(shelfSprite);
    pMenuItems.pushBack(deskSprite);
    pMenuItems.pushBack(computerSprite);
    
    
    return pMenuItems;
    
}

// call this method in the main menu scene to create the main menu
void DormController::CreateDormRoom(DormScene *that, Size visibleSize, Vec2 origin)
{
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems = CreateDormButtons(that, visibleSize, origin);
    
    // create menu, it's an autorelease object
    auto menu = Menu::createWithArray(pMenuItems);
    menu->setPosition(Vec2::ZERO);
    that->addChild(menu, 1);
    
    
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
    pg->setBarChangeRate(Vec2(1, 0));
    pg->setAnchorPoint(Vec2(0.f,0.5f));
    that->addChild(streSprite);
    that->addChild(pg2);
    
}


