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
    
    
    // create the new game button and place onto screen
    auto backbutton = MenuItemImage::create("New-Game-Back.png",
                                            "New-Game-Back.png",
                                            CC_CALLBACK_1(MenuDegreeSelect::BackButtonCallback, that));
    backbutton->setPosition(Vec2(origin.x + visibleSize.width / 2 - 450,
                                 origin.y + (visibleSize.height / 2 - 250)));
    
    pMenuItems.pushBack(backbutton);
    
    
    auto GoNext = MenuItemImage::create("New-Game-next_off.png",
                                        "New-Game-next_on.png",
                                        CC_CALLBACK_1(MenuDegreeSelect::NextButtonCallback, that));
    GoNext->setPosition(Vec2(origin.x + visibleSize.width / 2 + 100,
                             origin.y + (visibleSize.height / 2 - 250)));
    
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
    that->addChild(menu, 1);
    
    // add "MenuScene" splash screen"
    auto sprite = Sprite::create("New-Game-background.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    that->addChild(sprite, 0);
    
    
    /*
     ::JG::
     Create Array From SQL Data
     Set an Integer to the Size of the Vector (Or Use the Direct function Vector.size())
     Make the Loop Below create Buttons to the size of the Vector
     Use { model->setTitleText(<#const std::string &text#>); } to set the name of each button to its corresponding Data
     Use { model->setTag to give the Button a unique tag ID
     
     */
    
    
    that->clist.push_back("Bachelor Of Computer Science");
    that->ilist.push_back("Degree Information: \nCourse Duration: 3 Years\n The Bachelor of Computer Science is for People who\n\t A) Dont like Sleeping\n\t B) Are Masochists\n\t C) Like to Spend their free time doing assignments \ninstead of having fun \n D) Oh Dam");
    that->clist.push_back("Bachelor Of Info Tech");
    that->clist.push_back("Bachelor Of Swaggery");
    that->clist.push_back("Master of Funk");
    that->clist.push_back("PHD in Awesome");
    that->clist.push_back("Bachelor of Sciency Stuff");
    that->clist.push_back("PHD in Mediciney Stuff");
    that->clist.push_back("Masters of Birdwatching");
    that->clist.push_back("PHD in Kicking Ass");
    that->clist.push_back("Bachelor of Chewing Gum");
    that->clist.push_back("Bachelor Of Using Crayons");
    
    
    
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
    DegreeSelected->setColor(ccc3(0,0,0));
    DegreeSelected->setTag(15);
    that->addChild(DegreeSelected, 0);
    
    stringholder = "Degree Information: \n";
    cocos2d::ui::Text* DegreeIntro = cocos2d::ui::Text::create(stringholder, "Verdana", 20);
    DegreeIntro->setContentSize(Size(400, 40));
    DegreeIntro->setPosition(Vec2(origin.x + visibleSize.width / 2 - 250, visibleSize.height / 2 + 150));
    DegreeIntro->setTextHorizontalAlignment(TextHAlignment::CENTER);
    DegreeIntro->setTextVerticalAlignment(TextVAlignment::TOP);
    DegreeIntro->setColor(ccc3(0,0,0));
    DegreeIntro->setTag(16);
    that->addChild(DegreeIntro, 0);
    
    
    stringholder = "Name: ";
    cocos2d::ui::Text* NameHolder = cocos2d::ui::Text::create(stringholder, "Verdana", 20);
    NameHolder->setContentSize(Size(400, 40));
    NameHolder->setPosition(Vec2(origin.x + visibleSize.width / 2 - 350, visibleSize.height / 2 ));
    NameHolder->setTextHorizontalAlignment(TextHAlignment::CENTER);
    NameHolder->setTextVerticalAlignment(TextVAlignment::TOP);
    NameHolder->setColor(ccc3(0,0,0));
    NameHolder->setTag(17);
    that->addChild(NameHolder, 0);
    
    stringholder = "INT: ";
    cocos2d::ui::Text* INTHolder = cocos2d::ui::Text::create(stringholder, "Verdana", 20);
    INTHolder->setContentSize(Size(400, 40));
    INTHolder->setPosition(Vec2(origin.x + visibleSize.width / 2 - 350, visibleSize.height / 2 - 50));
    INTHolder->setTextHorizontalAlignment(TextHAlignment::CENTER);
    INTHolder->setTextVerticalAlignment(TextVAlignment::TOP);
    INTHolder->setColor(ccc3(0,0,0));
    INTHolder->setTag(18);
    that->addChild(INTHolder, 0);
    
    stringholder = "STA: ";
    cocos2d::ui::Text* STAHolder = cocos2d::ui::Text::create(stringholder, "Verdana", 20);
    STAHolder->setContentSize(Size(400, 40));
    STAHolder->setPosition(Vec2(origin.x + visibleSize.width / 2 - 350, visibleSize.height / 2 - 75));
    STAHolder->setTextHorizontalAlignment(TextHAlignment::CENTER);
    STAHolder->setTextVerticalAlignment(TextVAlignment::TOP);
    STAHolder->setColor(ccc3(0,0,0));
    STAHolder->setTag(19);
    that->addChild(STAHolder, 0);
    
    stringholder = "SOC: ";
    cocos2d::ui::Text* SOCHolder = cocos2d::ui::Text::create(stringholder, "Verdana", 20);
    SOCHolder->setContentSize(Size(400, 40));
    SOCHolder->setPosition(Vec2(origin.x + visibleSize.width / 2 - 350, visibleSize.height / 2 - 100));
    SOCHolder->setTextHorizontalAlignment(TextHAlignment::CENTER);
    SOCHolder->setTextVerticalAlignment(TextVAlignment::TOP);
    SOCHolder->setColor(ccc3(0,0,0));
    SOCHolder->setTag(20);
    that->addChild(SOCHolder, 0);
    
}











