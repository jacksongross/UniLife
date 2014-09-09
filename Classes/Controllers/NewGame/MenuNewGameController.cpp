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
    
    backButton->setPosition(Vec2(origin.x + visibleSize.width / 2 - 500, visibleSize.height / 2 + 250));
    pMenuItems.pushBack(backButton);
    
    
    auto quizbutton = MenuItemImage::create("New-Game-take_quiz_off.png","New-Game-take_quiz_off.png");
    quizbutton->setPosition(Vec2(origin.x + visibleSize.width / 2 - 400, visibleSize.height / 2 -250));
    pMenuItems.pushBack(quizbutton);
    
    
    
    
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
    that->addChild(menu, 2);
    
    // add "MenuScene" splash screen"
    auto sprite = Sprite::create("New-Game-background.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    that->addChild(sprite, 0);
    
    
    
    Sprite *border = Sprite::create("New-Game-Border.png");
    border->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y - 50));
    that->addChild(border,1);
    
    Sprite *title = Sprite::create("New-Game-Title.png");
    title->setPosition(Vec2(origin.x + visibleSize.width / 2, visibleSize.height / 2 + 250));
    that->addChild(title,1);
    
    
    
    //NAME ENTRY DATA
    std::string stringholder;
    stringholder = "Name: ";
    cocos2d::ui::Text* TL_Name = cocos2d::ui::Text::create(stringholder, "Verdana", 30);
    TL_Name->setContentSize(Size(300, 50));
    TL_Name->setPosition(Vec2(origin.x + visibleSize.width / 2 - 325 , visibleSize.height / 2 +140));
    TL_Name->setTextHorizontalAlignment(TextHAlignment::RIGHT);
    TL_Name->setColor(Color3B::BLACK);
    that->addChild(TL_Name,2);
    
    
    EditBox *EnterName = EditBox::create(Size(350,50), Scale9Sprite::create("New-Game-textbox.png"));
    EnterName->setPosition(Vec2(origin.x + visibleSize.width / 2 - 190, origin.y + visibleSize.height / 2 + 130));
    EnterName->setInputMode(cocos2d::extension::EditBox::InputMode::SINGLE_LINE);
    EnterName->setMaxLength(20);
    EnterName->setFontColor(Color3B::BLACK);
    EnterName->setPlaceHolder("   ");
    EnterName->setReturnType(EditBox::KeyboardReturnType::DONE);
    EnterName->setTag(1);
    that->addChild(EnterName,3);
    
    

    
    //INTELLIGENCE STAT DISPLAY DATA
    stringholder = "Intelligence ";
    cocos2d::ui::Text* TL_Intel = cocos2d::ui::Text::create(stringholder, "Verdana", 30);
    TL_Intel->setContentSize(Size(300, 50));
    TL_Intel->setPosition(Vec2(origin.x + visibleSize.width / 2 - 270 , visibleSize.height / 2 + 40));
    TL_Intel->setTextHorizontalAlignment(TextHAlignment::RIGHT);
    TL_Intel->setColor(Color3B::BLACK);
    that->addChild(TL_Intel,2);
    
    cocos2d::ui::Slider* intSlider = cocos2d::ui::Slider::create();
    intSlider->loadBarTexture("sliderTrack2.png");
    intSlider->loadSlidBallTextures("sliderThumb.png", "sliderThumb.png", "");
    intSlider->loadProgressBarTexture("slider_bar_active_9patch.png");
    intSlider->setScale9Enabled(true);
    intSlider->setCapInsets(Rect(0, 0, 0, 0));
    intSlider->setContentSize(Size(250.0f, 19));
    intSlider->setPosition(Vec2(origin.x + visibleSize.width / 2 - 20, origin.y + visibleSize.height / 2 + 30));
    intSlider->setScale(1.3);
    intSlider->addEventListener(CC_CALLBACK_2(MenuNewGame::intSliderChange, that));
    intSlider->setTag(2);
    that->addChild(intSlider,3);
    
    stringholder = "0";
    cocos2d::ui::Text* TL_DispINT = cocos2d::ui::Text::create(stringholder, "Verdana", 30);
    TL_DispINT->setPosition(Vec2(origin.x + visibleSize.width / 2 + 330, origin.y + visibleSize.height / 2 + 40));
    TL_DispINT->setTag(3);
    TL_DispINT->setColor(Color3B(0,0,0));
    that->addChild(TL_DispINT,3);
    
    
    
    
    //STAMINA STAT DISPLAY DATA
    stringholder = "\tStamina ";
    cocos2d::ui::Text* TL_Stamina = cocos2d::ui::Text::create(stringholder, "Verdana", 30);
    TL_Stamina->setContentSize(Size(300, 50));
    TL_Stamina->setPosition(Vec2(origin.x + visibleSize.width / 2 - 270 , visibleSize.height / 2 - 40));
    TL_Stamina->setTextHorizontalAlignment(TextHAlignment::RIGHT);
    TL_Stamina->setColor(Color3B::BLACK);
    that->addChild(TL_Stamina,2);
    
    cocos2d::ui::Slider* staSlider = cocos2d::ui::Slider::create();
    staSlider->loadBarTexture("sliderTrack2.png");
    staSlider->loadSlidBallTextures("sliderThumb.png", "sliderThumb.png", "");
    staSlider->loadProgressBarTexture("slider_bar_active_9patch.png");
    staSlider->setScale9Enabled(true);
    staSlider->setCapInsets(Rect(0, 0, 0, 0));
    staSlider->setContentSize(Size(250.0f, 19));
    staSlider->setPosition(Vec2(origin.x + visibleSize.width / 2 - 20, origin.y + visibleSize.height / 2 - 50));
    staSlider->setScale(1.3);
    staSlider->addEventListener(CC_CALLBACK_2(MenuNewGame::staSliderChange, that));
    staSlider->setTag(4);
    that->addChild(staSlider,3);
    
    stringholder = "0";
    cocos2d::ui::Text* TL_DispSTA = cocos2d::ui::Text::create(stringholder, "Verdana", 30);
    TL_DispSTA->setPosition(Vec2(origin.x + visibleSize.width / 2 + 330, origin.y + visibleSize.height / 2 - 40));
    TL_DispSTA->setTag(5);
    TL_DispSTA->setColor(Color3B(0,0,0));
    that->addChild(TL_DispSTA,3);
    
    
    
    
    //SOCIAL STAT DISPLAY DATA
    stringholder = "\t\tSocial ";
    cocos2d::ui::Text* TL_Social = cocos2d::ui::Text::create(stringholder, "Verdana", 30);
    TL_Social->setContentSize(Size(300, 50));
    TL_Social->setPosition(Vec2(origin.x + visibleSize.width / 2 - 270 , visibleSize.height / 2 - 120));
    TL_Social->setTextHorizontalAlignment(TextHAlignment::RIGHT);
    TL_Social->setColor(Color3B::BLACK);
    that->addChild(TL_Social,2);
    
    
    cocos2d::ui::Slider* socSlider = cocos2d::ui::Slider::create();
    socSlider->loadBarTexture("sliderTrack2.png");
    socSlider->loadSlidBallTextures("sliderThumb.png", "sliderThumb.png", "");
    socSlider->loadProgressBarTexture("slider_bar_active_9patch.png");
    socSlider->setScale9Enabled(true);
    socSlider->setCapInsets(Rect(0, 0, 0, 0));
    socSlider->setContentSize(Size(250.0f, 19));
    socSlider->setPosition(Vec2(origin.x + visibleSize.width / 2 - 20, origin.y + visibleSize.height / 2 - 130));
    socSlider->setScale(1.3);
    socSlider->addEventListener(CC_CALLBACK_2(MenuNewGame::socSliderChange, that));
    socSlider->setTag(6);
    that->addChild(socSlider,3);
    
    stringholder = "0";
    cocos2d::ui::Text* TL_DispSOC = cocos2d::ui::Text::create(stringholder, "Verdana", 30);
    TL_DispSOC->setPosition(Vec2(origin.x + visibleSize.width / 2 + 330, origin.y + visibleSize.height / 2 - 120));
    TL_DispSOC->setTag(7);
    TL_DispSOC->setColor(Color3B(0,0,0));
    that->addChild(TL_DispSOC,3);

    
    
    

    
    //POINTS AVAILABLE DISPLAY DATA
    stringholder = "Points Available: ";
    cocos2d::ui::Text* Tl_Points = cocos2d::ui::Text::create(stringholder, "Verdana", 30);
    Tl_Points->setContentSize(Size(300, 50));
    Tl_Points->setPosition(Vec2(origin.x + visibleSize.width / 2 , visibleSize.height / 2 - 225));
    Tl_Points->setTextHorizontalAlignment(TextHAlignment::RIGHT);
    Tl_Points->setColor(Color3B::BLACK);
    that->addChild(Tl_Points,2);
    
    
    stringholder = "20";
    cocos2d::ui::Text* TL_DispPOINTS = cocos2d::ui::Text::create(stringholder, "Verdana", 30);
    TL_DispPOINTS->setPosition(Vec2(origin.x + visibleSize.width / 2 + 135, origin.y + visibleSize.height / 2 - 232));
    TL_DispPOINTS->setTag(8);
    TL_DispPOINTS->setColor(Color3B::RED);
    that->addChild(TL_DispPOINTS,3);
    
    

    
   
    
    
}

















