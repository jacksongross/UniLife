//
//  DormController.cpp
//  UniLife
//
//  Created by csci321ga2a on 8/14/14.
//
//

#include "DormController.h"
#include "MapScene.h"
#include "MapController.h"

USING_NS_CC;

// create the buttons for the main menu
cocos2d::Vector<cocos2d::MenuItem*> DormController::CreateDormButtons(DormScene *that, Size visibleSize, Vec2 origin)
{
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems;
    
    return pMenuItems;
    
}

// call this method in the main menu scene to create the main menu
void DormController::CreateDormRoom(DormScene *that, Size visibleSize, Vec2 origin)
{
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems = CreateDormButtons(that, visibleSize, origin);
    
    // create menu, it's an autorelease object
    auto menu = Menu::createWithArray(pMenuItems);
    menu->setPosition(Vec2::ZERO);
    that->addChild(menu, 1);
    
    // create dorm room
    auto sprite = Sprite::create("dorm-background.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    that->addChild(sprite, 0);
    
    // add bill to the screen
    sprite = Sprite::create("bill_inside.png");
    
    sprite->setPosition(Vec2(visibleSize.width / 2 - 130, visibleSize.height / 2 - 135 ));
    
    that->addChild(sprite, 6);
    
    // add the door
    sprite = Sprite::create("dorm-door.png");
    
    sprite->setPosition(Vec2(visibleSize.width / 2 - origin.x - sprite->getContentSize().width - 39, visibleSize.height / 2 + origin.y - 10));
    
    that->addChild(sprite, 0);
    
    
    //Create a "one by one" touch event listener (processes one touch at a time)
    auto listener1 = EventListenerTouchOneByOne::create();
    // When "swallow touches" is true, then returning 'true' from the onTouchBegan method will "swallow" the touch event, preventing other listeners from using it.
    listener1->setSwallowTouches(true);
    
    // Example of using a lambda expression to implement onTouchBegan event callback function
    listener1->onTouchBegan = [](Touch* touch, Event* event){
        // event->getCurrentTarget() returns the *listener's* sceneGraphPriority node.
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        
        //Get the position of the current point relative to the button
        Point locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        
        //Check the click area
        if (rect.containsPoint(locationInNode))
        {
            log("you have touched the door!");
            
            // transition to the load game scene
            auto scene = MapScene::createScene();
            CCTransitionPageTurn *crosssfade = CCTransitionPageTurn::create(1,scene, true);
            CCDirector::sharedDirector()->replaceScene(crosssfade);
            
            return true;
        }
        return false;
    };
    
    //Trigger when moving touch
    listener1->onTouchMoved = [](Touch* touch, Event* event){
        //auto target = static_cast<Sprite*>(event->getCurrentTarget());
        //Move the position of current button sprite
        //target->setPosition(target->getPosition() + touch->getDelta());
    };
    
    //Process the touch end event
    listener1->onTouchEnded = [=](Touch* touch, Event* event){
        //auto target = static_cast<Sprite*>(event->getCurrentTarget());
        //log("sprite onTouchesEnded.. ");
        //target->setOpacity(255);
        //Reset zOrder and the display sequence will change
        /*if (target == sprite)
        {
            sprite->setZOrder(100);
        }
        else if(target == sprite)
        {
            sprite->setZOrder(0);
        }
         */
    };
    
    that->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener1, sprite);
    
    // add the bed
    sprite = Sprite::create("dorm-bed.png");
    
    sprite->setPosition(Vec2(visibleSize.width - origin.x - sprite->getContentSize().width + 202, visibleSize.height - sprite->getContentSize().height - 220));
    
    that->addChild(sprite, 1);
    
    // add the book shelf
    sprite = Sprite::create("dorm-book_shelf.png");
    
    sprite->setPosition(Vec2(visibleSize.width - sprite->getContentSize().width - 333, visibleSize.height / 2 + origin.y - 91));
    
    that->addChild(sprite, 2);
    
    // add the desk
    sprite = Sprite::create("dorm-desk.png");
    
    sprite->setPosition(Vec2(origin.x + sprite->getContentSize().width / 2 + 11, visibleSize.height / 2 - 121));
    
    that->addChild(sprite, 3);
    
    // add the computer
    sprite = Sprite::create("dorm-computer.png");
    
    sprite->setPosition(Vec2(origin.x + sprite->getContentSize().width / 2 + 12, visibleSize.height / 2 + 58));
    
    that->addChild(sprite, 4);
    
    // add the stool
    sprite = Sprite::create("dorm-stool.png");
    
    sprite->setPosition(Vec2(origin.x + sprite->getContentSize().width / 2 + 15, origin.y + sprite->getContentSize().height / 2));
    
    that->addChild(sprite, 5);
    
}
