//
//  Movement.h
//  UniLife
//
//  Created by Jackson Gross on 30/09/2014.
//
//

#ifndef __UniLife__Movement__
#define __UniLife__Movement__

#include <stdio.h>
#include "cocos2d.h"

class Movement : cocos2d::Layer
{
    
public:
    
    // load the sprite frames for the character
    static void loadSpriteFrames(cocos2d::Scene* scene);
    
    // move character in the scene from start position to end position (touch point)
    static void moveCharacter(cocos2d::Scene* scene, float startX, float endX);
    
    // returns the player x position
    static float getPlayerPosition(cocos2d::Scene* scene);
    
    
private:
    
};


#endif /* defined(__UniLife__Movement__) */
