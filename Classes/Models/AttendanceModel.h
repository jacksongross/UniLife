//
//  AttendanceModel.h
//  UniLife
//
//  Created by Jackson Gross on 21/10/2014.
//
//

#ifndef __UniLife__AttendanceModel__
#define __UniLife__AttendanceModel__

#include <stdio.h>
#include <string>

class AttendanceModel
{
    
private:
    
    //id
    int ID;
    
    // number of classes attended this week
    double count;
    
    // subject name
    std::string subject;
    
public:
    
    AttendanceModel();
    AttendanceModel(double count, std::string subject);
    AttendanceModel(int ID, double count, std::string subject);
    
    /********************************
                Getters
     *******************************/
    
    int getID();
    
    double getCount();
    
    std::string getSubject();
    
    /********************************
                Setters
     *******************************/
    
    void setID(int ID);
    
    void setCount(double count);
    
    void setSubject(std::string subject);
    
    
};

#endif /* defined(__UniLife__AttendanceModel__) */
