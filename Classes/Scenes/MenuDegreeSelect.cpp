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
#include <CCTransition.h>
#include <string>
#include <vector>

USING_NS_CC;

extern std::string g_PNAME;
extern int g_PINT;
extern int g_PSOC;
extern int g_PSTA;



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
    
    // create the main menu
    MenuDegreeSelectController::CreateMainMenu(this, visibleSize, origin);
    
    
    auto NameText = (cocos2d::ui::Text*)this->getChildByTag(17);
    auto INTText = (cocos2d::ui::Text*)this->getChildByTag(18);
    auto SOCText = (cocos2d::ui::Text*)this->getChildByTag(19);
    auto STAText = (cocos2d::ui::Text*)this->getChildByTag(20);
    
    NameText->setString("Name: " + g_PNAME);
    INTText->setString("INT: " + std::to_string(g_PINT));
    SOCText->setString("STA: " + std::to_string(g_PSTA));
    STAText->setString("SOC: " + std::to_string(g_PSOC));
    
    
    return true;
}



void MenuDegreeSelect::BackButtonCallback(Ref* pSender)
{
    log("Going Back to Menu!");
    
    auto scene = MenuScene::createScene();
    TransitionPageTurn *crosssfade = CCTransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
    
}



void MenuDegreeSelect::LVTouch(Ref *pSender, cocos2d::ui::Widget::TouchEventType type, int whosent)
{
    
    
    switch (type)
    {
        case cocos2d::ui::Widget::TouchEventType::BEGAN:
            //log("Touch Began, Sent By: %d" ,whosent+1 , " Swallowing Event");
            break;
            
        case cocos2d::ui::Widget::TouchEventType::MOVED:
            //log("Touch Moved, Sent By: %d" ,whosent+1 , " Swallowing Event");
            break;
            
        case cocos2d::ui::Widget::TouchEventType::ENDED:{
            log("Touch Began, Sent By: %d" , whosent+1);
            auto Header = (cocos2d::ui::Text*)this->getChildByTag(15);
            auto Body = (cocos2d::ui::Text*)this->getChildByTag(16);
            
            Header->setString(clist[whosent]);
            if(whosent < ilist.size()){
                Body->setString(ilist[whosent]);
            }else{
                Body->setString("Degree Information: N/A");
                
            }
        }
            break;
            
        case cocos2d::ui::Widget::TouchEventType::CANCELED:
            //log("Touch Cancelled, Sent By: %d" ,whosent+1 , " Swallowing Event");
            break;
            
        default:
            break;
    }
}

void MenuDegreeSelect::NextButtonCallback(Ref* pSender)
{
    
    log("Next Button Pressed");
    
    
    /*
     COPIED NEXT PLACEHOLDER
     
     auto scene = MenuDegreeSelect::createScene();
     CCTransitionPageTurn *crosssfade = CCTransitionPageTurn::create(1,scene, true);
     CCDirector::sharedDirector()->replaceScene(crosssfade);
     */
    
    
}


