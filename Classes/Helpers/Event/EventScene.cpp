//
//  EventScene.cpp
//  UniLife
//
//  Created by Jackson Gross on 28/10/2014.
//
//

#include "EventScene.h"

USING_NS_CC;

Scene* EventScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = EventScene::create();
    layer->setName("event");
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// overloaded createScene to pass in player
cocos2d::Scene* EventScene::createScene(std::string event)
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = EventScene::create(event);
    layer->setName("event");
    
    // add layer as a child to scene
    scene->addChild(layer);

    // create an image layer that displays an
    // image and fades out after 3 seconds
    
    Size visiblesize = Director::getInstance()->getVisibleSize();
    
    auto bg = Sprite::create(event);
    bg->setPosition(Vec2(visiblesize.width / 2, visiblesize.height / 2));
    
    layer->addChild(bg);
    
    DelayTime *dt = DelayTime::create(3);
    
    auto callback = CallFunc::create([](){
        
        Director::getInstance()->popScene();
        
    });
    
    scene->runAction(Sequence::createWithTwoActions(dt, callback));
    
    // return the scene
    return scene;
}

// overloaded create method to take player data
EventScene* EventScene::create(std::string event)
{
    EventScene *es = new EventScene();
    if (es->init())
    {
        es->autorelease();
        es->setFilename(event);
    }
    else{
        es = NULL;
    }
    return es;
}

// on "init" you need to initialize your instance
bool EventScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    // get the size of the screen that is visible
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    return true;
}



/********************************
        Getters
 *******************************/

std::string EventScene::getFilename()
{
    return this->filename;
}

/********************************
        Setters
 *******************************/

void EventScene::setFilename(std::string filename)
{
    this->filename = filename;
}

