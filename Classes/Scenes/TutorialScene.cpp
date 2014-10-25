//
//  TutorialScene.cpp
//  UniLife
//
//  Created by csci321ga2a on 14/10/2014.
//
//

#include "TutorialScene.h"
#include "TutorialController.h"
#include "MenuScene.h"
#include "PlayerModel.h"
#include "PlayerStatsModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "MenuNewGameController.h"
#include "MenuOptionScene.h"
#include <CCTransition.h>
#include "PhoneLayer.h"
#include <string>
#include <vector>
USING_NS_CC;
extern PlayerModel newplayer;

Scene* TutorialScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = TutorialScene::create();
    layer->setName("initlayer");
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool TutorialScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    // get the size of the screen that is visible
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    // create the main menu
    TutorialController::CreateMainMenu(this, visibleSize, origin);
    
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(TutorialScene::nextPage, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    return true;
}


bool TutorialScene::nextPage(cocos2d::Touch* touch, cocos2d::Event* event){
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto legodude = (Sprite*)this->getChildByName("legodude");
    auto sBubble = (Sprite*)this->getChildByName("sBubble");
    auto TalkText = (cocos2d::ui::Text*)this->getChildByName("IntroText");
    auto OtherText = (cocos2d::ui::Text*)this->getChildByName("OtherText");
    auto phonebutton = (ui::Button*)this->getChildByName("phonebutton");
    auto mapbutton = (cocos2d::ui::Button*)this->getChildByName("mapbutton");
    auto fac1 = (cocos2d::ui::Button*)this->getChildByName("fac1");
    auto fac2 = (cocos2d::ui::Button*)this->getChildByName("fac2");
    auto fac3 = (cocos2d::ui::Button*)this->getChildByName("fac3");
    auto fac4 = (cocos2d::ui::Button*)this->getChildByName("fac4");
    auto fac5 = (cocos2d::ui::Button*)this->getChildByName("fac5");
    auto phBG = (Sprite*)this->getChildByName("phBG");
    auto mapBG = (Sprite*)this->getChildByName("mapBG");
    auto officePerson = (ui::Button*)this->getChildByName("officePerson");
    auto pBubble = (Sprite*)this->getChildByName("pBubble");
    auto pBubbleText = (ui::Text*)this->getChildByName("pBubbleText");
    
    log("GO TO NEXT PAGE %d",whichpage);
    
    
    if(whichpage ==  0){
        TalkText->setTextHorizontalAlignment(cocos2d::TextHAlignment::CENTER);
        TalkText->setString("I Am your guide for Orientation Week and will \nhelp you become familiar with your studies at university");
        whichpage++;
    }else if(whichpage ==  1){
        string tmp = "You are currently Enrolled In ";
        tmp.append(newplayer.getDegree());
        TalkText->setString(tmp);
        whichpage++;
    }else if(whichpage ==  2){
        string tmp = "This is Your Phone, It has much of the information needed\n to live comfortably at university. You can tap it\n at any time during gameplay to bring up the menu ";
        TalkText->setString(tmp);
        phonebutton->setVisible(true);
        TutorialController::createHighlightedButton(this, visibleSize, origin, phonebutton);
        whichpage++;
    }else if(whichpage ==  3){
        string tmp = "It Contains Important Information such as Player Statistics\n Your Objectives, Timetable and Course Progress,  ";
        tmp.append(newplayer.getDegree());
        TalkText->setString(tmp);
        whichpage++;
    }else if(whichpage ==  4){
        TalkText->setString("Here Is A Map Of the Campus, \nYou can View it any time by Tapping the Compass Button");
        TutorialController::removeHighlightedButton(this, visibleSize, origin, phonebutton);
        TutorialController::createHighlightedButton(this, visibleSize, origin, mapbutton);
        mapbutton->setVisible(true);
        whichpage++;
    }else if(whichpage ==  5){
        TalkText->setString("Press The Compass Button To Continue");
        OtherText->setString("");
        mapbutton->setTouchEnabled(true);

    }else if(whichpage ==  6){
        TutorialController::removeHighlightedButton(this, visibleSize, origin, mapbutton);
        mapBG->setVisible(true);
        phBG->setVisible(false);
        fac1->setVisible(true);
        fac2->setVisible(true);
        fac3->setVisible(true);
        fac4->setVisible(true);
        fac5->setVisible(true);
        TalkText->setString("This is the Map Of The University");
        OtherText->setString("");
        whichpage++;

    }else if(whichpage ==  7){
        TalkText->setString("There Are A Total Of 5 Faculties On The Campus");
        OtherText->setString("Tap The Screen To Continue");
        whichpage++;
    }else if(whichpage ==  8){
        TalkText->setString("Arts...");
        TutorialController::createHighlightedButton(this, visibleSize, origin, fac1);
        OtherText->setString("Tap The Screen To Continue");
        TutorialController::loadMap(this, visibleSize, origin,1);
        whichpage++;
    }else if(whichpage ==  9){
        TalkText->setString("Social Science...");
        TutorialController::removeHighlightedButton(this, visibleSize, origin, fac1);
        TutorialController::createHighlightedButton(this, visibleSize, origin, fac2);
        OtherText->setString("Tap The Screen To Continue");
        TutorialController::loadMap(this, visibleSize, origin,2);
        whichpage++;
    }else if(whichpage ==  10){
        TalkText->setString("Business...");
        TutorialController::removeHighlightedButton(this, visibleSize, origin, fac2);
        TutorialController::createHighlightedButton(this, visibleSize, origin, fac3);
        OtherText->setString("Tap The Screen To Continue");
        TutorialController::loadMap(this, visibleSize, origin,3);
        whichpage++;
    }else if(whichpage ==  11){
        TalkText->setString("Science and Medicine...");
        TutorialController::removeHighlightedButton(this, visibleSize, origin, fac3);
        TutorialController::createHighlightedButton(this, visibleSize, origin, fac4);
        OtherText->setString("Tap The Screen To Continue");
        TutorialController::loadMap(this, visibleSize, origin,4);
        whichpage++;
    }else if(whichpage ==  12){
        TalkText->setString("and Computers and Engineering!");
         TutorialController::removeHighlightedButton(this, visibleSize, origin, fac4);
        TutorialController::createHighlightedButton(this, visibleSize, origin, fac5);
        
        OtherText->setString("Tap The Screen To Continue");
        whichpage++;
    }else if(whichpage ==  13){
        TutorialController::removeHighlightedButton(this, visibleSize, origin, fac5);
        TalkText->setString("Your Faculty Buidling is Highlighted");
        OtherText->setString("Find Your Faculty Building On the Map");
        whichpage++;
    }else if(whichpage == 14 && lock == false){

        auto TalkText2 = (cocos2d::ui::Text*)this->getChildByName("IntroText");
        auto OtherText2 = (cocos2d::ui::Text*)this->getChildByName("OtherText");
        
        whichbuild = rand()%(6-1)+1;
        log("whichbuild: %d", whichbuild);
        TutorialController::loadMap(this, visibleSize, origin,whichbuild);
        if(whichbuild == 1){
            auto GoToFaculty = (ui::Button*)this->getChildByName("fac1");
            GoToFaculty->setTouchEnabled(true);
            GoToFaculty->setEnabled(true);
        }else if(whichbuild == 2){
            auto GoToFaculty = (ui::Button*)this->getChildByName("fac2");
            GoToFaculty->setTouchEnabled(true);
            GoToFaculty->setEnabled(true);
        }else if(whichbuild == 3){
            auto GoToFaculty = (ui::Button*)this->getChildByName("fac3");
            GoToFaculty->setTouchEnabled(true);
            GoToFaculty->setEnabled(true);
        }else if(whichbuild == 4){
            auto GoToFaculty = (ui::Button*)this->getChildByName("fac4");
            GoToFaculty->setTouchEnabled(true);
            GoToFaculty->setEnabled(true);
        }else if(whichbuild == 5){
            auto GoToFaculty = (ui::Button*)this->getChildByName("fac5");
            GoToFaculty->setTouchEnabled(true);
            GoToFaculty->setEnabled(true);
        }
        
        legodude->setVisible(false);
        sBubble->setVisible(false);
        TalkText2->setString("");
        OtherText2->setString("");
        
        lock = true;
        
        
    }else if(whichpage == 15){
        auto TalkText2 = (cocos2d::ui::Text*)this->getChildByName("IntroText");
        auto OtherText2 = (cocos2d::ui::Text*)this->getChildByName("OtherText");
        TutorialController::removeHighlightedButton(this, visibleSize, origin, mapbutton);
        mapBG->setVisible(false);
        this->removeChild(fac1);
        this->removeChild(fac2);
        this->removeChild(fac3);
        this->removeChild(fac4);
        this->removeChild(fac5);
        legodude->setVisible(true);
        sBubble->setVisible(true);
        TalkText2->setString("This is Your Faculty Building");
        OtherText2->setString("Tap the Receptionist to talk to them");

        
        pBubble->setVisible(true);
        pBubbleText->setVisible(true);
        pBubbleText->setTextAreaSize(Size(235,150));
        pBubbleText->setTextHorizontalAlignment(cocos2d::TextHAlignment::CENTER);
        pBubbleText->setString("Hello");
        
        lock = false;
        whichpage++;
        
        
    }else if(whichpage == 16 && lock == false){
        TutorialController::createHighlightedButton(this, visibleSize, origin, officePerson);
        legodude->setVisible(false);
        sBubble->setVisible(false);
        TalkText->setString("");
        OtherText->setString("");
        officePerson->setTouchEnabled(true);
        lock = true;
        
    }else if(whichpage == 17 && lock == false){
        
        TutorialController::removeHighlightedButton(this, visibleSize, origin, officePerson);
        lock = false;
        officePerson->setTouchEnabled(false);
        
        
        
        pBubble->setVisible(true);
        pBubbleText->setVisible(true);
        pBubbleText->setTextAreaSize(Size(235,150));
        pBubbleText->setString("Here is Your Timetable for this Session");
        
        whichpage++;
        
        
    }else if(whichpage == 18){
        
        lock = true;
        officePerson->setTouchEnabled(false);
        TutorialController::removeHighlightedButton(this, visibleSize, origin, officePerson);
        
        
        pBubble->setVisible(true);
        pBubbleText->setVisible(true);
        pBubbleText->setTextAreaSize(Size(235,150));
        pBubbleText->setString("You Can View Your Timetable By Selecting it On Your Phone");
        TutorialController::createHighlightedButton(this, visibleSize, origin, phonebutton);
        phonebutton->setTouchEnabled(true);
        
    }else if(whichpage == 19 && lock == false){
        
        TutorialController::removeHighlightedButton(this, visibleSize, origin, phonebutton);
        
        auto coverSprite = Sprite::create();
        coverSprite->setPosition(Vec2(visibleSize.width * 0.2, visibleSize.height * 0.9));
        coverSprite->setName("coversprite");
        this->addChild(coverSprite);
        TutorialController::createHighlightedSprite(this, visibleSize, origin, coverSprite);
        
        
        
    }
    
    
    
    
    
    
    
    
    return true;
}



