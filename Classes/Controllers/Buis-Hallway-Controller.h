//
//  Buis-Hallway-Controller.h
//  UniLife
//
//  Created by csci321ga2a on 8/09/2014.
//
//

#ifndef __UniLife__Buis_Hallway_Controller__
#define __UniLife__Buis_Hallway_Controller__

#include <iostream>
#include <vector>
#include "MenuNewGame.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "MenuController.h"
#include "Buis-Hallway.h"

USING_NS_CC;

class BuisHallwayController
{
    
private:
    
public:
    
    // create buttons for main menu
    static cocos2d::Vector<cocos2d::MenuItem*> CreateMenuButtons(BuisHallway *that, Size visibleSize, Vec2 origin);
    
    // creates the main menu
    static void CreateMainMenu(BuisHallway *that, Size visibleSize, Vec2 origin);
};

#endif /* defined(__UniLife__Buis_Hallway_Controller__) */
