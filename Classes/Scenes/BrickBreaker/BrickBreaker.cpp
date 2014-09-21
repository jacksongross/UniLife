//
//  BrickBreaker.cpp
//  UniLife
//
//  Created by Jackson Gross on 9/09/2014.
//
//

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
#include "BrickBreaker.h"

USING_NS_CC;
using namespace cocos2d;
using namespace CocosDenshion;

#define PTM_RATIO 64

BrickBreaker::~BrickBreaker()
{
    CC_SAFE_DELETE(_world);
    _groundBody = NULL;
    delete _contactListener;
}

BrickBreaker::BrickBreaker()
{
    setTouchEnabled(true);
    
	Size winSize = CCDirector::getInstance()->getWinSize();
    
	// Define the gravity vector.
	b2Vec2 gravity;
	gravity.Set(0.0f, 0.0f);
    
	// Construct a world object, which will hold and simulate the rigid bodies.
	_world = new b2World(gravity);
    
    _world->SetAllowSleeping(true);
    
    // Create edges around the entire screen
	// Define the ground body.
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0, 0); // bottom-left corner
	
	// Call the body factory which allocates memory for the ground body
	// from a pool and creates the ground box shape (also from a pool).
	// The body is also added to the world.
	_groundBody = _world->CreateBody(&groundBodyDef);
	
	// Define the ground box shape.
	b2EdgeShape groundBox;
    
	// bottom
	groundBox.Set(b2Vec2(0,0), b2Vec2(winSize.width/PTM_RATIO,0));
	_bottomFixture = _groundBody->CreateFixture(&groundBox, 0);
	
	// top
	groundBox.Set(b2Vec2(0,winSize.height/PTM_RATIO), b2Vec2(winSize.width/PTM_RATIO,winSize.height/PTM_RATIO));
	_groundBody->CreateFixture(&groundBox, 0);
	
	// left
	groundBox.Set(b2Vec2(0,winSize.height/PTM_RATIO), b2Vec2(0,0));
	_groundBody->CreateFixture(&groundBox, 0);
	
	// right
	groundBox.Set(b2Vec2(winSize.width/PTM_RATIO,winSize.height/PTM_RATIO), b2Vec2(winSize.width/PTM_RATIO,0));
	_groundBody->CreateFixture(&groundBox, 0);
    
    // Create sprite and add it to the layer
	Sprite *ball = CCSprite::create("ball.png");
    ball->setPosition(Point(100, 100));
    ball->setScale(0.25);
    ball->setTag(1);
    this->addChild(ball);
    
    // Create ball body
    b2BodyDef ballBodyDef;
    ballBodyDef.type = b2_dynamicBody;
    ballBodyDef.position.Set(100/PTM_RATIO, 100/PTM_RATIO);
    ballBodyDef.userData = ball;
    
    b2Body *ballBody = _world->CreateBody(&ballBodyDef);
    
    // Create circle shape
    b2CircleShape circle;
    circle.m_radius = 26.0/PTM_RATIO;
    
    // Create shape definition and add body
    b2FixtureDef ballShapeDef;
    ballShapeDef.shape = &circle;
    ballShapeDef.density = 1.0f;
    ballShapeDef.friction = 0.f;
    ballShapeDef.restitution = 1.0f;
    _ballFixture = ballBody->CreateFixture(&ballShapeDef);
    
    b2Vec2 force = b2Vec2(10, 10);
    
    ballBody->ApplyLinearImpulse(force, ballBodyDef.position, true);
    
    Sprite *paddle = Sprite::create("paddle.png");
    paddle->setPosition(Point(winSize.width/2, 50));
    this->addChild(paddle);
    
    // Create paddle body
    b2BodyDef paddleBodyDef;
    paddleBodyDef.type = b2_dynamicBody;
    paddleBodyDef.position.Set(winSize.width/2/PTM_RATIO, 50/PTM_RATIO);
    paddleBodyDef.userData = paddle;
    _paddleBody = _world->CreateBody(&paddleBodyDef);
    
    // Create paddle shape
    b2PolygonShape paddleShape;
    paddleShape.SetAsBox(paddle->getContentSize().width/PTM_RATIO/2,
                         paddle->getContentSize().height/PTM_RATIO/2);
    
    // Create shape definition and add to body
    b2FixtureDef paddleShapeDef;
    paddleShapeDef.shape = &paddleShape;
    paddleShapeDef.density = 10.0f;
    paddleShapeDef.friction = 0.4f;
    paddleShapeDef.restitution = 0.1f;
    _paddleFixture = _paddleBody->CreateFixture(&paddleShapeDef);
    
    // Restrict paddle along the x axis
    b2PrismaticJointDef jointDef;
    b2Vec2 worldAxis(1.0f, 0.0f);
    jointDef.collideConnected = true;
    jointDef.Initialize(_paddleBody, _groundBody,
                        _paddleBody->GetWorldCenter(), worldAxis);
    _world->CreateJoint(&jointDef);
    
    // in C++ you need to initialize objects to NULL
    _mouseJoint = NULL;
    
    // Create contact listener
    _contactListener = new MyContactListener();
    _world->SetContactListener(_contactListener);
    
    for(int i = 0; i < 4; i++) {
        
        static int padding=40;
        
        // Create block and add it to the layer
        Sprite *block = Sprite::create("block.png");
        int xOffset = padding+block->getContentSize().width/2+
        ((block->getContentSize().width+padding)*i);
        block->setPosition(Point(xOffset, 450));
        block->setTag(2);
        this->addChild(block);
        
        // Create block body
        b2BodyDef blockBodyDef;
        blockBodyDef.type = b2_dynamicBody;
        blockBodyDef.position.Set(xOffset/PTM_RATIO, 250/PTM_RATIO);
        blockBodyDef.userData = block;
        b2Body *blockBody = _world->CreateBody(&blockBodyDef);
        
        // Create block shape
        b2PolygonShape blockShape;
        blockShape.SetAsBox(block->getContentSize().width/PTM_RATIO/2,
                            block->getContentSize().height/PTM_RATIO/2);
        
        // Create shape definition and add to body
        b2FixtureDef blockShapeDef;
        blockShapeDef.shape = &blockShape;
        blockShapeDef.density = 10.0;
        blockShapeDef.friction = 0.0;
        blockShapeDef.restitution = 0.1f;
        blockBody->CreateFixture(&blockShapeDef);
        
    }
    
    this->schedule(schedule_selector(BrickBreaker::tick));
}

