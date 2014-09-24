//
//  LogicGameMessages.h
//  UniLife
//
//  Created by csci321ga2a on 25/09/2014.
//
//

#ifndef __UniLife__LogicGameMessages__
#define __UniLife__LogicGameMessages__

#include "cocos2d.h"

class LogicGameMessages : public cocos2d::LayerColor
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    static cocos2d::Scene* createScene(std::string inMessage);
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    void retryCallback(cocos2d::Ref *pSender);
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(LogicGameMessages);
    
private:
    
};

#endif /* defined(__UniLife__LogicGameMessages__) */
