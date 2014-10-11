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
    this->subject = "";
    this->assessmentId = -1;
    this->percentage = -1;
    this->mark = -1;
}

AssessmentModel::AssessmentModel(std::string subject, int assessmentId, int percentage, int mark)
{
    this->subject = subject;
    this->assessmentId = assessmentId;
    this->percentage = percentage;
    this->mark = mark;
}

/********************************
            Getters
 *******************************/

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

/********************************
            Setters
 *******************************/

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