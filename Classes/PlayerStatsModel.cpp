//
//  PlayerStatsModel.cpp
//  UniLife
//
//  Created by Jackson Gross on 29/07/2014.
//
//

#include "PlayerStatsModel.h"

PlayerStatsModel::PlayerStatsModel()
{
    intelligence = 0;
    stamina = 0;
    social = 0;
    money = 0;
    energy = 0;
    stress = 0;
}

PlayerStatsModel::PlayerStatsModel(int intelligence, int stamina, int social, int money, int energy, int stress)
{
    this->intelligence = intelligence;
    this->stamina = stamina;
    this->social = social;
    this->money = money;
    this->energy = energy;
    this->stress = stress;
}

/********************************
            Getters
 *******************************/

int PlayerStatsModel::getIntelligence()
{
    return intelligence;
}

int PlayerStatsModel::getStamina()
{
    return stamina;
}

int PlayerStatsModel::getSocial()
{
    return social;
}

int PlayerStatsModel::getMoney()
{
    return money;
}

int PlayerStatsModel::getEnergy()
{
    return energy;
}

int PlayerStatsModel::getStress()
{
    return stress;
}

/********************************
            Setters
 *******************************/

void PlayerStatsModel::setIntelligence(int intelligence)
{
    this->intelligence = intelligence;
}

void PlayerStatsModel::setStamina(int stamina)
{
    this->stamina = stamina;
}

void PlayerStatsModel::setSocial(int social)
{
    this->social = social;
}

void PlayerStatsModel::setMoney(int money)
{
    this->money = money;
}

void PlayerStatsModel::setEnergy(int energy)
{
    this->energy = energy;
}

void PlayerStatsModel::setStress(int stress)
{
    this->stress = stress;
}