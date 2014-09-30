//
//  HUDHelper.cpp
//  UniLife
//
//  Created by csci321ga2a on 22/09/2014.
//
//

#include "HUDHelper.h"
#include "DormScene.h"
#include "PauseMenu.h"
#include <ctime>

// SOME GLOBALS FOR AUTOSAVE
/////////////////////////////
time_t start;
int gametime;
PlayerModel player;
cocos2d::Scene* activeScene;
////////////////////////////

// this method is used to create the HUD for each scene
void HUDLayer::createHUD(cocos2d::Scene* scene)
{
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();
    
    // set the active scene for the HUD
    activeScene = scene;
    
    cocos2d::ui::Text* engText = cocos2d::ui::Text::create("Energy ", "Verdana", 20);
    cocos2d::Sprite* engSprite = cocos2d::Sprite::create("HUD_energy_bar.png");
    cocos2d::ui::Text* streText = cocos2d::ui::Text::create("Stress ", "Verdana", 20);
    cocos2d::Sprite* streSprite = cocos2d::Sprite::create("HUD_stress_bar.png");
    cocos2d::ProgressTimer* pg = cocos2d::ProgressTimer::create(engSprite);
    cocos2d::ProgressTimer* pg2 = cocos2d::ProgressTimer::create(streSprite);
    // set up the timer
    cocos2d::Label* timer = cocos2d::Label::createWithSystemFont("", "Verdana", 64);
    timer->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height - 22));
    timer->setName("Timer");
    
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems;
    
    // animate the menu button to spin
    auto pauseButton = cocos2d::Sprite::create("cog-110.png");
    
    pauseButton->setPosition(cocos2d::Vec2(visibleSize.width * .95, visibleSize.height * .90));
    
    auto rotate = cocos2d::RotateBy::create(5.0f, 360);
    
    // run this forever so it keeps on spinning
    auto action = cocos2d::RepeatForever::create(rotate);
    
    pauseButton->runAction(action);
    
    auto listener1 = cocos2d::EventListenerTouchOneByOne::create();

    listener1->setSwallowTouches(true);
    
    listener1->onTouchBegan = [](cocos2d::Touch* touch, cocos2d::Event* event){
        
        auto target = static_cast<cocos2d::Sprite*>(event->getCurrentTarget());
        
        //Get the position of the current point relative to the button
        cocos2d::Point locationInNode = target->convertToNodeSpace(touch->getLocation());
        cocos2d::Size s = target->getContentSize();
        cocos2d::Rect rect = cocos2d::Rect(0, 0, s.width, s.height);
        
        //Check the click area
        if (rect.containsPoint(locationInNode))
        {
            // activate the pause overlay
            HUDLayer::PausedPressed(event->getCurrentTarget()->getScene());
            return true;
        }
        return false;
    };
    
    scene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener1, pauseButton);
    
    engText->setContentSize(cocos2d::Size(400, 40));
    engText->setPosition(cocos2d::Vec2(origin.x + visibleSize.width / 2 - 360, visibleSize.height / 2 + 310));
    engText->setColor(cocos2d::Color3B(0,0,0));
    
    engSprite->setPosition(cocos2d::Vec2(origin.x + visibleSize.width / 2 - 475, origin.y + visibleSize.height / 2 + 300));
    engSprite->setAnchorPoint(cocos2d::Vec2(0.f,0.5f));
    engSprite->setScale(0.5 , 0.5);
    engSprite->setName("EnergyHUD");
    
    streText->setContentSize(cocos2d::Size(400, 40));
    streText->setPosition(cocos2d::Vec2(origin.x + visibleSize.width / 2 - 360, visibleSize.height / 2 + 275));
    streText->setColor(cocos2d::Color3B(0,0,0));
    streSprite->setPosition(cocos2d::Vec2(origin.x + visibleSize.width / 2 - 475, origin.y + visibleSize.height / 2 + 265));
    streSprite->setAnchorPoint(cocos2d::Vec2(0.f,0.5f));
    streSprite->setScale(0.5 , 0.5);
    streSprite->setName("StressHUD");
    
    pg->setBarChangeRate(cocos2d::Vec2(1, 0));
    pg->setAnchorPoint(cocos2d::Vec2(0.f,0.5f));
    pg->setTag(98);
    pg2->setTag(99);
    pg2->setBarChangeRate(cocos2d::Vec2(1, 0));
    pg2->setAnchorPoint(cocos2d::Vec2(0.f,0.5f));
    
    pg->setScaleX(player.getStats().getEnergy()/100.0);
    pg2->setScaleX(player.getStats().getStress()/100.0);
    pg->setPercentage(player.getStats().getEnergy()/100.0);
    pg2->setPercentage(player.getStats().getStress()/100.0);

    activeScene->addChild(engText, 1);
    activeScene->addChild(engSprite);
    activeScene->addChild(pg);
    activeScene->addChild(streText, 1);
    activeScene->addChild(streSprite);
    activeScene->addChild(pg2);
    activeScene->addChild(pauseButton);
    activeScene->addChild(timer);
    
    scene->schedule(schedule_selector(HUDLayer::updateGameTime),1.0f);
    
}

