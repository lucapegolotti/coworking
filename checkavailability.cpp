#include "checkavailability.h"
#include "ui_checkavailability.h"

CheckAvailability::CheckAvailability(QDate current_date,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckAvailability)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint);

    ui->beginDateEdit->setDate(current_date);
    ui->endDateEdit->setDate(current_date);
    ui->beginDateEdit->setMinimumDate(QDate::currentDate());
    ui->endDateEdit->setMinimumDate(QDate::currentDate());

    QObject::connect(ui->indietroButton,SIGNAL(clicked(bool)),
                     this,SLOT(closedIsPressed()));
}

CheckAvailability::~CheckAvailability()
{
    delete ui;
}

void CheckAvailability::closedIsPressed(){
    emit closeIsPressedSignal();
    close();
}

void CheckAvailability::on_beginDateEdit_dateChanged(const QDate &date)
{
    if (date>ui->endDateEdit->date()){
        ui->endDateEdit->setDate(date);
    }
    ui->endDateEdit->setMinimumDate(date);
    emit beginDateChangedSignal(date);
}

void CheckAvailability::on_endDateEdit_dateChanged(const QDate &date)
{
    emit endDateChangedSignal(date);
}
