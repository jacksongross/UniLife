//
//  BBStartScreen.h
//  UniLife
//
//  Created by Jackson Gross on 16/10/2014.
//
//

#ifndef __UniLife__BBStartScreen__
#define __UniLife__BBStartScreen__

#include "cocos2d.h"

class BBStartScreen : public cocos2d::LayerColor
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    void playCallback(cocos2d::Ref *pSender);
    
    void quitCallback(cocos2d::Ref *pSender);
    
    bool touchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    
    // implement the "static create()" method manually
    CREATE_FUNC(BBStartScreen);
    
private:
    
};

#endif /* defined(__UniLife__BBStartScreen__) */
