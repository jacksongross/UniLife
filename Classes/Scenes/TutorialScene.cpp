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
#include "DormScene.h"
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

// overloaded createScene to pass in player
cocos2d::Scene* TutorialScene::createScene(PlayerModel inplayer)
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = TutorialScene::create(inplayer);
    layer->setName("initlayer");
    
    // add layer as a child to scene
    scene->addChild(layer);
    newplayer = inplayer;
    newplayer.setStats(inplayer.getStats());
    
    
    // return the scene
    return scene;
}

// overloaded create method to take player data
TutorialScene* TutorialScene::create(PlayerModel inplayer)
{
    TutorialScene *ts = new TutorialScene();
    if (ts->init())
    {
        ts->autorelease();
        ts->setPlayer(inplayer);
        newplayer = inplayer;
    }
    else{
        ts = NULL;
    }
    return ts;
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


bool TutorialScene::nextPageOnMap(cocos2d::Touch* touch, cocos2d::Event* event){
    
    auto legodude = (Sprite*)this->getChildByName("legodude");
    auto sBubble = (Sprite*)this->getChildByName("sBubble");
    auto TalkText = (cocos2d::ui::Text*)this->getChildByName("IntroText");
    auto OtherText = (cocos2d::ui::Text*)this->getChildByName("OtherText");
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    
    
    if(lock == false){
        lock = true;
        legodude->setVisible(false);
        sBubble->setVisible(false);
        TalkText->setVisible(false);
        OtherText->setVisible(false);
        
        auto dormbutton = cocos2d::ui::Button::create("dorm.png");
        dormbutton->setPosition(Vec2(origin.x + visibleSize.width / 2 -450, origin.y + visibleSize.height / 2 -250));
        dormbutton->setScale(0.8);
        dormbutton->setName("dormbutton");
        dormbutton->addTouchEventListener(CC_CALLBACK_2(TutorialScene::dormPress, this));
        this->addChild(dormbutton,4);
        
        TutorialController::createHighlightedButton(this, visibleSize, origin, dormbutton);
        

    
    }
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
    if(lock == false){
        log("IsLocked?: false");
    }
    else{
        log("IsLocked?: true");
    }
    
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
        
        
        // change this to the player's building
        
        string degree = newplayer.getDegree();
        
        if(degree == "Bachelor of Arts" || degree == "Bachelor of Law")
        {
            whichbuild = 1;
        }
        else if(degree == "Bachelor of Education" || degree == "Bachelor of Psychology")
        {
            whichbuild = 2;
        }
        else if(degree == "Bachelor of Commerce" || degree == "Bachelor of Business")
        {
            whichbuild = 3;
        }
        else if(degree == "Bachelor of Nursing" || degree == "Bachelor of Science")
        {
            whichbuild = 4;
        }
        else
        {
            whichbuild = 5;
        }
        
        
        
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

        
        
        lock = false;
        whichpage++;
        
        
    }else if(whichpage == 16 && lock == false){
        TutorialController::createHighlightedButton(this, visibleSize, origin, officePerson);
        pBubble->setVisible(true);
        pBubbleText->setVisible(true);
        pBubbleText->setTextAreaSize(Size(235,150));
        pBubbleText->setTextHorizontalAlignment(cocos2d::TextHAlignment::CENTER);
        pBubbleText->setString("Hello");
        
        legodude->setVisible(false);
        sBubble->setVisible(false);
        TalkText->setString("");
        OtherText->setString("");
        officePerson->setTouchEnabled(true);
        lock = true;
        whichpage++;
    }else if(whichpage == 17 && lock == false){
        
        TutorialController::removeHighlightedButton(this, visibleSize, origin, officePerson);
        lock = true;
        officePerson->setTouchEnabled(false);
        
        
        
        pBubble->setVisible(true);
        pBubbleText->setString("Here is Your Timetable for this Session");
        
        whichpage++;
        
        
    }else if(whichpage == 18){
        
        lock = true;
        officePerson->setTouchEnabled(false);
        TutorialController::removeHighlightedButton(this, visibleSize, origin, officePerson);
        
        ;
        pBubbleText->setTextAreaSize(Size(235,150));
        pBubbleText->setString("You Can View Your Timetable By Selecting it On Your Phone");
        TutorialController::createHighlightedButton(this, visibleSize, origin, phonebutton);
        phonebutton->setTouchEnabled(true);
        
    }else if(whichpage == 19 && lock == false){
        phonebutton->setTouchEnabled(false);
        TutorialController::removeHighlightedButton(this, visibleSize, origin, phonebutton);
        
        
        Sprite* overlayer = Sprite::create("phone_selection.png");
        overlayer->setVisible(false);
        overlayer->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
        this->addChild(overlayer,20);
        TutorialController::createHighlightedSprite(this, visibleSize, origin, overlayer);
        log("isthis");
        whichpage++;
    }else if(whichpage == 20 && lock == false){
        
        phonebutton->setTouchEnabled(false);
        mapbutton->setTouchEnabled(true);
        
        TutorialController::removeHighlightedButton(this, visibleSize, origin, phonebutton);
        auto TalkText2 = (cocos2d::ui::Text*)this->getChildByName("IntroText");
        auto OtherText2 = (cocos2d::ui::Text*)this->getChildByName("OtherText");

        pBubbleText->setVisible(false);
        pBubble->setVisible(false);
        
        legodude->setVisible(true);
        sBubble->setVisible(true);
        TalkText2->setString("Your Phone also contains A lot of other \nimportant information");
        OtherText2->setString("Tap the compass to head back to the map");
        TutorialController::createHighlightedButton(this, visibleSize, origin, mapbutton);
        
        
        lock = true;
        
        
        
    }else if(whichpage == 21){
        lock = false;
        TutorialController::removeHighlightedButton(this, visibleSize, origin, mapbutton);
        mapbutton->setTouchEnabled(false);
        TutorialController::removeFaculty(this);
        auto TalkText2 = (cocos2d::ui::Text*)this->getChildByName("IntroText");
        auto OtherText2 = (cocos2d::ui::Text*)this->getChildByName("OtherText");
        
        mapBG->setVisible(true);
        
        TalkText2->setString("Lets Go To Your Dorm \nand start playing");
        OtherText2->setString("The Dorm Button Is Highlighted ");
        
        this->_eventDispatcher->removeAllEventListeners();
        
        auto touchListener2 = EventListenerTouchOneByOne::create();
        touchListener2->setSwallowTouches(true);
        touchListener2->onTouchBegan = CC_CALLBACK_2(TutorialScene::nextPageOnMap, this);
        _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener2, this);
        
        
    }else if(whichpage == 22){
        legodude->setVisible(false);
        sBubble->setVisible(false);
        
        whichpage++;
    }else if(whichpage >= 23){
        
        
        log("EOF");
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
            lock = false;
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
            lock = false;
            break;
        }
        case ui::Widget::TouchEventType::CANCELED:
            break;
            
        default:
            break;
    }
    
}




