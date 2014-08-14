//
//  MenuNewGameController.cpp
//  UniLife
//
//  Created by csci321ga2a on 14/08/2014.
//
//
#include "MenuNewGameController.h"
#include "MenuNewGame.h"
#include "ExtensionMacros.h"
#include "cocos2d.h"
#include "extensions/cocos-ext.h"

using namespace cocos2d::extension;


USING_NS_CC;

// create the buttons for the main menu
cocos2d::Vector<cocos2d::MenuItem*> MenuNewGameController::CreateMenuButtons(MenuNewGame *that, Size visibleSize, Vec2 origin)
{
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems;
    
    
    // create the new game button and place onto screen
    auto PlayerNameReturn = MenuItemImage::create("New-Game-next_off.png",
                                             "New-Game-next_on.png",
                                             CC_CALLBACK_1(MenuNewGame::dostuffcallback, that));
    
    PlayerNameReturn->setPosition(Vec2(origin.x + visibleSize.width / 2 + 400,
                                  origin.y + (visibleSize.height / 2 - 250)));
    
    pMenuItems.pushBack(PlayerNameReturn);
    
    
    
    
    return pMenuItems;
    
}

// call this method in the main menu scene to create the main menu
void MenuNewGameController::CreateMainMenu(MenuNewGame *that, Size visibleSize, Vec2 origin)
{
    log("The New Game Menu Was Loaded");
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems = CreateMenuButtons(that, visibleSize, origin);
    
    // create menu, it's an autorelease object
    auto menu = Menu::createWithArray(pMenuItems);
    menu->setPosition(Vec2::ZERO);
    that->addChild(menu, 1);
    
    // add "MenuScene" splash screen"
    auto sprite = Sprite::create("New-Game-background.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    that->addChild(sprite, 0);
    
    
    // add the Back Button sprite to the menu
    sprite = Sprite::create("New-Game-Back.png");
    sprite->setPosition(Vec2(origin.x + visibleSize.width / 2 - 500, visibleSize.height / 2 -250));
    
    that->addChild(sprite, 0);
    
    
    /* add the Next Button sprite to the menu
    sprite = Sprite::create("New-Game-next_off.png");
    sprite->setPosition(Vec2(origin.x + visibleSize.width / 2 + 400, visibleSize.height / 2 -250));
    
    that->addChild(sprite, 0);
    */
    
    
    // add the Take Quiz Button Sprite to the menu
    sprite = Sprite::create("New-Game-take_quiz_off.png");
    sprite->setPosition(Vec2(origin.x + visibleSize.width / 2, visibleSize.height / 2 -250));
    
    that->addChild(sprite, 0);
    
    
    
    //Create Name Label For the Top of the Screen
    
    CCLabelTTF* ttf1 = CCLabelTTF::create("New Character", "Verdana", 64,
                                          CCSizeMake(490, 64), kCCTextAlignmentCenter);
    ttf1->setPosition(Vec2(origin.x + visibleSize.width / 2, visibleSize.height / 2 + 250));
    ttf1->setColor(ccc3(0,0,0));
    that->addChild(ttf1, 0);
    
    
   //Create Input Titles
    CCLabelTTF* ttf2 = CCLabelTTF::create("Name: ", "Verdana", 30,
                                          CCSizeMake(245, 32), kCCTextAlignmentCenter);
    ttf2->setPosition(Vec2(origin.x + visibleSize.width / 2 - 350 , visibleSize.height / 2 +150));
    ttf2->setColor(ccc3(0,0,0));
    that->addChild(ttf2, 0);
    
    
    CCLabelTTF* ttf3 = CCLabelTTF::create("Intelligence: ", "Verdana", 30,
                                          CCSizeMake(245, 32), kCCTextAlignmentCenter);
    ttf3->setPosition(Vec2(origin.x + visibleSize.width / 2 - 350 , visibleSize.height / 2 +100));
    ttf3->setColor(ccc3(0,0,0));
    that->addChild(ttf3, 0);
    
    
    CCLabelTTF* ttf4 = CCLabelTTF::create("Stamina: ", "Verdana", 30,
                                          CCSizeMake(245, 32), kCCTextAlignmentCenter);
    ttf4->setPosition(Vec2(origin.x + visibleSize.width / 2 - 350 , visibleSize.height / 2 +50));
    ttf4->setColor(ccc3(0,0,0));
    that->addChild(ttf4, 0);
    
    CCLabelTTF* ttf5 = CCLabelTTF::create("Social: ", "Verdana", 30,
                                          CCSizeMake(245, 32), kCCTextAlignmentCenter);
    ttf5->setPosition(Vec2(origin.x + visibleSize.width / 2 - 350 , visibleSize.height / 2 +10));
    ttf5->setColor(ccc3(0,0,0));
    that->addChild(ttf5, 0);
    
    
    CCLabelTTF* ttf6 = CCLabelTTF::create("Points Remaining: ", "Verdana", 30,
                                          CCSizeMake(300, 50), kCCTextAlignmentCenter);
    ttf6->setPosition(Vec2(origin.x + visibleSize.width / 2 -350 , visibleSize.height / 2 -125));
    ttf6->setColor(ccc3(0,0,0));
    that->addChild(ttf6, 0);
    
    
    
    EditBox* m_pEditName = EditBox::create((CCSizeMake(300, 50)), Scale9Sprite::create("New-Game-textbox.png"));
    m_pEditName->setPosition(ccp(origin.x + visibleSize.width / 2 - 150, origin.y + visibleSize.height / 2 + 150));
    m_pEditName->setFontColor(ccc3(0,0,0));
    m_pEditName->setPlaceHolder("   ");
    m_pEditName->setMaxLength(8);
    //m_pEditName->setReturnType(kKeyboardReturnTypeDone);
    //m_pEditName->setDelegate(this);
    that->addChild(m_pEditName);
    
    
    
    
}




