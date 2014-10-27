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
    static void loadMap(TutorialScene *that, Size visibleSize, Vec2 origin, int whichone);
    //static void loadMap(TutorialScene *that, Size visibleSize, Vec2 origin, int whichone);
    static void loadFaculty(TutorialScene *that, Size visibleSize, Vec2 origin, int whichone);
    static void removeFaculty(TutorialScene *that);
    
    static void loadDorm(TutorialScene *that, Size visibleSize, Vec2 origin);
    static void removeDorm(TutorialScene *that, Size visibleSize, Vec2 origin);
    
    static void createHighlightedButton(TutorialScene *that, Size visibleSize, Vec2 origin,ui::Button* active);
    static void removeHighlightedButton(TutorialScene *that, Size visibleSize, Vec2 origin,ui::Button* active);
    static void createHighlightedSprite(TutorialScene *that, Size visibleSize, Vec2 origin,Sprite* active);
    static void removeHighlightedSprite(TutorialScene *that, Size visibleSize, Vec2 origin,Sprite* active);
    static void createHighlightedMenuImage(TutorialScene *that, Size visibleSize, Vec2 origin,MenuItemImage* active);
    static void removeHighlightedMenuImage(TutorialScene *that, Size visibleSize, Vec2 origin,MenuItemImage* active);
};


#endif /* defined(__UniLife__TutorialController__) */
