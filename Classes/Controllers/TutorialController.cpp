//
//  TutorialController.cpp
//  UniLife
//
//  Created by csci321ga2a on 14/10/2014.
//
//

#include "TutorialController.h"
#include "MenuNewGameController.h"
#include "MenuNewGame.h"
#include "ExtensionMacros.h"
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
using namespace cocos2d::extension;

USING_NS_CC;

// create the buttons for the main menu
cocos2d::Vector<cocos2d::MenuItem*> TutorialController::CreateMenuButtons(TutorialScene *that, Size visibleSize, Vec2 origin)
{
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems;
    
    
    
    
    return pMenuItems;
    
}

// call this method in the main menu scene to create the main menu
void TutorialController::CreateMainMenu(TutorialScene *that, Size visibleSize, Vec2 origin)
{
    log("The Tutorial Was Loaded");
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems = CreateMenuButtons(that, visibleSize, origin);
    
    // create menu, it's an autorelease object
    auto menu = Menu::createWithArray(pMenuItems);
    menu->setPosition(Vec2::ZERO);
    that->addChild(menu, 2);
    
    // add "MenuScene" splash screen"
    auto sprite = Sprite::create("gates.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    sprite->setName("phBG");
    // add the sprite as a child to this layer
    that->addChild(sprite, 0);

    
    auto mapBG = Sprite::create("map_background.png");
    
    // position the sprite on the center of the screen
    mapBG->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    mapBG->setName("mapBG");
    mapBG->setVisible(false);
    // add the sprite as a child to this layer
    that->addChild(mapBG, 0);
    
    
    auto legoface = Sprite::create("legoDude.png");
    legoface->setPosition(Vec2(visibleSize.width/2 + origin.x - 425, visibleSize.height/2 + origin.y - 200));
    legoface->setScale(0.6);
    legoface->setName("legodude");
    that->addChild(legoface, 9);
    
    
    auto sBubble = Sprite::create("speech_big.png");
    sBubble->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y -100 ));
    sBubble->setScaleX(1.8);
    sBubble->setName("sBubble");
    that->addChild(sBubble, 9);

    
    auto introText = ui::Text::create("Welcome to The University Of Wollongong", "Arial", 30);
    introText->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y -50 ));
    introText->setColor(Color3B::BLACK);
    introText->setName("IntroText");
    that->addChild(introText, 10);
    
    
    auto otherText = ui::Text::create("Tap Screen To Continue", "Arial", 20);
    otherText->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y -150 ));
    otherText->setColor(Color3B::BLACK);
    otherText->setName("OtherText");
    that->addChild(otherText, 10);

    
    
    auto phoneButton = cocos2d::ui::Button::create("phone_button.png");
    phoneButton->setPosition(cocos2d::Vec2(visibleSize.width * .90, visibleSize.height * .85));
    phoneButton->setTouchEnabled(false);
    phoneButton->setVisible(false);
    phoneButton->setName("phonebutton");
    phoneButton->addTouchEventListener(CC_CALLBACK_2(TutorialScene::phonePress, that));
    that->addChild(phoneButton,4);

    

    auto mapButton = cocos2d::ui::Button::create("Map-marker.png");
    mapButton->setPosition(cocos2d::Vec2(visibleSize.width * .75, visibleSize.height * .85));
    mapButton->setScale(0.8);
    mapButton->setTouchEnabled(false);
    mapButton->setVisible(false);
    mapButton->setName("mapbutton");
    mapButton->addTouchEventListener(CC_CALLBACK_2(TutorialScene::compassPress, that));
    that->addChild(mapButton,4);
    
    auto GoToEIS = ui::Button::create("map-computing_engineering.png");
    GoToEIS->setName("fac5");
    GoToEIS->setPosition(Vec2(origin.x + visibleSize.width / 2 + 325, origin.y + visibleSize.height / 2 + 75));
    GoToEIS->addTouchEventListener(CC_CALLBACK_2(TutorialScene::buildingPress, that));
    GoToEIS->setScale(0.8);
    GoToEIS->setVisible(false);
    GoToEIS->setTouchEnabled(false);
    that->addChild(GoToEIS,5);
    
    auto GoToSciMed = ui::Button::create("map-science_medicine.png");
    GoToSciMed->setName("fac4");
    GoToSciMed->addTouchEventListener(CC_CALLBACK_2(TutorialScene::buildingPress, that));
    GoToSciMed->setScale(0.8);
    GoToSciMed->setVisible(false);
    GoToSciMed->setPosition(Vec2(origin.x + visibleSize.width / 2 - 20, origin.y + visibleSize.height / 2 + 180));
    GoToSciMed->setScale(0.8);
    GoToSciMed->setTouchEnabled(false);
    that->addChild(GoToSciMed,5);
    
    auto GoToBuis = ui::Button::create("map-business.png");
    GoToBuis->setName("fac3");
    GoToBuis->addTouchEventListener(CC_CALLBACK_2(TutorialScene::buildingPress, that));
    GoToBuis->setScale(0.8);
    GoToBuis->setVisible(false);
    GoToBuis->setEnabled(false);
    GoToBuis->setTouchEnabled(false);
    GoToBuis->setPosition(Vec2(origin.x + visibleSize.width / 2 - 400, origin.y + visibleSize.height / 2 + 105));
    GoToBuis->setScale(0.9);
    that->addChild(GoToBuis,5);
    
    auto GoToSocSci = ui::Button::create("map-social_science.png");
    GoToSocSci->setPosition(Vec2(origin.x + visibleSize.width / 2 - 400, origin.y + visibleSize.height / 2 - 60));
    GoToSocSci->setScale(0.9);
    GoToSocSci->setName("fac2");
    GoToSocSci->addTouchEventListener(CC_CALLBACK_2(TutorialScene::buildingPress, that));
    GoToSocSci->setVisible(false);
    GoToSocSci->setEnabled(false);
    GoToSocSci->setTouchEnabled(false);
    that->addChild(GoToSocSci,5);

    auto GoToArt = ui::Button::create("map-art.png");
    GoToArt->setPosition(Vec2(origin.x + visibleSize.width / 2 -240, origin.y + visibleSize.height / 2 - 185));
    GoToArt->setScale(0.9);
    GoToArt->setName("fac1");
    GoToArt->addTouchEventListener(CC_CALLBACK_2(TutorialScene::buildingPress, that));
    GoToArt->setVisible(false);
    GoToArt->setTouchEnabled(false);
    that->addChild(GoToArt,5);
    
    
    auto pBubble = Sprite::create("speech_small.png");
    pBubble->setPosition(Vec2(origin.x + visibleSize.width / 2 -50, origin.y + visibleSize.height / 2 +150));
    pBubble->setVisible(false);
    pBubble->setName("pBubble");
    that->addChild(pBubble,5);
    
    auto pBubbleText = ui::Text::create("NANANANA BATMAN", "Verdana", 20);
    pBubbleText->setPosition(Vec2(origin.x + visibleSize.width / 2 - 50, origin.y + visibleSize.height / 2 +165));
    pBubbleText->setVisible(false);
    pBubbleText->setTextHorizontalAlignment(cocos2d::TextHAlignment::CENTER);
    pBubbleText->setTextVerticalAlignment(cocos2d::TextVAlignment::CENTER);
    pBubbleText->setColor(Color3B::BLACK);
    pBubbleText->setName("pBubbleText");
    that->addChild(pBubbleText,6);
    
}




