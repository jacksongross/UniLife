//
//  PauseMenu.cpp
//  UniLife
//
//  Created by Jackson Gross on 11/09/2014.
//
//

#include "PauseMenu.h"
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
#include "PauseHelpScene.h"

USING_NS_CC;

extern PlayerModel pm;

Scene* PauseMenu::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = PauseMenu::create();
    //layer->setName("mainpauselayer");
    // add layer as a child to scene
    scene->addChild(layer);
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems;
    
    auto label = Label::createWithSystemFont("Game Paused", "Helvetica", 74);
    
    label->setColor(Color3B(0, 0, 0));
    
    label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 0.90));
    
    layer->addChild(label, 0);
    
    ui::Text* resumeButton = ui::Text::create("Resume", "Arial", 88);
    resumeButton->addTouchEventListener(CC_CALLBACK_1(PauseMenu::resumeCallback, layer));
    resumeButton->setColor(Color3B::BLACK);
    resumeButton->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    resumeButton->setTouchEnabled(true);
    layer->addChild(resumeButton,5);
    
    ui::Text* saveButton = ui::Text::create("Save Game", "Arial", 88);
    saveButton->addTouchEventListener(CC_CALLBACK_1(PauseMenu::saveCallback, layer));
    saveButton->setColor(Color3B::BLACK);
    saveButton->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 * 0.60));
    saveButton->setTouchEnabled(true);
    layer->addChild(saveButton,5);
    
    ui::Text* quitButton = ui::Text::create("Quit Game", "Arial", 88);
    quitButton->addTouchEventListener(CC_CALLBACK_1(PauseMenu::quitCallback, layer));
    quitButton->setColor(Color3B::BLACK);
    quitButton->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 * 0.20));
    quitButton->setTouchEnabled(true);
    layer->addChild(quitButton,5);
    
    ui::Text* helpButton = ui::Text::create("Need Help?", "Arial", 50);
    helpButton->addTouchEventListener(CC_CALLBACK_1(PauseMenu::helpCallback, layer));
    helpButton->setColor(Color3B::BLACK);
    helpButton->setPosition(Point(visibleSize.width * 0.15, visibleSize.height * 0.1));
    helpButton->setTouchEnabled(true);
    layer->addChild(helpButton,5);
    
    auto menu = Menu::createWithArray(pMenuItems);
    menu->setPosition(Vec2::ZERO);
    layer->addChild(menu, 1);

    
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool PauseMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if( !LayerColor::initWithColor(Color4B(255,255,255,100)) )
    {
        return false;
    }
    
    // this is needed so that all layers below the pause screen layer
    // don't take touch events!!
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(PauseMenu::touchBegan, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    return true;
}

// handles touches on the pause layer
bool PauseMenu::touchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
    log("touches on the layer!");
    return true;
}

void PauseMenu::resumeCallback(cocos2d::Ref *pSender)
{
    log("you have touched the resume button!");
    
    this->getParent()->removeChild(this);
    
    Director::getInstance()->resume();
}

void PauseMenu::saveCallback(cocos2d::Ref *pSender)
{
    log("you have touched the save button!");
    
    if(pm.getId() > 0)
    {
        log("Auto saving the game data");
        SqlHelper::autosave(pm);
        SqlHelper::updateAssessments(pm);
        SqlHelper::updateAttendance(pm);
    }
    else
    {
        log("First time saving game!");
        int id = SqlHelper::serialize(pm);
        pm.setId(id);
        SqlHelper::saveAssessments(pm);
        SqlHelper::saveAttendance(pm);
    }
    
    log("game saved!");
    
}

void PauseMenu::quitCallback(cocos2d::Ref *pSender)
{
    log("you have touched the quit button!");
    
    Director::getInstance()->resume();
    auto scene = MenuScene::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);

}

