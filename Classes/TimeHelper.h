//
//  TimeHelper.h
//  UniLife
//
//  Created by Jackson Gross on 29/07/2014.
//
//

#ifndef UniLife_TimeHelper_h
#define UniLife_TimeHelper_h

#include <string>
#include <sstream>

enum Day
{
    Monday = 1,
    Tuesday = 2,
    Wednesday = 3,
    Thursday = 4,
    Friday = 5,
    Saturday = 6,
    Sunday = 7
};

enum Month
{
    January = 1,
    Febuary = 2,
    March = 3,
    April = 4,
    May = 5,
    June = 6,
    July = 7,
    August = 8,
    September = 9,
    October = 10,
    November = 11,
    December = 12
};

struct GameTime
{
    double hours, minutes, seconds;
};

class TimeHelper
{
    
private:
    
    // current day
    Day currentDay;
    
    // current month
    Month currentMonth;
    
    // current year
    int currentYear;
    
    GameTime currentGameTime;
    
public:
    
    TimeHelper();
    TimeHelper(Day currentDay, Month currentMonth, int currentYear);
    TimeHelper(Day currentDay, Month currentMonth, int currentYear, GameTime currentTime);
    
    /********************************
                Getters
     *******************************/
    
    Day getCurrentDay();
    Month getCurrentMonth();
    int getCurrentYear();
    GameTime getCurrentGameTime();
    std::string getDate();
    std::string getTime();
    
    /********************************
                Setters
     *******************************/
    
    void setCurrentDay(Day currentDay);
    void setCurrentMonth(Month currentMonth);
    void setCurrentYear(int currentYear);
    void setCurrentGameTime(GameTime currentTime);

};


#endif
