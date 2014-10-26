//
//  MenuDegreeSelect.cpp
//  UniLife
//
//  Created by csci321ga2a on 21/08/2014.
//
//

#include "MenuDegreeSelect.h"
#include "MenuNewGame.h"
#include "MenuScene.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "MenuDegreeSelectController.h"
#include "MenuOptionScene.h"
#include "DormScene.h"
#include "HUDHelper.h"
#include <CCTransition.h>
#include <string>
#include <vector>
#include <UIListView.h>
#include <UIButton.h>

USING_NS_CC;

extern PlayerModel newplayer;

Scene* MenuDegreeSelect::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MenuDegreeSelect::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    
    
    // return the scene
    return scene;
}


cocos2d::Scene* MenuDegreeSelect::createScene(PlayerModel inplayer)
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MenuDegreeSelect::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    newplayer = inplayer;
    
    // Report on the loaded player object
    log("==========PLAYER IN DEGREE SELECT==========");
    log("NAME: %s", inplayer.getName().c_str());
    log("INT: %d", inplayer.getStats().getIntelligence());
    log("STA: %d", inplayer.getStats().getStamina());
    log("SOC: %d", inplayer.getStats().getSocial());
    log("DEGREE: %s", inplayer.getDegree().c_str());
    log("ENERGY: %d" , inplayer.getStats().getEnergy());
    log("STRESS: %d", inplayer.getStats().getStress());
    
    // return the scene
    return scene;
}


// on "init" you need to initialize your instance
bool MenuDegreeSelect::init()
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
    
    last = -1;
    
    this->setDegreesList(SqlHelper::getDegrees());
    
    // create the main menu
    MenuDegreeSelectController::CreateMainMenu(this, visibleSize, origin);   
    
    return true;
}



void MenuDegreeSelect::BackButtonCallback(Ref* pSender)
{
    log("Going Back to Menu!");
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("select.wav");
    
    auto scene = MenuScene::createScene();
    TransitionCrossFade *crossfade = TransitionCrossFade::create(0.5, scene);
    Director::getInstance()->replaceScene(crossfade);
    
}



void MenuDegreeSelect::NextButtonCallback(Ref* pSender)
{
    
    log("Next Button Pressed");
    
    log("==========PLAYER BEING SENT==========");
    log("NAME: %s", newplayer.getName().c_str());
    log("INT: %d", newplayer.getStats().getIntelligence());
    log("STA: %d", newplayer.getStats().getStamina());
    log("SOC: %d", newplayer.getStats().getSocial());
    log("DEGREE: %s", newplayer.getDegree().c_str());
    log("ENERGY: %d" , newplayer.getStats().getEnergy());
    log("STRESS: %d", newplayer.getStats().getStress());
    
    TimeModel tm;
    tm.setDay(1);
    tm.setHoursMinutes(8);
    tm.setWeek(1);
    tm.setSemester(1);
    
    PlayerModel pm(newplayer.getName(), newplayer.getDegree(), newplayer.getStats(), newplayer.getScene(), tm);
    
    std::vector<timeTableClassModel> timetable = pm.getTimeTable();
    
    std::vector<AssessmentModel> assessments;
    
    for(int i = 0; i < timetable.size(); i++)
    {
        std::vector<subjectBlockClassModel> sb = timetable[i].getClassQueue();
        
        for(int j = 0; j < sb.size(); j+= 3)
        {
            std::vector<AssessmentModel> am = sb[j].getAssessments();
            
            for(int k = 0; k < am.size(); k++)
            {
                assessments.push_back(am[k]);
            }
        }
    }
    
    pm.setAssessments(assessments);
    
    // set the player for the HUD
    HUDLayer::setPlayer(pm);
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("select.wav");
    
    auto scene = DormScene::createScene(pm);
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);

    
}

void MenuDegreeSelect::EIS_Selected(Ref* pSender)
{
    
    facultySelected = 1;
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("select.wav");
    
    this->setDegreesList(SqlHelper::getDegrees("Engineering and Information Sciences"));
    
    log("Faculty 1 Selected :: EIS");
    
    loadthelist(last);

    
}

