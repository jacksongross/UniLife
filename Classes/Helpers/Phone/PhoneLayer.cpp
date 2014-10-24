//
//  PhoneLayer.cpp
//  UniLife
//
//  Created by Jackson Gross on 30/09/2014.
//
//

#include "PhoneLayer.h"
#include "PauseMenu.h"
#include "MenuScene.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "MenuController.h"
#include "MenuOptionScene.h"
#include "MenuNewGame.h"
#include <CCTransition.h>
#include <vector>
#include "DormScene.h"
#include "MenuLoadScene.h"
#include "box2D/box2D.h"
#include "HUDHelper.h"

USING_NS_CC;

extern PlayerModel pm;

string active;

Scene* PhoneLayer::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = PhoneLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    // create the background for the phone layer
    auto bg = Sprite::create("phone-bg.png");
    bg->setPosition(visibleSize.width / 2, visibleSize.height / 2);
    layer->addChild(bg);
    
    // create the buttons for the phone
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems;
    
    // player, objectives, subject, stats
    auto playerButton = MenuItemImage::create("phone_selection.png", "phone_selection.png", CC_CALLBACK_1(PhoneLayer::playerInfoCallback, layer));
    auto objectivesButton = MenuItemImage::create("phone_selection.png", "phone_selection.png", CC_CALLBACK_1(PhoneLayer::objectivesCallBack, layer));
    auto subjectButton = MenuItemImage::create("phone_selection.png", "phone_selection.png", CC_CALLBACK_1(PhoneLayer::subjectsCallBack, layer));
    auto progressButton = MenuItemImage::create("phone_selection.png", "phone_selection.png", CC_CALLBACK_1(PhoneLayer::progressCallBack, layer));
    auto closeButton = MenuItemImage::create("power-off-100.png", "power-off-100.png", CC_CALLBACK_1(PhoneLayer::closeCallBack, layer));

    closeButton->setScale(0.7);
    
    playerButton->setPosition(Vec2(visibleSize.width * .16, visibleSize.height * .2));
    objectivesButton->setPosition(Vec2(visibleSize.width * .38, visibleSize.height * .2));
    subjectButton->setPosition(Vec2(visibleSize.width * .62, visibleSize.height * .2));
    progressButton->setPosition(Vec2(visibleSize.width * .84, visibleSize.height * .2));
    closeButton->setPosition(Vec2(visibleSize.width * .92, visibleSize.height * .85));
    
    // set names for buttons
    playerButton->setName("playerbutton");
    objectivesButton->setName("objectivesbutton");
    subjectButton->setName("subjectbutton");
    progressButton->setName("progressbutton");
    
    
    playerButton->setScaleX(220 / playerButton->getContentSize().width);
    playerButton->setScaleY(125 / playerButton->getContentSize().height);
    objectivesButton->setScaleX(220 / objectivesButton->getContentSize().width);
    objectivesButton->setScaleY(125 / objectivesButton->getContentSize().height);
    subjectButton->setScaleX(220 / subjectButton->getContentSize().width);
    subjectButton->setScaleY(125 / subjectButton->getContentSize().height);
    progressButton->setScaleX(220 / progressButton->getContentSize().width);
    progressButton->setScaleY(125 / progressButton->getContentSize().height);

    
    
    // add menu items to array
    pMenuItems.pushBack(playerButton);
    pMenuItems.pushBack(objectivesButton);
    pMenuItems.pushBack(subjectButton);
    pMenuItems.pushBack(progressButton);
    pMenuItems.pushBack(closeButton);
    
    auto menu = Menu::createWithArray(pMenuItems);
    menu->setName("menu");
    menu->setPosition(Vec2::ZERO);
    layer->addChild(menu, 1);
    
    // create the labels for the buttons
    auto playerLabel = Label::createWithSystemFont(pm.getName(), "Verdana", 32);
    auto objectivesLabel = Label::createWithSystemFont("Objectives", "Verdana", 32);
    auto subjectLabel = Label::createWithSystemFont("Subjects", "Verdana", 32);
    auto progressLabel = Label::createWithSystemFont("Progress", "Verdana", 32);
    
    playerLabel->setPosition(Vec2(visibleSize.width * 0.16, visibleSize.height * 0.2));
    objectivesLabel->setPosition(Vec2(visibleSize.width * 0.38, visibleSize.height * 0.2));
    subjectLabel->setPosition(Vec2(visibleSize.width * 0.62, visibleSize.height * 0.2));
    progressLabel->setPosition(Vec2(visibleSize.width * 0.84, visibleSize.height * 0.2));
    
    playerLabel->setTextColor(Color4B(0, 0, 0, 0));
    objectivesLabel->setTextColor(Color4B(0, 0, 0, 0));
    subjectLabel->setTextColor(Color4B(0, 0, 0, 0));
    progressLabel->setTextColor(Color4B(0, 0, 0, 0));
    
    layer->addChild(playerLabel, 10);
    layer->addChild(objectivesLabel, 10);
    layer->addChild(subjectLabel, 10);
    layer->addChild(progressLabel, 10);
    
    auto playerLayer = cocos2d::Layer::create();
    playerLayer->setName("playerlayer");
    active = "playerbutton";
    auto bgl = cocos2d::Sprite::create("phone_selection.png");
    bgl->setScaleX(1000 / bgl->getContentSize().width);
    bgl->setScaleY(500 / bgl->getContentSize().height);
    playerLayer->addChild(bgl);
    playerLayer->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2));
    
    // add some details, such as time, session details, player name
    
    string time = getTimeAsString(pm.getGameTime());
    string date = getDateAsString(pm.getGameTime());
    
    auto timeLabel = Label::createWithSystemFont(time, "Verdana", 50);
    auto dateLabel = Label::createWithSystemFont(date, "Verdana", 50);
    
    timeLabel->setColor(Color3B(0,0,0));
    dateLabel->setColor(Color3B(0,0,0));
    
    timeLabel->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * .80));
    dateLabel->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * .60));
    
    layer->addChild(playerLayer);
    layer->addChild(timeLabel);
    layer->addChild(dateLabel);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool PhoneLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if( !Layer::init() )
    {
        return false;
    }
    
    pm = HUDLayer::getCurrentPlayer();
    
    return true;
}

