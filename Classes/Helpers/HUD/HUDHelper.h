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



class HUDLayer
{
public:
    
    // this method is used to create the HUD for each scene
    static void createHUD(cocos2d::Scene* scene, PlayerModel pm);
    
    // this method is used to update the HUD bars
    static void updateHUD(cocos2d::Scene* scene, PlayerModel pm);
    
    static void PausedPressed(cocos2d::Scene* scene);
    
private:

    

};
#endif /* defined(__UniLife__HUDHelper__) */