//Set code for going into faculty building
//GoToSciMed->addTouchEventListener(CC_CALLBACK_2(TutorialController::FacultyPressed, that));

void TutorialController::loadMap(TutorialScene *that, Size visibleSize, Vec2 origin, int whichone)
{
    
    auto ph1 = (Sprite*)that->getChildByName("ph1");
    auto ph2 = (Sprite*)that->getChildByName("ph2");
    auto ph3 = (Sprite*)that->getChildByName("ph3");
    auto ph4 = (Sprite*)that->getChildByName("ph4");
    auto ph5 = (Sprite*)that->getChildByName("ph5");
    

    if(whichone == 1){
        auto facButton = (ui::Button*)that->getChildByName("fac1");
        removeHighlightedSprite(that,visibleSize, origin, ph1);
        createHighlightedButton(that, visibleSize, origin, facButton);

    }else if(whichone == 2){
        auto facButton = (ui::Button*)that->getChildByName("fac2");
        removeHighlightedSprite(that,visibleSize, origin, ph2);
        createHighlightedButton(that, visibleSize, origin, facButton);
    }else if(whichone == 3){
        auto facButton = (ui::Button*)that->getChildByName("fac3");
        removeHighlightedSprite(that,visibleSize, origin, ph3);
        createHighlightedButton(that, visibleSize, origin, facButton);
        
    }else if(whichone == 4){
        auto facButton = (ui::Button*)that->getChildByName("fac4");
        removeHighlightedSprite(that,visibleSize, origin, ph4);
        createHighlightedButton(that, visibleSize, origin, facButton);
        
    }else if(whichone == 5){
        auto facButton = (ui::Button*)that->getChildByName("fac5");
        removeHighlightedSprite(that,visibleSize, origin, ph5);
        createHighlightedButton(that, visibleSize, origin, facButton);
        
    }else{
        
        log(" BAD FACULTY INPUT ");
    }
    
}


