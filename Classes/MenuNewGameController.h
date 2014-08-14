//
//  MenuNewGameController.h
//  UniLife
//
//  Created by csci321ga2a on 14/08/2014.
//
//

#ifndef __UniLife__MenuNewGameController__
#define __UniLife__MenuNewGameController__

#include "MenuNewGame.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "MenuController.h"
#include <vector>

USING_NS_CC;

class MenuNewGameController
{
    
private:
    
public:
    
    // create buttons for main menu
    static cocos2d::Vector<cocos2d::MenuItem*> CreateMenuButtons(MenuNewGame *that, Size visibleSize, Vec2 origin);
    
    // creates the main menu
    static void CreateMainMenu(MenuNewGame *that, Size visibleSize, Vec2 origin);
    
};


enum KeyboardReturnType {
    kKeyboardReturnTypeDefault = 0,
    
    kKeyboardReturnTypeDone = 1,
    
    kKeyboardReturnTypeSend = 2,
    
    kKeyboardReturnTypeSearch = 3,
    
    kKeyboardReturnTypeGo = 4
};



#endif /* defined(__UniLife__MenuNewGameController__) */
