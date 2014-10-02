//
//  BrickBreaker.h
//  UniLife
//
//  Created by Jackson Gross on 9/09/2014.
//
//

#ifndef UniLife_BrickBreaker_h
#define UniLife_BrickBreaker_h

#include "cocos2d.h"
#include "box2d/Box2D.h"
#include "MyContactListener.h"
#include "GameOverScene.h"
#include "SimpleAudioEngine.h"

class BrickBreaker : public cocos2d::Layer
{
public:
    
    ~BrickBreaker();
    
    BrickBreaker();
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(BrickBreaker);

    // touch functions
    virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4& transform, bool transformUpdated);
    void touchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
    void touchCancelled(cocos2d::Touch* touch, cocos2d::Event* event);
    bool touchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    void touchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
    void tick(float dt);
    
    
private:
    
    b2World* _world;
    b2Body *_groundBody;
    b2Fixture *_bottomFixture;
    b2Fixture *_ballFixture;
    b2Body *_paddleBody;
    b2Fixture *_paddleFixture;
    b2MouseJoint *_mouseJoint;
    
    MyContactListener *_contactListener;
    
};


#endif
