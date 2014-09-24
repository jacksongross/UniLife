//
//  LogicGame.h
//  UniLife
//
//  Created by csci321ga2a on 17/09/2014.
//
//

#ifndef __UniLife__LogicGame__
#define __UniLife__LogicGame__

#include "cocos2d.h"
using namespace cocos2d;
class LogicGame : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    void RunLogicGame();
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
    void resetgame();
    void updatemoves();
    void PushMessage(std::string inMessage);
    
    // implement the "static create()" method manually
    CREATE_FUNC(LogicGame);
private:
    
    Sprite* sprite;
    Point touchOffset;
    
    
    
    //Game Data
    std::vector<std::string> spritelocs;
    std::vector<bool> onleft;
    int intheboat = 0;
    
    int moveamt = 0;
    
    
};

#endif /* defined(__UniLife__LogicGame__) */
