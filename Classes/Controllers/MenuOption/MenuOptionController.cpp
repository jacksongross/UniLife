//
//  MenuOptionController.cpp
//  UniLife
//
//  Created by csci321ga2a on 8/12/14.
//
//

#include "MenuOptionController.h"
#include "MenuScene.h"
#include "cocos2d.h"

USING_NS_CC;
using namespace cocos2d::extension;

// create the buttons for the main menu
cocos2d::Vector<cocos2d::MenuItem*> MenuOptionController::CreateMenuButtons(MenuOptionScene *that, Size visibleSize, Vec2 origin)
{
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems;
    
    // create the back button 
    auto backButton = MenuItemImage::create("options-back.png", "options-back.png", CC_CALLBACK_1(MenuOptionScene::backButtonCallback, that));
    
    backButton->setPosition(Vec2(origin.x + backButton->getContentSize().width, 490 + backButton->getContentSize().height));
    
    pMenuItems.pushBack(backButton);
    
    return pMenuItems;
    
}

// call this method in the main menu scene to create the main menu
void MenuOptionController::CreateMainMenu(MenuOptionScene *that, Size visibleSize, Vec2 origin)
{
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems = CreateMenuButtons(that, visibleSize, origin);
    
    // create menu, it's an autorelease object
    auto menu = Menu::createWithArray(pMenuItems);
    menu->setPosition(Vec2::ZERO);
    that->addChild(menu, 1);
    
    // add "MenuScene" splash screen"
    auto sprite = Sprite::create("options-bg.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    that->addChild(sprite, 0);
    
    // add the title sprite to the menu
    sprite = Sprite::create("options-title.png");
    sprite->setPosition(Vec2(origin.x + visibleSize.width / 2, visibleSize.height / 2 + 250));
    
    that->addChild(sprite, 0);
    
    // add the border to the layer
    
    sprite = Sprite::create("options-border.png");
    sprite->setPosition(Vec2(origin.x + visibleSize.width / 2, visibleSize.height / 2 - 30));
    
    that->addChild(sprite, 0);
    
    //INTELLIGENCE STAT DISPLAY DATA
    
    cocos2d::ui::Text* backgroundLabel = cocos2d::ui::Text::create("Background Music", "Verdana", 30);
    backgroundLabel->setContentSize(Size(300, 50));
    backgroundLabel->setPosition(Vec2(origin.x + visibleSize.width / 2 - 270 , visibleSize.height / 2 + 40));
    backgroundLabel->setTextHorizontalAlignment(TextHAlignment::RIGHT);
    backgroundLabel->setColor(Color3B::BLACK);
    that->addChild(backgroundLabel, 2);
    
    cocos2d::ui::Slider* backgroundSlider = cocos2d::ui::Slider::create();
    backgroundSlider->loadBarTexture("sliderTrack2.png");
    backgroundSlider->loadSlidBallTextures("sliderThumb.png", "sliderThumb.png", "");
    backgroundSlider->loadProgressBarTexture("slider_bar_active_9patch.png");
    backgroundSlider->setScale9Enabled(true);
    backgroundSlider->setCapInsets(Rect(0, 0, 0, 0));
    backgroundSlider->setContentSize(Size(250.0f, 19));
    backgroundSlider->setPosition(Vec2(origin.x + visibleSize.width / 2 - 20, origin.y + visibleSize.height / 2 + 30));
    backgroundSlider->setScale(2.0);
    backgroundSlider->addEventListener(CC_CALLBACK_2(MenuOptionScene::backgroundMusicSliderChange, that));
    backgroundSlider->setTag(2);
    that->addChild(backgroundSlider, 3);
    
}