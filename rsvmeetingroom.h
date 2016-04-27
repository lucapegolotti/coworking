#ifndef RSVMEETINGROOM_H
#define RSVMEETINGROOM_H

#include <QString>
#include <QDate>


class RSVMeetingRoom {

public:

    RSVMeetingRoom();

private:

    QString name;

    QString surname;

    QDate date;

    int starting_hour;

    int ending_hour;

};

#endif // RSVMEETINGROOM_H
