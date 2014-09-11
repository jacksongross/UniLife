//
//  GameView.h
//  UniLife
//
//  Created by Jackson Gross on 9/09/2014.
//
//

#ifndef UniLife_GameView_h
#define UniLife_GameView_h

#include "cocos2d.h"
#import <CCEventDispatcher.h>

class GameView : public cocos2d::LayerColor
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    void setPhyWorld(cocos2d::PhysicsWorld* world){m_world = world;}
    
    void addNewSpriteAtPosition(cocos2d::Point p);
    
    void addPaddle();
    
    void pushBall(float dt);
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameView);
    
private:
    cocos2d::PhysicsWorld* m_world;
};

#endif
