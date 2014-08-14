//
//  MenuController.h
//  UniLife
//
//  Created by csci321ga2a on 8/12/14.
//
//

#ifndef UniLife_MenuController_h
#define UniLife_MenuController_h

#include "MenuScene.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "MenuController.h"
#include <vector>

USING_NS_CC;

class MenuController
{
    
private:
    
public:
    
    // create buttons for main menu
    static cocos2d::Vector<cocos2d::MenuItem*> CreateMenuButtons(MenuScene *that, Size visibleSize, Vec2 origin);
    
    // creates the main menu
    static void CreateMainMenu(MenuScene *that, Size visibleSize, Vec2 origin);
    
    // new game callback method
    static void newGameCallback(Ref* pSender);
    
    // load game callback method
    static void loadGameCallback(Ref* pSender);
    
    // options callback method
    static void optionsCallback(Ref* pSender);
    
};

#endif
