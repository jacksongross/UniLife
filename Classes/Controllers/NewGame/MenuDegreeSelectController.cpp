//
//  MenuDegreeSelectController.cpp
//  UniLife
//
//  Created by csci321ga2a on 21/08/2014.
//
//
#include "MenuDegreeSelectController.h"
#include "MenuNewGame.h"
#include "ExtensionMacros.h"
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
using namespace cocos2d::extension;

USING_NS_CC;

// create the buttons for the main menu
cocos2d::Vector<cocos2d::MenuItem*> MenuDegreeSelectController::CreateMenuButtons(MenuDegreeSelect *that, Size visibleSize, Vec2 origin)
{
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems;
    
    
    
    auto backButton = MenuItemImage::create("options-back.png", "options-back.png", CC_CALLBACK_1(MenuDegreeSelect::BackButtonCallback, that));
    
    backButton->setPosition(Vec2(origin.x + visibleSize.width / 2 - 500, visibleSize.height / 2 + 250));
    pMenuItems.pushBack(backButton);
    
    
    auto GoNext = MenuItemImage::create("New-Game-next_off.png","New-Game-next_on.png",CC_CALLBACK_1(MenuDegreeSelect::NextButtonCallback, that));
    GoNext->setPosition(Vec2(origin.x + visibleSize.width / 2 + 265, origin.y + (visibleSize.height / 2 - 250)));
    
    pMenuItems.pushBack(GoNext);
    
    
    
    
    
    
    
    return pMenuItems;
    
}

