#ifndef CALENDAR_H
#define CALENDAR_H

#include <QWidget>
#include <date.h>
#include <QCalendarWidget>
#include <QMouseEvent>
#include <iostream>


namespace Ui {
class Calendar;
}

class Calendar : public QWidget
{
    Q_OBJECT

public:
    explicit Calendar(QWidget *parent = 0);

    Calendar(QDate cur_date,QWidget * parent = 0);

    ~Calendar();


signals:
    void sendChosenDate(const QDate& date);

private slots:
    void on_calendarWidget_clicked(const QDate &date);

    void disable();

    void enable();

private:
    Ui::Calendar *ui;

};

#endif // CALENDAR_H
