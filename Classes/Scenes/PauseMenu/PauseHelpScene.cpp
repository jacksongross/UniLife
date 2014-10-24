//
//  PauseHelpScene.cpp
//  UniLife
//
//  Created by Kurt Robinson on 22/10/2014.
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
#include "MenuLoadController.h"
#include "PauseMenu.h"

Scene* PauseHelpScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = PauseHelpScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool PauseHelpScene::init()
{

    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    // get the size of the screen that is visible
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
    
    auto backgroundSprite = Sprite::create("options-bg.png");
    backgroundSprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    auto textPanel = Sprite::create("Help/help-panel-bg.png");
    textPanel->setPosition(Point(visibleSize.width * .375, visibleSize.height/2));
    
    auto defaultPanelText = Sprite::create("Help/panel-default.png");
    defaultPanelText->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
    
    auto backButton = MenuItemImage::create("options-back.png", "options-back.png", CC_CALLBACK_1(PauseHelpScene::backButtonCallback, this));
    auto aboutButton = MenuItemImage::create("Help/about_off.png", "Help/about_on.png", CC_CALLBACK_1(PauseHelpScene::aboutCallback, this));
    auto faqButton = MenuItemImage::create("Help/faq_off.png", "Help/faq_on.png", CC_CALLBACK_1(PauseHelpScene::faqCallback, this));
    auto gameplayButton = MenuItemImage::create("Help/gameplay_off.png", "Help/gameplay_on.png", CC_CALLBACK_1(PauseHelpScene::gameplayCallback, this));
    auto hudButton = MenuItemImage::create("Help/hud_off.png", "Help/hud_on.png", CC_CALLBACK_1(PauseHelpScene::hudCallback, this));
    
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
    
    this->addChild(backgroundSprite);
    this->addChild(textPanel);
    this->addChild(defaultLayer);
    this->addChild(menu);

    return true;
}


void PauseHelpScene::backButtonCallback(Ref* pSender)
{
    log("Going Back to Debug!");
    
    auto scene = PauseMenu::createScene();
    TransitionCrossFade *crossfade = TransitionCrossFade::create(0.5, scene);
    Director::getInstance()->replaceScene(crossfade);
    
}

void PauseHelpScene::aboutCallback(Ref* pSender)
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


void PauseHelpScene::faqCallback(Ref* pSender)
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



void PauseHelpScene::gameplayCallback(Ref* pSender)
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


void PauseHelpScene::hudCallback(Ref* pSender)
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

