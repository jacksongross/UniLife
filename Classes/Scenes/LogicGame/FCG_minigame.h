//
//  FCG_minigame.h
//  UniLife
//
//  Created by csci321ga2a on 30/09/2014.
//
//

#ifndef __UniLife__FCG_minigame__
#define __UniLife__FCG_minigame__

#include <iostream>
#include "cocos2d.h"

using namespace cocos2d;
class FCGminigame : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    void createrules();
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    /// Returns the Cocos2d position of the touch
    Point touchToPoint(Touch* touch);
    
    /// Returns true if the touch is within the boundary of our sprite
    bool isTouchingSprite(Touch* touch, Sprite*);
    
    
    // we are multi-touch enabled, so we must use the ccTouches functions
    // vs the ccTouch functions
    void onTouchesBegan(const std::vector<Touch*>& touches, Event* event);
    void onTouchesMoved(const std::vector<Touch*>& touches, Event* event);
    void onTouchesEnded(const std::vector<Touch*>& touches, Event* event);
    
    
    void checkwin();
    void PushMessage(std::string inMessage);
    
    // implement the "static create()" method manually
    CREATE_FUNC(FCGminigame);
private:
    
    Sprite* sprite;
    Point touchOffset;
    
    
    
    //Game Data
    std::vector<std::string> spritelist;
    std::vector<bool> onleft;
    int intheboat = 0;
    int moveamt = 0;
    
    
};

#endif /* defined(__UniLife__FCG_minigame__) */
