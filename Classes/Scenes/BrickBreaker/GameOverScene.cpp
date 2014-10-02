//
//  GameOverScene.cpp
//  UniLife
//
//  Created by Jackson Gross on 9/09/2014.
//
//

#include "GameOverScene.h"
#include "BrickBreaker.h"

USING_NS_CC;

bool GameOverLayer::init()
{
	if (!CCLayerColor::initWithColor(Color4B(255,255,255,255)))
	{
		return false;
	}
	
	Size winSize = Director::getInstance()->getWinSize();
	this->_label = Label::createWithSystemFont("", "Arial", 12);
	this->_label->retain();
	this->getLabel()->setColor(Color3B(0,0,0));
	this->getLabel()->setPosition(Point(winSize.width/2, winSize.height/2));
	this->addChild(_label);
    
    DelayTime *delay = DelayTime::create(1);
    
    // perform the selector call
    CallFunc *callback = CallFunc::create(this, callfunc_selector(GameOverLayer::gameOverDone));
    
    // run the action
    this->runAction( Sequence::createWithTwoActions(delay, callback));
	
	return true;
}

void GameOverLayer::gameOverDone()
{
	Director::getInstance()->replaceScene(BrickBreaker::createScene());
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