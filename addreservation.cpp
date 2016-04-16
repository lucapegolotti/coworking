#include "addreservation.h"
#include "ui_addreservation.h"

AddReservation::AddReservation(int workst_number, QWidget *parent) :
    QDialog(parent),
    workstation_number(workst_number),
    ui(new Ui::AddReservation)
{
    ui->setupUi(this);
    ui->beginDateEdit->setDate(QDate::currentDate());
    ui->endDateEdit->setDate(QDate::currentDate());

    QObject::connect(ui->buttonBox,SIGNAL(accepted()),
                     this,SLOT(buttonOkPressed()));

}

AddReservation::~AddReservation()
{
    delete ui;
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
