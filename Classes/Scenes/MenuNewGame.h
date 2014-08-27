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
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
using namespace cocos2d::extension;




class MenuNewGame : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // new game callback method
    void NextButtonCallback(Ref* pSender);
    void backButtonCallback(Ref* pSender);
    void sliderEvent(Ref* pSender, cocos2d::ui::Slider::EventType type);
    void sliderEvent2(Ref* pSender, cocos2d::ui::Slider::EventType type);
    void sliderEvent3(Ref* pSender, cocos2d::ui::Slider::EventType type);
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    // implement the "static create()" method manually
    CREATE_FUNC(MenuNewGame);
    
private:
    bool slideenabled = true;
    int limiter = 5;
    int pointsleft, maxpoints = 20, prev;
    
};



#endif /* defined(__UniLife__MenuNewGame__) */