void TutorialController::loadFaculty(TutorialScene *that, Size visibleSize, Vec2 origin, int whichone)
{
    Rect newRect;
    
    
    
    Sprite *foyerDesk = Sprite::create("desk.png");
    foyerDesk->setPosition(Vec2(origin.x + visibleSize.width / 2 + 200, origin.y + visibleSize.height / 2 -125));
    foyerDesk->setScale(1.25);
    that->addChild(foyerDesk,5);
    
    Sprite *foyerBoard = Sprite::create("whiteboard.png");
    foyerBoard->setPosition(Vec2(origin.x + visibleSize.width / 2 - 250, origin.y + visibleSize.height / 2 + 100));
    foyerBoard->setScale(1);
    that->addChild(foyerBoard,2);
    
    
    
    
    cocos2d::ui::Text* LocName = cocos2d::ui::Text::create("", "Verdana", 15);
    LocName->setColor(Color3B(0,0,0));
    LocName->setTextHorizontalAlignment(cocos2d::TextHAlignment::CENTER);
    LocName->setPosition(Vec2(origin.x + visibleSize.width / 2 - 250, origin.y + visibleSize.height / 2 +165));
    that->addChild(LocName,3);
    
    ui::Button *officePerson = ui::Button::create("wendy.png");
    officePerson->setPosition(Vec2(origin.x + visibleSize.width / 2 + 200, origin.y + visibleSize.height / 2));
    officePerson->addTouchEventListener(CC_CALLBACK_2(TutorialScene::receptPress, that));
    officePerson->setTouchEnabled(false);
    officePerson->setName("officePerson");
    that->addChild(officePerson, 4);
    
    auto fac1 = (ui::Button*)that->getChildByName("fac1");
    auto fac2 = (ui::Button*)that->getChildByName("fac2");
    auto fac3 = (ui::Button*)that->getChildByName("fac3");
    auto fac4 = (ui::Button*)that->getChildByName("fac4");
    auto fac5 = (ui::Button*)that->getChildByName("fac5");
    fac1->setTouchEnabled(false);
    fac1->setVisible(false);
    fac2->setTouchEnabled(false);
    fac2->setVisible(false);
    fac3->setTouchEnabled(false);
    fac3->setVisible(false);
    fac4->setTouchEnabled(false);
    fac4->setVisible(false);
    fac5->setTouchEnabled(false);
    fac5->setVisible(false);
    
    if(whichone == 1){
        removeHighlightedButton(that, visibleSize, origin, fac1);
        auto facBG = Sprite::create("Art_Foyer.png");
        facBG->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
        facBG->setName("facBG");
        facBG->setVisible(true);
        LocName->setString("Arts \n Notice Board");
        // add the sprite as a child to this layer
        that->addChild(facBG, 0);

        
    }else if(whichone == 2){
        removeHighlightedButton(that, visibleSize, origin, fac2);
        auto facBG = Sprite::create("SocSci_Foyer.png");
        facBG->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
        facBG->setName("facBG");
        facBG->setVisible(true);
        LocName->setString("Social Sciences \n Notice Board");
        // add the sprite as a child to this layer
        that->addChild(facBG, 0);

    }else if(whichone == 3){
        removeHighlightedButton(that, visibleSize, origin, fac3);
        auto facBG = Sprite::create("Buis_Foyer.png");
        facBG->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
        facBG->setName("facBG");
        facBG->setVisible(true);
        LocName->setString("Business \n Notice Board");
        // add the sprite as a child to this layer
        that->addChild(facBG, 0);

        
    }else if(whichone == 4){
        removeHighlightedButton(that, visibleSize, origin, fac4);
        auto facBG = Sprite::create("SciMed_Foyer.png");
        facBG->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
        facBG->setName("facBG");
        facBG->setVisible(true);
        LocName->setString("Medical Science \n Notice Board");
        // add the sprite as a child to this layer
        that->addChild(facBG, 0);
        
    }else if(whichone == 5){
        removeHighlightedButton(that, visibleSize, origin, fac5);
        auto facBG = Sprite::create("EIS_Foyer.png");
        facBG->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
        facBG->setName("facBG");
        facBG->setVisible(true);
        LocName->setString("Engineering & Information Sciences \n Notice Board");
        // add the sprite as a child to this layer
        that->addChild(facBG, 0);

        
    }else{
        
        log(" BAD FACULTY INPUT ");
    }
    
}


