//
//  LogicGame.cpp
//  UniLife
//
//  Created by csci321ga2a on 17/09/2014.
//
//

#include "LogicGame.h"
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

USING_NS_CC;
using namespace cocos2d;
Scene* LogicGame::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = LogicGame::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool LogicGame::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    this->setAccelerometerEnabled(true);
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto sprite = Sprite::create("options-bg.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x + 250, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    this->addChild(sprite, 0);

    


    RunLogicGame();
    
    
    return true;
}



void LogicGame::RunLogicGame(){
    
    std::vector<std::string> questions;
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto title = ui::Text::create("Get Them All To The Other Side Of The River Safely", "Arial Bold", 30);
    title->cocos2d::Node::setPosition(Point(visibleSize.width/2 + 85, visibleSize.height/2 + 300));
    title->setColor(Color3B::BLACK);
    this->addChild(title,5);
    
    auto Chicken = Sprite::create("chicken.png");
    auto Fox = Sprite::create("fox.png");
    auto Grain = Sprite::create("wheat.png");
    
    
    Chicken->setPosition(Point(visibleSize.width/2 - 200, visibleSize.height/2 - 150));
    Fox->setPosition(Point(visibleSize.width/2 - 200, visibleSize.height/2 + 150));
    Grain->setPosition(Point(visibleSize.width/2 - 200, visibleSize.height/2));
    
    Fox->setName("FoxSprite");
    Chicken->setName("ChickenSprite");
    Grain->setName("GrainSprite");
    Fox->setAnchorPoint(Point(0.5f,0.55f));
    Chicken->setAnchorPoint(Point(0.5f,0.55f));
    Grain->setAnchorPoint(Point(0.5f,0.55f));
    
    this->addChild(Fox,4);
    this->addChild(Chicken,4);
    this->addChild(Grain,4);
    

    
    auto RulesBack = Sprite::create();
    RulesBack->setColor(Color3B::WHITE);
    RulesBack->setTextureRect(Rect(0, 0, 280, visibleSize.height));
    RulesBack->setVisible(true);
    // position the sprite on the center of the screen
    RulesBack->setPosition(Point(origin.x + 125, visibleSize.height/2 + origin.y));   // add the sprite as a child to this layer
    this->addChild(RulesBack, 1);
    
    
    auto rulesprite1 = Sprite::create("fox.png");
    auto rulesprite2 = Sprite::create("chicken.png");
    auto rulesprite3 = Sprite::create("chicken.png");
    auto rulesprite4 = Sprite::create("wheat.png");
    
    rulesprite1->setScale(0.5);
    rulesprite2->setScale(0.5);
    rulesprite1->setPosition(Point(origin.x + 50, visibleSize.height/2 + 150));
    rulesprite2->setPosition(Point(origin.x + 200, visibleSize.height/2 + 150));
    
    rulesprite3->setScale(0.5);
    rulesprite4->setScale(0.5);
    rulesprite3->setPosition(Point(origin.x + 50, visibleSize.height/2 + 50));
    rulesprite4->setPosition(Point(origin.x + 200, visibleSize.height/2 + 50));
    
    sprite = Fox;
    
    this->addChild(rulesprite1, 2);
    this->addChild(rulesprite2, 2);
    this->addChild(rulesprite3, 2);
    this->addChild(rulesprite4, 2);
    
    auto ruletext1 = ui::Text::create("If You Leave These Combinations on the same Side of the river ", "Arial", 15);
    ruletext1->setTextAreaSize(Size(250,250));
    ruletext1->setTextHorizontalAlignment(cocos2d::TextHAlignment::CENTER);
    ruletext1->cocos2d::Node::setPosition(Point(visibleSize.width/2 - 435, visibleSize.height/2 + 150));
    ruletext1->setColor(Color3B::BLACK);
    this->addChild(ruletext1,2);

    auto ruletext2 = ui::Text::create("Fox Will Eat Chicken ", "Arial", 15);
    ruletext2->cocos2d::Node::setPosition(Point(origin.x + 125, visibleSize.height/2 + 200));
    ruletext2->setColor(Color3B::BLACK);
    this->addChild(ruletext2,2);
    
    auto ruletext3 = ui::Text::create("Chicken Will Eat Grain ", "Arial", 15);
    ruletext3->cocos2d::Node::setPosition(Point(origin.x + 125, visibleSize.height/2 + 100));
    ruletext3->setColor(Color3B::BLACK);
    this->addChild(ruletext3,2);
    
    
    auto ruletext4 = ui::Text::create("Drag the Icon to the Boat to Send it Across the River OR Tap the Screen to Send the Boat Across The River", "Arial", 15);
    ruletext4->setTextAreaSize(Size(250,250));
    ruletext4->setTextHorizontalAlignment(cocos2d::TextHAlignment::CENTER);
    ruletext4->cocos2d::Node::setPosition(Point(visibleSize.width/2 - 435, visibleSize.height/2 - 150));
    ruletext4->setColor(Color3B::BLACK);
    this->addChild(ruletext4,2);
    
    
    auto River = Sprite::create("river-blue.png");
    River->setRotation(90);
    River->cocos2d::Node::setPosition(Point(visibleSize.width/2 + 90, visibleSize.height/2 ));
    River->setScale(1.2,2);
    this->addChild(River,3);
    
    
    auto Boat = Sprite::create("Boat.png");
    Boat->setFlippedX(true);
    Boat->cocos2d::Node::setPosition(Point(visibleSize.width/2 - 5, visibleSize.height/2 ));
    Boat->setScale(0.4);
    Boat->setName("BoatSprite");
    this->addChild(Boat,6);
    
    spritelocs.push_back("BoatSprite");
    spritelocs.push_back("FoxSprite");
    spritelocs.push_back("ChickenSprite");
    spritelocs.push_back("GrainSprite");
    onleft.push_back(true);
    onleft.push_back(true);
    onleft.push_back(true);
    onleft.push_back(true);
    
    
    
    auto listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesBegan = CC_CALLBACK_2(LogicGame::onTouchesBegan, this);
	listener->onTouchesMoved = CC_CALLBACK_2(LogicGame::onTouchesMoved, this);
	listener->onTouchesEnded = CC_CALLBACK_2(LogicGame::onTouchesEnded, this);
	listener->onTouchesCancelled = CC_CALLBACK_2(LogicGame::onTouchesEnded, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    
    
    auto movetext = ui::Text::create("Moves Made", "Arial", 25);
    movetext->setTextHorizontalAlignment(cocos2d::TextHAlignment::LEFT);
    movetext->cocos2d::Node::setPosition(Point(visibleSize.width/2 - 425, visibleSize.height/2  - 150));
    movetext->setColor(Color3B::BLACK);
    this->addChild(movetext,8);

    auto movecount = ui::Text::create("0", "Arial", 20);
    movecount->setTextHorizontalAlignment(cocos2d::TextHAlignment::LEFT);
    movecount->cocos2d::Node::setPosition(Point(visibleSize.width/2  - 425, visibleSize.height/2 - 200));
    movecount->setColor(Color3B::BLACK);
    movecount->setName("MoveCounter");
    this->addChild(movecount,8);
    
    
}

void LogicGame::onTouchesBegan(const std::vector<Touch*>& touches, Event* event)
{

    
	// reset touch offset
	this->touchOffset = Point::ZERO;
	
	for( auto touch : touches )
	{
		// if this touch is within our sprite's boundary
        
        for(int i = 1; i < spritelocs.size(); i++){
            auto *selected = (cocos2d::Sprite*)this->getChildByName(spritelocs[i]);
            if( touch && this->isTouchingSprite(touch, selected) )
            {
                // calculate offset from sprite to touch point
                sprite = selected;
                this->touchOffset = this->sprite->getPosition() - this->touchToPoint(touch);
            }
            
        }
	}
}

void LogicGame::onTouchesMoved(const std::vector<Touch*>& touches, Event* event)
{
	for( auto touch : touches )
	{
		// set the new sprite position
		if( touch && touchOffset.x && touchOffset.y )
			this->sprite->setPosition(this->touchToPoint(touch) + this->touchOffset);
	}
}

void LogicGame::onTouchesEnded(const std::vector<Touch*>& touches, Event* event)
{
	for( auto touch : touches )
	{
		if( touch && touchOffset.x && touchOffset.y  )
		{
			// set the new sprite position
			this->sprite->setPosition(this->touchToPoint(touch) + this->touchOffset);
            
			// stop any existing actions and reset the scale
			this->sprite->stopAllActions();
			this->sprite->setScale(1.0f);
            
			// animate letting go of the sprite
			this->sprite->runAction(Sequence::create(ScaleBy::create(0.125f, 1.111f),ScaleBy::create(0.125f, 0.9f),nullptr));
		}
	}
    
    
    
    auto boat = (cocos2d::Sprite*)this->getChildByName(spritelocs[0]);
    auto boatbox = Rect(boat->getBoundingBox());
    
    if(boat->getPositionX() < 0){
        onleft[0] = true;
    }
    
    int intheboat = 0;
    
    
    for(int i = 1; i < spritelocs.size(); i++){
        auto *selected = (cocos2d::Sprite*)this->getChildByName(spritelocs[i]);
        auto spriterec = selected->getBoundingBox();
        
            if(spriterec.intersectsRect(boatbox)){
                    selected->setPosition(boatbox.getMidX() + 20,boatbox.getMidY() + 20);
                    intheboat = i;
                }
            }
    
    
        //RESET LOCATIONS IF NO INTERSECTS ARE FOUND
        Size visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 origin = Director::getInstance()->getVisibleOrigin();
        
        auto Fox = (cocos2d::Sprite*)this->getChildByName("FoxSprite");
        auto Chicken = (cocos2d::Sprite*)this->getChildByName("ChickenSprite");
        auto Grain = (cocos2d::Sprite*)this->getChildByName("GrainSprite");

        
        switch (intheboat){
                //If the Fox is in the Boat
            case 1:{
                if(onleft[0] == onleft[1] && onleft[0] == true){
                    boat->setPosition(Point(visibleSize.width/2 + 200, visibleSize.height/2 ));
                    Fox->setPosition(Point(visibleSize.width/2 + 450, visibleSize.height/2 + 150));
                    onleft[0] = false;
                    onleft[1] = false;
                    log("Boat and Fox Move To Right Side");
                }else if(onleft[0] == onleft[1] && onleft[0] == false){
                    boat->setPosition(Point(visibleSize.width/2 - 5, visibleSize.height/2 ));
                    Fox->setPosition(Point(visibleSize.width/2 - 200, visibleSize.height/2 + 150));
                    onleft[0] = true;
                    onleft[1] = true;
                    log("Boat and Fox Move To Left Side");
                }else{
                    log("Boat & Fox Not The Same Side");
                    if(onleft[1] == true){
                        Fox->setPosition(Point(visibleSize.width/2 - 200, visibleSize.height/2 + 150));
                    }else{
                        Fox->setPosition(Point(visibleSize.width/2 + 450, visibleSize.height/2 + 150));
                    }
                }
                moveamt++;
                break;
            }
                //If the Fox is in the Boat
            case 2:{
                if(onleft[0] == onleft[2] && onleft[0] == true){
                    boat->setPosition(Point(visibleSize.width/2 + 200, visibleSize.height/2 ));
                    Chicken->setPosition(Point(visibleSize.width/2 + 450, visibleSize.height/2 - 150));
                    onleft[0] = false;
                    onleft[2] = false;
                    log("Boat and Chicken Move To Right Side");
                }else if(onleft[0] == onleft[2] && onleft[0] == false){
                    boat->setPosition(Point(visibleSize.width/2 - 5, visibleSize.height/2 ));
                    Chicken->setPosition(Point(visibleSize.width/2 - 200, visibleSize.height/2 - 150));
                    onleft[0] = true;
                    onleft[2] = true;
                    log("Boat and Chicken Move To Left Side");
                }else{
                    log("Boat & Chicken Not The Same Side");
                    if(onleft[2] == true){
                        Chicken->setPosition(Point(visibleSize.width/2 - 200, visibleSize.height/2 - 150));
                    }else{
                        Chicken->setPosition(Point(visibleSize.width/2 + 450, visibleSize.height/2 - 150));
                    }
                }
                moveamt++;
                break;

            }
            case 3:{
                if(onleft[0] == onleft[3] && onleft[0] == true){
                    boat->setPosition(Point(visibleSize.width/2 + 200, visibleSize.height/2 ));
                    Grain->setPosition(Point(visibleSize.width/2 + 450, visibleSize.height/2));
                    onleft[0] = false;
                    onleft[3] = false;
                    log("Boat and Grain Move To Right Side");
                }else if(onleft[0] == onleft[3] && onleft[0] == false){
                    boat->setPosition(Point(visibleSize.width/2 - 5, visibleSize.height/2 ));
                    Grain->setPosition(Point(visibleSize.width/2 - 200, visibleSize.height/2));
                    onleft[0] = true;
                    onleft[3] = true;
                    log("Boat and Grain Move To Left Side");
                }else{
                    log("Boat & Grain Not The Same Side");
                    if(onleft[3] == true){
                        Grain->setPosition(Point(visibleSize.width/2 - 200, visibleSize.height/2));
                    }else{
                        Grain->setPosition(Point(visibleSize.width/2 + 450, visibleSize.height/2));
                    }
                }
                moveamt++;
                break;
                
            }
            case 0:{
                log("Nothing is in the Boat");
                if(onleft[0] == true){
                     boat->setPosition(Point(visibleSize.width/2 + 200, visibleSize.height/2 ));
                    onleft[0] = false;
                }else{
                     boat->setPosition(Point(visibleSize.width/2 - 5, visibleSize.height/2 ));
                    onleft[0] = true;
                }
                 moveamt++;

                
            }

        
    }
    
    if(!(onleft[1] == true && onleft[2] == onleft[1] && onleft[3] == onleft[1])){
    checkwin();
    }
    
    updatemoves();
    
}


bool LogicGame::isTouchingSprite(Touch* touch, Sprite* isSprite)
{
	// here's one way, but includes the rectangular white space around our sprite
	//return CGRectContainsPoint(this->sprite->boundingBox(), this->touchToPoint(touch));
	
	// this way is more intuitive for the user because it ignores the white space.
	// it works by calculating the distance between the sprite's center and the touch point,
	// and seeing if that distance is less than the sprite's radius
	return (isSprite->getPosition().getDistance(this->touchToPoint(touch)) < 100.0f);
}

Point LogicGame::touchToPoint(Touch* touch)
{
	// convert the touch object to a position in our cocos2d space
	return CCDirector::getInstance()->convertToGL(touch->getLocationInView());
}


void LogicGame::checkwin(){
    
    
    //WIN CONDITION
    if(onleft[1] == false && onleft[1] == onleft[2] && onleft[2] == onleft[3]){
        log("They All Made It Safely Across");
        log("You Win!");
        
    }
    //IF FOX AND CHICKEN LEFT TOGETHER
    else if(onleft[1] == onleft[2] && onleft[0] != onleft[1]){
        log("You Left the Fox with The Chicken!");
        
        log("The Fox Ate The Chicken");
        
        log("GameOver");
        
        resetgame();
        
    }
    
    //IF CHICKEN & GRAIN LEFT TOGETHER
    else if(onleft[2] == onleft[3] && onleft[0] != onleft[2]){
        log("You Left the Chicken with The Grain!");
        
        log("The Chicken Ate The Grain");
        
        log("GameOver");
        
        resetgame();
        
    }
    
    
    
    
    
}

void LogicGame::resetgame(){
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto Boat = (cocos2d::Sprite*)this->getChildByName("BoatSprite");
    auto Fox = (cocos2d::Sprite*)this->getChildByName("FoxSprite");
    auto Chicken = (cocos2d::Sprite*)this->getChildByName("ChickenSprite");
    auto Grain = (cocos2d::Sprite*)this->getChildByName("GrainSprite");
    
    Chicken->setPosition(Point(visibleSize.width/2 - 200, visibleSize.height/2 - 150));
    Fox->setPosition(Point(visibleSize.width/2 - 200, visibleSize.height/2 + 150));
    Grain->setPosition(Point(visibleSize.width/2 - 200, visibleSize.height/2));
    Boat->setPosition(Point(visibleSize.width/2 - 5, visibleSize.height/2 ));
    
    //Reset All The Left Markers
    for(int i = 0; i < onleft.size();i++){
        onleft[i] = true;
    }
    
}

void LogicGame::updatemoves(){

    
    auto MoveCounter = (cocos2d::ui::Text*)this->getChildByName("MoveCounter");
    
    std::string newstring;
    newstring = std::to_string(moveamt);
    log("Move String: %s",newstring.c_str());
    MoveCounter->setString(newstring);
    log("Move Amount: %d",moveamt);
    
    
    
    
}



