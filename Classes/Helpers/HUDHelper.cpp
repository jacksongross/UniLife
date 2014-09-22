//
//  HUDHelper.cpp
//  UniLife
//
//  Created by csci321ga2a on 22/09/2014.
//
//

#include "HUDHelper.h"

HUDLayer::HUDLayer(){
    
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    engText->setContentSize(Size(400, 40));
    engText->setPosition(Vec2(origin.x + visibleSize.width / 2 - 360, visibleSize.height / 2 + 310));
    engText->setColor(Color3B(0,0,0));
    
    engSprite->setPosition(Vec2(origin.x + visibleSize.width / 2 - 475, origin.y + visibleSize.height / 2 + 300));
    engSprite->setAnchorPoint(Vec2(0.f,0.5f));
    engSprite->setScale(0.5 , 0.5);
    engSprite->setName("EnergyHUD");
    
    
    
    streText->setContentSize(Size(400, 40));
    streText->setPosition(Vec2(origin.x + visibleSize.width / 2 - 360, visibleSize.height / 2 + 275));
    streText->setColor(Color3B(0,0,0));
    streSprite->setPosition(Vec2(origin.x + visibleSize.width / 2 - 475, origin.y + visibleSize.height / 2 + 265));
    streSprite->setAnchorPoint(Vec2(0.f,0.5f));
    streSprite->setScale(0.5 , 0.5);
    streSprite->setName("StressHUD");
    
    
    pg->setBarChangeRate(Vec2(1, 0));
    pg->setAnchorPoint(Vec2(0.f,0.5f));
    pg2->setBarChangeRate(Vec2(1, 0));
    pg2->setAnchorPoint(Vec2(0.f,0.5f));
    
}

void HUDLayer::create(ArtFoyer *that, PlayerModel pm){
    
    pg->setScaleX(pm.getStats().getEnergy()/100.0);
    pg2->setScaleX(pm.getStats().getStress()/100.0);
    that->addChild(engText, 1);
    that->addChild(engSprite);
    that->addChild(pg);
    that->addChild(streText, 1);
    that->addChild(streSprite);
    that->addChild(pg2);

}


void HUDLayer::create(ArtHallway *that, PlayerModel pm){
    
    pg->setScaleX(pm.getStats().getEnergy()/100.0);
    pg2->setScaleX(pm.getStats().getStress()/100.0);
    that->addChild(engText, 1);
    that->addChild(engSprite);
    that->addChild(pg);
    that->addChild(streText, 1);
    that->addChild(streSprite);
    that->addChild(pg2);
    
}

void HUDLayer::create(BuisFoyer *that, PlayerModel pm){
    
    pg->setScaleX(pm.getStats().getEnergy()/100.0);
    pg2->setScaleX(pm.getStats().getStress()/100.0);
    that->addChild(engText, 1);
    that->addChild(engSprite);
    that->addChild(pg);
    that->addChild(streText, 1);
    that->addChild(streSprite);
    that->addChild(pg2);
    
}


void HUDLayer::create(BuisHallway *that, PlayerModel pm){
    
    pg->setScaleX(pm.getStats().getEnergy()/100.0);
    pg2->setScaleX(pm.getStats().getStress()/100.0);
    that->addChild(engText, 1);
    that->addChild(engSprite);
    that->addChild(pg);
    that->addChild(streText, 1);
    that->addChild(streSprite);
    that->addChild(pg2);
    
}


void HUDLayer::create(SocSciFoyer *that, PlayerModel pm){
    
    pg->setScaleX(pm.getStats().getEnergy()/100.0);
    pg2->setScaleX(pm.getStats().getStress()/100.0);
    that->addChild(engText, 1);
    that->addChild(engSprite);
    that->addChild(pg);
    that->addChild(streText, 1);
    that->addChild(streSprite);
    that->addChild(pg2);
    
}


void HUDLayer::create(SocSciHallway *that, PlayerModel pm){
    
    pg->setScaleX(pm.getStats().getEnergy()/100.0);
    pg2->setScaleX(pm.getStats().getStress()/100.0);
    that->addChild(engText, 1);
    that->addChild(engSprite);
    that->addChild(pg);
    that->addChild(streText, 1);
    that->addChild(streSprite);
    that->addChild(pg2);
    
}

