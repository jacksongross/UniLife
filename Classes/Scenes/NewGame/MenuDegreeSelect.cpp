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
#include <CCTransition.h>
#include <string>
#include <vector>
#include <UIListView.h>
#include <UIButton.h>

USING_NS_CC;



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
    loadthetestdata();

    
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
    log("List View Touched");
    
}

void MenuDegreeSelect::NextButtonCallback(Ref* pSender)
{
    
    log("Next Button Pressed");
    

}

void MenuDegreeSelect::EIS_Selected(Ref* pSender)
{
    
    facultySelected = 1;
    
    std::string facName = "Faculty of Engineering & Information Sciences";
    
    

    
}

void MenuDegreeSelect::Buis_Selected(Ref* pSender)
{
    
    facultySelected = 2;
    std::string facName = "Faculty of Buisness";

    
}


void MenuDegreeSelect::Art_Selected(Ref* pSender)
{
    
    facultySelected = 3;
    std::string facName = "Faculty of Law, Humanities & the Arts";

    
}


void MenuDegreeSelect::SciMed_Selected(Ref* pSender)
{
    
    facultySelected = 4;
    std::string facName = "Faculty of Science & Medicine";

    
}

void MenuDegreeSelect::SocSci(Ref* pSender)
{
    
    facultySelected = 5;
    std::string facName = "Faculty of Social Sciences";

    
}


void MenuDegreeSelect::loadthetestdata(){
    
    Temp_Degree load;
    load.setFacultyID(1);
    load.setDegreeName("Computer Science");
    degrees.push_back(load);
    
    
}

