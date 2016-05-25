#include <reservation.h>

Reservation::Reservation() {}

Reservation::Reservation(QString name, QString surname, QString telephone, QString email,
                         QString whopays, int badge, int workstation,
                         float tariff, int hourLeft, bool alldayacc,bool deposit,
                         QString depositnum, bool ethernet, QDate beginDate, QDate endDate) :
    name(name),
    surname(surname),
    telephone(telephone),
    email(email),
    whoPays(whopays),
    badgeNumber(badge),
    workstation(workstation),
    dailyTariff(tariff),
    meetingroomHoursLeft(hourLeft),
    allDayAccess(alldayacc),
    depositKey(deposit),
    depositNumber(depositnum),
    ethernet(ethernet),
    beginDay(beginDate.day()),
    beginMonth(beginDate.month()),
    beginYear(beginDate.year()),
    endDay(endDate.day()),
    endMonth(endDate.month()),
    endYear(endDate.year()),
    payment(0.0){}

void Reservation::setName(QString name){
    this->name = name;
}

void Reservation::setSurname(QString surname){
    this->surname = surname;
}

void Reservation::setTelephone(QString telephone){
    this->telephone = telephone;
}

void Reservation::setEmail(QString email){
    this->email = email;
}

void Reservation::setWhoPays(QString who){
    whoPays = who;
}

void Reservation::setBadgeNumber(int number){
    badgeNumber = number;
}

void Reservation::setWorkstation(int workstation){
    this->workstation = workstation;
}

void Reservation::setDailyTariff(float tariff){
    dailyTariff = tariff;
}

void Reservation::detractMeetingroomHours(int hoursSpent){
    meetingroomHoursLeft -= hoursSpent;
    if (meetingroomHoursLeft < 0)
        meetingroomHoursLeft = 0;
}

void Reservation::setAllDayAccess(bool value){
    allDayAccess = value;
}

void Reservation::setDepositKey(bool value){
    depositKey = value;
}

void Reservation::setDepositNumber(QString number){
    depositNumber = number;
}

void Reservation::setEthernet(bool value){
    ethernet = value;
}

void Reservation::setBeginDate(int day, int month, int year){
    beginDay = day;
    beginMonth = month;
    beginYear = year;
}

void Reservation::setEndDate(int day, int month, int year){
    endDay = day;
    endMonth = month;
    endYear = year;
}

void Reservation::setPayment(double payment) {
    this->payment = payment;
}

QString Reservation::getName() const{
    return name;
}

QString Reservation::getSurname() const{
    return surname;
}

QString Reservation::getTelephone() const{
    return telephone;
}

QString Reservation::getEmail() const{
    return email;
}

QString Reservation::getWhoPays() const{
    return whoPays;
}

int Reservation::getBadgeNumber() const{
    return badgeNumber;
}

int Reservation::getWorkstation() const{
    return workstation;
}

float Reservation::getDailyTariff() const{
    return dailyTariff;
}

int Reservation::getMeetingroomHourse() const{
    return meetingroomHoursLeft;
}

bool Reservation::getAllDayAccess() const{
    return allDayAccess;
}

bool Reservation::getDepositKey() const{
    return depositKey;
}

QString Reservation::getDepositNumber() const{
    return depositNumber;
}

bool Reservation::getEthernet() const{
    return ethernet;
}

int Reservation::getBeginDay() const{
    return beginDay;
}

int Reservation::getBeginMonth() const{
    return beginMonth;
}

int Reservation::getBeginYear() const{
    return beginYear;
}

QDate Reservation::getBeginDate() const{
    QDate beginDate(beginYear,beginMonth,beginDay);
    return beginDate;
}

int Reservation::getEndDay() const{
    return endDay;
}

int Reservation::getEndMonth() const{
    return endMonth;
}

int Reservation::getEndYear() const{
    return endYear;
}

QDate Reservation::getEndDate() const{
    QDate endDate(endYear,endMonth,endDay);
    return endDate;
}

double Reservation::getPayment() const{
    return payment;
}

void Reservation::read(const QJsonObject &json){
    name = json["name"].toString();
    surname = json["surname"].toString();
    telephone = json["telephone"].toString();
    email = json["email"].toString();
    whoPays = json["whopays"].toString();
    badgeNumber = json["badge"].toInt();
    workstation = json["workstation"].toInt();
    dailyTariff = (float) json["tariff"].toDouble();
    meetingroomHoursLeft = json["meetinghoursleft"].toInt();
    allDayAccess = json["alldayaccess"].toBool();
    depositKey = json["depositkey"].toBool();
    depositNumber = json["depositnumber"].toString();
    ethernet = json["ethernet"].toBool();
    beginDay = json["beginday"].toInt();
    beginMonth = json["beginmonth"].toInt();
    beginYear = json["beginyear"].toInt();
    endDay = json["endday"].toInt();
    endMonth = json["endmonth"].toInt();
    endYear = json["endyear"].toInt();
    payment = json["payment"].toDouble();
}

void Reservation::write(QJsonObject &json) const{
    json["name"] = name;
    json["surname"]= surname;
    json["telephone"] = telephone;
    json["email"] = email;
    json["whopays"] = whoPays;
    json["badge"] = badgeNumber;
    json["workstation"] = workstation;
    json["tariff"] = dailyTariff;
    json["meetinghoursleft"] = meetingroomHoursLeft;
    json["alldayaccess"] = allDayAccess;
    json["depositkey"] = depositKey;
    json["depositnumber"] = depositNumber;
    json["ethernet"] = ethernet;
    json["beginday"] = beginDay;
    json["beginmonth"] = beginMonth;
    json["beginyear"] = beginYear;
    json["endday"] = endDay;
    json["endmonth"] = endMonth;
    json["endyear"] = endYear;
    json["payment"] = payment;
}

bool Reservation::operator==(const Reservation& other) const{
    return (name == other.getName() &&
            surname == other.getSurname() &&
            telephone == other.getTelephone() &&
            email == other.getEmail() &&
            whoPays == other.getWhoPays() &&
            badgeNumber == other.getBadgeNumber() &&
            workstation == other.getWorkstation() &&
            dailyTariff == other.getDailyTariff() &&
            meetingroomHoursLeft == other.getMeetingroomHourse() &&
            allDayAccess == other.getAllDayAccess() &&
            depositKey == other.getDepositKey() &&
            depositNumber == other.getDepositNumber() &&
            ethernet == other.getEthernet() &&
            beginDay == other.getBeginDay() &&
            beginMonth == other.getBeginMonth() &&
            beginYear == other.getBeginYear() &&
            endDay == other.getEndDay() &&
            endMonth == other.getEndMonth() &&
            endYear == other.getEndYear() &&
            payment == other.getPayment());

}
