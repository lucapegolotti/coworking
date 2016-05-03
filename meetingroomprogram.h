#ifndef MEETINGROOMPROGRAM_H
#define MEETINGROOMPROGRAM_H

#include <QList>
#include <QDate>
#include <genericlist.h>
#include <rsvmeetingroom.h>
#include <QDebug>

class MeetingRoomProgram
{
public:

    MeetingRoomProgram(GenericList<RSVMeetingRoom>& list, QDate current_date);

    QString getNameAt(int i);

    QDate getDate() const;

    void addReservation(RSVMeetingRoom rsv);

private:

    QString names[15];

    QDate programdate;
};

#endif // MEETINGROOMPROGRAM_H