// call this method in the main menu scene to create the main menu
void MenuDegreeSelectController::CreateMainMenu(MenuDegreeSelect *that, Size visibleSize, Vec2 origin)
{
    log("The Degree Select Was Loaded");
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems = CreateMenuButtons(that, visibleSize, origin);
    
    // create menu, it's an autorelease object
    auto menu = Menu::createWithArray(pMenuItems);
    menu->setPosition(Vec2::ZERO);
    that->addChild(menu, 6);
    
    // add "MenuScene" splash screen"
    auto sprite = Sprite::create("New-Game-background.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    that->addChild(sprite, 0);
    
    
    Sprite *border = Sprite::create("New-Game-Border.png");
    border->setPosition(Vec2(visibleSize.width / 2 + 250, visibleSize.height/2 + origin.y - 50));
    border->setScaleX(0.5);
    that->addChild(border,1);
    
    
    Sprite *degreetitle = Sprite::create("DegreeSelect_Title.png");
    degreetitle->setPosition(Vec2(origin.x + visibleSize.width / 2, visibleSize.height / 2 + 250));
    that->addChild(degreetitle,1);
    
    
    
    Sprite *Box1 = Sprite::create("EIS_Border.png");
    Box1->setPosition(Vec2(origin.x + visibleSize.width / 2 - 420, visibleSize.height / 2 + 60));
    that->addChild(Box1,2);
    
    
    Sprite *Box2 = Sprite::create("EIS_Border.png");
    Box2->setPosition(Vec2(origin.x + visibleSize.width / 2 - 420, visibleSize.height / 2 - 185));
    that->addChild(Box2,2);
  
    Sprite *Box3 = Sprite::create("Buis_Border.png");
    Box3->setPosition(Vec2(origin.x + visibleSize.width / 2 -150, visibleSize.height / 2 + 100));
    that->addChild(Box3,2);
    
    Sprite *Box4 = Sprite::create("Art_Border.png");
    Box4->setPosition(Vec2(origin.x + visibleSize.width / 2 -150, visibleSize.height / 2 - 60));
    that->addChild(Box4,2);
    
      Sprite *Box5 = Sprite::create("SocSci_Border.png");
    Box5->setPosition(Vec2(origin.x + visibleSize.width / 2 -150, visibleSize.height / 2 - 225));
    that->addChild(Box5,2);
    
    
    /*
     
     THIS IS THE OLD CODE FOR THE MENU DEGREE SELECTION
     
    
    cocos2d::ui::ListView* lv = cocos2d::ui::ListView::create();
    cocos2d::ui::Button* model = cocos2d::ui::Button::create("backtotoppressed.png", "backtotopnormal.png");
    lv->setItemModel(model);
    for (int i = 0; i < that->clist.size(); i++)
    {
        std::string defstring = "Button ";
        std::string addstring = std::to_string(i+1);
        defstring.append(addstring);
        model->setTitleFontSize(10);
        model->setTitleText(defstring);
        model->addTouchEventListener(CC_CALLBACK_2(MenuDegreeSelect::LVTouch, that,i));
        model->setTag(i);
        
        lv->pushBackDefaultItem();
    }
    lv->setItemsMargin(10);
    lv->setGravity(cocos2d::ui::ListView::Gravity::RIGHT);
    lv->setSize(Size(300, 300));
    lv->setScale(2);
    lv->setBackGroundColor(Color3B::GRAY);
    lv->scrollToPercentBothDirection(Vec2(100,100), 0.1, false);
    lv->setPosition(Point(visibleSize.width/2 + origin.x - 100, visibleSize.height/2 + origin.y - 300));
    that->addChild(lv);
     

    
    std::string stringholder ="Selected Degree: ";
    
    cocos2d::ui::Text* DegreeSelected = cocos2d::ui::Text::create(stringholder, "Verdana", 35);
    DegreeSelected->setContentSize(Size(490, 64));
    DegreeSelected->setPosition(Vec2(origin.x + visibleSize.width / 2 - 200, visibleSize.height / 2 + 300));
    DegreeSelected->setTextHorizontalAlignment(TextHAlignment::CENTER);
    DegreeSelected->setColor(Color3B(0,0,0));
    DegreeSelected->setTag(15);
    that->addChild(DegreeSelected, 0);
    
    stringholder = "Degree Information: \n";
    cocos2d::ui::Text* DegreeIntro = cocos2d::ui::Text::create(stringholder, "Verdana", 20);
    DegreeIntro->setContentSize(Size(400, 40));
    DegreeIntro->setPosition(Vec2(origin.x + visibleSize.width / 2 - 250, visibleSize.height / 2 + 150));
    DegreeIntro->setTextHorizontalAlignment(TextHAlignment::CENTER);
    DegreeIntro->setTextVerticalAlignment(TextVAlignment::TOP);
    DegreeIntro->setColor(Color3B(0,0,0));
    DegreeIntro->setTag(16);
    that->addChild(DegreeIntro, 0);
    
    
    stringholder = "Name: ";
    cocos2d::ui::Text* NameHolder = cocos2d::ui::Text::create(stringholder, "Verdana", 20);
    NameHolder->setContentSize(Size(400, 40));
    NameHolder->setPosition(Vec2(origin.x + visibleSize.width / 2 - 350, visibleSize.height / 2 ));
    NameHolder->setTextHorizontalAlignment(TextHAlignment::CENTER);
    NameHolder->setTextVerticalAlignment(TextVAlignment::TOP);
    NameHolder->setColor(Color3B(0,0,0));
    NameHolder->setTag(17);
    that->addChild(NameHolder, 0);
    
    stringholder = "INT: ";
    cocos2d::ui::Text* INTHolder = cocos2d::ui::Text::create(stringholder, "Verdana", 20);
    INTHolder->setContentSize(Size(400, 40));
    INTHolder->setPosition(Vec2(origin.x + visibleSize.width / 2 - 350, visibleSize.height / 2 - 50));
    INTHolder->setTextHorizontalAlignment(TextHAlignment::CENTER);
    INTHolder->setTextVerticalAlignment(TextVAlignment::TOP);
    INTHolder->setColor(Color3B(0,0,0));
    INTHolder->setTag(18);
    that->addChild(INTHolder, 0);
    
    stringholder = "STA: ";
    cocos2d::ui::Text* STAHolder = cocos2d::ui::Text::create(stringholder, "Verdana", 20);
    STAHolder->setContentSize(Size(400, 40));
    STAHolder->setPosition(Vec2(origin.x + visibleSize.width / 2 - 350, visibleSize.height / 2 - 75));
    STAHolder->setTextHorizontalAlignment(TextHAlignment::CENTER);
    STAHolder->setTextVerticalAlignment(TextVAlignment::TOP);
    STAHolder->setColor(Color3B(0,0,0));
    STAHolder->setTag(19);
    that->addChild(STAHolder, 0);
    
    stringholder = "SOC: ";
    cocos2d::ui::Text* SOCHolder = cocos2d::ui::Text::create(stringholder, "Verdana", 20);
    SOCHolder->setContentSize(Size(400, 40));
    SOCHolder->setPosition(Vec2(origin.x + visibleSize.width / 2 - 350, visibleSize.height / 2 - 100));
    SOCHolder->setTextHorizontalAlignment(TextHAlignment::CENTER);
    SOCHolder->setTextVerticalAlignment(TextVAlignment::TOP);
    SOCHolder->setColor(Color3B(0,0,0));
    SOCHolder->setTag(20);
    that->addChild(SOCHolder, 0);
    
    */
    
}











