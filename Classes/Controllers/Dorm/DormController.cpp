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
#include "CCActionInterval.h"
#include "CCAction.h"

extern PlayerModel pm;

USING_NS_CC;

// create the buttons for the main menu
cocos2d::Vector<cocos2d::MenuItem*> DormController::CreateDormButtons(DormScene *that, Size visibleSize, Vec2 origin)
{
    
    // create the a vector to hold the menu items
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems;
    
    // animate the menu button to spin
    auto pauseButton = MenuItemImage::create("cog-110.png", "cog-110.png", CC_CALLBACK_1(DormScene::PausedPressed, that));
    
    pauseButton->setPosition(Vec2(visibleSize.width * .95, visibleSize.height * .90));
    
    auto rotate = RotateBy::create(5.0f, 360);
    
    // run this forever so it keeps on spinning
    auto action = RepeatForever::create(rotate);
    
    pauseButton->runAction(action);
    
    pMenuItems.pushBack(pauseButton);
    
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
    auto bg = Sprite::create("dorm-background.png");
    
    // position the sprite on the center of the screen
    bg->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    that->addChild(bg, 0);
    
    // add bill to the screen
    auto player2 = Sprite::create("bill_inside.png");
    
    player2->setPosition(Vec2(visibleSize.width / 2 - 130, visibleSize.height / 2 - 135 ));
    
    that->addChild(player2, 6);
    
    // add the door
    auto sprite = Sprite::create("dorm-door.png");
    
    sprite->setPosition(Vec2(visibleSize.width / 2 - origin.x - sprite->getContentSize().width - 39, visibleSize.height / 2 + origin.y - 10));
    
    sprite->setTag(8);
    
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
            auto scene = MapScene::createScene(pm);
            TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
            Director::getInstance()->replaceScene(crosssfade);
            
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
    
    sprite->setPosition(Vec2(origin.x + sprite->getContentSize().width / 2 + 11, visibleSize.height / 2 - 120));
    
    that->addChild(sprite, 3);
    
    // add the computer
    sprite = Sprite::create("dorm-computer.png");
    
    sprite->setPosition(Vec2(origin.x + sprite->getContentSize().width / 2 + 12, visibleSize.height / 2 + 58));
    
    that->addChild(sprite, 4);
    
    // add the stool
    sprite = Sprite::create("dorm-stool.png");
    
    sprite->setPosition(Vec2(origin.x + sprite->getContentSize().width / 2 + 15, origin.y + sprite->getContentSize().height / 2));
    
    that->addChild(sprite, 5);
    
    //sprite->runAction(action);
    
    //that->addChild(sprite, 6);
    
    // set up the timer
    
    that->timer = Label::createWithSystemFont("11:30pm", "Verdana", 64);
    
    that->timer->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - 22));
    
    that->addChild(that->timer);
    
    
    //Energy HUD
    cocos2d::ui::Text* engText = cocos2d::ui::Text::create("Energy ", "Verdana", 20);
    engText->setContentSize(Size(400, 40));
    engText->setPosition(Vec2(origin.x + visibleSize.width / 2 - 360, visibleSize.height / 2 + 310));
    engText->setColor(Color3B(0,0,0));
    that->addChild(engText, 0);
    
    
    Sprite* engSprite = Sprite::create("HUD_energy_bar.png");
    engSprite->setPosition(Vec2(origin.x + visibleSize.width / 2 - 400, origin.y + visibleSize.height / 2 + 300));
    ProgressTimer* pg = ProgressTimer::create(engSprite);
    engSprite->setScale(0.5 , 0.5);
    engSprite->setTag(1);
    that->addChild(engSprite);
    that->addChild(pg);
    
    
    //Stress HUD
    cocos2d::ui::Text* strText = cocos2d::ui::Text::create("Stress ", "Verdana", 20);
    strText->setContentSize(Size(400, 40));
    strText->setPosition(Vec2(origin.x + visibleSize.width / 2 - 360, visibleSize.height / 2 + 275));
    strText->setColor(Color3B(0,0,0));
    that->addChild(strText, 0);
    
    Sprite* streSprite = Sprite::create("HUD_stress_bar.png");
    streSprite->setPosition(Vec2(origin.x + visibleSize.width / 2 - 400, origin.y + visibleSize.height / 2 + 265));
    ProgressTimer* pg2 = ProgressTimer::create(streSprite);
    streSprite->setScale(0.5 , 0.5);
    streSprite->setTag(2);
    that->addChild(streSprite);
    that->addChild(pg2);
    
    
    
}

