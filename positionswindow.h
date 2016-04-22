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
#include <detailsreservation.h>
#include <checkavailability.h>

namespace Ui {
class PositionsWindow;
}

class PositionsWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit PositionsWindow(QWidget *parent = 0);

    ~PositionsWindow();

public slots:
    void receiveNewDate(const QDate& date);

    void customMenuRequested(const QPoint &pos);

    void addReservation(bool);

    void addReservationResult(User user);

    void showDetails(bool);

    void enableAgain();

    void modifyUser(User* old_user,User new_user);

    void deleteUser(User* user);

    void openCheckAvailability();

    void receiveNewBeginDateAvailability(QDate date);

    void receiveNewEndDateAvailability(QDate date);



signals:

    void addingReservation();

    void finishedAddingReservation();


private:
    Ui::PositionsWindow *ui;

    Workstations workstations;

    UsersList list;

    int lastWorkstationClicked;

    QDate displayedDate;

    QDate endDateAvailability;

    QColor* freeSpotColor;

    QColor* notFreeSpotColor;

    QColor* availableInPeriodColor;

    void setTime(Date date);

};

#endif // POSITIONSWINDOW_H
