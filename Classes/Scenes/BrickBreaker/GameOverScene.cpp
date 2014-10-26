//
//  GameOverScene.cpp
//  UniLife
//
//  Created by Jackson Gross on 9/09/2014.
//
//

#include "GameOverScene.h"
#include "BrickBreaker.h"
#include "DormScene.h"
#include "Debugger.h"

USING_NS_CC;

bool GameOverLayer::init()
{
	if (!CCLayerColor::initWithColor(Color4B(255,255,255,255)))
	{
		return false;
	}
	
	Size winSize = Director::getInstance()->getWinSize();
	this->_label = Label::createWithSystemFont("", "Arial", 64);
	this->_label->retain();
	this->getLabel()->setPosition(Point(winSize.width / 2, winSize.height * .90));
	this->addChild(_label, 2);
    
    auto bg = Sprite::create("brickbreaker-bg.jpg");
    bg->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
    this->addChild(bg, 1);
    
    auto retryButton = MenuItemFont::create("Retry", CC_CALLBACK_1(GameOverLayer::retryCallback, this));
    auto quitButton = MenuItemFont::create("Quit", CC_CALLBACK_1(GameOverLayer::quitCallback, this));
    
    retryButton->setPosition(Vec2(winSize.width * 0.5, winSize.height * 0.4));
    quitButton->setPosition(Vec2(winSize.width * 0.5, winSize.height * 0.3));
    
    retryButton->setFontSize(50);
    quitButton->setFontSize(50);
    
    auto menu = Menu::create(retryButton, quitButton, NULL);
    menu->setPosition(Point::ZERO);
    
    this->addChild(menu, 2);

	
	return true;
}

void GameOverLayer::retryCallback(Ref* pSender)
{
    log("retry pressed!");
    
    auto scene = BrickBreaker::createScene();
    TransitionCrossFade *crossfade = TransitionCrossFade::create(0.5, scene);
    Director::getInstance()->replaceScene(crossfade);
}

void GameOverLayer::quitCallback(Ref* pSender)
{
    log("quit pressed!");
    auto scene = DormScene::createScene();
    TransitionCrossFade *crossfade = TransitionCrossFade::create(0.5, scene);
    Director::getInstance()->replaceScene(crossfade);

}

GameOverLayer::~GameOverLayer()
{
	_label->release();
}

bool GameOverScene::init()
{
	if( CCScene::init() )
	{
		this->_layer = GameOverLayer::create();
		this->_layer->retain();
		this->addChild(_layer);
		
		return true;
	}
	else
	{
		return false;
	}
}

GameOverScene::~GameOverScene()
{
	if (_layer)
	{
		_layer->release();
		_layer = NULL;
	}
}