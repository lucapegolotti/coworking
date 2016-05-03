#ifndef ADDMEETINGROOMRSV_H
#define ADDMEETINGROOMRSV_H

#include <QDialog>
#include <meetingroomprogram.h>

namespace Ui {
class AddMeetingRoomRSV;
}

class AddMeetingRoomRSV : public QDialog
{
    Q_OBJECT

public:

    AddMeetingRoomRSV(QString aula, MeetingRoomProgram program, QWidget *parent = 0);

    ~AddMeetingRoomRSV();

public slots:

   void nameIsChanged(QString name);

   void surnameIsChanged(QString surname);

   void add();

   void beginHourChanged(int newhour);

   void endHourChanged(int newhoue);

signals:

   void addSignal(QString name, QString surname, int begin_hour, int end_hour);


private:
    Ui::AddMeetingRoomRSV *ui;

    MeetingRoomProgram program;

    bool namechanged;
    bool surnamechanged;

    void enableAggiungi();

    bool hoursAreSuitable();

};

#endif // ADDMEETINGROOMRSV_H
