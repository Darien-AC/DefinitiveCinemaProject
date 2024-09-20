#pragma once
#include "define.h"
#include "Movie.h"
#include "Theater.h"

class Schedule
{
private:
	string startTime;
	string endTime;
	string date;

public:
	Schedule();
    Schedule(const string& startTime, const string& endTime, const string& date);

    void setStartTime(const string& startTime);
    void setEndTime(const string& endTime);
    void setDate(const string& date);

    string getStartTime() const;
    string getEndTime() const;
    string getDate() const;

    void saveDatesInformation(string*& schedules);
    void showDatesInformation(string*& schedules);

};

