//
//  PlayerModel.cpp
//  UniLife
//
//  Created by Jackson Gross on 29/07/2014.
//
//

#include <string>
#include "PlayerModel.h"
#include "PlayerStatsModel.h"

// default constructor
PlayerModel::PlayerModel()
{
    id = 0;
    name = "";
    degree = "";
}

// new player constructor with values
PlayerModel::PlayerModel(std::string name, std::string degree, PlayerStatsModel stats)
{
    this->name = name;
    this->degree = degree;
    this->stats = stats;
}

/********************************
            Getters
 *******************************/

std::string PlayerModel::getName()
{
    return name;
}

std::string PlayerModel::getDegree()
{
    return degree;
}

PlayerStatsModel PlayerModel::getStats()
{
    return stats;
}

TimeHelper PlayerModel::getGameTime()
{
    return gameTime;
}


/********************************
            Setters
 *******************************/

void PlayerModel::setName(std::string name)
{
    this->name = name;
}

void PlayerModel::setDegree(std::string degree)
{
    this->degree = degree;
}

void PlayerModel::setStats(PlayerStatsModel stats)
{
    this->stats = stats;
}

void PlayerModel::setGameTime(TimeHelper gameTime)
{
    this->gameTime = gameTime;
}
