//
//  timeTableClassModel.cpp
//  Timetabler
//
//  Created by James Glennan on 29/06/2014.
//  Copyright (c) 2014 JamesGlennan. All rights reserved.
//

#include "timeTableClassModel.h"
#include <ctime>
#include <cstdlib>

timeTableClassModel::timeTableClassModel(){
    
    totalTimeInt = 0;
    currentDayInt = 0;
    currentTimeInt = DAYSTART;
    //init 2d array for days and timeblocks
    timetableClassArray = new subjectBlockClassModel*[NUMBERDAYS];
    for(int i = 0; i < DAYEND-DAYSTART; ++i)
        timetableClassArray[i] = new subjectBlockClassModel[DAYEND-DAYSTART];


}


timeTableClassModel::~timeTableClassModel(){
    
    for(int i = 0; i < DAYEND-DAYSTART; ++i)
        delete [] timetableClassArray[i];
    
    delete [] timetableClassArray;
    
}

void timeTableClassModel::push(subjectBlockClassModel obj){
    
    obj.putStartVoid(currentTimeInt);
    
    //classQueue.push(obj);
    timetableClassArray[currentDayInt][currentTimeInt-DAYSTART-1] = obj;
    totalTimeInt += obj.getTotalTimeInt();
    currentTimeInt += obj.getTotalTimeInt();
    
    if (currentTimeInt==12) {
        push(subjectBlockClassModel(1, "Lunch"));
    }else if (currentTimeInt >= DAYEND-DAYSTART && currentDayInt < NUMBERDAYS-1){
        currentDayInt++;
        currentTimeInt = DAYSTART;
    }
    
    return;
}


subjectBlockClassModel timeTableClassModel::popClass(){
    
    //subjectBlockClassModel obj = classQueue.front();
    //classQueue.pop();
    
    //totalTimeInt-=obj.getTotalTimeInt(); //not really sure why i'm doing this- but hey its there
    
  
    
    return *new subjectBlockClassModel;
}

//use an array- where a class runs over longer than an hour, point the elements back to the start of itself



subjectBlockClassModel timeTableClassModel::retElementSBCM(unsigned int day, unsigned int hour){
    
    int testTime = DAYEND-DAYSTART;
    
    if(day-1<NUMBERDAYS && hour-DAYSTART < testTime){
    
        return timetableClassArray[day-1][hour-DAYSTART];}
    else
    return subjectBlockClassModel(0, "NO CLASS");

}

void timeTableClassModel::insertSubj(subjectBlockClassModel ins, int timeInt, int dayInt){
    
    timetableClassArray[dayInt][timeInt] = ins;
    
    for (int i = timeInt; i<ins.getTotalTimeInt()+timeInt; ++i) {
        timetableClassArray[dayInt][timeInt] = subjectBlockClassModel(1, "BLOCKED");
    }
    
    return;
}

bool timeTableClassModel::freeSpaceCheck(subjectBlockClassModel ins, int timeInt, int dayInt){
    
    if (timeInt+ins.getTotalTimeInt()+DAYSTART > DAYEND) {
        return false;
    }
    
    for (int i = timeInt; i<ins.getTotalTimeInt()+timeInt; ++i) {
        if (timetableClassArray[dayInt][i].getNameString()!="NO CLASS"){
            return false;
        }
    }
    
    return true;
}

int timeTableClassModel::randomAllocationInt(subjectBlockClassModel ins){
    
    int timeInt = -1;
    int dayInt = -1;
    //bool checker = false;
    
    srand(time(NULL));
    
    do{
        timeInt = rand()%(DAYEND-DAYSTART);
        dayInt = rand()%3;
        
    }while(!freeSpaceCheck(ins, timeInt, dayInt));
    
    
    insertSubj(ins, timeInt, dayInt);
    
    
    return timeInt;
}


