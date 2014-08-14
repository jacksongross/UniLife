//
//  DormController.cpp
//  UniLife
//
//  Created by csci321ga2a on 8/14/14.
//
//

#include "DormController.h"

USING_NS_CC;

// create the buttons for the main menu
cocos2d::Vector<cocos2d::MenuItem*> DormController::CreateDormButtons(DormScene *that, Size visibleSize, Vec2 origin)
{
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems;
    
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
    
    // create dorm room
    auto sprite = Sprite::create("dorm-background.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    that->addChild(sprite, 0);
    
    // add the door
    sprite = Sprite::create("dorm-door.png");
    
    sprite->setPosition(Vec2(visibleSize.width / 2 - origin.x - sprite->getContentSize().width - 39, visibleSize.height / 2 + origin.y - 10));
    
    that->addChild(sprite, 0);
    
    // add the bed
    sprite = Sprite::create("dorm-bed.png");
    
    sprite->setPosition(Vec2(visibleSize.width - origin.x - sprite->getContentSize().width + 202, visibleSize.height - sprite->getContentSize().height - 220));
    
    that->addChild(sprite, 0);
    
    // add the book shelf
    sprite = Sprite::create("dorm-book_shelf.png");
    
    sprite->setPosition(Vec2(visibleSize.width - sprite->getContentSize().width - 333, visibleSize.height / 2 + origin.y - 91));
    
    that->addChild(sprite, 0);
    
    // add the desk
    sprite = Sprite::create("dorm-desk.png");
    
    sprite->setPosition(Vec2(origin.x + sprite->getContentSize().width / 2 + 11, visibleSize.height / 2 - 121));
    
    that->addChild(sprite, 0);
    
    // add the computer
    sprite = Sprite::create("dorm-computer.png");
    
    sprite->setPosition(Vec2(origin.x + sprite->getContentSize().width / 2 + 12, visibleSize.height / 2 + 58));
    
    that->addChild(sprite, 0);
    
    // add the stool
    sprite = Sprite::create("dorm-stool.png");
    
    sprite->setPosition(Vec2(origin.x + sprite->getContentSize().width / 2 + 15, origin.y + sprite->getContentSize().height / 2));
    
    that->addChild(sprite, 0);
}