void PhoneLayer::playerInfoCallback(Ref* pSender)
{
    this->removeChildByName("playerlayer");
    
    // get the previous tab selected and revert its selected state
    auto prevButton = (MenuItemImage *) this->getChildByName("menu")->getChildByName(active);
    prevButton->setColor(Color3B(255, 255, 255));
    
    auto button = (MenuItemImage *) this->getChildByName("menu")->getChildByName("playerbutton");
    button->setColor(Color3B(100, 100, 100));
    
    // set the previously selected element to
    active = "playerbutton";
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    cocos2d::log("pressed the info button");
    
    auto playerLayer = cocos2d::Layer::create();
    
    playerLayer->setName("playerlayer");
    
    auto bg = cocos2d::Sprite::create("phone_selection.png");
    
    bg->setScaleX(1000 / bg->getContentSize().width);
    bg->setScaleY(500 / bg->getContentSize().height);
    
    playerLayer->setContentSize(bg->getContentSize() * 4);
    
    playerLayer->addChild(bg);
    playerLayer->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2));
    
    
    Size b = bg->getContentSize();
    
    auto playersprite = cocos2d::Sprite::create("Bill/Fred.png");
    
    playersprite->setScaleX(playersprite->getScaleX() / bg->getScaleX());
    playersprite->setScaleY(playersprite->getScaleY() / bg->getScaleY());
    
    playersprite->setPosition(b.width * 0.2, b.height * 0.55);
    
    //current mood = (100 - stress) + energy)) / 2
    int mood = ((100 - pm.getStats().getStress()) + pm.getStats().getEnergy()) / 2;
    cocos2d::log("current mood: %d", mood);
    
    std::string moodDescription;
    
    if(mood > 90)
    {
        moodDescription = "Feeling Fantastic!";
    }
    else if(mood >= 75 && mood < 90)
    {
        moodDescription = "Feeling a little stressed right now.";
    }
    else if(mood >= 50 && mood < 75)
    {
        moodDescription = "Feeling quite anxious. I should try relaxing once in a while.";
    }
    else
    {
        moodDescription = "Feeling very stressed out! I need a holiday!";
    }
    
    auto moodLabel = cocos2d::ui::Text::create(moodDescription, "Verdana", 50);
    moodLabel->ignoreContentAdaptWithSize(false);
    moodLabel->setColor(Color3B(0, 0, 0));
    moodLabel->setContentSize(Size(380, 400));
    moodLabel->setTextHorizontalAlignment(TextHAlignment::CENTER);
    
    moodLabel->setScaleX(moodLabel->getScaleX() / bg->getScaleX());
    moodLabel->setScaleY(moodLabel->getScaleY() / bg->getScaleY());
    moodLabel->setPosition(Vec2(b.width * .60, b.height * 0.45));
    
    bg->addChild(playersprite);
    bg->addChild(moodLabel);
    
    this->addChild(playerLayer);
    
}

