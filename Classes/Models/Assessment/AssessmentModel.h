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
    AssessmentModel(std::string subject, int assessmentId, int percentage, int mark);
    
    /********************************
                Getters
     *******************************/
    
    std::string getSubject();
    
    int getAssessmentId();
    
    int getPercentage();
    
    int getMark();
    
    
    /********************************
                Setters
     *******************************/
    
    void setSubject(std::string subject);
    
    void setAssessmentId(int assessmentId);
    
    void setPercentage(int percentage);
    
    void setMark(int mark);
    
};

#endif /* defined(__UniLife__AssessmentModel__) */