void TutorialScene::receptPress(Ref *pSender, ui::Widget::TouchEventType type){
    
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    switch (type)
    {
        case ui::Widget::TouchEventType::BEGAN:
            
            break;
            
        case ui::Widget::TouchEventType::MOVED:
            break;
            
        case ui::Widget::TouchEventType::ENDED:{
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
            auto *p = PhoneLayer::createScene(newplayer);
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




void TutorialScene::dormPress(Ref *pSender, ui::Widget::TouchEventType type){
    
    
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto dormbutton = (cocos2d::ui::Button*)this->getChildByName("dormbutton");
    switch (type)
    {
        case ui::Widget::TouchEventType::BEGAN:
            
            break;
            
        case ui::Widget::TouchEventType::MOVED:
            break;
            
        case ui::Widget::TouchEventType::ENDED:{
            TutorialController::removeHighlightedButton(this,visibleSize, origin, dormbutton);
            this->removeChildByName("dormbutton");
            //TutorialController::loadDorm(this,visibleSize, origin);
            
            auto scene = DormScene::createScene(newplayer);
            TransitionCrossFade *crosssfade = TransitionCrossFade::create(1,scene);
            Director::getInstance()->replaceScene(crosssfade);
           
            
            break;
        }
        case ui::Widget::TouchEventType::CANCELED:
            break;
            
        default:
            break;
    }
    
}

void TutorialScene::setPlayer(PlayerModel player)
{
    this->playerModel = player;
}

PlayerModel TutorialScene::getPlayer()
{
    return this->playerModel;
}


