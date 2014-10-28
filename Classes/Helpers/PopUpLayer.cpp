//
//  PopUpLayer.cpp
//  UniLife
//
//  Created by csci321ga2a on 30/09/2014.
//
//


#include "PopUpLayer.h"
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
#include "BrickBreaker.h"
#include "PopUpLayer.h"
#include "TutorialScene.h"
#include "QDSplashScene.h"
#include "FCG_minigame.h"
#include "EventScene.h"

USING_NS_CC;

extern PlayerModel pm;
int callback;
bool locked = false;

Scene* PopUpLayer::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = PopUpLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems;
    
    auto label = Label::createWithSystemFont("Blank Box Test", "Helvetica", 74);
    label->setColor(Color3B(0, 0, 0));
    label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 0.90));
    layer->addChild(label, 0);

    
    //Creates A plain Box with no internal Data, this is the defautl createScene construction of the PopupLayer
    createPopUp(layer,Rect(visibleSize.width/2 - 300, visibleSize.height/2, 200, 200));
    
    // return the scene
    return scene;
}

Scene* PopUpLayer::createScene(Rect inRect, vector<std::string> inText)
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = PopUpLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems;
    
    auto label = Label::createWithSystemFont("String Input Test", "Helvetica", 74);
    label->setColor(Color3B(0, 0, 0));
    label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 0.90));
    layer->addChild(label, 0);
    
    
    //Creates A plain Box with no internal Data, this is the defautl createScene construction of the PopupLayer
   createPopUpText(layer,Rect(visibleSize.width/2 - 300, visibleSize.height/2, 200, 200),inText);
    
    // return the scene
    return scene;
}

Scene* PopUpLayer::createScene(Rect inRect, vector<ui::Button*> inButtons)
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = PopUpLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems;
    
    auto label = Label::createWithSystemFont("Button Input Test", "Helvetica", 74);
    label->setColor(Color3B(0, 0, 0));
    label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 0.90));
    layer->addChild(label, 0);
    
    
    createPopUpButtons(layer,inRect,inButtons);
    
    // return the scene
    return scene;
}

Scene* PopUpLayer::createScene(Rect rect, std::string text, int btnCallback)
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = PopUpLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems;
    
    // create the option pop up
    createPopUpOptions(layer, rect, btnCallback, text);
    
    // return the scene
    return scene;
}


// on "init" you need to initialize your instance
bool PopUpLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if( !LayerColor::initWithColor(Color4B(255,255,255,0)) )
    {
        return false;
    }
    
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(PopUpLayer::touchBegan, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(PopUpLayer::touchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    return true;
  
}


bool PopUpLayer::touchBegan(cocos2d::Touch* touch, cocos2d::Event* event){
    
    return true;
}


void PopUpLayer::touchEnded(cocos2d::Touch* touch, cocos2d::Event* event){
    
    auto *selected = (cocos2d::Sprite*)this->getChildByName("optBox");
    
    Size s = selected->getContentSize();
    
    if( touch && selected->getPosition().getDistance(touch->getLocation()) < 100 && locked == false)
    {
        switch (callback)
        {
                
            case 1:
            {
                Director::getInstance()->resume();
                this->getParent()->removeChild(this);
                brickBreakerCallback();
                break;
            }
                
            case 2:
            {
                Director::getInstance()->resume();
                this->getParent()->removeChild(this);
                quackyDuckCallback();
                break;
            }
                
            case 3:
            {
                Director::getInstance()->resume();
                this->getParent()->removeChild(this);
                studyCallback();
                break;
            }
                
            case 4:
            {
                Director::getInstance()->resume();
                this->getParent()->removeChild(this);
                sleepCallback();
                break;
            }
                
            case 5:
            {
                Director::getInstance()->resume();
                this->getParent()->removeChild(this);
                socialCallback();
                break;
            }
                
            case 6:
            {
                Director::getInstance()->resume();
                this->getParent()->removeChild(this);
                tavernCallback();
                break;
            }
                
            case 7:
            {
                Director::getInstance()->resume();
                this->getParent()->removeChild(this);
                logicGameCallback();
                break;
            }
                
        }
        
        return;
    }
    else
    {
        Director::getInstance()->resume();
        this->getParent()->removeChild(this);
        locked = true;
    }
    
}

void PopUpLayer::createPopUp(PopUpLayer* that, Rect inRect){

    
    auto optBox = Sprite::create();
    optBox->setColor(Color3B::WHITE);
    optBox->setTextureRect(inRect);
    optBox->setVisible(true);
    optBox->setPosition(Vec2(inRect.origin.x,inRect.origin.y));
    optBox->setName("optBox");
    that->addChild(optBox, 11);
    
    
    Rect newsize = Rect(inRect.origin.x, inRect.origin.y, inRect.size.width + 20, inRect.size.height + 20);
    auto optBorder = Sprite::create();
    optBorder->setColor(Color3B::BLACK);
    optBorder->setTextureRect(newsize);
    optBorder->setVisible(true);
    optBorder->setPosition(Vec2(inRect.origin.x,inRect.origin.y));
    optBorder->setName("optBox");
    that->addChild(optBorder, 10);
    
}


void PopUpLayer::createPopUpOptions(PopUpLayer *layer, cocos2d::Rect rect, int btnCallback, std::string text)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    auto optBox = Sprite::create();
    optBox->setColor(Color3B::WHITE);
    optBox->setTextureRect(rect);
    optBox->setVisible(true);
    optBox->setPosition(Vec2(rect.origin.x, rect.origin.y));
    optBox->setName("optBox");
    layer->addChild(optBox, 11);
    
    
    Rect newsize = Rect(rect.origin.x, rect.origin.y, rect.size.width + 20, rect.size.height + 20);
    
    auto optBorder = Sprite::create();
    optBorder->setColor(Color3B::BLACK);
    optBorder->setTextureRect(newsize);
    optBorder->setVisible(true);
    optBorder->setPosition(Vec2(rect.origin.x,rect.origin.y));
    optBorder->setName("optBox");
    layer->addChild(optBorder, 10);
    
    callback = btnCallback;
    
    Size rectSize = rect.size;
    
    auto label = Label::createWithSystemFont(text, "Helvetica", 54);
    label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 0.65));
    label->setColor(Color3B(0, 0, 0));
    layer->addChild(label, 12);
    
    auto help = Label::createWithSystemFont("(Touch here to \n trigger event)", "Helvetica", 38);
    help->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 0.45));
    help->setColor(Color3B(0, 0, 0));
    layer->addChild(help, 12);
    
}



