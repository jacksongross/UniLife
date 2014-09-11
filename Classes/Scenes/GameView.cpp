//
//  GameView.cpp
//  UniLife
//
//  Created by Jackson Gross on 9/09/2014.
//
//

#include "GameView.h"
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

USING_NS_CC;

Scene* GameView::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    
    // 'layer' is an autorelease object
    auto layer = GameView::create();
    layer->setPhyWorld(scene->getPhysicsWorld());
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    
    scene->getPhysicsWorld()->setGravity(Vec2(0.0f, -400.0f));
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    PhysicsMaterial test;
    test.restitution = 1.0f;
    test.friction = 0.0f;
    test.density = 1.0f;
    
    auto body = PhysicsBody::createEdgeBox(visibleSize, test, 3);
    body->setLinearDamping(0.0f);
    auto edgeNode = Node::create();
    edgeNode->setPosition(Point(visibleSize.width/2,visibleSize.height/2));
    edgeNode->setPhysicsBody(body);
    scene->addChild(edgeNode);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameView::init()
{
    //////////////////////////////
    // 1. super init first
    if( !LayerColor::initWithColor(Color4B(255,255,255,255)) )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    this->addNewSpriteAtPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
    
    this->addPaddle();
    
    auto listener = EventListenerTouchOneByOne::create();
    
    listener->setSwallowTouches(true);
    
    listener->onTouchBegan = [&](Touch* touch, Event* event){
        
        if (this->getBoundingBox().containsPoint(this->convertTouchToNodeSpace(touch))) {
            log("testing touches");
            GameView::pushBall(12);
            return true;
        }
        return false;
        
    };
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}

void GameView::addNewSpriteAtPosition(Point p)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    for(int i=0; i < 1; i++)
    {
        auto sprite = Sprite::create("circle.png");
        sprite->setScale(0.05f);
        sprite->setTag(1);
        PhysicsMaterial test;
        test.restitution = 1.0f;
        test.friction = 0.0f;
        test.density = 1.0f;
        auto body = PhysicsBody::createCircle(sprite->getContentSize().width * 0.025, test);
        
        
        //b2BodyDef - specify position, velocity, etc.
        //b2Body - create body with above bodydef
        //b2Shape - create shape with geometry to simulate
        //b2FixtureDef - specify fixtures
        //b2Fixture - create fixture object from above fixturedef
        
        body->setLinearDamping(0.0f);
        sprite->setPhysicsBody(body);
        sprite->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2 + i * 2));
        this->addChild(sprite);
    }
    
}

void GameView::addPaddle()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    auto paddle = Sprite::create("paddle.png");
    paddle->setTag(2);
    PhysicsMaterial paddleMaterial;
    paddleMaterial.density = 10.0f;
    paddleMaterial.friction = 0.4f;
    paddleMaterial.restitution = 1.0f;
    
    auto body = PhysicsBody::createBox(Size(paddle->getContentSize().width, paddle->getContentSize().height), paddleMaterial);
    body->setLinearDamping(0.0f);
    
    
    paddle->setPhysicsBody(body);
    paddle->setPosition(Point(visibleSize.width / 2, 200));
    this->addChild(paddle);
  
    
    
    
}

void GameView::pushBall(float dt)
{
    auto sprite = (Sprite*) this->getChildByTag(1);
    log("testing a force push");
    sprite->getPhysicsBody()->applyForce(Vec2(200.0f, 600.0f));
}

