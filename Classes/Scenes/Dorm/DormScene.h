//
//  DormScene.h
//  UniLife
//
//  Created by Jackson Gross on 8/14/14.
//
//

#ifndef UniLife_DormScene_h
#define UniLife_DormScene_h

#include "PlayerModel.h"
#include "cocos2d.h"

class DormScene : public cocos2d::Layer
{
    
private:
    
    // player data
    PlayerModel player;
    
public:
    
    bool isPaused;
    
    cocos2d::Label* timer;
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // overloaded createScene to pass in player
    static cocos2d::Scene* createScene(PlayerModel player);
    
    // overloaded create method to take player data
    static DormScene* create(PlayerModel player);
    
    void UpdateTimer(float dt);
    
    void PausedPressed(Ref* pSender);
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(DormScene);
    
    /********************************
                Getters
     *******************************/
    
    PlayerModel getPlayer();
    
    /********************************
                Setters
     *******************************/
    
    void setPlayer(PlayerModel player);
    
};

#endif
