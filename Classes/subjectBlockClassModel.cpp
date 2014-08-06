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

subjectBlockClassModel::subjectBlockClassModel(int timeInt, string nameString){
    
    theTimeInt = timeInt;
    subjNameString = nameString;
    startTimeInt = -1;
}


subjectBlockClassModel& subjectBlockClassModel::operator=(const subjectBlockClassModel rhs){
    
    this->theTimeInt= rhs.theTimeInt;
    this->subjNameString=rhs.subjNameString;
    this->startTimeInt=rhs.startTimeInt;
    return *this;}


ostream& operator<<(ostream& output, const subjectBlockClassModel print){
    
    output << print.subjNameString << "\t\t";
    
    if (print.startTimeInt >= 0) {
    
        output << std::setw(2) << setfill('0') << print.startTimeInt<<":30";
    }else{
        output << "00:00";
    }
        output << "\t\t"<< print.theTimeInt<< " Hrs";
    
    return output;}
