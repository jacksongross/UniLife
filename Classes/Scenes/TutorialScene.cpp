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
    
    auto TalkText = (cocos2d::ui::Text*)this->getChildByName("IntroText");
    auto OtherText = (cocos2d::ui::Text*)this->getChildByName("OtherText");
    auto phonebutton = (Sprite*)this->getChildByName("phonebutton");
    auto highlighter = (Sprite*)this->getChildByName("highlighter");
    auto mapbutton = (cocos2d::ui::Button*)this->getChildByName("mapbutton");
    auto BG = (Sprite*)this->getChildByName("mapBG");
    auto legodude = (Sprite*)this->getChildByName("legodude");
    auto sBubble = (Sprite*)this->getChildByName("sBubble");
    
    auto ph1 = (Sprite*)this->getChildByName("ph1");
    auto ph2 = (Sprite*)this->getChildByName("ph2");
    auto ph3 = (Sprite*)this->getChildByName("ph3");
    auto ph4 = (Sprite*)this->getChildByName("ph4");
    auto ph5 = (Sprite*)this->getChildByName("ph5");
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    int faculNum;

    
    switch(whichpage){
        case 0:{
            TalkText->setTextHorizontalAlignment(cocos2d::TextHAlignment::CENTER);
            TalkText->setString("I Am your guide for Orientation Week and will \nhelp you become familiar with your studies at university");
             whichpage++;
            break;
        }
        case 1:{
            string tmp = "You are currently Enrolled In ";
            tmp.append(newplayer.getDegree());
            TalkText->setString(tmp);
             whichpage++;
            break;
        }
        case 2:{
            string tmp = "This is Your Phone, It has much of the information needed\n to live comfortably at university. You can tap it\n at any time during gameplay to bring up the menu ";
            tmp.append(newplayer.getDegree());
            TalkText->setString(tmp);
            phonebutton->setVisible(true);
            highlighter->setVisible(true);
            auto action = RepeatForever::create(Sequence::create(Blink::create(10, 20),Blink::create(10, 20),nullptr));
            highlighter->runAction(action);
            whichpage++;
        }
            break;
        case 3:{
            string tmp = "It Contains Important Information such as Player Statistics\n Your Objectives, Timetable and Course Progress,  ";
            tmp.append(newplayer.getDegree());
            TalkText->setString(tmp);
            whichpage++;
            break;
        }
        case 4:{
            TalkText->setString("Here Is A Map Of the Campus, \nYou can View it any time by Tapping the Compass Button");
            highlighter->stopAllActions();

            Rect newRect = Rect(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y, mapbutton->getContentSize().width, mapbutton->getContentSize().height);
            highlighter->setTextureRect(newRect);
            highlighter->setVisible(true);
            highlighter->setPosition(cocos2d::Vec2(visibleSize.width * .75, visibleSize.height * .85));
            mapbutton->setVisible(true);
            auto action = RepeatForever::create(Sequence::create(Blink::create(10, 20),Blink::create(10, 20),nullptr));
            highlighter->runAction(action);
            whichpage++;
            break;
        }
        case 5:{
            TalkText->setString("Press The Compass Button To Continue");
            OtherText->setString("");
            
            bool compassPress = false;
            while(!compassPress) {
                
            }
            
            break;
        }case 6:{
            highlighter->stopAllActions();
            highlighter->setVisible(false);
            auto newBG = Sprite::create("map_background.png");
            newBG->setPosition(Vec2(BG->getPositionX(),BG->getPositionY()));
            this->removeChildByName("mapBG");
            this->addChild(newBG,0);
            ph1->setVisible(true);
            ph2->setVisible(true);
            ph3->setVisible(true);
            ph4->setVisible(true);
            ph5->setVisible(true);
            TalkText->setString("This is the Map Of The University");
            OtherText->setString("");
            whichpage++;
            break;
        }case 7:{
            TalkText->setString("There Are A Total Of 5 Faculties On The Campus");
            OtherText->setString("Tap The Screen To Continue");
            break;
        }case 8:{
            TalkText->setString("Arts...");
            OtherText->setString("Tap The Screen To Continue");
            TutorialController::loadMap(this, visibleSize, origin,1);
            break;
        }case 9:{
            TalkText->setString("Social Science...");
            OtherText->setString("Tap The Screen To Continue");
            TutorialController::loadMap(this, visibleSize, origin,2);
            break;
        }case 10:{
            TalkText->setString("Business...");
            OtherText->setString("Tap The Screen To Continue");
            TutorialController::loadMap(this, visibleSize, origin,3);
            break;
        }case 11:{
            TalkText->setString("Science and Medicine...");
            OtherText->setString("Tap The Screen To Continue");
            TutorialController::loadMap(this, visibleSize, origin,4);
            break;
        }case 12:{
            TalkText->setString("and Computers and Engineering!");
            OtherText->setString("Tap The Screen To Continue");
            TutorialController::loadMap(this, visibleSize, origin,5);
            break;
        }case 13:{
            TalkText->setString("Your Faculty Buidling is Highlighted");
            OtherText->setString("Find Your Faculty Building On the Map");
            break;
        }case 14:{
            TalkText->setVisible(false);
            OtherText->setVisible(false);
            legodude->setVisible(false);
            sBubble->setVisible(false);
            srand(time(NULL)); // Seed the time
            int faculNum = rand()%(5-1)+1; // Generate the number, assign to variable.
            TutorialController::loadMap(this, visibleSize, origin,faculNum);
            whichpage++;
            break;
        }default:{
            log("NUNYAFUCKINGBUSINESSMATE");
            
        }

            
    }
    
    return true;
}