void HUDLayer::create(SciMedFoyer *that, PlayerModel pm){
    
    pg->setScaleX(pm.getStats().getEnergy()/100.0);
    pg2->setScaleX(pm.getStats().getStress()/100.0);
    that->addChild(engText, 1);
    that->addChild(engSprite);
    that->addChild(pg);
    that->addChild(streText, 1);
    that->addChild(streSprite);
    that->addChild(pg2);
    
}


void HUDLayer::create(SciMedHallway *that, PlayerModel pm){
    
    pg->setScaleX(pm.getStats().getEnergy()/100.0);
    pg2->setScaleX(pm.getStats().getStress()/100.0);
    that->addChild(engText, 1);
    that->addChild(engSprite);
    that->addChild(pg);
    that->addChild(streText, 1);
    that->addChild(streSprite);
    that->addChild(pg2);
    
}

void HUDLayer::create(Inside_EIS *that, PlayerModel pm){
    
    pg->setScaleX(pm.getStats().getEnergy()/100.0);
    pg2->setScaleX(pm.getStats().getStress()/100.0);
    that->addChild(engText, 1);
    that->addChild(engSprite);
    that->addChild(pg);
    that->addChild(streText, 1);
    that->addChild(streSprite);
    that->addChild(pg2);
    
}


void HUDLayer::create(EIS_Hallway *that, PlayerModel pm){
    
    pg->setScaleX(pm.getStats().getEnergy()/100.0);
    pg2->setScaleX(pm.getStats().getStress()/100.0);
    that->addChild(engText, 1);
    that->addChild(engSprite);
    that->addChild(pg);
    that->addChild(streText, 1);
    that->addChild(streSprite);
    that->addChild(pg2);
    
}

void HUDLayer::create(DormScene *that, PlayerModel pm){
    
    pg->setScaleX(pm.getStats().getEnergy()/100.0);
    pg2->setScaleX(pm.getStats().getStress()/100.0);
    that->addChild(engText, 1);
    that->addChild(engSprite);
    that->addChild(pg);
    that->addChild(streText, 1);
    that->addChild(streSprite);
    that->addChild(pg2);
    
}

void HUDLayer::create(TavernFoyer *that, PlayerModel pm){
    
    pg->setScaleX(pm.getStats().getEnergy()/100.0);
    pg2->setScaleX(pm.getStats().getStress()/100.0);
    that->addChild(engText, 1);
    that->addChild(engSprite);
    that->addChild(pg);
    that->addChild(streText, 1);
    that->addChild(streSprite);
    that->addChild(pg2);
    
}

void HUDLayer::create(TavernRoom *that, PlayerModel pm){
    
    pg->setScaleX(pm.getStats().getEnergy()/100.0);
    pg2->setScaleX(pm.getStats().getStress()/100.0);
    that->addChild(engText, 1);
    that->addChild(engSprite);
    that->addChild(pg);
    that->addChild(streText, 1);
    that->addChild(streSprite);
    that->addChild(pg2);
    
}

void HUDLayer::create(LibraryRooms *that, PlayerModel pm){
    
    pg->setScaleX(pm.getStats().getEnergy()/100.0);
    pg2->setScaleX(pm.getStats().getStress()/100.0);
    that->addChild(engText, 1);
    that->addChild(engSprite);
    that->addChild(pg);
    that->addChild(streText, 1);
    that->addChild(streSprite);
    that->addChild(pg2);
    
}

void HUDLayer::create(LibraryFoyer *that, PlayerModel pm){
    
    pg->setScaleX(pm.getStats().getEnergy()/100.0);
    pg2->setScaleX(pm.getStats().getStress()/100.0);
    that->addChild(engText, 1);
    that->addChild(engSprite);
    that->addChild(pg);
    that->addChild(streText, 1);
    that->addChild(streSprite);
    that->addChild(pg2);
    
}

void HUDLayer::update(PlayerModel pm){
    
    
    //Added an update for the HUD Stress & Energy Bars
    pg->setScaleX(pm.getStats().getEnergy()/100.0);
    pg->setAnchorPoint(Vec2(0.f,0.5f));
    log("%d",pm.getStats().getEnergy());
    
    pg2->setScaleX(pm.getStats().getEnergy()/100.0);
    pg2->setAnchorPoint(Vec2(0.f,0.5f));
    log("%d",pm.getStats().getStress());
    
    

    
    
}