void TutorialScene::compassPress(Ref *pSender, ui::Widget::TouchEventType type){
    
    switch (type)
    {
        case ui::Widget::TouchEventType::BEGAN:

            break;
            
        case ui::Widget::TouchEventType::MOVED:
            break;
            
        case ui::Widget::TouchEventType::ENDED:{
            whichpage++;
            auto mapbutton = (cocos2d::ui::Button*)this->getChildByName("mapbutton");
            mapbutton->setTouchEnabled(false);
            Touch* newtouch;
            Event* newEvent;
            TutorialScene::nextPage(newtouch,newEvent);
            break;
        }
        case ui::Widget::TouchEventType::CANCELED:
            break;
            
        default:
            break;
    }

    
}


void TutorialScene::buildingPress(Ref *pSender, ui::Widget::TouchEventType type){

    
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    switch (type)
    {
        case ui::Widget::TouchEventType::BEGAN:
            
            break;
            
        case ui::Widget::TouchEventType::MOVED:
            break;
            
        case ui::Widget::TouchEventType::ENDED:{
            whichpage++;
            TutorialController::loadFaculty(this, visibleSize, origin, whichbuild);
            Touch* newtouch;
            Event* newEvent;
            TutorialScene::nextPage(newtouch,newEvent);
            break;
        }
        case ui::Widget::TouchEventType::CANCELED:
            break;
            
        default:
            break;
    }
    
}




