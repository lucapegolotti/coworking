#ifndef MEETINGROOMDAILY_H
#define MEETINGROOMDAILY_H

#include <QWidget>
#include <QLabel>
#include <QItemDelegate>
#include <meetingroomprogram.h>
#include <QListWidgetItem>

namespace Ui {
class MeetingRoomDaily;
}

class MeetingRoomDaily : public QWidget
{
    Q_OBJECT

 public:

    explicit MeetingRoomDaily(QWidget *parent = 0);

    ~MeetingRoomDaily();

    void updateWithProgram(MeetingRoomProgram& program);

 private:

    Ui::MeetingRoomDaily *ui;

    QListWidgetItem* names_labels[15];

};

#endif // MEETINGROOMDAILY_H
