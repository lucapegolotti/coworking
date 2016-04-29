#include "positionswindow.h"
#include <QApplication>
#include <QGraphicsView>
#include <vector>
#include <unistd.h>
#include <QGraphicsRectItem>
#include <reservation.h>
#include <meetingroomdaily.h>
#include <meetingroomprogram.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    PositionsWindow w;
    MeetingRoomDaily m;
    RSVMeetingRoomList list;
    QDate date;

    MeetingRoomProgram program(list,date);
    m.updateWithProgram(program);




    w.show();

    m.show();



    return app.exec();
}
