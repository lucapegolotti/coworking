#ifndef DETAILSRESERVATION_H
#define DETAILSRESERVATION_H

#include <QDialog>
#include <reservation.h>

namespace Ui {
class DetailsReservation;
}

class DetailsReservation : public QDialog
{
    Q_OBJECT

public:

    DetailsReservation(Reservation* user,QWidget *parent = 0);
    ~DetailsReservation();

public slots:

    void modifyEntry(bool);

    void cancelOrOkButtonIsPressed();

    void sendModifiedUser();

    void deleteUser();

signals:

    void cancelOrOkButtonSignal();

    void sendModifiedUserSignal(Reservation* old_user, Reservation newuser);

    void deleteUserSignal(Reservation* user);

private:

    Ui::DetailsReservation *ui;

    Reservation* user_det;
};

#endif // DETAILSRESERVATION_H
