//
//  TimeModel.cpp
//  UniLife
//
//  Created by Jackson Gross on 29/07/2014.
//
//

#include "TimeModel.h"

TimeModel::TimeModel()
{
    day = week = semester = 1; // year one, week one, day one
    hoursMinutes = 8; // 8am start !! get up!!
}

TimeModel::TimeModel(int day, int week, int semester, double hoursMinutes)
{
    this->day = day;
    this->week = week;
    this->semester = semester;
    this->hoursMinutes = hoursMinutes;
}

/********************************
            Getters
 *******************************/

int TimeModel::getDay()
{
    return day;
}

int TimeModel::getWeek()
{
    return week;
}

int TimeModel::getSemester()
{
    return semester;
}

double TimeModel::getHoursMinutes()
{
    return hoursMinutes;
}

/********************************
            Setters
 *******************************/

void TimeModel::setDay(int day)
{
    this->day = day;
}

void TimeModel::setWeek(int week)
{
    this->week = week;
}

void TimeModel::setSemester(int semester)
{
    this->semester = semester;
}

void TimeModel::setHoursMinutes(double hoursMinutes)
{
    this->hoursMinutes = hoursMinutes;
}