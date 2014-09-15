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

extern PlayerModel newplayer;
int last;
int facultySelected;

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
    
    auto scene = DormScene::createScene(newplayer);
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);

    
}

void MenuDegreeSelect::EIS_Selected(Ref* pSender)
{
    
    facultySelected = 1;
    
    log("Faculty 1 Selected :: EIS");
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto s1 = (cocos2d::ui::ListView*)this->getChildByTag(20);
    this->removeChild(s1);
    
    ui::ListView* lv = ui::ListView::create();
    ui::Text* model = ui::Text::create();
    model->setColor(Color3B::BLACK);
    model->setFontSize(40);
    
    lv->setItemModel(model);
    
    for (int i=0; i < degrees.size(); i++)
    {
        if(facultySelected == degrees[i].getFacultyID()){
            model->setString(degrees[i].getDegreeName());
            model->setTouchEnabled(true);
            model->addTouchEventListener(CC_CALLBACK_2(MenuDegreeSelect::LVTouch, this, i));
            model->setTag(50+i);
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

void MenuDegreeSelect::Buis_Selected(Ref* pSender)
{
    facultySelected = 2;
    
    log("Faculty 2 Selected :: Buis");
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto s1 = (cocos2d::ui::ListView*)this->getChildByTag(20);
    this->removeChild(s1);
    
    ui::ListView* lv = ui::ListView::create();
    ui::Text* model = ui::Text::create();
    model->setColor(Color3B::BLACK);
    model->setFontSize(40);
    
    lv->setItemModel(model);
    
    for (int i=0; i < degrees.size(); i++)
    {
        if(facultySelected == degrees[i].getFacultyID()){
            model->setString(degrees[i].getDegreeName());
            model->setTouchEnabled(true);
            model->addTouchEventListener(CC_CALLBACK_2(MenuDegreeSelect::LVTouch, this, i));
            model->setTag(50+i);
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


void MenuDegreeSelect::Art_Selected(Ref* pSender)
{
    facultySelected = 3;
    
    log("Faculty 3 Selected :: Art");
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto s1 = (cocos2d::ui::ListView*)this->getChildByTag(20);
    this->removeChild(s1);
    
    ui::ListView* lv = ui::ListView::create();
    ui::Text* model = ui::Text::create();
    model->setColor(Color3B::BLACK);
    model->setFontSize(40);
    
    lv->setItemModel(model);
    
    for (int i=0; i < degrees.size(); i++)
    {
        if(facultySelected == degrees[i].getFacultyID()){
            model->setString(degrees[i].getDegreeName());
            model->setTouchEnabled(true);
            model->addTouchEventListener(CC_CALLBACK_2(MenuDegreeSelect::LVTouch, this, i));
            model->setTag(50+i);
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

void MenuDegreeSelect::SocSci_Selected(Ref* pSender)
{
    facultySelected = 4;
    
    log("Faculty 4 Selected :: SocSci");
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto s1 = (cocos2d::ui::ListView*)this->getChildByTag(20);
    this->removeChild(s1);
    
    ui::ListView* lv = ui::ListView::create();
    ui::Text* model = ui::Text::create();
    model->setColor(Color3B::BLACK);
    model->setFontSize(40);
    
    lv->setItemModel(model);
    
    for (int i=0; i < degrees.size(); i++)
    {
        if(facultySelected == degrees[i].getFacultyID()){
            model->setString(degrees[i].getDegreeName());
            model->setTouchEnabled(true);
            model->addTouchEventListener(CC_CALLBACK_2(MenuDegreeSelect::LVTouch, this, i));
            model->setTag(50+i);
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

void MenuDegreeSelect::SciMed_Selected(Ref* pSender)
{
    facultySelected = 5;
    
    log("Faculty 5 Selected :: SciMed");
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto s1 = (cocos2d::ui::ListView*)this->getChildByTag(20);
    this->removeChild(s1);
    
    ui::ListView* lv = ui::ListView::create();
    ui::Text* model = ui::Text::create();
    model->setColor(Color3B::BLACK);
    model->setFontSize(40);
    
    lv->setItemModel(model);
    std::string setter;
    
    for (int i=0; i < degrees.size(); i++)
    {
        if(facultySelected == degrees[i].getFacultyID()){
            model->setString(degrees[i].getDegreeName());
            model->setTouchEnabled(true);
            model->addTouchEventListener(CC_CALLBACK_2(MenuDegreeSelect::LVTouch, this, i));
            model->setTag(50+i);
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



void MenuDegreeSelect::LVTouch(Ref *pSender, cocos2d::ui::Text::TouchEventType type, int whosent)
{
    
    switch (type)
    {
        case cocos2d::ui::ListView::TouchEventType::BEGAN:
        {
            break;
        }
        case cocos2d::ui::ListView::TouchEventType::ENDED:
        {
            log("Selected: %s",degrees[whosent].getDegreeName().c_str());
            newplayer.setDegree(degrees[whosent].getDegreeName());
            break;

        }
        default:
            break;
    }

}

void MenuDegreeSelect::loadthelist(){

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto s1 = (cocos2d::ui::ListView*)this->getChildByTag(20);
    this->removeChild(s1);
    ui::ListView* lv = ui::ListView::create();
    ui::Text* model = ui::Text::create();
    model->setColor(Color3B::BLACK);
    model->setFontSize(40);
    
    lv->setItemModel(model);
    std::string compiled;

    for (int i=0; i < degrees.size(); i++)
    {
        if(facultySelected == degrees[i].getFacultyID()){
            model->setString(degrees[i].getDegreeName());
            model->setTouchEnabled(true);
            model->addTouchEventListener(CC_CALLBACK_2(MenuDegreeSelect::LVTouch, this, i));
            
            compiled = facultySelected;
            compiled += " ";
            compiled += i;
            
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

void MenuDegreeSelect::loadthetestdata(){
    
    //28 Is max Char Limit At Font Size 40
    
    Temp_Degree load;
    load.setFacultyID(1);
    load.setDegreeName("Computer Science");
    degrees.push_back(load);
    
    load.setFacultyID(1);
    load.setDegreeName("Engineering");
    degrees.push_back(load);
    
    load.setFacultyID(1);
    load.setDegreeName("Info Tech");
    degrees.push_back(load);
    
    load.setFacultyID(1);
    load.setDegreeName("Electrical Engineering");
    degrees.push_back(load);
 
    load.setFacultyID(1);
    load.setDegreeName("This is a really Long Degree");
    degrees.push_back(load);
    
    load.setFacultyID(1);
    load.setDegreeName("Games Development");
    degrees.push_back(load);
    
    load.setFacultyID(2);
    load.setDegreeName("Nunya Business");
    degrees.push_back(load);
    
    load.setFacultyID(2);
    load.setDegreeName("Commerce");
    degrees.push_back(load);
    
    load.setFacultyID(2);
    load.setDegreeName("Money Counting");
    degrees.push_back(load);
    
    load.setFacultyID(2);
    load.setDegreeName("Being a Banker");
    degrees.push_back(load);
    
    load.setFacultyID(3);
    load.setDegreeName("Un-Creative Arts");
    degrees.push_back(load);
    
    load.setFacultyID(3);
    load.setDegreeName("Drama Queenology");
    degrees.push_back(load);
    
    load.setFacultyID(3);
    load.setDegreeName("Modern Art");
    degrees.push_back(load);
    
    load.setFacultyID(3);
    load.setDegreeName("International Studies");
    degrees.push_back(load);
    
    load.setFacultyID(4);
    load.setDegreeName("Psycho-Logy");
    degrees.push_back(load);
    
    load.setFacultyID(4);
    load.setDegreeName("Science of Lovemaking");
    degrees.push_back(load);
    
    load.setFacultyID(4);
    load.setDegreeName("Teaching Little kids");
    degrees.push_back(load);
    
    load.setFacultyID(4);
    load.setDegreeName("Being A Soulless Lawyer");
    degrees.push_back(load);
    
    load.setFacultyID(4);
    load.setDegreeName("In Joblessness");
    degrees.push_back(load);
    
    load.setFacultyID(5);
    load.setDegreeName("Pharmacology");
    degrees.push_back(load);

    load.setFacultyID(5);
    load.setDegreeName("Seussology");
    degrees.push_back(load);

    load.setFacultyID(5);
    load.setDegreeName("Physics");
    degrees.push_back(load);
    
    load.setFacultyID(5);
    load.setDegreeName("Methology");
    degrees.push_back(load);
    
    load.setFacultyID(5);
    load.setDegreeName("Chemistry");
    degrees.push_back(load);
    
}

