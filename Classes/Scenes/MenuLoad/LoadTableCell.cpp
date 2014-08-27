//
//  LoadTableCell.cpp
//  UniLife
//
//  Created by Jackson Gross on 17/08/2014.
//
//

#include "LoadTableCell.h"

LoadTableCell::LoadTableCell():_cellBackground(NULL), Name(NULL), Degree(NULL), Scene(NULL)
{
    
    // Background
    
    Sprite *sprite = Sprite::create("options-border.png");
    Size spriteSize = sprite->getContentSize();
    sprite->setPosition( Vec2(spriteSize.width / 2, spriteSize.height/2) );
    this->addChild(sprite);
    
    // Label : Character Name
    
    Name = Label::createWithSystemFont("", "Arial", 64);
    Name->setColor(Color3B(0, 0, 0));
    Name->setPosition( Vec2(spriteSize.width / 2, 350) );
    this->addChild(Name);
    
    // Label : Degree
    
    Degree = Label::createWithSystemFont("", "Arial", 64);
    Degree->setColor(Color3B(0, 0, 0));
    Degree->setPosition( Vec2(spriteSize.width / 2, 250) );
    this->addChild(Degree);
    
    // Label : Scene
    
    Scene = Label::createWithSystemFont("", "Arial", 64);
    Scene->setColor(Color3B(0, 0, 0));
    Scene->setPosition( Vec2(spriteSize.width / 2, 150) );
    this->addChild(Scene);
}

LoadTableCell::~LoadTableCell()
{
}