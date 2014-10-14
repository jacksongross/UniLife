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
    int dayInt;
    std::vector<AssessmentModel> assessments;
public:

    subjectBlockClassModel();
    subjectBlockClassModel(string, char, int, int, int);
    
    subjectBlockClassModel& operator=(const subjectBlockClassModel rhs);
    
    
    //GET FUNCTIONS
    string getNameString(){return subjNameString;};
    int getTotalTimeInt(){return theTimeInt;};
    char getClassIDChar(){return classID;};
    int getStartTime(){return startTimeInt;};
    int getDay(){return dayInt;};
    std::vector<AssessmentModel> getAssessments(){return assessments;};
    friend ostream& operator<<(ostream& output,const subjectBlockClassModel print);
    //INSERT FUNCTIONS
    void putNameVoid(string nameString){subjNameString = nameString;};
    void putTimeVoid(int timeInt){theTimeInt = timeInt;};
    void putStartVoid(int startInt){startTimeInt = startInt;}
    void putDayVoid(int day){dayInt = day;};
    void setAssessments(std::vector<AssessmentModel> assessments){this->assessments = assessments;};
    

};


#endif /* defined(__Timetabler__subjectBlockClassModel__) */
