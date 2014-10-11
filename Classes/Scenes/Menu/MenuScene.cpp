
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
#include "SimpleAudioEngine.h"
#include "AssessmentModel.h"

USING_NS_CC;

Scene* MenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    // checks if the database initialisation has been run before
    // to ensure it gets seeded once
    bool isSeeded = UserDefault::getInstance()->getBoolForKey("seeded");
    
    if(isSeeded == false)
    {
        log("seeding the database!");
        SqlHelper::initDatabase();
        UserDefault::getInstance()->setBoolForKey("seeded", true);
    }
    
    std::vector<string> list =  SqlHelper::getDegrees();
    
    for(int i = 0 ; i < list.size(); i++)
    {
        int code = SqlHelper::getDegreeCode(list[i]);
        cout << list[i] << ", Code: " << code <<endl << endl;
        
        std::vector<string> classes = SqlHelper::getClasses(code, 1);
        std::vector<subjectBlockClassModel> subjects = SqlHelper::getBlocks(classes);
        
        for(int j = 0; j < subjects.size(); j++)
        {
            cout << subjects[i] << endl;
            
            std::vector<AssessmentModel> marks = SqlHelper::getAssignments(subjects[i].getNameString());
            
            subjects[i].setAssessments(marks);
            
            for(int z = 0; z < subjects[i].getAssessments().size(); z++)
            {
                cout << subjects[i].getAssessments()[z].getSubject() << " " << subjects[i].getAssessments()[z].getAssessmentId() << " " << subjects[i].getAssessments()[z].getPercentage() << endl;
            }
            cout << endl;
            
            
        }
        cout << endl;

    }
    
    
    
    
    // get the size of the screen that is visible
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    // create the main menu
    MenuController::CreateMainMenu(this, visibleSize, origin);
    
    return true;
}
  
void MenuScene::newGameCallback(Ref* pSender)
{
    log("new game button pressed!");
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("select.wav");
    
    auto scene = MenuNewGame::createScene();
    TransitionPageTurn *crosssfade = CCTransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
}

void MenuScene::loadGameCallback(Ref* pSender)
{
    log("load game button pressed!");
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("select.wav");
    
    // transition to the load game scene
    auto scene = MenuLoadScene::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
}

void MenuScene::optionsCallback(Ref* pSender)
{
    log("options button pressed!");
    
    // transition to the menu options scene
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("select.wav");
    
    auto scene = MenuOptionScene::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
    
}
