//
//  TimeHelper.cpp
//  UniLife
//
//  Created by Jackson Gross on 29/07/2014.
//
//

#include "TimeHelper.h"

TimeHelper::TimeHelper()
{
    day = week = semester = 1; // year one, week one, day one
    hoursMinutes = 8; // 8am start !! get up!!
}

TimeHelper::TimeHelper(int day, int week, int semester, double hoursMinutes)
{
    this->day = day;
    this->week = week;
    this->semester = semester;
    this->hoursMinutes = hoursMinutes;
}

/********************************
            Getters
 *******************************/

int TimeHelper::getDay()
{
    return day;
}

int TimeHelper::getWeek()
{
    return week;
}

int TimeHelper::getSemester()
{
    return semester;
}

double TimeHelper::getHoursMinutes()
{
    return hoursMinutes;
}

/********************************
            Setters
 *******************************/

void TimeHelper::setDay(int day)
{
    this->day = day;
}

void TimeHelper::setWeek(int week)
{
    this->week = week;
}

void TimeHelper::setSemester(int semester)
{
    this->semester = semester;
}

void TimeHelper::setHoursMinutes(double hoursMinutes)
{
    this->hoursMinutes = hoursMinutes;
}