void BrickBreaker::draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, bool transformUpdated)
{
	glDisable(GL_TEXTURE_2D);
		
	glEnable(GL_TEXTURE_2D);
}

void BrickBreaker::tick(float dt)
{
	
	int velocityIterations = 8;
	int positionIterations = 1;
    
	// Instruct the world to perform a single step of simulation. It is
	// generally best to keep the time step and iterations fixed.
	_world->Step(dt, velocityIterations, positionIterations);
	
    bool blockFound = false;
    
	//Iterate over the bodies in the physics world
	for (b2Body* b = _world->GetBodyList(); b; b = b->GetNext())
	{
		if (b->GetUserData() != NULL) {
			//Synchronize the AtlasSprites position and rotation with the corresponding body
			Sprite* myActor = (Sprite*)b->GetUserData();
			myActor->setPosition( Point( b->GetPosition().x * PTM_RATIO, b->GetPosition().y * PTM_RATIO) );
			myActor->setRotation( -1 * CC_RADIANS_TO_DEGREES(b->GetAngle()) );
            
            if (myActor->getTag() == 1) {
                static int maxSpeed = 10;
                
                b2Vec2 velocity = b->GetLinearVelocity();
                float32 speed = velocity.Length();
                
                if (speed > maxSpeed) {
                    b->SetLinearDamping(0.5);
                } else if (speed < maxSpeed) {
                    b->SetLinearDamping(0.0);
                }
                
            }
            
            if (myActor->getTag() == 2) {
                blockFound = true;
            }
		}
	}
    
    std::vector<b2Body *>toDestroy;
    std::vector<MyContact>::iterator pos;
    for(pos = _contactListener->_contacts.begin();
        pos != _contactListener->_contacts.end(); ++pos) {
        MyContact contact = *pos;
        
        if ((contact.fixtureA == _bottomFixture && contact.fixtureB == _ballFixture) ||
            (contact.fixtureA == _ballFixture && contact.fixtureB == _bottomFixture)) {
            GameOverScene *gameOverScene = GameOverScene::create();
            gameOverScene->getLayer()->getLabel()->setString("You Lose! :[");
            CCDirector::getInstance()->replaceScene(gameOverScene);
        }
        
        b2Body *bodyA = contact.fixtureA->GetBody();
        b2Body *bodyB = contact.fixtureB->GetBody();
        if (bodyA->GetUserData() != NULL && bodyB->GetUserData() != NULL) {
            Sprite *spriteA = (Sprite *) bodyA->GetUserData();
            Sprite *spriteB = (Sprite *) bodyB->GetUserData();
            
            // Sprite A = ball, Sprite B = Block
            if (spriteA->getTag() == 1 && spriteB->getTag() == 2) {
                if (std::find(toDestroy.begin(), toDestroy.end(), bodyB)
                    == toDestroy.end()) {
                    toDestroy.push_back(bodyB);
                }
            }
            // Sprite B = block, Sprite A = ball
            else if (spriteA->getTag() == 2 && spriteB->getTag() == 1) {
                if (std::find(toDestroy.begin(), toDestroy.end(), bodyA)
                    == toDestroy.end()) {
                    toDestroy.push_back(bodyA);
                }
            }
        }
    }
    
    std::vector<b2Body *>::iterator pos2;
    for(pos2 = toDestroy.begin(); pos2 != toDestroy.end(); ++pos2) {
        b2Body *body = *pos2;
        if (body->GetUserData() != NULL) {
            Sprite *sprite = (Sprite *) body->GetUserData();
            this->removeChild(sprite, true);
        }
        _world->DestroyBody(body);
    }
    
    if (!blockFound)
    {
        GameOverScene *gameOverScene = GameOverScene::create();
        gameOverScene->getLayer()->getLabel()->setString("You Win!");
        CCDirector::getInstance()->replaceScene(gameOverScene);
    }
    
    if (toDestroy.size() > 0)
    {
        //SimpleAudioEngine::sharedEngine()->playEffect("blip.caf");
    }
}

