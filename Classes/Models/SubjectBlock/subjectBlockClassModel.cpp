//
//  subjectBlockModel.cpp
//  Timetabler
//
//  Created by James Glennan on 29/06/2014.
//  Copyright (c) 2014 JamesGlennan. All rights reserved.
//

#include "subjectBlockClassModel.h"

subjectBlockClassModel::subjectBlockClassModel(){
    theTimeInt = 0;
    startTimeInt = -1;
    subjNameString = "Free";
}

subjectBlockClassModel::subjectBlockClassModel(string subjNameString, char classID, int theTimeInt, int startTimeInt, int dayInt)
{
    this->subjNameString = subjNameString;
    this->classID = classID;
    this->theTimeInt = theTimeInt;
    this->startTimeInt = startTimeInt;
    this->dayInt = dayInt;
}


subjectBlockClassModel& subjectBlockClassModel::operator=(const subjectBlockClassModel rhs){
    
    this->subjNameString = rhs.subjNameString;
    this->classID = rhs.classID;
    this->theTimeInt = rhs.theTimeInt;
    this->startTimeInt = rhs.startTimeInt;
    this->dayInt = rhs.dayInt;
    
    return *this;
}


ostream& operator<<(ostream& output, const subjectBlockClassModel print){
    
    output << print.subjNameString << "\t\t";
    
    if (print.startTimeInt >= 0) {
    
        output << std::setw(2) << setfill('0') << print.startTimeInt<<":00";
    }else{
        output << "00:00";
    }
        output << "\t\t"<< print.theTimeInt<< " Hrs";
    
    output << "\t\t" << print.dayInt;
    
    return output;
}
