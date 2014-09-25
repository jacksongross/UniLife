//
//  HUDHelper.cpp
//  UniLife
//
//  Created by csci321ga2a on 22/09/2014.
//
//

#include "HUDHelper.h"

// this method is used to create the HUD for each scene
void HUDLayer::createHUD(cocos2d::Scene* scene, PlayerModel pm)
{
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();
    
    cocos2d::log(pm.getName().c_str());
    cocos2d::log("energy: %d", pm.getStats().getEnergy());
    cocos2d::log("stress: %d", pm.getStats().getStress());
    
    cocos2d::ui::Text* engText = cocos2d::ui::Text::create("Energy ", "Verdana", 20);
    cocos2d::Sprite* engSprite = cocos2d::Sprite::create("HUD_energy_bar.png");
    cocos2d::ui::Text* streText = cocos2d::ui::Text::create("Stress ", "Verdana", 20);
    cocos2d::Sprite* streSprite = cocos2d::Sprite::create("HUD_stress_bar.png");
    cocos2d::ProgressTimer* pg = cocos2d::ProgressTimer::create(engSprite);
    cocos2d::ProgressTimer* pg2 = cocos2d::ProgressTimer::create(streSprite);
    
    engText->setContentSize(cocos2d::Size(400, 40));
    engText->setPosition(cocos2d::Vec2(origin.x + visibleSize.width / 2 - 360, visibleSize.height / 2 + 310));
    engText->setColor(cocos2d::Color3B(0,0,0));
    
    engSprite->setPosition(cocos2d::Vec2(origin.x + visibleSize.width / 2 - 475, origin.y + visibleSize.height / 2 + 300));
    engSprite->setAnchorPoint(cocos2d::Vec2(0.f,0.5f));
    engSprite->setScale(0.5 , 0.5);
    engSprite->setName("EnergyHUD");
    
    streText->setContentSize(cocos2d::Size(400, 40));
    streText->setPosition(cocos2d::Vec2(origin.x + visibleSize.width / 2 - 360, visibleSize.height / 2 + 275));
    streText->setColor(cocos2d::Color3B(0,0,0));
    streSprite->setPosition(cocos2d::Vec2(origin.x + visibleSize.width / 2 - 475, origin.y + visibleSize.height / 2 + 265));
    streSprite->setAnchorPoint(cocos2d::Vec2(0.f,0.5f));
    streSprite->setScale(0.5 , 0.5);
    streSprite->setName("StressHUD");
    
    pg->setBarChangeRate(cocos2d::Vec2(1, 0));
    pg->setAnchorPoint(cocos2d::Vec2(0.f,0.5f));
    pg->setTag(98);
    pg2->setTag(99);
    pg2->setBarChangeRate(cocos2d::Vec2(1, 0));
    pg2->setAnchorPoint(cocos2d::Vec2(0.f,0.5f));
    
    pg->setScaleX(pm.getStats().getEnergy()/100.0);
    pg2->setScaleX(pm.getStats().getStress()/100.0);
    pg->setPercentage(pm.getStats().getEnergy()/100.0);
    pg2->setPercentage(pm.getStats().getStress()/100.0);

    scene->addChild(engText, 1);
    scene->addChild(engSprite);
    scene->addChild(pg);
    scene->addChild(streText, 1);
    scene->addChild(streSprite);
    scene->addChild(pg2);
    
    
}

// this method is used to update the HUD bars
void HUDLayer::updateHUD(cocos2d::Scene* scene, PlayerModel pm)
{
    auto pgTimer = (cocos2d::ProgressTimer*)scene->getChildByName("EnergyHUD");
    
    pgTimer->setScaleX(pm.getStats().getEnergy()/100.0);
    pgTimer->setAnchorPoint(cocos2d::Vec2(0.f,0.5f));
    cocos2d::log("%d",pm.getStats().getEnergy());
    
    auto pgTimer2 = (cocos2d::ProgressTimer*)scene->getChildByName("StressHUD");
    
    pgTimer2->setScaleX(pm.getStats().getStress()/100.0);
    pgTimer2->setAnchorPoint(cocos2d::Vec2(0.f,0.5f));
    cocos2d::log("%d",pm.getStats().getStress());
    
}
