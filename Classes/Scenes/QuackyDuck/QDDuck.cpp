#include "QDDuck.h"
#include "QDDefinitions.h"
USING_NS_CC;

QDDuck::QDDuck( cocos2d::Layer *layer)
{
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
    
    quackyDuck = Sprite::create("QuackyDuck/Ducky2.png");
    quackyDuck->setPosition( Point( visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    auto quackyBody = PhysicsBody::createCircle( quackyDuck->getContentSize().width/2);
    quackyBody->setCollisionBitmask(DUCK_COLLISION_BITMASK);
    quackyBody->setContactTestBitmask(true);
    quackyDuck->setPhysicsBody(quackyBody);
    
    layer->addChild(quackyDuck, 100);
    
    isFalling = true;
}

void QDDuck::Fall()
{
    if(isFalling == true) {
        quackyDuck->setPositionX(visibleSize.width/2 + origin.x);
        quackyDuck->setPositionY( quackyDuck->getPositionY() - (DUCK_FALLING_SPEED * visibleSize.height+1));
        
    }
    else {
        quackyDuck->setPositionX(visibleSize.width/2 + origin.x);
        quackyDuck->setPositionY( quackyDuck->getPositionY() + (DUCK_FALLING_SPEED * visibleSize.height+2));
    }
}
