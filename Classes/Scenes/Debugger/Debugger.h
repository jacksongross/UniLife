//
//  Debugger.h
//  UniLife
//
//  Created by csci321ga2a on 18/09/2014.
//
//

#ifndef __UniLife__Debugger__
#define __UniLife__Debugger__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"

using namespace cocos2d;
using namespace ui;

class Debugger : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    void gotoLogicGame(Ref* sender);
    void gotoBrickBreaker(Ref* pSender);

    void SpawnList();
    
    // implement the "static create()" method manually
    CREATE_FUNC(Debugger);
private:
    
    
};

#endif /* defined(__UniLife__Debugger__) */
