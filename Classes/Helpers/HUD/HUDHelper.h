//
//  HUDHelper.h
//  UniLife
//
//  Created by csci321ga2a on 22/09/2014.
//
//

#ifndef __UniLife__HUDHelper__
#define __UniLife__HUDHelper__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "PlayerModel.h"
#include "SqlHelper.h"

#include <UIText.h>



class HUDLayer : cocos2d::Layer
{
public:
    
    // this method is used to create the HUD for each scene
    static void createHUD(cocos2d::Scene* scene);
    
    // this method is used to update the HUD bars
    static void updateHUD(PlayerModel &pm);
    
    // handles pause button being pressed in HUD
    static void PausedPressed(cocos2d::Scene* scene);
    
    // handles phone button being pressed in HUD
    static void PhonePressed(cocos2d::Scene* scene);
    
    // used to set the player model for the HUD
    static void setPlayer(PlayerModel pm);
    
    static void setScene(cocos2d::Scene* scene);
    
    // returns current player instance
    static PlayerModel getCurrentPlayer();
    
    // update stats for a player
    static void updateStats(int intelligence, int stamina, int social, int energy, int stress);
    
    // updates the time for a player
    static void updateTime(double hoursminutes);
    
    // runs the code to validate autosaving
    void updateGameTime(float t);
    
    
    // updates the timer in the HUD
    void updateTimer();
    
    
private:

    

};
#endif /* defined(__UniLife__HUDHelper__) */
