//
//  MenuLoadController.h
//  UniLife
//
//  Created by csci321ga2a on 8/12/14.
//
//

#ifndef UniLife_MenuLoadController_h
#define UniLife_MenuLoadController_h

#include "MenuLoadScene.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "MenuController.h"
#include <vector>

USING_NS_CC;

class MenuLoadController
{
    
private:
    
public:
    
    // create buttons for main menu
    static cocos2d::Vector<cocos2d::MenuItem*> CreateMenuButtons(MenuLoadScene *that, Size visibleSize, Vec2 origin);
    
    // creates the main menu
    static void CreateMainMenu(MenuLoadScene *that, Size visibleSize, Vec2 origin);
    
};

#endif
