#ifndef DATE_H
#define DATE_H

#include <ctime>

class Date {
 public:

    Date();

    Date(int d, int m, int y);

    int getDay();

    int getMonth();

    int getYear();

    int getWeekDay();

    bool isLeapYear(int year);

    int daysFrom1Jan2016();

    int daysFromBeginningOfYear();

    bool isContained(Date beginDate, Date endDate);

 private:
    int day;

    int month;

    int year;

    int weekday;

    const int daysinmonths[12] = {31,28,31,30,31,30,31,31,30,31,30,31};


};

#endif // DATE_H
