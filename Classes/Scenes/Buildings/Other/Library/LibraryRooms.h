//
//  LibraryRooms.h
//  UniLife
//
//  Created by csci321ga2a on 9/09/2014.
//
//

#ifndef __UniLife__LibraryRooms__
#define __UniLife__LibraryRooms__

#include <iostream>
#include "PlayerModel.h"
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"

class LibraryRooms : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    void ToFoyer(Ref* pSender);
    void ToMeet1(Ref* pSender);
    void ToMeet2(Ref* pSender);
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    // implement the "static create()" method manually
    CREATE_FUNC(LibraryRooms);
    
    cocos2d::Scene* getHUDScene(){return this->HUDScene;};
    
    void setHUDScene(cocos2d::Scene* HUDScene){this->HUDScene = HUDScene;};
    
    
    
private:
    // holds reference to parent scene
    cocos2d::Scene* HUDScene;
    
};
#endif /* defined(__UniLife__LibraryRooms__) */
