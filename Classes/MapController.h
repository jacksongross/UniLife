//
//  MapController.h
//  UniLife
//
//  Created by csci321ga2a on 8/14/14.
//
//

#ifndef UniLife_MapController_h
#define UniLife_MapController_h

#include "MenuScene.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "MenuController.h"
#include "DormScene.h"
#include "MapScene.h"
#include <vector>

USING_NS_CC;

class MapController
{
    
private:
    
public:
    
    // create buttons for dorm room
    static cocos2d::Vector<cocos2d::MenuItem*> CreateMapButtons(MapScene *that, Size visibleSize, Vec2 origin);
    
    // creates the dorm room
    static void CreateMapView(MapScene *that, Size visibleSize, Vec2 origin);
    
};

#endif
