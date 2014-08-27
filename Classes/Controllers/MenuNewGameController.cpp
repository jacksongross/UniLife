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
#include "ui/CocosGUI.h"
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
                                                  CC_CALLBACK_1(MenuNewGame::NextButtonCallback, that));
    PlayerNameReturn->setPosition(Vec2(origin.x + visibleSize.width / 2 + 400,
                                       origin.y + (visibleSize.height / 2 - 250)));
    
    pMenuItems.pushBack(PlayerNameReturn);
    
    
    // create the back button
    auto backButton = MenuItemImage::create("options-back.png", "options-back.png", CC_CALLBACK_1(MenuNewGame::backButtonCallback, that));
    
    backButton->setPosition(Vec2(origin.x + visibleSize.width / 2 - 500, visibleSize.height / 2 -250));
    pMenuItems.pushBack(backButton);
    
    
    
    
    
    
    
    
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
    
    
    
    //STATIC LABELS FOR THE PAGE
    
    //New Character Label
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
    
    
    //Stat Labels
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
    
    //Points Remaining Label
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
    m_pEditName->setTag(1);
    that->addChild(m_pEditName);
    
    
    
    
    // THE INTELLIGENCE SLIDER & ASSOCIATED LABEL END
    cocos2d::ui::Slider* slider = cocos2d::ui::Slider::create();
    slider->loadBarTexture("sliderTrack2.png");
    slider->loadSlidBallTextures("sliderThumb.png", "sliderThumb.png", "");
    slider->loadProgressBarTexture("slider_bar_active_9patch.png");
    slider->setScale9Enabled(true);
    slider->setCapInsets(Rect(0, 0, 0, 0));
    slider->setContentSize(Size(250.0f, 19));
    slider->setPosition(Vec2(origin.x + visibleSize.width / 2 - 110, origin.y + visibleSize.height / 2 + 95));
    slider->addEventListener(CC_CALLBACK_2(MenuNewGame::sliderEvent, that));
    slider->setTag(2);
    that->addChild(slider);
    
    
    CCLabelTTF* ttf7 = CCLabelTTF::create("0 ", "Verdana", 30,
                                          Size(300, 50), kCCTextAlignmentCenter);
    ttf7->setPosition(Vec2(origin.x + visibleSize.width / 2 + 300, origin.y + visibleSize.height / 2 + 95));
    ttf7->setColor(ccc3(0,0,0));
    ttf7->setTag(3);
    that->addChild(ttf7, 0);
    // THE INTELLIGENCE SLIDER & ASSOCIATED LABEL END
    
    
    
    
    // THE STAMINA SLIDER & ASSOCIATED LABEL
    cocos2d::ui::Slider* slider2 = cocos2d::ui::Slider::create();
    slider2->loadBarTexture("sliderTrack2.png");
    slider2->loadSlidBallTextures("sliderThumb.png", "sliderThumb.png", "");
    slider2->loadProgressBarTexture("slider_bar_active_9patch.png");
    slider2->setScale9Enabled(true);
    slider2->setCapInsets(Rect(0, 0, 0, 0));
    slider2->setContentSize(Size(250.0f, 19));
    slider2->setPosition(Vec2(origin.x + visibleSize.width / 2 - 110, origin.y + visibleSize.height / 2 + 50));
    slider2->addEventListener(CC_CALLBACK_2(MenuNewGame::sliderEvent2, that));
    slider2->setTag(4);
    that->addChild(slider2);
    
    
    CCLabelTTF* ttf8 = CCLabelTTF::create("0 ", "Verdana", 30,
                                          Size(300, 50), kCCTextAlignmentCenter);
    ttf8->setPosition(Vec2(origin.x + visibleSize.width / 2 + 300, origin.y + visibleSize.height / 2 +50));
    ttf8->setColor(ccc3(0,0,0));
    ttf8->setTag(5);
    that->addChild(ttf8, 0);
    // THE STAMINA SLIDER & ASSOCIATED LABEL END
    
    
    
    // THE SOCIAL SLIDER & ASSOCIATED LABEL
    cocos2d::ui::Slider* slider3 = cocos2d::ui::Slider::create();
    slider3->loadBarTexture("sliderTrack2.png");
    slider3->loadSlidBallTextures("sliderThumb.png", "sliderThumb.png", "");
    slider3->loadProgressBarTexture("slider_bar_active_9patch.png");
    slider3->setScale9Enabled(true);
    slider3->setCapInsets(Rect(0, 0, 0, 0));
    slider3->setContentSize(Size(250.0f, 19));
    slider3->setPosition(Vec2(origin.x + visibleSize.width / 2 - 110, origin.y + visibleSize.height / 2 + 10));
    slider3->addEventListener(CC_CALLBACK_2(MenuNewGame::sliderEvent3, that));
    slider3->setTag(6);
    
    that->addChild(slider3);
    
    
    CCLabelTTF* ttf9 = CCLabelTTF::create("0 ", "Verdana", 30,
                                          Size(300, 50), kCCTextAlignmentCenter);
    ttf9->setPosition(Vec2(origin.x + visibleSize.width / 2 + 300, origin.y + visibleSize.height / 2 +10));
    ttf9->setColor(ccc3(0,0,0));
    ttf9->setTag(7);
    that->addChild(ttf9, 0);
    // THE SOCIAL SLIDER & ASSOCIATED LABEL END
    
    
    
    
    CCLabelTTF* ttf10 = CCLabelTTF::create("20 ", "Verdana", 30,
                                           Size(300, 50), kCCTextAlignmentCenter);
    ttf10->setPosition(Vec2(origin.x + visibleSize.width / 2 -200, origin.y + visibleSize.height / 2 -125));
    ttf10->setColor(ccc3(0,0,0));
    ttf10->setTag(8);
    that->addChild(ttf10, 0);
    
    
    
}

