void TutorialScene::receptPress(Ref *pSender, ui::Widget::TouchEventType type){
    
    
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    switch (type)
    {
        case ui::Widget::TouchEventType::BEGAN:
            
            break;
            
        case ui::Widget::TouchEventType::MOVED:
            break;
            
        case ui::Widget::TouchEventType::ENDED:{
                whichpage++;
                Touch* newtouch;
                Event* newEvent;
                TutorialScene::nextPage(newtouch,newEvent);
                lock = false;
            
            break;
        }
        case ui::Widget::TouchEventType::CANCELED:
            break;
            
        default:
            break;
    }
    
}


void TutorialScene::phonePress(Ref *pSender, ui::Widget::TouchEventType type){
    
    
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    switch (type)
    {
        case ui::Widget::TouchEventType::BEGAN:
            
            break;
            
        case ui::Widget::TouchEventType::MOVED:
            break;
            
        case ui::Widget::TouchEventType::ENDED:{
            whichpage++;
            Touch* newtouch;
            Event* newEvent;
            TutorialScene::nextPage(newtouch,newEvent);
            
            this->pause();
            auto *p = PhoneLayer::createScene();
            this->addChild(p, 10);
            lock = false;
            
            
            
            
            break;
        }
        case ui::Widget::TouchEventType::CANCELED:
            break;
            
        default:
            break;
    }
    
}
