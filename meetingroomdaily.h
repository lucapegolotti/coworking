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

 private:

    Ui::MeetingRoomDaily *ui;

    QListWidgetItem* names_labels[15];

    GenericList<RSVMeetingRoom>* rsvlist;

    QDate displayed_date;

    MeetingRoomProgram displayed_program;

};

#endif // MEETINGROOMDAILY_H
