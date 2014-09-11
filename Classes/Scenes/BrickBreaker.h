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

class BrickBreaker : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(BrickBreaker);
};


#endif
