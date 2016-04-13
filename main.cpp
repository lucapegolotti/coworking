#include "positionswindow.h"
#include <QApplication>
#include <QGraphicsView>
#include <vector>
#include <unistd.h>
#include <QGraphicsRectItem>
#include <user.h>
#include <userslist.h>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    PositionsWindow w;
    w.show();
    UsersList list;
    list.loadData();

    User user;
    user.setName("Giovanni");
    user.setSurname("Muciaccia");

    list.addUser(user);

    std::cout << "Code = " << list.saveData() << std::endl;
    std::cout << "n = " << list.numberUsers() << std::endl;




    return app.exec();
}
