#ifndef _QD_GAME_SCENE_H_
#define _QD_GAME_SCENE_H_

#include "cocos2d.h"
#include "QDPipe.h"
#include "QDDuck.h"

class QDGameScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // implement the "static create()" method manually
    CREATE_FUNC(QDGameScene);
    
private:
    void SetPhysicsWorld( cocos2d::PhysicsWorld *world) { sceneWorld = world; }
    
    void SpawnPipe(float dt);
    
    bool onContactBegin(cocos2d::PhysicsContact &contact);
    
    bool onTouchBegin(cocos2d::Touch *touch, cocos2d::Event *event);
    
    void StopFlying(float dt);
    void update(float dt);
    
    cocos2d::PhysicsWorld *sceneWorld;
    
    QDPipe pipe;
    
    QDDuck *duck;
    
    unsigned int score;
    
    cocos2d::Label *scoreLabel;
};

#endif // _QD_GAME_SCENE_H_
