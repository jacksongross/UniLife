//
//  Inside_EIS_Controller.h
//  UniLife
//
//  Created by csci321ga2a on 28/08/2014.
//
//

#ifndef __UniLife__Inside_EIS_Controller__
#define __UniLife__Inside_EIS_Controller__

#include <iostream>
#include <vector>
#include "MenuNewGame.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "MenuController.h"
#include "Inside_EIS.h"

USING_NS_CC;

class Inside_EIS_Controller
{
    
private:
    
public:
    
    // create buttons for main menu
    static cocos2d::Vector<cocos2d::MenuItem*> CreateMenuButtons(Inside_EIS *that, Size visibleSize, Vec2 origin);
    
    // creates the main menu
    static void CreateMainMenu(Inside_EIS *that, Size visibleSize, Vec2 origin);
    
};


enum KeyboardReturnType {
    kKeyboardReturnTypeDefault = 0,
    
    kKeyboardReturnTypeDone = 1,
    
    kKeyboardReturnTypeSend = 2,
    
    kKeyboardReturnTypeSearch = 3,
    
    kKeyboardReturnTypeGo = 4
};

#endif /* defined(__UniLife__Inside_EIS_Controller__) */
