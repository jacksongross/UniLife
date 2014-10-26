//
//  GameOverScene.h
//  UniLife
//
//  Created by Jackson Gross on 9/09/2014.
//
//

#ifndef UniLife_GameOverScene_h
#define UniLife_GameOverScene_h

#include "cocos2d.h"

class GameOverLayer : public cocos2d::LayerColor
{
public:
    CREATE_FUNC(GameOverLayer);
    CC_SYNTHESIZE_READONLY(cocos2d::Label*, _label, Label);
	
    virtual ~GameOverLayer();
    bool init();
    
    void retryCallback(Ref* pSender);
    void quitCallback(Ref* pSender);
	
};

class GameOverScene : public cocos2d::Scene
{
public:
    CREATE_FUNC(GameOverScene);
    CC_SYNTHESIZE_READONLY(GameOverLayer*, _layer, Layer);
    
    ~GameOverScene();
    bool init();
};

#endif
