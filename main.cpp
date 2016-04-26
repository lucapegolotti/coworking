#include "positionswindow.h"
#include <QApplication>
#include <QGraphicsView>
#include <vector>
#include <unistd.h>
#include <QGraphicsRectItem>
#include <reservation.h>
#include <date.h>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    PositionsWindow w;

    w.show();



    return app.exec();
}
