//
//  MenuOptionController.h
//  UniLife
//
//  Created by csci321ga2a on 8/12/14.
//
//

#ifndef UniLife_MenuOptionController_h
#define UniLife_MenuOptionController_h

#include "MenuScene.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "MenuController.h"
#include "MenuOptionScene.h"
#include <vector>

USING_NS_CC;

class MenuOptionController
{
    
private:
    
public:
    
    // create buttons for main menu
    static cocos2d::Vector<cocos2d::MenuItem*> CreateMenuButtons(MenuOptionScene *that, Size visibleSize, Vec2 origin);
    
    // creates the main menu
    static void CreateMainMenu(MenuOptionScene *that, Size visibleSize, Vec2 origin);
    
};


#endif
