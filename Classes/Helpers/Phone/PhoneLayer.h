//
//  PhoneLayer.h
//  UniLife
//
//  Created by Jackson Gross on 30/09/2014.
//
//

#ifndef __UniLife__PhoneLayer__
#define __UniLife__PhoneLayer__

#include <stdio.h>
#include "cocos2d.h"
#include <string>
#include "TimeModel.h"

class PhoneLayer : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    void playerInfoCallback(Ref* pSender);
    
    void objectivesCallBack(Ref* pSender);
    
    void subjectsCallBack(Ref* pSender);
    
    void progressCallBack(Ref* pSender);
    
    void closeCallBack(Ref* pSender);
    
    static std::string getDateAsString(TimeModel tm);
    
    static std::string getTimeAsString(TimeModel tm);
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(PhoneLayer);
    
private:
    
};

#endif /* defined(__UniLife__PhoneLayer__) */
