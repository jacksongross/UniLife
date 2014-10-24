//
//  PauseHelpScene.h
//  UniLife
//
//  Created by Kurt Robinson on 22/10/2014.
//
//

#ifndef __UniLife__PauseHelpScene__
#define __UniLife__PauseHelpScene__

#include "cocos2d.h"

class PauseHelpScene : public cocos2d::Layer
{
    
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    //bool touchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    
    // implement the "static create()" method manually
    CREATE_FUNC(PauseHelpScene);
    
private:
    
};

#endif /* defined(__UniLife__PauseHelpScene__) */
