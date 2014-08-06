//
//  timeTableClassModel.h
//  Timetabler
//
//  Created by James Glennan on 29/06/2014.
//  Copyright (c) 2014 JamesGlennan. All rights reserved.
//

#ifndef __Timetabler__timeTableClassModel__
#define __Timetabler__timeTableClassModel__

#include <iostream>
#include <queue>
#include "subjectBlockClassModel.h"
using namespace std;

const int NUMBERDAYS = 3;
const int DAYSTART = 8;
const int DAYEND = 20;


class timeTableClassModel{

private:
    
    queue<subjectBlockClassModel> classQueue;
    int totalTimeInt;
    int currentTimeInt;
    int currentDayInt;
    subjectBlockClassModel** timetableClassArray; //[day][time]
public:
    
    timeTableClassModel();
    
    void push(subjectBlockClassModel);
    subjectBlockClassModel popClass(); //will return first element and remove from queue
    bool executeBool(); //will allocate times to classes-return T if ok
    subjectBlockClassModel retElementSBCM(unsigned int day, unsigned int hour);
    ~timeTableClassModel();
    
    int randomAllocationInt(subjectBlockClassModel insert);
    void insertSubj(subjectBlockClassModel insert, int timeInt, int dayInt);
    bool freeSpaceCheck(subjectBlockClassModel, int timeInt, int dayInt); //returns false if gap isn't free
};



#endif /* defined(__Timetabler__timeTableClassModel__) */
