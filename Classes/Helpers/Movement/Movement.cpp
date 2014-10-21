//
//  Movement.cpp
//  UniLife
//
//  Created by Jackson Gross on 30/09/2014.
//
//

#include "Movement.h"
#include <string>
#include "cocos2d.h"
USING_NS_CC;
// GLOBALS FOR THE SPRITES USED FOR MOVEMENT/////////
cocos2d::Vector<cocos2d::SpriteFrame*> animFrames(4);
cocos2d::SpriteBatchNode *spritesheet;
/////////////////////////////////////////////////////

// load the sprite frames for the character
void Movement::loadSpriteFrames(cocos2d::Scene* scene)
{
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    
    spritesheet = cocos2d::SpriteBatchNode::create("walk.png");
    
    for(int i = 1; i <= 5; i++)
    {
        std::string file = "walk";
        file.append(std::to_string(i));
        file.append(".png");
        auto frame = cocos2d::SpriteFrameCache::getInstance()->getSpriteFrameByName(file);
        animFrames.pushBack(frame);
    }
    
    auto character = cocos2d::Sprite::createWithSpriteFrameName("walk1.png");
    character->setPosition(cocos2d::Vec2(visibleSize.width / 2 - 130, visibleSize.height / 2 - 135 ));
    character->setName("bill");
    
    spritesheet->setName("test");
    
    spritesheet->addChild(character);
    
    scene->addChild(spritesheet, 1);
    
}

// move character in the scene from start position to end position (touch point)
void Movement::moveCharacter(cocos2d::Scene* scene, float startX, float endX)
{
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    
    auto animation = cocos2d::Animation::createWithSpriteFrames(animFrames, 0.1f);
    auto walkAction = cocos2d::Repeat::create(cocos2d::Animate::create(animation), 3);
    
    auto ss = (cocos2d::Sprite*)scene->getChildByName("test");
    auto character = ss->getChildByName<cocos2d::Sprite*>("bill");
    
    // reset the character's facing side
    character->setFlippedX(false);
    
    // if the point to move is in the opposite direction
    // to where the player is currently standing
    if(endX > startX)
        character->setFlippedX(true);
    
    // change the height here
    auto move = cocos2d::MoveTo::create(2, cocos2d::Vec2(endX, visibleSize.height / 2 - 135));
    
    auto easeMove = cocos2d::EaseInOut::create(move, 3);
    
    auto easeWalk = cocos2d::EaseInOut::create(walkAction, 3);
    
    character->runAction(easeWalk);
    character->runAction(easeMove);
    
}

