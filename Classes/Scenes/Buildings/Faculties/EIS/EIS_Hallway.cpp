//
//  EIS_Hallway.cpp
//  UniLife
//
//  Created by csci321ga2a on 1/09/2014.
//
//

#include "EIS_Hallway.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "EIS_Hallway_Controller.h"
#include "MenuOptionScene.h"
#include <CCTransition.h>
#include <string>
#include <vector>
#include "MapScene.h"
#include "HUDHelper.h"

USING_NS_CC;
extern PlayerModel pm;

Scene* EIS_Hallway::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = EIS_Hallway::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    layer->setHUDScene(scene);
    
    // create the HUD
    HUDLayer::createHUD(scene);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool EIS_Hallway::init()
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
    EIS_Hallway_Controller::CreateMainMenu(this, visibleSize, origin);
    
    return true;
}

void EIS_Hallway::ToFoyer(Ref* pSender)
{
    log("Going To EIS Foyer!");
    
    auto scene = Inside_EIS::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
    
}


void EIS_Hallway::ToLecture(Ref* pSender){
    log("Going To EIS Lecture!");
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("dorm-door-opening.wav");
    
    // check whether the player is due for a lecture
    
    std::vector<timeTableClassModel> timetable = pm.getTimeTable();
    TimeModel tm = HUDLayer::getCurrentPlayer().getGameTime();
    
    std::vector<subjectBlockClassModel> classes = timetable[tm.getSemester() - 1].getClassQueue();
    
    float attendance = 0;
    
    log("time: %f", tm.getHoursMinutes());
    
    for(int i = 0; i < classes.size(); i++)
    {
        cout << classes[i].getNameString() << " " << classes[i].getDay() << " " << classes[i].getStartTime() << " " << classes[i].getTotalTimeInt() << endl;
        
        double start = classes[i].getStartTime();
        
        if(start < 9)
        {
            start += 12.0;
        }
        
        double end = classes[i].getTotalTimeInt() + start;
        
        log("Start: %f", start);
        log("End: %f", end);
        
        if(tm.getDay() == classes[i].getDay())
        {
            // calculate a buffer for attendance
            
            double bufferMin = start - 0.5;
            double bufferMax = start + 1;
            
            log("MIN: %f", bufferMin);
            log("MAX: %f", bufferMax);
            
            if(bufferMin == tm.getHoursMinutes() || start == tm.getHoursMinutes())
            {
                attendance = 1;
            }
            // if you enter the class after the start time and before the end
            else if(tm.getHoursMinutes() > bufferMax
                    && tm.getHoursMinutes() <= end)
            {
                attendance = 0.5;
            }
        }
    }
    
    log("Attendance: %f", attendance);
    
    if(attendance == 1)
    {
        HUDLayer::updateStats(0, 0, 0, -5, 10);
    }
    else if(attendance == 0.5)
    {
        HUDLayer::updateStats(0, 0, 0, -5, 15);
    }

    
}


void EIS_Hallway::ToTutorial(Ref* pSender){
    log("Going To EIS Tutorial!");
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("dorm-door-opening.wav");
    
    // check whether the player is due for a tutorial
    
    std::vector<timeTableClassModel> timetable = pm.getTimeTable();
    TimeModel tm = HUDLayer::getCurrentPlayer().getGameTime();
    
    std::vector<subjectBlockClassModel> classes = timetable[tm.getSemester() - 1].getClassQueue();
    
    float attendance = 0;
    
    log("time: %f", tm.getHoursMinutes());
    
    for(int i = 0; i < classes.size(); i++)
    {
        cout << classes[i].getNameString() << " " << classes[i].getDay() << " " << classes[i].getStartTime() << " " << classes[i].getTotalTimeInt() << endl;
        
        double start = classes[i].getStartTime();
        
        if(start < 9)
        {
            start += 12.0;
        }
        
        double end = classes[i].getTotalTimeInt() + start;
        
        log("Start: %f", start);
        log("End: %f", end);
        
        if(tm.getDay() == classes[i].getDay())
        {
            // calculate a buffer for attendance
            
            double bufferMin = start - 0.5;
            double bufferMax = start + 1;
            
            log("MIN: %f", bufferMin);
            log("MAX: %f", bufferMax);
            
            if(bufferMin == tm.getHoursMinutes() || start == tm.getHoursMinutes())
            {
                attendance = 1;
            }
            // if you enter the class after the start time and before the end
            else if(tm.getHoursMinutes() > bufferMax
                    && tm.getHoursMinutes() <= end)
            {
                attendance = 0.5;
            }
        }
    }
    
    log("Attendance: %f", attendance);
    
    if(attendance == 1)
    {
        HUDLayer::updateStats(0, 0, 0, -5, 10);
    }
    else if(attendance == 0.5)
    {
        HUDLayer::updateStats(0, 0, 0, -5, 15);
    }
    
    
}


