//
//  LibraryRoomsController.h
//  UniLife
//
//  Created by csci321ga2a on 9/09/2014.
//
//

#ifndef __UniLife__LibraryRoomsController__
#define __UniLife__LibraryRoomsController__

#include <iostream>
#include <vector>
#include "MenuNewGame.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "MenuController.h"
#include "LibraryRooms.h"

USING_NS_CC;

class LibraryRoomsController
{
    
private:
    
public:
    
    // create buttons for main menu
    static cocos2d::Vector<cocos2d::MenuItem*> CreateMenuButtons(LibraryRooms *that, Size visibleSize, Vec2 origin);
    
    // creates the main menu
    static void CreateMainMenu(LibraryRooms *that, Size visibleSize, Vec2 origin);
};
#endif /* defined(__UniLife__LibraryRoomsController__) */
