//
//  MenuDegreeSelect.h
//  UniLife
//
//  Created by csci321ga2a on 21/08/2014.
//
//

#ifndef __UniLife__MenuDegreeSelect__
#define __UniLife__MenuDegreeSelect__

#include <iostream>
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include <vector>
using namespace cocos2d::extension;

class MenuDegreeSelect : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    void BackButtonCallback(Ref* pSender);
    void LVTouch(Ref *pSender, cocos2d::ui::Widget::TouchEventType type, int whosent);
    void NextButtonCallback(Ref* pSender);
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    // implement the "static create()" method manually
    CREATE_FUNC(MenuDegreeSelect);
    std::vector<std::string> clist;
    std::vector<std::string> ilist;
    
    
    
private:
    
    
};



#endif /* defined(__UniLife__MenuDegreeSelect__) */