void BrickBreaker::ccTouchesBegan(cocos2d::Touch *touches, cocos2d::Event *event)
{
    if (_mouseJoint != NULL) return;
    
    Point location = touches->getLocationInView();
    location = CCDirector::getInstance()->convertToGL(location);
    b2Vec2 locationWorld = b2Vec2(location.x/PTM_RATIO, location.y/PTM_RATIO);
    
    if (_paddleFixture->TestPoint(locationWorld)) {
        b2MouseJointDef md;
        md.bodyA = _groundBody;
        md.bodyB = _paddleBody;
        md.target = locationWorld;
        md.collideConnected = true;
        md.maxForce = 1000.0f * _paddleBody->GetMass();
        
        _mouseJoint = (b2MouseJoint *)_world->CreateJoint(&md);
        _paddleBody->SetAwake(true);
    }
}

void BrickBreaker::ccTouchesMoved(cocos2d::Touch *touches, cocos2d::Event *event)
{
    if (_mouseJoint == NULL) return;
    
    Point location = touches->getLocationInView();
    location = CCDirector::getInstance()->convertToGL(location);
    b2Vec2 locationWorld = b2Vec2(location.x/PTM_RATIO, location.y/PTM_RATIO);
    
    _mouseJoint->SetTarget(locationWorld);
}

void BrickBreaker::ccTouchesCancelled(cocos2d::Touch *touches, cocos2d::Event *event)
{
    if (_mouseJoint)
    {
        _world->DestroyJoint(_mouseJoint);
        _mouseJoint = NULL;
    }
}

void BrickBreaker::ccTouchesEnded(cocos2d::Touch *touches, cocos2d::Event *event)
{
    if (_mouseJoint)
    {
        _world->DestroyJoint(_mouseJoint);
        _mouseJoint = NULL;
    }
}

Scene* BrickBreaker::createScene()
{
    // 'scene' is an autorelease object
    //auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    //auto layer = GameView::create();
    
    // add layer as a child to scene
    //scene->addChild(layer);
    
    // return the scene
    //return scene;
    
    
    // 'scene' is an autorelease object
    Scene *scene = Scene::create();
    
    // add layer as a child to scene
    Layer* layer = new BrickBreaker();
    
    scene->addChild(layer);
    
    layer->release();
    
    return scene;
    
    
}

// on "init" you need to initialize your instance
bool BrickBreaker::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    return true;
}
