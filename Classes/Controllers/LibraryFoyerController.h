//
//  LibraryFoyerController.h
//  UniLife
//
//  Created by csci321ga2a on 9/09/2014.
//
//

#ifndef __UniLife__LibraryFoyerController__
#define __UniLife__LibraryFoyerController__

#include <iostream>
#include <vector>
#include "MenuNewGame.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "MenuController.h"
#include "LibraryFoyer.h"

USING_NS_CC;

class LibraryFoyerController
{
    
private:
    
public:
    
    // create buttons for main menu
    static cocos2d::Vector<cocos2d::MenuItem*> CreateMenuButtons(LibraryFoyer *that, Size visibleSize, Vec2 origin);
    
    // creates the main menu
    static void CreateMainMenu(LibraryFoyer *that, Size visibleSize, Vec2 origin);
};
#endif /* defined(__UniLife__LibraryFoyerController__) */
