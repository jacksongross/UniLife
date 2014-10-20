//
//  AssessmentModel.h
//  UniLife
//
//  Created by Jackson Gross on 11/10/2014.
//
//

#ifndef __UniLife__AssessmentModel__
#define __UniLife__AssessmentModel__

#include <stdio.h>
#include <string>

class AssessmentModel
{
    
private:
    
    // id for the record
    int ID;
    
    // id for player related to this assessment
    int playerID;
    
    // subject code for assessment
    std::string subject;
    
    // assessment number
    int assessmentId;
    
    // how much it is is worth
    int percentage;
    
    // player's mark for assessment
    int mark;
    
    
public:
    
    AssessmentModel();
    AssessmentModel(int ID, int playerID, std::string subject, int assessmentId, int percentage, int mark);
    
    /********************************
                Getters
     *******************************/
    
    int getID();
    
    int getPlayerId();
    
    std::string getSubject();
    
    int getAssessmentId();
    
    int getPercentage();
    
    int getMark();
    
    
    /********************************
                Setters
     *******************************/
    
    void setID(int ID);
    
    void setPlayerId(int playerID);
    
    void setSubject(std::string subject);
    
    void setAssessmentId(int assessmentId);
    
    void setPercentage(int percentage);
    
    void setMark(int mark);
    
};

#endif /* defined(__UniLife__AssessmentModel__) */
