#include <user.h>

User::User(QString name, QString surname) :
    name(name),
    surname(surname) {}

void User::setWhoPays(QString who){
    whoPays = who;
}

void User::setDailyTariff(float tariff){
    dailyTariff = tariff;
}

void User::detractMeetingroomHours(int hoursSpent){
    meetingroomHoursLeft -= hoursSpent;
    if (meetingroomHoursLeft < 0)
        meetingroomHoursLeft = 0;
}

void User::setAllDayAccess(bool value){
    allDayAccess = value;
}

void User::setDepositKey(bool value){
    depositKey = value;
}

void User::setEthernet(bool value){
    ethernet = value;
}

void User::setTelephone(bool value){
    telephone = value;
}

void User::setBeginDate(int day, int month, int year){
    beginDay = day;
    beginMonth = month;
    beginYear = year;
}

void User::setEndDate(int day, int month, int year){
    endDay = day;
    endMonth = month;
    endYear = year;
}

QString User::getName(){
    return name;
}

QString User::getSurname(){
    return surname;
}

QString User::getWhoPays(){
    return whoPays;
}

float User::getDailyTariff(){
    return dailyTariff;
}

int User::getMeetingroomHourse(){
    return meetingroomHoursLeft;
}

bool User::getAllDayAccess(){
    return allDayAccess;
}

bool User::getDepositKey(){
    return depositKey;
}

bool User::getEthernet(){
    return ethernet;
}

bool User::getTelephone(){
    return telephone;
}

int User::getBeginDay(){
    return beginDay;
}

int User::getBeginMonth(){
    return beginMonth;
}

int User::getBeginYear(){
    return beginYear;
}

int User::getEndDay(){
    return endDay;
}

int User::getEndMonth(){
    return endMonth;
}

int User::getEndYear(){
    return endYear;
}
