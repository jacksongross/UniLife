//
//  AttendanceModel.cpp
//  UniLife
//
//  Created by Jackson Gross on 21/10/2014.
//
//

#include "AttendanceModel.h"

AttendanceModel::AttendanceModel()
{
    this->ID = 0;
    this->count = 0;
    this->subject = "";
}

AttendanceModel::AttendanceModel(double count, std::string subject)
{
    this->ID = 0;
    this->count = count;
    this->subject = subject;
}

AttendanceModel::AttendanceModel(int ID, double count, std::string subject)
{
    this->ID = ID;
    this->count = count;
    this->subject = subject;
}

/********************************
            Getters
 *******************************/

int AttendanceModel::getID()
{
    return this->ID;
}

double AttendanceModel::getCount()
{
    return this->count;
}

std::string AttendanceModel::getSubject()
{
    return this->subject;
}

/********************************
            Setters
 *******************************/

void AttendanceModel::setID(int ID)
{
    this->ID = ID;
}

void AttendanceModel::setCount(double count)
{
    this->count = count;
}

void AttendanceModel::setSubject(std::string subject)
{
    this->subject = subject;
}