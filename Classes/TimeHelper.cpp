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

}

TimeHelper::TimeHelper(Day currentDay, Month currentMonth, int currentYear)
{
    this->currentDay = currentDay;
    this->currentMonth = currentMonth;
    this->currentYear = currentYear;
}

TimeHelper::TimeHelper(Day currentDay, Month currentMonth, int currentYear, GameTime currentGameTime)
{
    this->currentDay = currentDay;
    this->currentMonth = currentMonth;
    this->currentYear = currentYear;
    this->currentGameTime = currentGameTime;
}

/********************************
            Getters
 *******************************/

Day TimeHelper::getCurrentDay()
{
    return currentDay;
}

Month TimeHelper::getCurrentMonth()
{
    return currentMonth;
}

int TimeHelper::getCurrentYear()
{
    return currentYear;
}

GameTime TimeHelper::getCurrentGameTime()
{
    return currentGameTime;
}

std::string TimeHelper::getDate()
{
    std::stringstream ss;
    ss << currentDay << "/" << currentMonth << "/" << currentYear;
    return ss.str();
}

std::string TimeHelper::getTime()
{
    std::stringstream ss;
    ss << currentGameTime.hours << ":" << currentGameTime.minutes << ":" << currentGameTime.seconds;
    return ss.str();
}

/********************************
            Setters
 *******************************/

void TimeHelper::setCurrentDay(Day currentDay)
{
    this->currentDay = currentDay;
}

void TimeHelper::setCurrentMonth(Month currentMonth)
{
    this->currentMonth = currentMonth;
}

void TimeHelper::setCurrentYear(int currentYear)
{
    this->currentYear = currentYear;
}

void TimeHelper::setCurrentGameTime(GameTime currentGameTime)
{
    this->currentGameTime = currentGameTime;
}