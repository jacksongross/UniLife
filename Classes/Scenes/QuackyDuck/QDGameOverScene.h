#ifndef _QD_GAMEOVER_SCENE_H_
#define _QD_GAMEOVER_SCENE_H_

#include "cocos2d.h"

class QDGameOverScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene(unsigned int tempScore);

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // implement the "static create()" method manually
    CREATE_FUNC(QDGameOverScene);
    
private:
    void GoToMainMenuScene( cocos2d::Ref *pSender);
    //void GoToGameScene( cocos2d::Ref *pSender);
    
};

#endif // _QD_GAMEOVER_SCENE_H_
