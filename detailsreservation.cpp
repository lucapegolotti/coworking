#include "detailsreservation.h"
#include "ui_detailsreservation.h"

DetailsReservation::DetailsReservation(Reservation* user,QWidget *parent) :
    user_det(user),
    QDialog(parent),
    ui(new Ui::DetailsReservation)
{
    ui->setupUi(this);
    ui->okButton->setDisabled(true);
    ui->nomeLineEdit_2->setText(user->getName());
    ui->cognomeLineEdit_2->setText(user->getSurname());
    ui->telefonoLineEdit->setText(user->getTelephone());
    ui->emailLineEdit->setText(user->getEmail());
    ui->chiPagaLineEdit_2->setText(user->getWhoPays());
    ui->tariffaSpinBox_2->setValue(user->getDailyTariff());
    ui->accesso24hCheckBox_2->setChecked(user->getAllDayAccess());
    ui->ethernetCheckBox_2->setChecked(user->getEthernet());
    ui->chiaveCheckBox_2->setChecked(user->getDepositKey());
    ui->nomeLineEdit_2->setDisabled(true);
    ui->cognomeLineEdit_2->setDisabled(true);
    ui->telefonoLineEdit->setDisabled(true);
    ui->emailLineEdit->setDisabled(true);
    ui->chiPagaLineEdit_2->setDisabled(true);
    ui->tariffaSpinBox_2->setDisabled(true);
    ui->accesso24hCheckBox_2->setDisabled(true);
    ui->ethernetCheckBox_2->setDisabled(true);
    ui->chiaveCheckBox_2->setDisabled(true);
    QObject::connect(ui->modificaButton,SIGNAL(clicked(bool)),
                     this,SLOT(modifyEntry(bool)));

    QObject::connect(ui->indietroButton,SIGNAL(clicked(bool)),
                     this,SLOT(cancelOrOkButtonIsPressed()));

    QObject::connect(ui->okButton,SIGNAL(clicked(bool)),
                     this,SLOT(cancelOrOkButtonIsPressed()));

    QObject::connect(ui->eliminaButton,SIGNAL(clicked(bool)),
                     this,SLOT(cancelOrOkButtonIsPressed()));

    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint);

    QObject::connect(ui->okButton,SIGNAL(clicked(bool)),
                     this,SLOT(sendModifiedUser()));

    QObject::connect(ui->eliminaButton,SIGNAL(clicked(bool)),
                     this,SLOT(deleteUser()));




}

DetailsReservation::~DetailsReservation()
{
    delete ui;
}

void DetailsReservation::deleteUser(){
    emit deleteUserSignal(user_det);
}

void DetailsReservation::cancelOrOkButtonIsPressed(){
    close();
    emit cancelOrOkButtonSignal();
}

void DetailsReservation::sendModifiedUser(){
    Reservation newuser;
    newuser.setName(ui->nomeLineEdit_2->text());
    newuser.setSurname(ui->cognomeLineEdit_2->text());
    newuser.setTelephone(ui->telefonoLineEdit->text());
    newuser.setEmail(ui->emailLineEdit->text());
    newuser.setWhoPays(ui->chiPagaLineEdit_2->text());
    newuser.setDailyTariff(std::stof(ui->tariffaSpinBox_2->text().toStdString()));
    newuser.setEthernet(ui->ethernetCheckBox_2->isChecked());
    newuser.setDepositKey(ui->chiaveCheckBox_2->isChecked());
    newuser.setBeginDate(user_det->getBeginDay(),user_det->getBeginMonth(),user_det->getBeginYear());
    newuser.setEndDate(user_det->getEndDay(),user_det->getEndMonth(),user_det->getEndYear());
    newuser.setWorkstation(user_det->getWorkstation());
    sendModifiedUserSignal(user_det,newuser);
}

void DetailsReservation::modifyEntry(bool){
    ui->okButton->setEnabled(true);
    ui->modificaButton->setDisabled(true);
    ui->nomeLineEdit_2->setEnabled(true);
    ui->cognomeLineEdit_2->setEnabled(true);
    ui->telefonoLabel->setEnabled(true);
    ui->emailLabel->setEnabled(true);
    ui->chiPagaLineEdit_2->setEnabled(true);
    ui->tariffaSpinBox_2->setEnabled(true);
    ui->accesso24hCheckBox_2->setEnabled(true);
    ui->ethernetCheckBox_2->setEnabled(true);
    ui->chiaveCheckBox_2->setEnabled(true);
}
