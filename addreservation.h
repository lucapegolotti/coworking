#ifndef ADDRESERVATION_H
#define ADDRESERVATION_H

#include <QDialog>
#include <iostream>
#include <User.h>

namespace Ui {
class AddReservation;
}

class AddReservation : public QDialog
{
    Q_OBJECT

public:
    AddReservation(int workst_number,QWidget *parent = 0);
    ~AddReservation();

public slots:
    void buttonOkPressed();

signals:
    void sendReservationToMainWindow(User user);

private:
    Ui::AddReservation *ui;
    int workstation_number;
};

#endif // ADDRESERVATION_H
