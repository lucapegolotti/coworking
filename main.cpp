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
    w.show();
    c.show();

    return app.exec();
}
