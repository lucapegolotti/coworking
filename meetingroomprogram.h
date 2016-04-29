#ifndef MEETINGROOMPROGRAM_H
#define MEETINGROOMPROGRAM_H

#include <QList>
#include <rsvmeetingroomlist.h>
#include <QDate>

class MeetingRoomProgram
{
public:

    MeetingRoomProgram(RSVMeetingRoomList& list, QDate current_date);

    QString getNameAt(int i);

private:

    QString names[15];
};

#endif // MEETINGROOMPROGRAM_H
