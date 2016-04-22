#ifndef ADDRESERVATION_H
#define ADDRESERVATION_H

#include <QDialog>
#include <iostream>
#include <User.h>
#include <QDate>

namespace Ui {
class AddReservation;
}

class AddReservation : public QDialog
{
    Q_OBJECT

public:
    AddReservation(int workst_number,QDate beginDate,QDate maximumEndDate, QWidget *parent = 0);
    ~AddReservation();

public slots:
    void buttonOkPressed();

    void cancelOrOkButtonIsPressed();

    void nameChanged(QString string);
    void surnameChanged(QString string);
    void whopaysChanged(QString string);
    void dailyTariffChanged(double number);
    void beginDateChanged(QDate date);

signals:
    void sendReservationToMainWindow(User user);

    void cancelOrOkButtonSignal();

private:
    Ui::AddReservation *ui;
    int workstation_number;
    bool tariffIsValid;
    bool nameIsValid;
    bool surnameIsValid;
    bool whopaysIsValid;
    void unlocksOkButton();
};

#endif // ADDRESERVATION_H
