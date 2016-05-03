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

    MeetingRoomDaily(MeetingRoomProgram program, GenericList<RSVMeetingRoom>* list, QWidget *parent = 0);

    ~MeetingRoomDaily();

    void updateWithProgram(MeetingRoomProgram& program);

 public slots:

    void customMenuRequested(QPoint pos);

    void addReservation();

    void add(QString name,QString surname,int inithour,int endhour);


 private:

    Ui::MeetingRoomDaily *ui;

    QListWidgetItem* names_labels[15];

    GenericList<RSVMeetingRoom>* rsvlist;

    MeetingRoomProgram displayed_program;

};

#endif // MEETINGROOMDAILY_H
