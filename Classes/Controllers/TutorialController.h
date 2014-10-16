//
//  TutorialController.h
//  UniLife
//
//  Created by csci321ga2a on 14/10/2014.
//
//

#ifndef __UniLife__TutorialController__
#define __UniLife__TutorialController__

#include <iostream>
#include "TutorialScene.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "MenuController.h"
#include <vector>

class TutorialController
{
    
private:
    
public:
    
    // create buttons for main menu
    static cocos2d::Vector<cocos2d::MenuItem*> CreateMenuButtons(TutorialScene *that, Size visibleSize, Vec2 origin);
    
    // creates the main menu
    static void CreateMainMenu(TutorialScene *that, Size visibleSize, Vec2 origin);
    static void loadMap(TutorialScene *that, Size visibleSize, Vec2 origin, int buildingID, int whichone);
    static void FacultyPressed(cocos2d::Ref *pSender, ui::Widget::TouchEventType eEventType);

};


#endif /* defined(__UniLife__TutorialController__) */
