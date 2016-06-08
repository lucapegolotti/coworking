#ifndef MEETINGROOMDAILY_H
#define MEETINGROOMDAILY_H

#include <QWidget>
#include <QLabel>
#include <QItemDelegate>
#include <meetingroomprogram.h>
#include <QListWidgetItem>
#include <QMenu>
#include <iostream>
#include <addmeetingroomrsv.h>

namespace Ui {
class MeetingRoomDaily;
}

class MeetingRoomDaily : public QWidget
{
    Q_OBJECT

 public:

    MeetingRoomDaily(QDate current_date, GenericList<RSVMeetingRoom>* list, QWidget *parent = 0);

    ~MeetingRoomDaily();

 public slots:

    void customMenuRequested(QPoint pos);

    void addReservation();

    void add(QString name,QString surname,int inithour,int endhour);

    void updateToNewDate(QDate newDate);

    void deleteReservation();

private slots:
    void on_riunioniButton_clicked();

    void on_corsiButton_clicked();

private:

    Ui::MeetingRoomDaily *ui;

    QListWidgetItem* names_labels[15];

    GenericList<RSVMeetingRoom>* rsvlist;

    QDate displayed_date;

    MeetingRoomProgram displayed_program;

    RSVMeetingRoom last_rsv_clicked;


    void updateWithProgram();

};

#endif // MEETINGROOMDAILY_H
