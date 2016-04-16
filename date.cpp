#include <date.h>

Date::Date(){
    time_t now = time(0);
    tm* time_format = gmtime(&now);
    day = time_format->tm_mday;
    month = time_format->tm_mon + 1;
    year = time_format->tm_year + 1900;
    weekday = time_format->tm_mday + 1;
}

Date::Date(int d, int m, int y) :
    day(d),
    month(m),
    year(y) {}

int Date::getDay(){
    return day;
}

int Date::getMonth(){
    return month;
}

int Date::getYear(){
    return year;
}

int Date::getWeekDay(){
    return weekday;
}

bool Date::isLeapYear(int year){
    return year%4;
}

int Date::daysFrom1Jan2016(){
    int sum = daysFromBeginningOfYear();
    for (int i = 2016; i < month; i++){
        sum += 365 + isLeapYear(i);
    }
    return sum;
}

int Date::daysFromBeginningOfYear(){
    int sum = day;
    for (int i = 1; i < month; i++){
        if (i != 2){
            sum += daysinmonths[i];
        }
        else{
            sum += daysinmonths[i] + isLeapYear(year);
        }
    }
    return sum;
}

bool Date::isContained(Date beginDate, Date endDate){
    int daysfrom1j = daysFrom1Jan2016();
    return (beginDate.daysFrom1Jan2016() <= daysfrom1j &&
            daysfrom1j <= endDate.daysFrom1Jan2016());
}
