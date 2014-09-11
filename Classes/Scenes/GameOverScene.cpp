//
//  GameOverScene.cpp
//  UniLife
//
//  Created by Jackson Gross on 9/09/2014.
//
//

#include "GameOverScene.h"
#include "GameView.h"

USING_NS_CC;

bool GameOverLayer::init()
{
	if (!CCLayerColor::initWithColor(Color4B(255,255,255,255)))
	{
		return false;
	}
	
	Size winSize = CCDirector::sharedDirector()->getWinSize();
	this->_label = Label::labelWithString("", "Arial", 12);
    this->_label = LabelTTF
	this->_label->retain();
	this->getLabel()->setColor(Color3B(0,0,0));
	this->getLabel()->setPosition(ccp(winSize.width/2, winSize.height/2));
	this->addChild(_label);
	
	this->runAction(CCSequence::actions(CCDelayTime::actionWithDuration(3),
										CCCallFunc::actionWithTarget(this, callfunc_selector(GameOverLayer::gameOverDone)),
										NULL));
	
	return true;
}

void GameOverLayer::gameOverDone()
{
	Director::sharedDirector()->replaceScene(GameView::scene());
}

GameOverLayer::~GameOverLayer()
{
	_label->release();
}

bool GameOverScene::init()
{
	if( CCScene::init() )
	{
		this->_layer = GameOverLayer::node();
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