void PhoneLayer::objectivesCallBack(Ref* pSender)
{
    this->removeChildByName("playerlayer");
    
    // get the previous tab selected and revert its selected state
    auto prevButton = (MenuItemImage *) this->getChildByName("menu")->getChildByName(active);
    prevButton->setColor(Color3B(255, 255, 255));
    
    auto button = (MenuItemImage *) this->getChildByName("menu")->getChildByName("objectivesbutton");
    
    button->setColor(Color3B(100, 100, 100));
    
    active = "objectivesbutton";
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    cocos2d::log("pressed the objectives button");
    
    auto playerLayer = cocos2d::Layer::create();
    
    playerLayer->setName("playerlayer");
    
    auto bg = cocos2d::Sprite::create("phone_selection.png");
    
    bg->setScaleX(1000 / bg->getContentSize().width);
    bg->setScaleY(500 / bg->getContentSize().height);
    
    playerLayer->setContentSize(bg->getContentSize() * 4);
    
    playerLayer->addChild(bg);
    playerLayer->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2));
    
    Size b = bg->getContentSize();
    
    auto subject = cocos2d::ui::Text::create("Subject", "Verdana", 50);
    auto date = cocos2d::ui::Text::create("Date", "Verdana", 50);
    auto time = cocos2d::ui::Text::create("Time", "Verdana", 50);
    
    subject->ignoreContentAdaptWithSize(false);
    subject->setColor(Color3B(0, 0, 0));
    subject->setTextHorizontalAlignment(TextHAlignment::CENTER);
    
    date->ignoreContentAdaptWithSize(false);
    date->setColor(Color3B(0, 0, 0));
    date->setTextHorizontalAlignment(TextHAlignment::CENTER);
    
    time->ignoreContentAdaptWithSize(false);
    time->setColor(Color3B(0, 0, 0));
    time->setTextHorizontalAlignment(TextHAlignment::CENTER);
    
    subject->setScaleX(subject->getScaleX() / bg->getScaleX());
    subject->setScaleY(subject->getScaleY() / bg->getScaleY());
    subject->setPosition(Vec2(b.width * .2, b.height * 0.9));
   
    date->setScaleX(date->getScaleX() / bg->getScaleX());
    date->setScaleY(date->getScaleY() / bg->getScaleY());
    date->setPosition(Vec2(b.width * .5, b.height * 0.9));
    
    time->setScaleX(time->getScaleX() / bg->getScaleX());
    time->setScaleY(time->getScaleY() / bg->getScaleY());
    time->setPosition(Vec2(b.width * .8, b.height * 0.9));
    
    bg->addChild(subject);
    bg->addChild(date);
    bg->addChild(time);
    
    std::vector<AssessmentModel> am = pm.getAssessments();
    std::vector<AssessmentModel> dueList;
    
    TimeModel tm = pm.getGameTime();
    
    for(int i = 0; i < am.size(); i++)
    {
        // if in the current session
        if(am[i].getDueSemester() == tm.getSemester())
        {
            // if theres an assignment due within 2 weeks
            if((am[i].getDueWeek() - tm.getWeek()) <= 2)
            {
                dueList.push_back(am[i]);
            }
        }
    }
    //create some objective labels with their due dates
    
    float padding = 0.7;
    
    for(int i = 0; i < dueList.size(); i++)
    {
        string subj = dueList[i].getSubject();
        
        string d = "";
        
        int day = dueList[i].getdueDay();
        
        switch(day)
        {
            case 1:
            {
                d.append("Monday");
                break;
            }
                
            case 2:
            {
                d.append("Tuesday");
                break;
            }
                
            case 3:
            {
                d.append("Wednesday");
                break;
            }
                
            case 4:
            {
                d.append("Thursday");
                break;
            }
                
            case 5:
            {
                d.append("Friday");
                break;
            }
                
            case 6:
            {
                d.append("Saturday");
                break;
            }
                
            case 7:
            {
                d.append("Sunday");
                break;
            }
        };
        
        
        d.append(", Week ");
        d.append(to_string(dueList[i].getDueWeek()));
        string t = to_string(dueList[i].getDueTime());
        
        if(dueList[i].getDueTime() > 11.5)
        {
            t.append(":00pm");
        }
        else
        {
            t.append(":00am");
        }
        
        auto subject = cocos2d::ui::Text::create(subj, "Verdana", 32);
        auto date = cocos2d::ui::Text::create(d, "Verdana", 32);
        auto time = cocos2d::ui::Text::create(t, "Verdana", 32);
        
        subject->ignoreContentAdaptWithSize(false);
        subject->setColor(Color3B(0, 0, 0));
        subject->setTextHorizontalAlignment(TextHAlignment::CENTER);
        
        date->ignoreContentAdaptWithSize(false);
        date->setColor(Color3B(0, 0, 0));
        date->setTextHorizontalAlignment(TextHAlignment::CENTER);
        
        time->ignoreContentAdaptWithSize(false);
        time->setColor(Color3B(0, 0, 0));
        time->setTextHorizontalAlignment(TextHAlignment::CENTER);
        
        subject->setScale(subject->getScale() / 4);
        subject->setPosition(Vec2(b.width * .2, b.height * padding));
        
        date->setScale(date->getScale() / 4);
        date->setPosition(Vec2(b.width * .5, b.height * padding));
        
        time->setScale(time->getScale() / 4);
        time->setPosition(Vec2(b.width * .8, b.height * padding));
        
        bg->addChild(subject, 5);
        bg->addChild(date, 5);
        bg->addChild(time, 5);
        
        padding -= 0.1;
    }

    this->addChild(playerLayer);
}

