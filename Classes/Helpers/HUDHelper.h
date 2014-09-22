//
//  HUDHelper.h
//  UniLife
//
//  Created by csci321ga2a on 22/09/2014.
//
//

#ifndef __UniLife__HUDHelper__
#define __UniLife__HUDHelper__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include <CCTransition.h>
#include <vector>
#include "MenuScene.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "MenuController.h"
#include "MenuOptionScene.h"
#include "MenuNewGame.h"
#include "DormScene.h"
#include "MenuLoadScene.h"
#include "MenuDegreeSelect.h"
#include "Art-Foyer.h"
#include "Art-Hallway.h"
#include "Buis-Foyer.h"
#include "Buis-Hallway.h"
#include "SocSci-Foyer.h"
#include "SocSci-Hallway.h"
#include "SciMed-Foyer.h"
#include "SciMed-Hallway.h"
#include "EIS_Hallway.h"
#include "Inside_EIS.h"
#include "DormScene.h"
#include "LibraryFoyer.h"
#include "LibraryRooms.h"
#include "TavernFoyer.h"
#include "TavernRoom.h"



class HUDLayer
{
public:
    HUDLayer();
    void create(ArtFoyer *that, PlayerModel pm);
    void create(ArtHallway *that, PlayerModel pm);
    void create(BuisFoyer *that, PlayerModel pm);
    void create(BuisHallway *that, PlayerModel pm);
    void create(SocSciFoyer *that, PlayerModel pm);
    void create(SocSciHallway *that, PlayerModel pm);
    void create(SciMedFoyer *that, PlayerModel pm);
    void create(SciMedHallway *that, PlayerModel pm);
    void create(Inside_EIS *that, PlayerModel pm);
    void create(EIS_Hallway *that, PlayerModel pm);
    void create(TavernFoyer *that, PlayerModel pm);
    void create(TavernRoom *that, PlayerModel pm);
    void create(LibraryRooms *that, PlayerModel pm);
    void create(LibraryFoyer *that, PlayerModel pm);
    void create(DormScene *that, PlayerModel pm);
    void update(PlayerModel);
private:
    cocos2d::ui::Text* engText = cocos2d::ui::Text::create("Energy ", "Verdana", 20);
    Sprite* engSprite = Sprite::create("HUD_energy_bar.png");
    cocos2d::ui::Text* streText = cocos2d::ui::Text::create("Stress ", "Verdana", 20);
    Sprite* streSprite = Sprite::create("HUD_stress_bar.png");
    ProgressTimer* pg = ProgressTimer::create(engSprite);
    ProgressTimer* pg2 = ProgressTimer::create(streSprite);
};
#endif /* defined(__UniLife__HUDHelper__) */
