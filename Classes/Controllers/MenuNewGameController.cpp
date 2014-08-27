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
    std::string stringholder ="New Character: ";
    
    cocos2d::ui::Text* TL_NewChar = cocos2d::ui::Text::create(stringholder, "Verdana", 30);
    TL_NewChar->setContentSize(Size(300, 50));
    TL_NewChar->setPosition(Vec2(origin.x + visibleSize.width / 2, visibleSize.height / 2 + 250));
    TL_NewChar->setTextHorizontalAlignment(TextHAlignment::CENTER);
    TL_NewChar->setColor(Color3B(0,0,0));
    that->addChild(TL_NewChar);
    
    
    
    
    stringholder = "Name: ";
    cocos2d::ui::Text* TL_Name = cocos2d::ui::Text::create(stringholder, "Verdana", 30);
    TL_Name->setContentSize(Size(300, 50));
    TL_Name->setPosition(Vec2(origin.x + visibleSize.width / 2 - 350 , visibleSize.height / 2 +150));
    TL_Name->setTextHorizontalAlignment(TextHAlignment::LEFT);
    TL_Name->setColor(Color3B(0,0,0));
    that->addChild(TL_Name);
    

    
    
    stringholder = "Intelligence: ";
    cocos2d::ui::Text* TL_Intel = cocos2d::ui::Text::create(stringholder, "Verdana", 30);
    TL_Intel->setContentSize(Size(300, 50));
    TL_Intel->setPosition(Vec2(origin.x + visibleSize.width / 2 - 350 , visibleSize.height / 2 +100));
    TL_Intel->setTextHorizontalAlignment(TextHAlignment::LEFT);
    TL_Intel->setColor(Color3B(0,0,0));
    that->addChild(TL_Intel);
    
    
    
    stringholder = "Stamina: ";
    cocos2d::ui::Text* TL_Stamina = cocos2d::ui::Text::create(stringholder, "Verdana", 30);
    TL_Stamina->setContentSize(Size(300, 50));
    TL_Stamina->setPosition(Vec2(origin.x + visibleSize.width / 2 - 350 , visibleSize.height / 2 +50));
    TL_Stamina->setTextHorizontalAlignment(TextHAlignment::LEFT);
    TL_Stamina->setColor(Color3B(0,0,0));
    that->addChild(TL_Stamina);
    
    
    stringholder = "Social: ";
    cocos2d::ui::Text* TL_Social = cocos2d::ui::Text::create(stringholder, "Verdana", 30);
    TL_Social->setContentSize(Size(300, 50));
    TL_Social->setPosition(Vec2(origin.x + visibleSize.width / 2 - 350 , visibleSize.height / 2 +10));
    TL_Social->setTextHorizontalAlignment(TextHAlignment::LEFT);
    TL_Social->setColor(Color3B(0,0,0));
    that->addChild(TL_Social);
    
    
    stringholder = "Points Remaining: ";
    cocos2d::ui::Text* Tl_Points = cocos2d::ui::Text::create(stringholder, "Verdana", 30);
    Tl_Points->setContentSize(Size(300, 50));
    Tl_Points->setPosition(Vec2(origin.x + visibleSize.width / 2 -350 , visibleSize.height / 2 -125));
    Tl_Points->setTextHorizontalAlignment(TextHAlignment::LEFT);
    Tl_Points->setColor(Color3B(0,0,0));
    that->addChild(Tl_Points);
    
    
    
    
    EditBox* m_pEditName = EditBox::create((Size(300, 50)), Scale9Sprite::create("New-Game-textbox.png"));
    m_pEditName->setPosition(Vec2(origin.x + visibleSize.width / 2 - 150, origin.y + visibleSize.height / 2 + 150));
    m_pEditName->setFontColor(Color3B(0,0,0));
    m_pEditName->setPlaceHolder("   ");
    m_pEditName->setMaxLength(8);
    m_pEditName->setTag(1);
    that->addChild(m_pEditName);
    
    
    
    

    
    
    
    stringholder = "0";
    
    
    
    // THE INTELLIGENCE SLIDER & ASSOCIATED LABEL
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
    
    
    cocos2d::ui::Text* TL_DispINT = cocos2d::ui::Text::create(stringholder, "Verdana", 30);
    TL_DispINT->setContentSize(Size(300, 50));
    TL_DispINT->setPosition(Vec2(origin.x + visibleSize.width / 2 + 300, origin.y + visibleSize.height / 2 + 95));
    TL_DispINT->setTextHorizontalAlignment(TextHAlignment::LEFT);
    TL_DispINT->setTag(3);
    TL_DispINT->setColor(Color3B(0,0,0));
    that->addChild(TL_DispINT);
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
    
    cocos2d::ui::Text* TL_DispSTA = cocos2d::ui::Text::create(stringholder, "Verdana", 30);
    TL_DispSTA->setContentSize(Size(300, 50));
    TL_DispSTA->setPosition(Vec2(origin.x + visibleSize.width / 2 + 300, origin.y + visibleSize.height / 2 +50));
    TL_DispSTA->setTextHorizontalAlignment(TextHAlignment::LEFT);
    TL_DispSTA->setTag(5);
    TL_DispSTA->setColor(Color3B(0,0,0));
    that->addChild(TL_DispSTA);
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
    
    cocos2d::ui::Text* TL_DispSOC = cocos2d::ui::Text::create(stringholder, "Verdana", 30);
    TL_DispSOC->setContentSize(Size(300, 50));
    TL_DispSOC->setPosition(Vec2(origin.x + visibleSize.width / 2 + 300, origin.y + visibleSize.height / 2 +10));
    TL_DispSOC->setTextHorizontalAlignment(TextHAlignment::LEFT);
    TL_DispSOC->setTag(7);
    TL_DispSOC->setColor(Color3B(0,0,0));
    that->addChild(TL_DispSOC);
    
    // THE SOCIAL SLIDER & ASSOCIATED LABEL END
    

    
    //TEXT DISPLAY THAT HOLDS THE POINTS REMAINING INFORMATION
    stringholder = "20";
    cocos2d::ui::Text* TL_DispPOINTS = cocos2d::ui::Text::create(stringholder, "Verdana", 30);
    TL_DispPOINTS->setContentSize(Size(300, 50));
    TL_DispPOINTS->setPosition(Vec2(origin.x + visibleSize.width / 2 -50, origin.y + visibleSize.height / 2 -125));
    TL_DispPOINTS->setTextHorizontalAlignment(TextHAlignment::LEFT);
    TL_DispPOINTS->setTag(8);
    TL_DispPOINTS->setColor(Color3B(0,0,0));
    that->addChild(TL_DispPOINTS);
    
    
}

