void TutorialController::createHighlightedSprite(TutorialScene *that, Size visibleSize, Vec2 origin,Sprite* active){
    
    auto highlighter = Sprite::create();
    highlighter->setColor(Color3B::BLUE);
    highlighter->setOpacity(90);
    Rect newRect = Rect(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y, active->getContentSize().width + 25, active->getContentSize().height + 25);
    highlighter->setTextureRect(newRect);
    highlighter->setVisible(true);
    highlighter->setScale(active->getScale());
    highlighter->setPosition(active->getPosition());
    highlighter->setName("highlighter");
    auto action = RepeatForever::create(Sequence::create(Blink::create(10, 20),Blink::create(10, 20),nullptr));
    highlighter->runAction(action);
    that->addChild(highlighter, 3);

    
    
}


void TutorialController::removeHighlightedSprite(TutorialScene *that, Size visibleSize, Vec2 origin,Sprite* active){
    
    that->removeChildByName("highlighter");

}


void TutorialController::createHighlightedButton(TutorialScene *that, Size visibleSize, Vec2 origin,ui::Button* active){
    
    
    auto highlighter = Sprite::create();
    highlighter->setColor(Color3B::BLUE);
    highlighter->setOpacity(90);
    Rect newRect = Rect(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y, active->getContentSize().width + 25, active->getContentSize().height + 25);
    highlighter->setTextureRect(newRect);
    highlighter->setVisible(true);
    highlighter->setScale(active->getScale());
    highlighter->setPosition(active->getPosition());
    highlighter->setName("highlighter");
    auto action = RepeatForever::create(Sequence::create(Blink::create(10, 20),Blink::create(10, 20),nullptr));
    highlighter->runAction(action);
    that->addChild(highlighter, 3);

    
    
}


void TutorialController::removeHighlightedButton(TutorialScene *that, Size visibleSize, Vec2 origin,ui::Button* active){
    
    that->removeChildByName("highlighter");
    
    
}