void PopUpLayer::createPopUpButtons(PopUpLayer* that, Rect inRect, vector<ui::Button*> inButtons){
    
    
    auto optBox = Sprite::create();
    optBox->setColor(Color3B::WHITE);
    optBox->setTextureRect(inRect);
    optBox->setVisible(true);
    optBox->setPosition(Vec2(inRect.origin.x,inRect.origin.y));
    optBox->setName("optBox");
    that->addChild(optBox, 11);
    
    
    Rect newsize = Rect(inRect.origin.x, inRect.origin.y, inRect.size.width + 20, inRect.size.height + 20);
    
    auto optBorder = Sprite::create();
    optBorder->setColor(Color3B::BLACK);
    optBorder->setTextureRect(newsize);
    optBorder->setVisible(true);
    optBorder->setPosition(Vec2(inRect.origin.x,inRect.origin.y));
    optBorder->setName("optBox");
    that->addChild(optBorder, 10);
    
    Rect newsize2 = Rect(inRect.origin.x, inRect.origin.y, inRect.size.width - 20, inRect.size.height - 20);
    
    ui::ListView* lv = ui::ListView::create();
    
    for (int i=0; i<inButtons.size(); i++)
    {
        ui::Button* model = inButtons[i];
        lv->setItemModel(model);
        lv->pushBackDefaultItem();
    }
    lv->setItemsMargin(10);
    lv->setGravity(ui::ListView::Gravity::CENTER_HORIZONTAL);
    lv->setContentSize(Size(newsize2.size.width, newsize2.size.height));
    lv->setBackGroundColorType(cocos2d::ui::Layout::BackGroundColorType::SOLID);
    lv->setBackGroundColor(Color3B::WHITE);
    lv->setPosition(Vec2(inRect.origin.x - newsize2.size.width/2,inRect.origin.y - newsize2.size.height/2));
    that->addChild(lv,12);
    
    
}


void PopUpLayer::createPopUpText(PopUpLayer* that, Rect inRect, vector<std::string> inText){
    
    
    auto optBox = Sprite::create();
    optBox->setColor(Color3B::WHITE);
    optBox->setTextureRect(inRect);
    optBox->setVisible(true);
    optBox->setPosition(Vec2(inRect.origin.x,inRect.origin.y));
    optBox->setName("optBox");
    that->addChild(optBox, 11);
    
    
    Rect newsize = Rect(inRect.origin.x, inRect.origin.y, inRect.size.width + 20, inRect.size.height + 20);
    auto optBorder = Sprite::create();
    optBorder->setColor(Color3B::BLACK);
    optBorder->setTextureRect(newsize);
    optBorder->setVisible(true);
    optBorder->setPosition(Vec2(inRect.origin.x,inRect.origin.y));
    optBorder->setName("optBox");
    that->addChild(optBorder, 10);
    
}

void PopUpLayer::closeCallback()
{
    Director::getInstance()->resume();
    this->getParent()->removeChild(this);
}

void PopUpLayer::quackyDuckCallback()
{
    HUDLayer::pauseTimer();
    
    auto scene = QDSplashScene::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
}

// brick breaker
void PopUpLayer::brickBreakerCallback()
{
    HUDLayer::pauseTimer();
    
    auto scene = BrickBreaker::createScene();
    TransitionCrossFade *crossfade = TransitionCrossFade::create(0.5, scene);
    Director::getInstance()->replaceScene(crossfade);
}

// logic game
void PopUpLayer::logicGameCallback()
{
    HUDLayer::pauseTimer();
    
    auto scene = FCGminigame::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
}

// socialise
void PopUpLayer::socialCallback()
{
    auto event = EventScene::createScene("events/bed-event.png");
    
    HUDLayer::updateStats(0, 0, 2, -10, -10);
    
    TransitionCrossFade *crossfade = TransitionCrossFade::create(0.5, event);
    Director::getInstance()->pushScene(crossfade);

}

// study
void PopUpLayer::studyCallback()
{
    auto event = EventScene::createScene("events/study.png");
    
    HUDLayer::updateStats(2, 1, -1, 100, -10);
    
    TransitionCrossFade *crossfade = TransitionCrossFade::create(0.5, event);
    Director::getInstance()->pushScene(crossfade);

}

// get drunk at bar
void PopUpLayer::tavernCallback()
{
    auto event = EventScene::createScene("events/bed-event.png");
    
    HUDLayer::updateStats(0, -1, 2, 100, 5);
    
    TransitionCrossFade *crossfade = TransitionCrossFade::create(0.5, event);
    Director::getInstance()->pushScene(crossfade);

}

// sleep
void PopUpLayer::sleepCallback()
{
    auto event = EventScene::createScene("events/bed-event.png");
    
    HUDLayer::updateStats(0, 0, 0, 100, -10);
    
    TransitionCrossFade *crossfade = TransitionCrossFade::create(0.5, event);
    Director::getInstance()->pushScene(crossfade);
}




