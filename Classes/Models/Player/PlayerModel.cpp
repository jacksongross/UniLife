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
#include "SqlHelper.h"
#include "timeTableClassModel.h"
// default constructor
PlayerModel::PlayerModel()
{
    Id = 0;
    name = "";
    degree = "";
}

// new player constructor with values
PlayerModel::PlayerModel(std::string name, std::string degree, PlayerStatsModel stats, std::string scene, TimeModel gameTime)
{
    this->Id = -1;
    this->name = name;
    this->degree = degree;
    this->stats = stats;
    this->scene = scene;
    this->gameTime = gameTime;
    
    for(int i = 0; i < 3; i++)
    {
        timeTableClassModel t(SqlHelper::getDegreeCode(degree), i + 1);
        this->timetable.push_back(t);
    }
    
    for(int i = 0; i < this->timetable.size(); i++)
    {
        std::vector<subjectBlockClassModel> sb = this->timetable[i].getClassQueue();
        
        for(int j = 0; j < sb.size(); j+=3)
        {
            std::string name = sb[j].getNameString();
            
            AttendanceModel am(0, name);
            
            attendance.push_back(am);
        }
    }
}

/********************************
            Getters
 *******************************/

int PlayerModel::getId()
{
    return this->Id;
}

std::string PlayerModel::getName()
{
    return this->name;
}

std::string PlayerModel::getDegree()
{
    return this->degree;
}

PlayerStatsModel PlayerModel::getStats()
{
    return this->stats;
}

std::string PlayerModel::getScene()
{
    return this->scene;
}

TimeModel PlayerModel::getGameTime()
{
    return this->gameTime;
}

std::vector<timeTableClassModel> PlayerModel::getTimeTable()
{
    return this->timetable;
}

std::vector<AssessmentModel> PlayerModel::getAssessments()
{
    return this->assessments;
}

std::vector<AttendanceModel> PlayerModel::getAttendance()
{
    return this->attendance;
}

/********************************
            Setters
 *******************************/
void PlayerModel::setId(int Id)
{
    this->Id = Id;
}

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

void PlayerModel::setGameTime(TimeModel gameTime)
{
    this->gameTime = gameTime;
}

void PlayerModel::setTimeTable(std::vector<timeTableClassModel> timetable)
{
    this->timetable = timetable;
}

void PlayerModel::setAssessments(std::vector<AssessmentModel> assessments)
{
    this->assessments = assessments;
}

void PlayerModel::setAttendance(std::vector<AttendanceModel> attendance)
{
    this->attendance = attendance;
}
