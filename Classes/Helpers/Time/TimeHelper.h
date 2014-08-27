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

class TimeHelper
{
    
private:
    
    // current day
    int day;
    
    // current week
    int week;
    
    // current semester
    int semester;
    
    //hours in 30 min blocks e.g 14.5 = 2:30pm
    double hoursMinutes;
    
public:
    
    TimeHelper();
    TimeHelper(int day, int week, int semester, double hoursMinutes);
    
    /********************************
                Getters
     *******************************/
    
    int getDay();
    int getWeek();
    int getSemester();
    double getHoursMinutes();
    
    /********************************
                Setters
     *******************************/
    
    void setDay(int day);
    void setWeek(int week);
    void setSemester(int semester);
    void setHoursMinutes(double hoursMinutes);

};


#endif
