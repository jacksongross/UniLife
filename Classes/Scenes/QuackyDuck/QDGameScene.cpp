#include "QDGameScene.h"
#include "QDGameOverScene.h"
#include "QDDefinitions.h"
USING_NS_CC;

Scene* QDGameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_NONE);
    scene->getPhysicsWorld()->setGravity(Vect(0, 0));
    
    // 'layer' is an autorelease object
    auto layer = QDGameScene::create();
    layer->SetPhysicsWorld(scene->getPhysicsWorld());
    
    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool QDGameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto backgroundSprite = Sprite::create("QuackyDuck/Background.png");
    backgroundSprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    this->addChild(backgroundSprite);
    
    auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
    edgeBody->setCollisionBitmask(OBSTACLE_COLLISION_BITMASK);
    edgeBody->setContactTestBitmask(true);
    
    auto edgeNode = Node::create();
    edgeNode->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    edgeNode->setPhysicsBody(edgeBody);
    
    this->addChild(edgeNode);
    
    this->schedule(schedule_selector(QDGameScene::SpawnPipe), PIPE_SPAWN_FREQUENCY * visibleSize.width);
    
    duck = new QDDuck(this);
    
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(QDGameScene::onContactBegin, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
    
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(QDGameScene::onTouchBegin, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    
    //Scoring system
    
    score = 0;
    
    __String *tempScoreString = __String::createWithFormat( "%i", score );
    
    scoreLabel = Label::createWithTTF( tempScoreString->getCString( ), "QuackyDuck/Marker Felt.ttf", visibleSize.height * SCORE_FONT_SIZE );
    scoreLabel->setColor(Color3B::RED);
    scoreLabel->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height * 0.75 + origin.y ) );
    
    this->addChild(scoreLabel, 10000);
    
    this->scheduleUpdate();
    
    return true;
}

void QDGameScene::SpawnPipe(float dt)
{
    pipe.SpawnPipe(this);
}

bool QDGameScene::onContactBegin (PhysicsContact &contact)
{
    PhysicsBody *a = contact.getShapeA()->getBody();
    PhysicsBody *b = contact.getShapeB()->getBody();
    
    if((DUCK_COLLISION_BITMASK == a->getCollisionBitmask() && OBSTACLE_COLLISION_BITMASK == b->getCollisionBitmask()) ||
       (DUCK_COLLISION_BITMASK == b->getCollisionBitmask() && OBSTACLE_COLLISION_BITMASK == a->getCollisionBitmask())) {
        CCLOG("SCORE: %i ", score);
        auto scene = QDGameOverScene::createScene(score);
        
        Director::getInstance()->replaceScene(TransitionFade::create( TRANSITION_TIME, scene));
    }

    else if((DUCK_COLLISION_BITMASK == a->getCollisionBitmask() && POINT_COLLISION_BITMASK == b->getCollisionBitmask()) ||
            (DUCK_COLLISION_BITMASK == b->getCollisionBitmask() && POINT_COLLISION_BITMASK == a->getCollisionBitmask())) {
        score++;
        
        __String *tempScoreString = __String::createWithFormat( "%i", score );
        
        scoreLabel->setString(tempScoreString->getCString());
    }
    
    return true;
}

bool QDGameScene::onTouchBegin(cocos2d::Touch *touch, cocos2d::Event *event)
{
    duck->Fly();

    this->scheduleOnce(schedule_selector(QDGameScene::StopFlying), DUCK_FLY_DURATION);
    
    return true;
}

void QDGameScene::StopFlying(float dt)
{
    duck->StopFlying();
}

void QDGameScene::update(float dt)
{
    duck->Fall();
}

