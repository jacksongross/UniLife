//
//  PlayerModel.h
//  UniLife
//
//  Created by Jackson Gross on 29/07/2014.
//
//

#ifndef UniLife_PlayerModel_h
#define UniLife_PlayerModel_h

#include <string>
#include "PlayerStatsModel.h"
#include "TimeHelper.h"

class PlayerModel
{
    
private:
    
    // player id
    int Id;
    
    // player name
    std::string name;
    
    // player degree title
    std::string degree;
    
    // player stats
    PlayerStatsModel stats;
    
    // last recorded scene player is in
    std::string scene;
    
    // player game time
    TimeHelper gameTime;
    

public:
    
    // default constructor
    PlayerModel();
    
    // new player constructor with values
    PlayerModel(std::string name, std::string degree, PlayerStatsModel stats, std::string scene, TimeHelper gameTime);
    
    /********************************
                Getters
     *******************************/
    
    int getId();
    
    std::string getName();
    
    std::string getDegree();
    
    PlayerStatsModel getStats();
    
    std::string getScene();
    
    TimeHelper getGameTime();
    
    /********************************
                Setters
     *******************************/
    void setId(int Id);
    
    void setName(std::string name);
    
    void setDegree(std::string degree);
    
    void setStats(PlayerStatsModel stats);
    
    void setScene(std::string scene);
    
    void setGameTime(TimeHelper gameTime);
    
    
};



#endif
