//
//  PopUpLayer.h
//  UniLife
//
//  Created by csci321ga2a on 30/09/2014.
//
//

#ifndef __UniLife__PopUpLayer__
#define __UniLife__PopUpLayer__

#include "cocos2d.h"

class PopUpLayer : public cocos2d::LayerColor
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    void offClick(Ref* pSender);
    
    void bedPressed(cocos2d::Rect inRect, cocos2d::Vec2 inLoc);
    
    bool touchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    
    // implement the "static create()" method manually
    CREATE_FUNC(PopUpLayer);
    
private:
    
};

#endif /* defined(__UniLife__PopUpLayer__) */