void PauseMenu::helpCallback(Ref* pSender) {
    log("Help Screen Initalize");
    
    //this->removeChildByName("mainpauselayer");
    
    Director::getInstance()->resume();
    auto scene = PauseHelpScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(1, scene));
    
    
    /*
     *
     Commented out because may need to be included as returning from PauseHelpScene is all errored up and its like 4:15am so I don't wanna deal with that right now
     May need to implement all in PauseMenu. For now it's as is.
     *
     */
    
    /*
    // get the size of the screen that is visible
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
    
    //auto backgroundSprite = Sprite::create("options-bg.png");
    //backgroundSprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    auto textPanel = Sprite::create("Help/help-panel-bg.png");
    textPanel->setPosition(Point(visibleSize.width * .375, visibleSize.height/2));
    
    auto defaultPanelText = Sprite::create("Help/panel-default.png");
    defaultPanelText->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
    
    auto backButton = MenuItemImage::create("options-back.png", "options-back.png", CC_CALLBACK_1(PauseMenu::backButtonCallback, this));
    auto aboutButton = MenuItemImage::create("Help/about_off.png", "Help/about_on.png", CC_CALLBACK_1(PauseMenu::aboutCallback, this));
    auto faqButton = MenuItemImage::create("Help/faq_off.png", "Help/faq_on.png", CC_CALLBACK_1(PauseMenu::faqCallback, this));
    auto gameplayButton = MenuItemImage::create("Help/gameplay_off.png", "Help/gameplay_on.png", CC_CALLBACK_1(PauseMenu::gameplayCallback, this));
    auto hudButton = MenuItemImage::create("Help/hud_off.png", "Help/hud_on.png", CC_CALLBACK_1(PauseMenu::hudCallback, this));
    
    backButton->setPosition(Point(visibleSize.width * .09, visibleSize.height * .83));
    aboutButton->setPosition(Point(visibleSize.width * 0.87, visibleSize.height * .15));
    faqButton->setPosition(Point(visibleSize.width * 0.87, visibleSize.height * .38));
    gameplayButton->setPosition(Point(visibleSize.width * 0.87, visibleSize.height * .62));
    hudButton->setPosition(Point(visibleSize.width * 0.87, visibleSize.height  * .85));
    
    auto menu = Menu::create(backButton, aboutButton, faqButton, gameplayButton, hudButton, NULL);
    menu->setPosition(Point::ZERO);
    
    auto defaultLayer = Layer::create();
    defaultLayer->setName("helplayer");
    defaultLayer->addChild(defaultPanelText);
    
    auto layer = Layer::create();
    layer->setName("mainhelplayer");
    layer->addChild(textPanel);
    layer->addChild(menu);
    
    //this->addChild(backgroundSprite);
    this->addChild(layer);
    this->addChild(defaultLayer);
     
     */
}

/*
void PauseMenu::backButtonCallback(Ref* pSender)
{
    this->removeChildByName("helplayer");
    this->removeChildByName("mainhelplayer");
    
    
}

void PauseMenu::aboutCallback(Ref* pSender)
{
    log("about");
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("select.wav");
    
    this->removeChildByName("helplayer");
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto selectedAbout = Sprite::create("Help/about_on.png");
    selectedAbout->setPosition(Point(visibleSize.width * 0.87, visibleSize.height * .15));
    
    auto aboutPanelText = Sprite::create("Help/panel-about.png");
    aboutPanelText->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
    
    auto helpLayer = Layer::create();
    
    helpLayer->addChild(aboutPanelText);
    helpLayer->addChild(selectedAbout);
    
    helpLayer->setName("helplayer");
    
    this->addChild(helpLayer);
    
}


void PauseMenu::faqCallback(Ref* pSender)
{
    log("faq");
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("select.wav");
    
    this->removeChildByName("helplayer");
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto selectedFaq = Sprite::create("Help/faq_on.png");
    selectedFaq->setPosition(Point(visibleSize.width * 0.87, visibleSize.height * .38));
    
    auto faqPanelText = Sprite::create("Help/panel-faq.png");
    faqPanelText->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
    
    auto helpLayer = Layer::create();
    
    helpLayer->addChild(faqPanelText);
    helpLayer->addChild(selectedFaq);
    
    helpLayer->setName("helplayer");
    
    this->addChild(helpLayer);
}



void PauseMenu::gameplayCallback(Ref* pSender)
{
    log("gameplay");
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("select.wav");
    
    this->removeChildByName("helplayer");
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto selectedGameplay = Sprite::create("Help/gameplay_on.png");
    selectedGameplay->setPosition(Point(visibleSize.width * 0.87, visibleSize.height * .62));
    
    auto gameplayPanelText = Sprite::create("Help/panel-gameplay.png");
    gameplayPanelText->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
    
    auto helpLayer = Layer::create();
    
    helpLayer->addChild(gameplayPanelText);
    helpLayer->addChild(selectedGameplay);
    
    helpLayer->setName("helplayer");
    
    this->addChild(helpLayer);
}


void PauseMenu::hudCallback(Ref* pSender)
{
    log("hud");
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("select.wav");
    
    this->removeChildByName("helplayer");
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto selectedHud = Sprite::create("Help/hud_on.png");
    selectedHud->setPosition(Point(visibleSize.width * 0.87, visibleSize.height  * .85));
    
    auto hudPanelText = Sprite::create("Help/panel-hud.png");
    hudPanelText->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
    
    auto helpLayer = Layer::create();
    
    helpLayer->addChild(hudPanelText);
    helpLayer->addChild(selectedHud);
    
    helpLayer->setName("helplayer");
    
    this->addChild(helpLayer);
}

*/
                                           
                        
