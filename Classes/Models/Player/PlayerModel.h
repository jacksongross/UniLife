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
#include "TimeModel.h"
#include "timeTableClassModel.h"
#include <ctime>
class PlayerModel
{
    
private:
    
    // player id
    int Id;
    
    // player name
    std::string name;
    
    // player degree title
    std::string degree;
    int degreeCode;
    
    // player stats
    PlayerStatsModel stats;
    
    // last recorded scene player is in
    std::string scene;
    
    // player game time
    TimeModel gameTime;
    
    // array of timetables, holding all your classes
    // and assessments 
    std::vector<timeTableClassModel> timetable;
    
    // array to hold assessments
    std::vector<AssessmentModel> assessments;
    
    // used to track game time
    time_t start;

public:
    
    // default constructor
    PlayerModel();
    
    // new player constructor with values
    PlayerModel(std::string name, std::string degree, PlayerStatsModel stats, std::string scene, TimeModel gameTime);
    
    /********************************
                Getters
     *******************************/
    
    int getId();
    
    std::string getName();
    
    std::string getDegree();
    
    PlayerStatsModel getStats();
    
    std::string getScene();
    
    TimeModel getGameTime();
    
    std::vector<timeTableClassModel> getTimeTable();
    
    std::vector<AssessmentModel> getAssessments();
    
    
    /********************************
                Setters
     *******************************/
    void setId(int Id);
    
    void setName(std::string name);
    
    void setDegree(std::string degree);
    
    void setStats(PlayerStatsModel stats);
    
    void setScene(std::string scene);
    
    void setGameTime(TimeModel gameTime);
    
    void setTimeTable(std::vector<timeTableClassModel> timetable);
    
    void setAssessments(std::vector<AssessmentModel> assessments);
    
};



#endif
