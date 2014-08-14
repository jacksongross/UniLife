//
//  MenuNewGame.h
//  UniLife
//
//  Created by csci321ga2a on 14/08/2014.
//
//

#ifndef __UniLife__MenuNewGame__
#define __UniLife__MenuNewGame__

#include "cocos2d.h"

class MenuNewGame : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // new game callback method
    void dostuffcallback(Ref* pSender);
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(MenuNewGame);
};



#endif /* defined(__UniLife__MenuNewGame__) */