void PhoneLayer::subjectsCallBack(Ref* pSender)
{
    this->removeChildByName("playerlayer");
    
    // get the previous tab selected and revert its selected state
    auto prevButton = (MenuItemImage *) this->getChildByName("menu")->getChildByName(active);
    prevButton->setColor(Color3B(255, 255, 255));
    
    auto button = (MenuItemImage *) this->getChildByName("menu")->getChildByName("subjectbutton");
    
    button->setColor(Color3B(100, 100, 100));
    
    active = "subjectbutton";
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    cocos2d::log("pressed the subject button");
    
    // create the default panel for opening the phone
    auto playerLayer = cocos2d::Layer::create();
    playerLayer->setName("playerlayer");
    auto bg = cocos2d::Sprite::create("phone_selection.png");
    bg->setScaleX(1000 / bg->getContentSize().width);
    bg->setScaleY(500 / bg->getContentSize().height);
    playerLayer->addChild(bg);
    playerLayer->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2));
    
    this->addChild(playerLayer);
}

void PhoneLayer::progressCallBack(Ref* pSender)
{
    this->removeChildByName("playerlayer");
    
    // get the previous tab selected and revert its selected state
    auto prevButton = (MenuItemImage *) this->getChildByName("menu")->getChildByName(active);
    prevButton->setColor(Color3B(255, 255, 255));
    
    auto button = (MenuItemImage *) this->getChildByName("menu")->getChildByName("progressbutton");
    
    button->setColor(Color3B(100, 100, 100));
    
    active = "progressbutton";
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    cocos2d::log("pressed the progress button");
    
    auto playerLayer = cocos2d::Layer::create();
    playerLayer->setName("playerlayer");
    auto bg = cocos2d::Sprite::create("phone_selection.png");
    bg->setScaleX(1000 / bg->getContentSize().width);
    bg->setScaleY(500 / bg->getContentSize().height);
    playerLayer->addChild(bg);
    playerLayer->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2));
    
    this->addChild(playerLayer);
}

void PhoneLayer::closeCallBack(Ref* pSender)
{
    this->getParent()->removeChild(this);
}

std::string PhoneLayer::getDateAsString(TimeModel tm)
{
    std::string days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
    
    std::string weeks[] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen"};
    
    std::string semesters[] = {"One", "Two", "Three", "Four"};
    
    std::string date = "";
    
    date.append(days[tm.getDay() - 1] + ", ");
    date.append("Week " + weeks[tm.getWeek() - 1] + ", ");
    date.append("Semester " + semesters[tm.getSemester() - 1]);
    
    return date;
    
}

std::string PhoneLayer::getTimeAsString(TimeModel tm)
{
    std::string ampm;
    std::ostringstream stringStream;
    std::string time;
    
    double hour = tm.getHoursMinutes();
    
    if( hour > 11.5) // roll over to afternoon
    {
        ampm = "pm";
    }
    else
    {
        ampm = "am";
    }
    
    stringStream << (int)hour << ":";
    
    if((hour + 0.5) == ceil(hour))
    {
        stringStream << "30" << ampm;
    }
    else
    {
        stringStream << "00" << ampm;
    }
    
    time = stringStream.str();
    
    return time;
    
}