void MenuDegreeSelect::Buis_Selected(Ref* pSender)
{
    facultySelected = 2;
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("select.wav");
    
    this->setDegreesList(SqlHelper::getDegrees("Business"));
    
    log("Faculty 2 Selected :: Buis");
    
    loadthelist(last);

}


void MenuDegreeSelect::Art_Selected(Ref* pSender)
{
    facultySelected = 3;
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("select.wav");
    
    this->setDegreesList(SqlHelper::getDegrees("Law, Humanities and the Arts"));
    
    log("Faculty 3 Selected :: Art");
    
    loadthelist(last);

}

void MenuDegreeSelect::SocSci_Selected(Ref* pSender)
{
    facultySelected = 4;
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("select.wav");
    
    this->setDegreesList(SqlHelper::getDegrees("Social Science"));
    
    log("Faculty 4 Selected :: SocSci");
    
    
    loadthelist(last);
    
    
}

void MenuDegreeSelect::SciMed_Selected(Ref* pSender)
{
    facultySelected = 5;
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("select.wav");
    
    this->setDegreesList(SqlHelper::getDegrees("Science, Medicine and Health"));
    
    log("Faculty 5 Selected :: SciMed");
    
    loadthelist(last);
    
}



void MenuDegreeSelect::LVTouch(Ref *pSender, cocos2d::ui::Text::TouchEventType type, int whosent, std::string degree)
{
    
    switch (type)
    {
        case cocos2d::ui::ListView::TouchEventType::BEGAN:
        {
            break;
        }
        case cocos2d::ui::ListView::TouchEventType::ENDED:
        {
            newplayer.setDegree(degree);
            loadthelist(whosent);
            break;

        }
        default:
            break;
    }

}

void MenuDegreeSelect::loadthelist(int withopt){

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto s1 = (cocos2d::ui::ListView*)this->getChildByTag(20);
    this->removeChild(s1);
    ui::ListView* lv = ui::ListView::create();
    ui::Text* model = ui::Text::create();
    model->setFontSize(40);
    
    lv->setItemModel(model);
    std::string compiled;
    
    std::vector<std::string> dList = this->getDegreesList();
    
    for(int i = 0; i < dList.size(); i++)
    {
        if(withopt == i)
        {
            model->setString(dList[i]);
            model->setTouchEnabled(true);
            model->addTouchEventListener(CC_CALLBACK_2(MenuDegreeSelect::LVTouch, this, i, dList[i]));
            model->setScale(1.2);
            model->setColor(Color3B::RED);
            model->setBrightStyle(cocos2d::ui::Widget::BrightStyle::HIGHLIGHT);
            compiled = facultySelected;
            compiled += " ";
            compiled += i;
            last = i;
            model->setName(compiled);
            model->setTextAreaSize(Size(500,80));
            model->setTextHorizontalAlignment(cocos2d::TextHAlignment::CENTER);
            model->setTextVerticalAlignment(cocos2d::TextVAlignment::CENTER);
            lv->pushBackDefaultItem();
        }
        else
        {
            model->setColor(Color3B::BLACK);
            model->setString(dList[i]);
            model->setTouchEnabled(true);
            model->addTouchEventListener(CC_CALLBACK_2(MenuDegreeSelect::LVTouch, this, i, dList[i]));
            
            compiled = facultySelected;
            compiled += " ";
            compiled += i;
            model->setScale(1.0);
            model->setName(compiled);
            model->setTextAreaSize(Size(500,80));
            model->setTextHorizontalAlignment(cocos2d::TextHAlignment::CENTER);
            model->setTextVerticalAlignment(cocos2d::TextVAlignment::CENTER);
            lv->pushBackDefaultItem();
            
        }
    }

    lv->setItemsMargin(10);
    lv->setGravity(ui::ListView::Gravity::CENTER_HORIZONTAL);
    lv->setSize(Size(500, 350));
    lv->setPosition(Vec2(origin.x + visibleSize.width / 2, visibleSize.height / 2 - 190));
    lv->setTag(20);
    
    this->addChild(lv, 6);

    
}

void MenuDegreeSelect::setDegreesList(std::vector<std::string> degreesList)
{
    this->degreesList = degreesList;
}

std::vector<std::string> MenuDegreeSelect::getDegreesList()
{
    return this->degreesList;
}


