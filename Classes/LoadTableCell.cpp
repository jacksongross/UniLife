//
//  LoadTableCell.cpp
//  UniLife
//
//  Created by Jackson Gross on 17/08/2014.
//
//

#include "LoadTableCell.h"

#define RANK_TABLE_WIDTH 400
#define RANK_TABLE_CELL_HEIGHT 400

LoadTableCell::LoadTableCell():_cellBackground(NULL), _lbNickName(NULL), _lbPlayCount(NULL), _lbTotalScore(NULL)
{
    
    const float gapLeft = 10.0f;
    const float gapRight = 10.0f;
    
    const float widthPlayCount  = 40.0f;
    const float widthTotalScore = 80.0f;
    const float widthNickName   = RANK_TABLE_WIDTH - (widthPlayCount + widthTotalScore) - (gapLeft + gapRight);
    
    const float posNickName = gapLeft;
    const float posPlayCount = posNickName + widthNickName;
    const float posTotalScore = posPlayCount + widthPlayCount;
    
    // Background
    
    Sprite *sprite = Sprite::create("options-border.png");
    Size spriteSize = sprite->getContentSize();
    sprite->setPosition( Vec2(spriteSize.width/2, spriteSize.height/2) );
    this->addChild(sprite);
    
    // Label : NickName
    
    _lbNickName = Label::createWithSystemFont("", "Arial", 64);

    _lbNickName->setColor( Color3B(192, 64, 64) );
    
    _lbNickName->setPosition( Vec2(RANK_TABLE_WIDTH / 2, RANK_TABLE_CELL_HEIGHT/2) );
    this->addChild(_lbNickName);
    
    // Label : PlayCount
    
    _lbPlayCount = Label::createWithSystemFont("", "Arial", 32);
    
    _lbPlayCount->setColor( Color3B(64, 64, 192) );
    
    _lbPlayCount->setPosition( Vec2(posPlayCount + widthPlayCount/2, RANK_TABLE_CELL_HEIGHT/2) );
    //this->addChild(_lbPlayCount);
    
    // Label : TotalScore
    
    _lbTotalScore = Label::createWithSystemFont("", "Arial", 32);

    _lbTotalScore->setColor( Color3B(64, 128, 128) );
    
    _lbTotalScore->setPosition( Vec2(posTotalScore + widthTotalScore/2, RANK_TABLE_CELL_HEIGHT/2) );
    //this->addChild(_lbTotalScore);
}

LoadTableCell::~LoadTableCell()
{
}