#ifndef MEETINGROOMDAILY_H
#define MEETINGROOMDAILY_H

#include <QWidget>
#include <QLabel>
#include <QItemDelegate>

namespace Ui {
class MeetingRoomDaily;
}

class MeetingRoomDaily : public QWidget
{
    Q_OBJECT

    class CustomDelegate : public QItemDelegate {
     public:
        QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const{
            QSize size = QItemDelegate::sizeHint(option,index);
            size.setHeight(size.height());
            return size;
        }
    };

 public:
    explicit MeetingRoomDaily(QWidget *parent = 0);
    ~MeetingRoomDaily();

 private:
    Ui::MeetingRoomDaily *ui;
};

#endif // MEETINGROOMDAILY_H
