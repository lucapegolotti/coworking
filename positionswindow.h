#ifndef POSITIONSWINDOW_H
#define POSITIONSWINDOW_H

#include <QMainWindow>
#include <QGraphicsRectItem>
#include <vector>
#include <QMouseEvent>
#include <ctime>
#include <iostream>
#include <reservationslist.h>
#include <workstations.h>
#include <QDate>
#include <addreservation.h>
#include <detailsreservation.h>
#include <checkavailability.h>
#include <calendar.h>

namespace Ui {
class PositionsWindow;
}

class PositionsWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit PositionsWindow(QWidget *parent = 0);

    void changeCurrentDate(QDate date);

    ~PositionsWindow();

public slots:
    void receiveNewDate(const QDate& date);

    void customMenuRequested(const QPoint &pos);

    void addReservation(bool);

    void addReservationResult(Reservation user);

    void showDetails(bool);

    void enableAgain();

    void modifyUser(Reservation* old_user,Reservation new_user);

    void deleteUser(Reservation* user);

    void openCheckAvailability();

    void receiveNewBeginDateAvailability(QDate date);

    void receiveNewEndDateAvailability(QDate date);

    void openCalendar();

    void checkAvailabilityIsClosed();

signals:

    void addingReservation();

    void finishedAddingReservation();


private slots:
    void on_previousButton_clicked();

    void on_followingButton_clicked();

private:
    Ui::PositionsWindow *ui;

    Workstations workstations;

    ReservationsList list;

    int lastWorkstationClicked;

    QDate displayedDate;

    QDate endDateAvailability;

    QColor* freeSpotColor;

    QColor* notFreeSpotColor;

    QColor* notAvailableInPeriodColor;

    void setTime(QDate date);

    bool checkAvailOpen;

};

#endif // POSITIONSWINDOW_H
