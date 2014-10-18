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
    
    // create dorm room
    auto bg = Sprite::create("dorm-background.png");
    
    // position the sprite on the center of the screen
    bg->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    that->addChild(bg, 0);
    
    // add the door
    
    auto doorSprite = MenuItemImage::create("dorm-door.png", "dorm-door.png", CC_CALLBACK_1(DormScene::DoorPressed, that));
    
    doorSprite->setPosition(Vec2(visibleSize.width / 2 - origin.x - doorSprite->getContentSize().width - 39, visibleSize.height / 2 + origin.y - 10));
    
    doorSprite->setTag(8);
    doorSprite->setName("door");
    
    // add the bed
    auto bedSprite = MenuItemImage::create("dorm-bed.png", "dorm-bed.png", CC_CALLBACK_1(DormScene::BedPressed, that));

    
    bedSprite->setPosition(Vec2(visibleSize.width - origin.x - bedSprite->getContentSize().width + 202, visibleSize.height - bedSprite->getContentSize().height - 220));
    
    bedSprite->setName("bed");

    // add the book shelf
    auto shelfSprite = MenuItemImage::create("dorm-book_shelf.png", "dorm-book_shelf.png", CC_CALLBACK_1(DormScene::ShelfPressed, that));
    
    
    shelfSprite->setPosition(Vec2(visibleSize.width - shelfSprite->getContentSize().width - 333, visibleSize.height / 2 + origin.y - 91));
    
    shelfSprite->setName("shelf");
    
    // add the desk
    auto deskSprite = MenuItemImage::create("dorm-desk.png", "dorm-desk.png", CC_CALLBACK_1(DormScene::DeskPressed, that));
    
    deskSprite->setPosition(Vec2(origin.x + deskSprite->getContentSize().width / 2 + 11, visibleSize.height / 2 - 120));
    
    deskSprite->setName("desk");
    
    // add the computer
    auto computerSprite = MenuItemImage::create("dorm-computer.png", "dorm-computer.png", CC_CALLBACK_1(DormScene::ComputerPressed, that));
    
    computerSprite->setPosition(Vec2(origin.x + computerSprite->getContentSize().width / 2 + 12, visibleSize.height / 2 + 58));
    
    computerSprite->setName("computer");
    
    // add the stool
    auto sprite = Sprite::create("dorm-stool.png");
    
    sprite->setPosition(Vec2(origin.x + sprite->getContentSize().width / 2 + 15, origin.y + sprite->getContentSize().height / 2));
    
    sprite->setName("stool");
    
    that->addChild(sprite, 5);
    
    // push the sprites onto the scene
    pMenuItems.pushBack(doorSprite);
    pMenuItems.pushBack(bedSprite);
    pMenuItems.pushBack(shelfSprite);
    pMenuItems.pushBack(deskSprite);
    pMenuItems.pushBack(computerSprite);
    
    cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Walk.plist");
    
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
    menu->setName("menu");
    that->addChild(menu, 1);
    

}


