//
//  PauseMenu.h
//  UniLife
//
//  Created by Jackson Gross on 11/09/2014.
//
//

#ifndef UniLife_PauseMenu_h
#define UniLife_PauseMenu_h

#include "cocos2d.h"

class PauseMenu : public cocos2d::LayerColor
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    void resumeCallback(cocos2d::Ref *pSender);
    
    void saveCallback(cocos2d::Ref *pSender);
    
    void quitCallback(cocos2d::Ref *pSender);

    void helpCallback(Ref* pSender);
    
    bool touchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

    // implement the "static create()" method manually
    CREATE_FUNC(PauseMenu);
    
private:
    
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
};

#endif
