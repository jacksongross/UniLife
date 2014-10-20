//
//  AssessmentModel.cpp
//  UniLife
//
//  Created by Jackson Gross on 11/10/2014.
//
//

#include "AssessmentModel.h"

AssessmentModel::AssessmentModel()
{
    this->ID = -1;
    this->playerID = -1;
    this->subject = "";
    this->assessmentId = -1;
    this->percentage = -1;
    this->mark = 0;
    this->dueDay = -1;
    this->dueWeek = -1;
    this->dueSemester = -1;
    this->dueTime = -1;
}

AssessmentModel::AssessmentModel(int ID, int playerID, std::string subject, int assessmentId, int percentage, int mark, int dueTime, int dueDay, int dueWeek, int dueSemester)
{
    this->ID = ID;
    this->playerID = playerID;
    this->subject = subject;
    this->assessmentId = assessmentId;
    this->percentage = percentage;
    this->mark = mark;
    this->dueDay = dueDay;
    this->dueWeek = dueWeek;
    this->dueSemester = dueSemester;
    this->dueTime = dueTime;
}

/********************************
            Getters
 *******************************/

int AssessmentModel::getID()
{
    return this->ID;
}

int AssessmentModel::getPlayerId()
{
    return this->playerID;
}

std::string AssessmentModel::getSubject()
{
    return this->subject;
}

int AssessmentModel::getAssessmentId()
{
    return this->assessmentId;
}

int AssessmentModel::getPercentage()
{
    return this->percentage;
}

int AssessmentModel::getMark()
{
    return this->mark;
}

int AssessmentModel::getDueTime()
{
    return this->dueTime;
}

int AssessmentModel::getdueDay()
{
    return this->dueDay;
}

int AssessmentModel::getDueWeek()
{
    return this->dueWeek;
}

int AssessmentModel::getDueSemester()
{
    return this->dueSemester;
}

/********************************
            Setters
 *******************************/

void AssessmentModel::setID(int ID)
{
    this->ID = ID;
}

void AssessmentModel::setPlayerId(int playerID)
{
    this->playerID = playerID;
}

void AssessmentModel::setSubject(std::string subject)
{
    this->subject = subject;
}

void AssessmentModel::setAssessmentId(int assessmentId)
{
    this->assessmentId = assessmentId;
}

void AssessmentModel::setPercentage(int percentage)
{
    this->percentage = percentage;
}

void AssessmentModel::setMark(int mark)
{
    this->mark = mark;
}

void AssessmentModel::setDueTime(int dueTime)
{
    this->dueTime = dueTime;
}

void AssessmentModel::setDueDay(int dueDay)
{
    this->dueDay = dueDay;
}

void AssessmentModel::setDueWeek(int dueWeek)
{
    this->dueWeek = dueWeek;
}

void AssessmentModel::setDueSemester(int dueSemester)
{
    this->dueSemester = dueSemester;
}