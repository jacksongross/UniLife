//
//  UniCenterGym.h
//  UniLife
//
//  Created by Jackson Gross on 28/10/2014.
//
//

#ifndef __UniLife__UniCenterGym__
#define __UniLife__UniCenterGym__

#include <iostream>
#include "PlayerModel.h"
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"

class UniCenterGym : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    void toMap(Ref* pSender);
    void ToFoyer(Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(UniCenterGym);
    
    cocos2d::Scene* getHUDScene()
    {
        return this->HUDScene;
    };
    
    void setHUDScene(cocos2d::Scene* HUDScene)
    {
        this->HUDScene = HUDScene;
    };
    
private:
    
    cocos2d::Scene* HUDScene;
};



#endif /* defined(__UniLife__UniCenterScene__) */
