#include "addreservation.h"
#include "ui_addreservation.h"

AddReservation::AddReservation(int workst_number,QDate beginDate, QWidget *parent) :
    QDialog(parent),
    workstation_number(workst_number),
    ui(new Ui::AddReservation)
{
    ui->setupUi(this);
    ui->beginDateEdit->setDate(beginDate);
    ui->endDateEdit->setDate(beginDate);

    QObject::connect(ui->buttonBox,SIGNAL(accepted()),
                     this,SLOT(buttonOkPressed()));
    QObject::connect(ui->buttonBox,SIGNAL(clicked(QAbstractButton*)),
                     this,SLOT(cancelOrOkButtonIsPressed()));

    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint);

    ui->buttonBox->buttons().at(0)->setDisabled(true);

    QObject::connect(ui->nomeLineEdit,SIGNAL(textChanged(QString)),
                     this,SLOT(nameChanged(QString)));
    QObject::connect(ui->cognomeLineEdit,SIGNAL(textChanged(QString)),
                     this,SLOT(surnameChanged(QString)));
    QObject::connect(ui->chiPagaLineEdit,SIGNAL(textChanged(QString)),
                     this,SLOT(whopaysChanged(QString)));
    QObject::connect(ui->tariffaSpinBox,SIGNAL(valueChanged(double)),
                     this,SLOT(dailyTariffChanged(double)));


}

AddReservation::~AddReservation()
{
    delete ui;
}

void AddReservation::nameChanged(QString string){
    nameIsValid = string.length()>0;
    unlocksOkButton();
}

void AddReservation::surnameChanged(QString string){
    surnameIsValid = string.length()>0;
    unlocksOkButton();
}

void AddReservation::whopaysChanged(QString string){
    whopaysIsValid = string.length()>0;
    unlocksOkButton();
}

void AddReservation::dailyTariffChanged(double number){
    tariffIsValid = number > 0;
    unlocksOkButton();
}

void AddReservation::unlocksOkButton(){
    if (tariffIsValid && nameIsValid && surnameIsValid && whopaysIsValid){
        ui->buttonBox->buttons().at(0)->setEnabled(true);
    }
    else{
        ui->buttonBox->buttons().at(0)->setDisabled(true);
    }
}

void AddReservation::buttonOkPressed(){
    User newuser;
    newuser.setName(ui->nomeLineEdit->text());
    newuser.setSurname(ui->cognomeLineEdit->text());
    newuser.setWhoPays(ui->chiPagaLineEdit->text());
    newuser.setDailyTariff(std::stof(ui->tariffaSpinBox->text().toStdString()));
    newuser.setEthernet(ui->ethernetCheckBox->isChecked());
    newuser.setTelephone(ui->telefonoCheckBox->isChecked());
    newuser.setDepositKey(ui->chiaveCheckBox->isChecked());
    newuser.setBeginDate(ui->beginDateEdit->date().day(),
                         ui->beginDateEdit->date().month(),
                         ui->beginDateEdit->date().year());
    newuser.setEndDate(ui->endDateEdit->date().day(),
                         ui->endDateEdit->date().month(),
                         ui->endDateEdit->date().year());
    newuser.setWorkstation(workstation_number);
    sendReservationToMainWindow(newuser);
}

void AddReservation::cancelOrOkButtonIsPressed(){
    emit cancelOrOkButtonSignal();
}
