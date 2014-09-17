//
//  MenuOptionScene.h
//  UniLife
//
//  Created by csci321ga2a on 8/12/14.
//
//

#ifndef UniLife_MenuOptionScene_h
#define UniLife_MenuOptionScene_h

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"

class MenuOptionScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    void backButtonCallback(Ref* pSender);
    void debugButtonCallback(Ref* pSender);
    
    void backgroundMusicSliderChange(Ref* pSender, cocos2d::ui::Slider::EventType type);
    void soundEffectsSliderChange(Ref* pSender, cocos2d::ui::Slider::EventType type);
    // implement the "static create()" method manually
    CREATE_FUNC(MenuOptionScene);
    
};

#endif
