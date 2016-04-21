#ifndef DETAILSRESERVATION_H
#define DETAILSRESERVATION_H

#include <QDialog>
#include <user.h>

namespace Ui {
class DetailsReservation;
}

class DetailsReservation : public QDialog
{
    Q_OBJECT

public:
    DetailsReservation(User* user,QWidget *parent = 0);
    ~DetailsReservation();

public slots:
    void modifyEntry(bool);

    void cancelOrOkButtonIsPressed();

    void sendModifiedUser();

    void deleteUser();

signals:
    void cancelOrOkButtonSignal();

    void sendModifiedUserSignal(User* old_user, User newuser);

    void deleteUserSignal(User* user);

private:
    Ui::DetailsReservation *ui;
    User* user_det;
};

#endif // DETAILSRESERVATION_H
