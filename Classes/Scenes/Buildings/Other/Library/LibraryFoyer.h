//
//  Library-Foyer.h
//  UniLife
//
//  Created by csci321ga2a on 8/09/2014.
//
//

#ifndef __UniLife__Library_Foyer__
#define __UniLife__Library_Foyer__

#include <iostream>
#include "PlayerModel.h"
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"

class LibraryFoyer : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    void UpdateMeters(PlayerStatsModel updateModel);
    
    void ToMeetingRoom(Ref* pSender);
    void ToMap(Ref* pSender);
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    // implement the "static create()" method manually
    CREATE_FUNC(LibraryFoyer);
    
private:
    
};
#endif /* defined(__UniLife__Library_Foyer__) */
