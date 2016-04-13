#include "positionswindow.h"
#include <QApplication>
#include <QGraphicsView>
#include <vector>
#include <unistd.h>
#include <QGraphicsRectItem>
#include <user.h>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    PositionsWindow w;
    w.show();

    User user("Giovanni","Muciaccia");

    std::cout << user.getName().toStdString() << " " << user.getSurname().toStdString() << std::endl;




    return app.exec();
}
