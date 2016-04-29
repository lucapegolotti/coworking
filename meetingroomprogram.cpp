#include "meetingroomprogram.h"

MeetingRoomProgram::MeetingRoomProgram(RSVMeetingRoomList& list, QDate current_date) {

    for (int i = 0; i < 15; i++){
        names[i] = "";
    }

    // random names
    names[0] = "Paolo Roberto";
    names[1] = "Paolo Roberto";

    names[4] = "Mario Marino";
    names[5] = "Mario Marino";
    names[6] = "Mario Marino";

}

QString MeetingRoomProgram::getNameAt(int i){
    return names[i];
}
