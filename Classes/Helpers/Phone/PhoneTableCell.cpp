//
//  PhoneTableCell.cpp
//  UniLife
//
//  Created by Jackson Gross on 25/10/2014.
//
//

#include "PhoneTableCell.h"

PhoneTableCell::PhoneTableCell():_cellBackground(NULL), Subject(NULL), Time(NULL), ClassType(NULL)
{
    
    // Background
    
    Sprite *sprite = Sprite::create("options-border.png");
    Size spriteSize = sprite->getContentSize();
    sprite->setPosition( Vec2(spriteSize.width / 2, spriteSize.height/2) );
    this->addChild(sprite);
    
    // Label : Subject Name
    
    Subject = Label::createWithSystemFont("", "Arial", 64);
    Subject->setColor(Color3B(0, 0, 0));
    Subject->setPosition( Vec2(spriteSize.width / 2, 350) );
    this->addChild(Subject);
    
    // Label : Class Time
    
    Time = Label::createWithSystemFont("", "Arial", 64);
    Time->setColor(Color3B(0, 0, 0));
    Time->setPosition( Vec2(spriteSize.width / 2, 250) );
    this->addChild(Time);
    
    // Label : Class type - tutorial or lecture
    
    ClassType = Label::createWithSystemFont("", "Arial", 64);
    ClassType->setColor(Color3B(0, 0, 0));
    ClassType->setPosition( Vec2(spriteSize.width / 2, 150) );
    this->addChild(ClassType);
}

PhoneTableCell::~PhoneTableCell()
{
}