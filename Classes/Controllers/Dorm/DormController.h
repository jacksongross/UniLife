//
//  DormController.h
//  UniLife
//
//  Created by csci321ga2a on 8/14/14.
//
//

#ifndef UniLife_DormController_h
#define UniLife_DormController_h

#include "MenuScene.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "MenuController.h"
#include "DormScene.h"
#include "ui/CocosGUI.h"
#include <vector>

USING_NS_CC;

class DormController : public Node
{
    
private:
    
public:
    
    // create buttons for dorm room
    static cocos2d::Vector<cocos2d::MenuItem*> CreateDormButtons(DormScene *that, Size visibleSize, Vec2 origin);
    
    // creates the dorm room
    static void CreateDormRoom(DormScene *that, Size visibleSize, Vec2 origin);
    
    void UpdateTimer(float dt);
    
    void timeLost(float dt);//The countdown
    
    void doSomething();

};


#endif
