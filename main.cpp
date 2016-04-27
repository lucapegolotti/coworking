#include "positionswindow.h"
#include <QApplication>
#include <QGraphicsView>
#include <vector>
#include <unistd.h>
#include <QGraphicsRectItem>
#include <reservation.h>
#include <meetingroomdaily.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    PositionsWindow w;
    MeetingRoomDaily m;

    w.show();

    m.show();



    return app.exec();
}
