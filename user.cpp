#include <user.h>

User::User() {}

User::User(QString name, QString surname, QString whopays, int workstation,
           float tariff, int hourLeft, bool alldayacc, bool deposit,
           bool ethernet, bool telephone, QDate beginDate, QDate endDate) :
    name(name),
    surname(surname),
    whoPays(whopays),
    workstation(workstation),
    dailyTariff(tariff),
    meetingroomHoursLeft(hourLeft),
    allDayAccess(alldayacc),
    depositKey(deposit),
    ethernet(ethernet),
    telephone(telephone),
    beginDay(beginDate.day()),
    beginMonth(beginDate.month()),
    beginYear(beginDate.year()),
    endDay(endDate.day()),
    endMonth(endDate.month()),
    endYear(endDate.year()){}

void User::setName(QString name){
    this->name = name;
}

void User::setSurname(QString surname){
    this->surname = surname;
}

void User::setWhoPays(QString who){
    whoPays = who;
}

void User::setWorkstation(int workstation){
    this->workstation = workstation;
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

QString User::getName() const{
    return name;
}

QString User::getSurname() const{
    return surname;
}

QString User::getWhoPays() const{
    return whoPays;
}

int User::getWorkstation() const{
    return workstation;
}

float User::getDailyTariff() const{
    return dailyTariff;
}

int User::getMeetingroomHourse() const{
    return meetingroomHoursLeft;
}

bool User::getAllDayAccess() const{
    return allDayAccess;
}

bool User::getDepositKey() const{
    return depositKey;
}

bool User::getEthernet() const{
    return ethernet;
}

bool User::getTelephone() const{
    return telephone;
}

int User::getBeginDay() const{
    return beginDay;
}

int User::getBeginMonth() const{
    return beginMonth;
}

int User::getBeginYear() const{
    return beginYear;
}

QDate User::getBeginDate() const{
    QDate beginDate(beginYear,beginMonth,beginDay);
    return beginDate;
}

int User::getEndDay() const{
    return endDay;
}

int User::getEndMonth() const{
    return endMonth;
}

int User::getEndYear() const{
    return endYear;
}

QDate User::getEndDate() const{
    QDate endDate(endYear,endMonth,endDay);
    return endDate;
}

void User::read(const QJsonObject &json){
    name = json["name"].toString();
    surname = json["surname"].toString();
    whoPays = json["whopays"].toString();
    workstation = json["workstation"].toInt();
    dailyTariff = (float) json["tariff"].toDouble();
    meetingroomHoursLeft = json["meetinghoursleft"].toInt();
    allDayAccess = json["alldayaccess"].toBool();
    depositKey = json["depositkey"].toBool();
    ethernet = json["ethernet"].toBool();
    telephone = json["telephone"].toBool();
    beginDay = json["beginday"].toInt();
    beginMonth = json["beginmonth"].toInt();
    beginYear = json["beginyear"].toInt();
    endDay = json["endday"].toInt();
    endMonth = json["endmonth"].toInt();
    endYear = json["endyear"].toInt();
}

void User::write(QJsonObject &json) const{
    json["name"] = name;
    json["surname"]= surname;
    json["whopays"] = whoPays;
    json["workstation"] = workstation;
    json["tariff"] = dailyTariff;
    json["meetinghoursleft"] = meetingroomHoursLeft;
    json["alldayaccess"] = allDayAccess;
    json["depositkey"] = depositKey;
    json["ethernet"] = ethernet;
    json["telephone"] = telephone;
    json["beginday"] = beginDay;
    json["beginmonth"] = beginMonth;
    json["beginyear"] = beginYear;
    json["endday"] = endDay;
    json["endmonth"] = endMonth;
    json["endyear"] = endYear;
}

bool User::operator==(const User& other) const{
    return (name == other.getName() &&
            surname == other.getSurname() &&
            whoPays == other.getWhoPays() &&
            workstation == other.getWorkstation() &&
            dailyTariff == other.getDailyTariff() &&
            meetingroomHoursLeft == other.getMeetingroomHourse() &&
            allDayAccess == other.getAllDayAccess() &&
            depositKey == other.getDepositKey() &&
            ethernet == other.getEthernet() &&
            telephone == other.getTelephone() &&
            beginDay == other.getBeginDay() &&
            beginMonth == other.getBeginMonth() &&
            beginYear == other.getBeginYear() &&
            endDay == other.getEndDay() &&
            endMonth == other.getEndMonth() &&
            endYear == other.getEndYear());

}
