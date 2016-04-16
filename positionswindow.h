#ifndef POSITIONSWINDOW_H
#define POSITIONSWINDOW_H

#include <QMainWindow>
#include <QGraphicsRectItem>
#include <vector>
#include <QMouseEvent>
#include <ctime>
#include <iostream>
#include <userslist.h>
#include <workstations.h>
#include <date.h>
#include <QDate>
#include <addreservation.h>

namespace Ui {
class PositionsWindow;
}

class PositionsWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit PositionsWindow(QWidget *parent = 0);

    ~PositionsWindow();

    void mousePressEvent(QMouseEvent* event);

public slots:
    void receiveNewDate(const QDate& date);

    void customMenuRequested(const QPoint &pos);

    void addReservation(bool);

    void addReservationResult(User user);

private:
    Ui::PositionsWindow *ui;

    Workstations workstations;

    UsersList list;

    int lastWorkstationClicked;

    QDate displayedDate;

    QColor* freeSpotColor;

    QColor* notFreeSpotColor;

    void setTime(Date date);

};

#endif // POSITIONSWINDOW_H
