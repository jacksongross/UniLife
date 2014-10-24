//
//  TutorialScene.h
//  UniLife
//
//  Created by csci321ga2a on 14/10/2014.
//
//

#ifndef __UniLife__TutorialScene__
#define __UniLife__TutorialScene__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
using namespace cocos2d::extension;




class TutorialScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // new game callback method
   
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    bool nextPage(cocos2d::Touch* touch, cocos2d::Event* event);
    void compassPress(Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
    void buildingPress(Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
    void receptPress(Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
    // implement the "static create()" method manually
    CREATE_FUNC(TutorialScene);
    
private:
    int whichpage = 0;
    int whichbuild = 0;
    bool lock = false;
};





#endif /* defined(__UniLife__TutorialScene__) */
