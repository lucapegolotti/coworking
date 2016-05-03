#include "meetingroomprogram.h"

MeetingRoomProgram::MeetingRoomProgram(GenericList<RSVMeetingRoom>& list, QDate current_date) :
    programdate(current_date) {

    for (int i = 0; i < 15; i++){
        names[i] = "";

    }

    QList<RSVMeetingRoom> list_m = list.getList();

    for (QList<RSVMeetingRoom>::iterator it = list_m.begin(); it < list_m.end(); it++){
        RSVMeetingRoom rsv = *it;
        if (rsv.getDate() == current_date){
            addReservation(rsv);
        }
    }

}

void MeetingRoomProgram::addReservation(RSVMeetingRoom rsv){
    QString constructed_name = rsv.getName();
    qDebug() << "------";
    constructed_name.append(" ").append(rsv.getSurname());
    for (int i = rsv.getStartingHour()-9;i < rsv.getEndingHour()-8;i++){
        names[i] = constructed_name;
        qDebug() << i;
        qDebug() << constructed_name;
    }
}

QString MeetingRoomProgram::getNameAt(int i){
    return names[i];
}

QDate MeetingRoomProgram::getDate() const {
    return programdate;
}
