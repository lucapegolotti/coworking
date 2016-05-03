#include "rsvmeetingroom.h"

RSVMeetingRoom::RSVMeetingRoom() {

}

void RSVMeetingRoom::setName(QString n) {
    name = n;
}

void RSVMeetingRoom::setSurname(QString s) {
    surname = s;
}

void RSVMeetingRoom::setDate(QDate d){
    date = d;
}

void RSVMeetingRoom::setStartingHour(int h) {
    starting_hour = h;
}

void RSVMeetingRoom::setEndingHour(int h) {
    ending_hour = h;
}

QString RSVMeetingRoom::getName() const{
    return name;
}

QString RSVMeetingRoom::getSurname() const{
    return surname;
}

QDate RSVMeetingRoom::getDate() const{
    return date;
}

int RSVMeetingRoom::getStartingHour() const{
    return starting_hour;
}

int RSVMeetingRoom::getEndingHour() const{
    return ending_hour;
}

void RSVMeetingRoom::read(const QJsonObject& json) {
    name = json["name"].toString();
    surname = json["surname"].toString();
    int day = json["day"].toInt();
    int month = json["month"].toInt();
    int year = json["year"].toInt();
    date.setDate(year,month,day);
    starting_hour = json["starthour"].toInt();
    ending_hour = json["endhour"].toInt();
}

void RSVMeetingRoom::write(QJsonObject& json) const {
    json["name"] = name;
    json["surname"]= surname;
    json["day"] = date.day();
    json["month"] = date.month();
    json["year"] = date.year();
    json["starthour"] = starting_hour;
    json["endhour"] = ending_hour;
}

bool RSVMeetingRoom::operator==(const RSVMeetingRoom& other) const {
    return (name == other.getName() &&
            surname == other.getSurname() &&
            date == other.getDate() &&
            starting_hour == other.getStartingHour() &&
            ending_hour == other.getEndingHour());
}
