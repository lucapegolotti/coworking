#include "calendar.h"
#include "ui_calendar.h"

Calendar::Calendar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calendar)
{
    ui->setupUi(this);
}

Calendar::~Calendar()
{
    delete ui;
}


void Calendar::on_calendarWidget_clicked(const QDate &date)
{
    emit sendChosenDate(date);

}
