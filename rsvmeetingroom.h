#ifndef RSVMEETINGROOM_H
#define RSVMEETINGROOM_H

#include <QString>
#include <QDate>
#include <QJsonObject>
#include <QList>


class RSVMeetingRoom {

public:

    RSVMeetingRoom();

    void setName(QString n);

    void setSurname(QString s);

    void setDate(QDate d);

    void setStartingHour(int h);

    void setEndingHour(int h);

    QString getName() const;

    QString getSurname() const;

    QDate getDate() const;

    int getStartingHour() const;

    int getEndingHour() const;

    void read(const QJsonObject& json);

    void write(QJsonObject& json) const;

    bool operator==(const RSVMeetingRoom& other) const;

private:

    QString name;

    QString surname;

    QDate date;

    int starting_hour;

    int ending_hour;

};

#endif // RSVMEETINGROOM_H
