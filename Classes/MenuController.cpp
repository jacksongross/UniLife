//
//  MenuController.cpp
//  UniLife
//
//  Created by csci321ga2a on 8/12/14.
//
//

#include "MenuController.h"
#include "MenuScene.h"
#include "cocos2d.h"

USING_NS_CC;

// create the buttons for the main menu
cocos2d::Vector<cocos2d::MenuItem*> MenuController::CreateMenuButtons(MenuScene *that, Size visibleSize, Vec2 origin)
{
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems;
    
    
    // create the new game button and place onto screen
    auto newGameItem = MenuItemImage::create("new_game_off.png",
                                             "new_game_on.png",
                                             CC_CALLBACK_1(MenuScene::newGameCallback, that));
    
    newGameItem->setPosition(Vec2(origin.x + visibleSize.width / 2,
                                  origin.y + (visibleSize.height - newGameItem->getContentSize().height - 120)));
    
    
    // create the load game button and place onto screen
    auto loadGameItem = MenuItemImage::create("load_game_off.png",
                                              "load_game_on.png",
                                              CC_CALLBACK_1(MenuScene::loadGameCallback, that));
    
    loadGameItem->setPosition(Vec2(origin.x + visibleSize.width / 2,
                                   origin.y + (visibleSize.height - loadGameItem->getContentSize().height - newGameItem->getContentSize().height - 140)));
    
    // create the options button and place onto screen
    auto optionsItem = MenuItemImage::create("options_off.png",
                                             "options_on.png",
                                             CC_CALLBACK_1(MenuScene::optionsCallback, that));
    
    optionsItem->setPosition(Vec2(origin.x + visibleSize.width / 2,
                                  origin.y + (visibleSize.height - loadGameItem->getContentSize().height - newGameItem->getContentSize().height - newGameItem->getContentSize().height - 160)));
    
    // add menu items to array
    pMenuItems.pushBack(newGameItem);
    pMenuItems.pushBack(loadGameItem);
    pMenuItems.pushBack(optionsItem);
    
    return pMenuItems;

}

// call this method in the main menu scene to create the main menu
void MenuController::CreateMainMenu(MenuScene *that, Size visibleSize, Vec2 origin)
{
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems = CreateMenuButtons(that, visibleSize, origin);
    
    // create menu, it's an autorelease object
    auto menu = Menu::createWithArray(pMenuItems);
    menu->setPosition(Vec2::ZERO);
    that->addChild(menu, 1);
    
    // add "MenuScene" splash screen"
    auto sprite = Sprite::create("background.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    that->addChild(sprite, 0);
    
    // add the title sprite to the menu
    sprite = Sprite::create("title.png");
    sprite->setPosition(Vec2(origin.x + visibleSize.width / 2, visibleSize.height / 2 + 250));
    
    that->addChild(sprite, 0);
}