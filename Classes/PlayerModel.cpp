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
PlayerModel::PlayerModel(std::string name, std::string degree, PlayerStatsModel stats, std::string scene, TimeHelper gameTime)
{
    this->name = name;
    this->degree = degree;
    this->stats = stats;
    this->scene = scene;
    this->gameTime = gameTime;
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

std::string PlayerModel::getScene()
{
    return scene;
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

void PlayerModel::setScene(std::string scene)
{
    this->scene = scene;
}

void PlayerModel::setGameTime(TimeHelper gameTime)
{
    this->gameTime = gameTime;
}
