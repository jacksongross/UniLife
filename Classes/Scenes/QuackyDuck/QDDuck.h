#ifndef _QD_DUCK_H_
#define _QD_DUCK_H_

#include "cocos2d.h"

class QDDuck
{
public:
    QDDuck( cocos2d::Layer *layer);
    
    void Fall();
    void Fly() { isFalling = false; }
    void StopFlying() { isFalling = true; }
    
private:
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    
    cocos2d::Sprite *quackyDuck;;
    
    bool isFalling;
};

#endif // _QD_DUCK_H_