// this method is used to update the HUD bars
void HUDLayer::updateHUD(PlayerModel pm)
{
    
    player = pm;
    
    auto pgTimer = (cocos2d::ProgressTimer*)activeScene->getChildByName("EnergyHUD");
    
    pgTimer->setScaleX(player.getStats().getEnergy()/100.0);
    pgTimer->setAnchorPoint(cocos2d::Vec2(0.f,0.5f));
    
    auto pgTimer2 = (cocos2d::ProgressTimer*)activeScene->getChildByName("StressHUD");
    
    pgTimer2->setScaleX(player.getStats().getStress()/100.0);
    pgTimer2->setAnchorPoint(cocos2d::Vec2(0.f,0.5f));
    
}

void HUDLayer::PausedPressed(cocos2d::Scene* scene)
{
    cocos2d::Director::getInstance()->pause();
    cocos2d::log("Pausing the game");
    
    auto *p = PauseMenu::createScene();
    
    scene->addChild(p, 10);
}

void HUDLayer::setPlayer(PlayerModel pm)
{
    player = pm;
    
    // start the timers for this player
    start = time(0);
    gametime = 0;
}

void HUDLayer::updateGameTime(float t)
{
    double seconds_since_start = difftime( time(0), start);
    
    gametime = (int) seconds_since_start;
    
    // if the game has been played for 5 minute intervals
    if( gametime % 300 == 0)
    {
        cocos2d::log("TIME TO AUTOSAVE");
        cocos2d::log("Player: %d", player.getId());
        
        if(player.getId() > 0)
        {
            SqlHelper::autosave(player);
        }
        else
        {
            cocos2d::log("First time saving game!");
            SqlHelper::serialize(player);
        }
    }
    
    HUDLayer::updateTimer();
}

///SOME STUFF HERE FOR THE TIMER CODE

void HUDLayer::updateTimer()
{
    std::string ampm;
    std::ostringstream stringStream;
    
    TimeModel th = player.getGameTime();
    
    // set some local variables for manipulation
    double hour = th.getHoursMinutes() + 0.5;
    int day = th.getDay();
    int week = th.getWeek();
    int semester = th.getSemester();
    
    if( hour > 11.5) // roll over to afternoon
    {
        ampm = "pm";
    }
    else
    {
        ampm = "am";
    }
    
    if(hour > 23.5) // roll over to new day
    {
        hour = 12;
        ampm = "am";
        
        if(day ==  7) // roll over to new week
        {
            day = 1;
            
            if(week == 16) // roll over to new semester
            {
                week = 1;
                
                if(semester == 6) // game over
                {
                    cocos2d::log("...GAME OVER...");
                }
                
                else semester++;
            }
            
            else week++;
        }
        
        else day++;
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
    
    // update the timer with the new time
    auto timer = (cocos2d::Label*)activeScene->getChildByName("Timer");
    timer->setString(stringStream.str());
    
    // persist stat changes
    th.setHoursMinutes(hour);
    th.setDay(day);
    th.setWeek(week);
    th.setSemester(semester);
    
    // persist changes to player object
    player.setGameTime(th);
    
    //Added an update for the HUD Stress & Energy Bars
    HUDLayer::updateHUD(player);
    
}

