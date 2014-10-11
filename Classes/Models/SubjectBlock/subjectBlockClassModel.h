//
//  subjectBlockModel.h
//  Timetabler
//
//  Created by James Glennan on 29/06/2014.
//  Copyright (c) 2014 JamesGlennan. All rights reserved.
//

#ifndef __Timetabler__subjectBlockClassModel__
#define __Timetabler__subjectBlockClassModel__

#include <iostream>
#include <queue>
#include <string>
#include <iomanip>
#include <vector>
#include "AssessmentModel.h"
using namespace std;

class subjectBlockClassModel{
    
private:
    int theTimeInt;
    string subjNameString;
    int startTimeInt;
    char classID;
    std::vector<AssessmentModel> assessments;
public:

    subjectBlockClassModel();
    subjectBlockClassModel(char, int, string);
    
    subjectBlockClassModel& operator=(const subjectBlockClassModel rhs);
    
    
    //GET FUNCTIONS
    string getNameString(){return subjNameString;};
    int getTotalTimeInt(){return theTimeInt;};
    char getClassIDChar(){return classID;};
    std::vector<AssessmentModel> getAssessments(){return assessments;};
    friend ostream& operator<<(ostream& output,const subjectBlockClassModel print);
    //INSERT FUNCTIONS
    void putNameVoid(string nameString){subjNameString = nameString;};
    void putTimeVoid(int timeInt){theTimeInt = timeInt;};
    void putStartVoid(int startInt){startTimeInt = startInt;}
    void setAssessments(std::vector<AssessmentModel> assessments){this->assessments = assessments;};
    

};


#endif /* defined(__Timetabler__subjectBlockClassModel__) */
