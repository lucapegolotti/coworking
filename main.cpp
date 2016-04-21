#include "positionswindow.h"
#include <QApplication>
#include <QGraphicsView>
#include <vector>
#include <unistd.h>
#include "calendar.h"
#include <QGraphicsRectItem>
#include <user.h>
#include <date.h>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    PositionsWindow w;
    Calendar c;

    QObject::connect(&c,SIGNAL(sendChosenDate(const QDate&)),
                     &w,SLOT(receiveNewDate(const QDate&)));
    QObject::connect(&w,SIGNAL(addingReservation()),
                     &c,SLOT(disable()));
    QObject::connect(&w,SIGNAL(finishedAddingReservation()),
                     &c,SLOT(enable()));
    QObject::connect(&w,SIGNAL(destroyed(QObject*)),
                     &c,SLOT(close()));
    w.show();
    c.show();



    return app.exec();
}
