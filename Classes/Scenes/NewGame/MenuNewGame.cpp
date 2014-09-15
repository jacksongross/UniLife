//
//  MenuNewGame.cpp
//  UniLife
//
//  Created by csci321ga2a on 14/08/2014.
//
//

#include "MenuNewGame.h"

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
#include <MenuDegreeSelect.h>

USING_NS_CC;
PlayerModel newplayer;

Scene* MenuNewGame::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MenuNewGame::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MenuNewGame::init()
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
    MenuNewGameController::CreateMainMenu(this, visibleSize, origin);
    return true;
}


void MenuNewGame::NextButtonCallback(Ref* pSender)
{
    std::string g_PNAME;
    int g_PINT;
    int g_PSOC;
    int g_PSTA;
    
    log("Next Button Pressed");
    
    if(totpoints >= 20){
        auto ebox = (EditBox*)this->getChildByTag(1);//Access to EditBox via tag
        
        g_PNAME = ebox->getText();
        log("%s", g_PNAME.c_str());
        
        auto s1 = (cocos2d::ui::Slider*)this->getChildByTag(2);
        auto s2 = (cocos2d::ui::Slider*)this->getChildByTag(4);
        auto s3 = (cocos2d::ui::Slider*)this->getChildByTag(6);
        
        g_PINT = s1->getPercent() / 5;
        g_PSTA = s2->getPercent() / 5;
        g_PSOC = s3->getPercent() / 5;
        
        for(int i = 2; i < 8; i+=2){
            auto inteperc = (cocos2d::ui::Slider*)this->getChildByTag(i);//Access to Slider via tag
            log("%d",inteperc->getPercent()/5);
        }
        
        PlayerStatsModel tmp;
        
        newplayer.setName(g_PNAME);
        tmp = newplayer.getStats();
        tmp.setIntelligence(g_PINT);
        tmp.setStamina(g_PSTA);
        tmp.setSocial(g_PSOC);
        tmp.setEnergy(100);
        tmp.setStress(0);
        newplayer.setStats(tmp);
        newplayer.setScene("DormScene");
        auto scene = MenuDegreeSelect::createScene(newplayer);
        TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
        Director::getInstance()->replaceScene(crosssfade);
    }else{
        log("Cannot Go Until 20 Points Spent");
    }
    
}


void MenuNewGame::backButtonCallback(Ref* pSender)
{
    log("Going Back to Menu!");
    
    auto scene = MenuScene::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
    
}



void MenuNewGame::intSliderChange(Ref *pSender, cocos2d::ui::Slider::EventType type)
{
    auto s1 = (cocos2d::ui::Slider*)this->getChildByTag(2);
    auto s2 = (cocos2d::ui::Slider*)this->getChildByTag(4);
    auto s3 = (cocos2d::ui::Slider*)this->getChildByTag(6);
    
    int totalperc = 0;
    totalperc += (s1->getPercent() / 5) + (s2->getPercent() / 5) + (s3->getPercent() / 5);
    totpoints = totalperc;
    
    
    if(totalperc < 21){
        if (type == cocos2d::ui::Slider::EventType::ON_PERCENTAGE_CHANGED)
        {
            cocos2d::ui::Slider* slider = dynamic_cast<cocos2d::ui::Slider*>(pSender);
            int percent = slider->getPercent() / limiter;
            auto displayInt = (cocos2d::ui::Text*)this->getChildByTag(3);//Access to Slider via tag
            displayInt->setString(String::createWithFormat("%d", percent)->getCString());
            prev = slider->getPercent();
        }
    }else{
        log("Slider Disabled: %d", totalperc);
        s1->setPercent(prev);
        log("Previous: %d", prev);
        
    }
    
    pointsleft = maxpoints - ((s1->getPercent() / 5) + (s2->getPercent() / 5) + (s3->getPercent() / 5));
    auto setremaining = (cocos2d::ui::Text*)this->getChildByTag(8);//Access to Slider via tag
    setremaining->setString(String::createWithFormat("%d", pointsleft)->getCString());

    
    
}

void MenuNewGame::staSliderChange(Ref *pSender, cocos2d::ui::Slider::EventType type)
{
    
    
    auto s1 = (cocos2d::ui::Slider*)this->getChildByTag(2);
    auto s2 = (cocos2d::ui::Slider*)this->getChildByTag(4);
    auto s3 = (cocos2d::ui::Slider*)this->getChildByTag(6);
    
    int totalperc = 0;
    totalperc += (s1->getPercent() / 5) + (s2->getPercent() / 5) + (s3->getPercent() / 5);
    totpoints = totalperc;
    
    
    if(totalperc < 21){
        if (type == cocos2d::ui::Slider::EventType::ON_PERCENTAGE_CHANGED)
        {
            cocos2d::ui::Slider* slider = dynamic_cast<cocos2d::ui::Slider*>(pSender);
            int percent = slider->getPercent() / limiter;
            auto displaySta = (cocos2d::ui::Text*)this->getChildByTag(5);//Access to Slider via tag
            displaySta->setString(String::createWithFormat("%d", percent)->getCString());
            prev = slider->getPercent();
        }
    }else{
        log("Slider Disabled: %d", totalperc);
        s2->setPercent(prev);
        log("Previous: %d", prev);
        
    }
    
    pointsleft = maxpoints - ((s1->getPercent() / 5) + (s2->getPercent() / 5) + (s3->getPercent() / 5));
    auto setremaining = (cocos2d::ui::Text*)this->getChildByTag(8);//Access to Slider via tag
    setremaining->setString(String::createWithFormat("%d", pointsleft)->getCString());

    
}


void MenuNewGame::socSliderChange(Ref *pSender, cocos2d::ui::Slider::EventType type)
{
    
    auto s1 = (cocos2d::ui::Slider*)this->getChildByTag(2);
    auto s2 = (cocos2d::ui::Slider*)this->getChildByTag(4);
    auto s3 = (cocos2d::ui::Slider*)this->getChildByTag(6);
    
    int totalperc = 0;
    totalperc += (s1->getPercent() / 5) + (s2->getPercent() / 5) + (s3->getPercent() / 5);
    totpoints = totalperc;
    
    
    if(totalperc < 21){
        if (type == cocos2d::ui::Slider::EventType::ON_PERCENTAGE_CHANGED)
        {
            cocos2d::ui::Slider* slider = dynamic_cast<cocos2d::ui::Slider*>(pSender);
            int percent = slider->getPercent() / limiter;
            auto displaySoc = (cocos2d::ui::Text*)this->getChildByTag(7);//Access to Slider via tag
            displaySoc->setString(String::createWithFormat("%d", percent)->getCString());
            prev = slider->getPercent();
        }
    }else{
        log("Slider Disabled: %d", totalperc);
        s3->setPercent(prev);
        log("Previous: %d", prev);
        
    }
    
    pointsleft = maxpoints - ((s1->getPercent() / 5) + (s2->getPercent() / 5) + (s3->getPercent() / 5));
    auto setremaining = (cocos2d::ui::Text*)this->getChildByTag(8);//Access to Slider via tag
    setremaining->setString(String::createWithFormat("%d", pointsleft)->getCString());

    
}

