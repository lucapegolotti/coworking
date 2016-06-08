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

    void addReservation(const RSVMeetingRoom rsv);

    void deleteReservation(RSVMeetingRoom rsv);

    void updateToDate(QDate newDate, bool classroom);

    RSVMeetingRoom rsvat(int i);

private:

    QString names[15];

    QDate programdate;

    GenericList<RSVMeetingRoom>& list;

    RSVMeetingRoom rsv_ptr[15];
};

#endif // MEETINGROOMPROGRAM_H
