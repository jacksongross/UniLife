//
//  TavernRoomController.h
//  UniLife
//
//  Created by csci321ga2a on 8/09/2014.
//
//

#ifndef __UniLife__TavernRoomController__
#define __UniLife__TavernRoomController__
#include <iostream>
#include <vector>
#include "MenuNewGame.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "MenuController.h"
#include "TavernRoom.h"

USING_NS_CC;

class TavernRoomController
{
    
private:
    
public:
    
    // create buttons for main menu
    static cocos2d::Vector<cocos2d::MenuItem*> CreateMenuButtons(TavernRoom *that, Size visibleSize, Vec2 origin);
    
    // creates the main menu
    static void CreateMainMenu(TavernRoom *that, Size visibleSize, Vec2 origin);
};
#endif /* defined(__UniLife__TavernRoomController__) */
