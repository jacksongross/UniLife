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
#include "subjectBlockClassModel.h"
#include <map>
#include <vector>
//using namespace std;

const int NUMBERDAYS = 3;
const int DAYSTART = 8;
const int DAYEND = 20;


class timeTableClassModel{

private:
    
    vector<subjectBlockClassModel> classQueue;
    int totalTimeInt;
    int currentTimeInt;
    int currentDayInt;
   // subjectBlockClassModel** timetableClassArray; //[day][time]
    map<unsigned int, subjectBlockClassModel> classTable;
    int degreeCode;
    int currYear;
public:
    
    timeTableClassModel();
    timeTableClassModel(int degreeCode, int year);
    
    subjectBlockClassModel popClass(); //will return first element and remove from queue
    bool executeBool(); //will allocate times to classes-return T if ok
    subjectBlockClassModel getObjAtTime(unsigned int day, unsigned int hour); //returns free of time=0 when not found otherwise returns subjblock at time
    
    
    
    int randomAllocationInt(subjectBlockClassModel insert);
    bool checkTimeBool(unsigned int );
    
    
    bool checkTimeBool(unsigned int day, unsigned int time){return checkTimeBool(day*100+time);};
    
    void printAll();
    
    //deprecated
    void insertSubj(subjectBlockClassModel insert, int timeInt, int dayInt);
    bool freeSpaceCheck(subjectBlockClassModel, int timeInt, int dayInt); //returns false if gap isn't free
    //void push(subjectBlockClassModel);
 //   ~timeTableClassModel();
};



#endif /* defined(__Timetabler__timeTableClassModel__) */
