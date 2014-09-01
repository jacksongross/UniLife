//
//  TavernFoyerController.h
//  UniLife
//
//  Created by csci321ga2a on 1/09/2014.
//
//

#ifndef __UniLife__TavernFoyerController__
#define __UniLife__TavernFoyerController__

#include <iostream>
#include <vector>
#include "MenuNewGame.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "MenuController.h"
#include "TavernFoyer.h"

USING_NS_CC;

class TavernFoyerController
{
    
private:
    
public:
    
    // create buttons for main menu
    static cocos2d::Vector<cocos2d::MenuItem*> CreateMenuButtons(TavernFoyer *that, Size visibleSize, Vec2 origin);
    
    // creates the main menu
    static void CreateMainMenu(TavernFoyer *that, Size visibleSize, Vec2 origin);
};
#endif /* defined(__UniLife__TavernFoyerController__) */
