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
    
    auto EIS_Selected = MenuItemImage::create("EIS_Border.png","EIS_Border.png",CC_CALLBACK_1(MenuDegreeSelect::EIS_Selected, that));
    EIS_Selected->setPosition(Vec2(origin.x + visibleSize.width / 2 - 420, visibleSize.height / 2 + 60));
    
    pMenuItems.pushBack(EIS_Selected);
    
    auto SciMed_Selected = MenuItemImage::create("SciMed_Border.png","SciMed_Border.png",CC_CALLBACK_1(MenuDegreeSelect::SciMed_Selected, that));
    SciMed_Selected->setPosition(Vec2(origin.x + visibleSize.width / 2 - 420, visibleSize.height / 2 - 185));
    pMenuItems.pushBack(SciMed_Selected);
    
    auto Buis_Selected = MenuItemImage::create("Buis_Border.png","Buis_Border.png",CC_CALLBACK_1(MenuDegreeSelect::Buis_Selected, that));
    Buis_Selected->setPosition(Vec2(origin.x + visibleSize.width / 2 -150, visibleSize.height / 2 + 100));
    pMenuItems.pushBack(Buis_Selected);
    
    auto SocSci_Selected = MenuItemImage::create("SocSci_Border.png","SocSci_Border.png",CC_CALLBACK_1(MenuDegreeSelect::SocSci_Selected, that));
    SocSci_Selected->setPosition(Vec2(origin.x + visibleSize.width / 2 -150, visibleSize.height / 2 - 225));
    pMenuItems.pushBack(SocSci_Selected);
    
    auto Art_Selected = MenuItemImage::create("Art_Border.png","Art_Border.png",CC_CALLBACK_1(MenuDegreeSelect::Art_Selected, that));
    Art_Selected->setPosition(Vec2(origin.x + visibleSize.width / 2 -150, visibleSize.height / 2 - 60));
    pMenuItems.pushBack(Art_Selected);
    

    
    
    
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
    
    
    

    ui::ListView* lv = ui::ListView::create();
    that->addChild(lv, 5);

    
    
    ui::Text *Label1 = ui::Text::create("Engineering & \n Information\n Sciences", "Arial", 20);
    Label1->setPosition(Vec2(origin.x + visibleSize.width / 2 - 420, visibleSize.height / 2 + 60));
    Label1->setColor(Color3B::BLACK);
    Label1->setTextHorizontalAlignment(TextHAlignment::CENTER);
    that->addChild(Label1,8);
    
    ui::Text *Label2 = ui::Text::create("Social Sciences", "Arial", 20);
    Label2->setPosition(Vec2(origin.x + visibleSize.width / 2 -150, visibleSize.height / 2 - 225));
    Label2->setColor(Color3B::BLACK);
    Label2->setTextHorizontalAlignment(TextHAlignment::CENTER);
    that->addChild(Label2,8);
    
    ui::Text *Label3 = ui::Text::create("Buisness", "Arial", 20);
    Label3->setPosition(Vec2(origin.x + visibleSize.width / 2 -150, visibleSize.height / 2 + 100));
    Label3->setColor(Color3B::BLACK);
    Label3->setTextHorizontalAlignment(TextHAlignment::CENTER);
    that->addChild(Label3,8);
    
    ui::Text *Label4 = ui::Text::create("Creative \n Arts", "Arial", 20);
    Label4->setPosition(Vec2(origin.x + visibleSize.width / 2 -150, visibleSize.height / 2 - 60));
    Label4->setColor(Color3B::BLACK);
    Label4->setTextHorizontalAlignment(TextHAlignment::CENTER);
    that->addChild(Label4,8);
    
    ui::Text *Label5 = ui::Text::create("Sciences &\n Medicine", "Arial", 20);
    Label5->setPosition(Vec2(origin.x + visibleSize.width / 2 - 420, visibleSize.height / 2 - 185));
    Label5->setColor(Color3B::BLACK);
    Label5->setTextHorizontalAlignment(TextHAlignment::CENTER);
    that->addChild(Label5,8);
    
    
}











