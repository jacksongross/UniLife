//
//  Art-Hallway.h
//  UniLife
//
//  Created by csci321ga2a on 8/09/2014.
//
//

#ifndef __UniLife__Art_Hallway__
#define __UniLife__Art_Hallway__

#include <iostream>
#include "PlayerModel.h"
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"

class ArtHallway : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    void UpdateMeters(PlayerStatsModel updateModel);
    
    void ToFoyer(Ref* pSender);
    void ToLecture(Ref* pSender);
    void ToTutorial(Ref* pSender);
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    // implement the "static create()" method manually
    CREATE_FUNC(ArtHallway);
    
private:
    
};

#endif /* defined(__UniLife__Art_Hallway__) */
