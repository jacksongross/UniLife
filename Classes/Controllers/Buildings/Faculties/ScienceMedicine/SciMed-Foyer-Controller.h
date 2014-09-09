//
//  SciMed-Foyer-Controller.h
//  UniLife
//
//  Created by csci321ga2a on 8/09/2014.
//
//

#ifndef __UniLife__SciMed_Foyer_Controller__
#define __UniLife__SciMed_Foyer_Controller__

#include <iostream>
#include <vector>
#include "MenuNewGame.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "MenuController.h"
#include "SciMed-Hallway.h"
#include "SciMed-Foyer.h"

USING_NS_CC;

class SciMedFoyerController
{
    
private:
    
public:
    
    // create buttons for main menu
    static cocos2d::Vector<cocos2d::MenuItem*> CreateMenuButtons(SciMedFoyer *that, Size visibleSize, Vec2 origin);
    
    // creates the main menu
    static void CreateMainMenu(SciMedFoyer *that, Size visibleSize, Vec2 origin);
};

#endif /* defined(__UniLife__SciMed_Foyer_Controller__) */
