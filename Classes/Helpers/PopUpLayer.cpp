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

USING_NS_CC;

extern PlayerModel pm;

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
    
    
    createPopUpButtons(layer,Rect(visibleSize.width/2 - 300, visibleSize.height/2, 200, 200),inButtons);
    
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

bool PopUpLayer::touchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
    log("TouchBegan");
    auto *selected = (cocos2d::Sprite*)this->getChildByName("optBox");
    //selected->getPosition().getDistance(CCDirector::getInstance()->convertToGL(touch->getLocationInView())) < 100.0f
    if( touch && !(selected->getPosition().getDistance(touch->getLocation())<100.0f))
    {
        log("You Didnt touch Me Where I Wanted");
        this->getParent()->removeChild(this);
        Director::getInstance()->resume();
        return true;
    }
    return true;
    
}


void PopUpLayer::touchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
    log("Touchended");
    auto *selected = (cocos2d::Sprite*)this->getChildByName("optBox");
    //selected->getPosition().getDistance(CCDirector::getInstance()->convertToGL(touch->getLocationInView())) < 100.0f
    if( touch && selected->getPosition().getDistance(touch->getLocation())<100.0f)
    {
        log("You Touched Me in All The Right Places ;)");
        return;
    }else{
        _eventDispatcher->removeAllEventListeners();
    }
    return;
    
    
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
    
    
    ui::Layout* layout = ui::Layout::create();
    layout->setContentSize(Size(newsize2.size.width, newsize2.size.height));
    layout->setPosition(Vec2(inRect.origin.x - newsize2.size.width/2,inRect.origin.y - newsize2.size.height/2));
    layout->setBackGroundColor(Color3B::WHITE);
    layout->setBackGroundColorType(cocos2d::ui::Layout::BackGroundColorType::SOLID);
    that->addChild(layout,12);
    
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



