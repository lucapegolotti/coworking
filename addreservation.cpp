#include "addreservation.h"
#include "ui_addreservation.h"

AddReservation::AddReservation(int workst_number, QDate beginDate, QDate maximumEndDate, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddReservation),
    workstation_number(workst_number)
{
    tariffIsValid = false;
    nameIsValid = false;
    surnameIsValid = false;
    telephoneIsValid = false;
    emailIsValid = false;
    whopaysIsValid = false;
    badgeIsValid = false;
    depositIsValid = true;

    ui->setupUi(this);
    ui->beginDateEdit->setDate(beginDate);
    ui->beginDateEdit->setMinimumDate(beginDate);
    ui->endDateEdit->setDate(beginDate);
    QDate myBirthday(1992,11,5);
    if (maximumEndDate != myBirthday){
        std::cout << maximumEndDate.day() << std::endl;
        ui->endDateEdit->setMaximumDate(maximumEndDate.addDays(-1));
        ui->endDateEdit->setDate(maximumEndDate.addDays(-1));

    }

    QObject::connect(ui->aggiungiButton,SIGNAL(clicked(bool)),
                     this,SLOT(buttonOkPressed()));

    QObject::connect(ui->aggiungiButton,SIGNAL(clicked(bool)),
                     this,SLOT(cancelOrOkButtonIsPressed()));
    QObject::connect(ui->indietroButton,SIGNAL(clicked(bool)),
                     this,SLOT(cancelOrOkButtonIsPressed()));


    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint);

    ui->aggiungiButton->setDisabled(true);

    ui->armadiettoAggLineEdit->setDisabled(true);

    QObject::connect(ui->nomeLineEdit,SIGNAL(textChanged(QString)),
                     this,SLOT(nameChanged(QString)));
    QObject::connect(ui->cognomeLineEdit,SIGNAL(textChanged(QString)),
                     this,SLOT(surnameChanged(QString)));
    QObject::connect(ui->telefonoLineEdit,SIGNAL(textChanged(QString)),
                     this,SLOT(telephoneChanged(QString)));
    QObject::connect(ui->emailLineEdit,SIGNAL(textChanged(QString)),
                     this,SLOT(emailChanged(QString)));
    QObject::connect(ui->chiPagaLineEdit,SIGNAL(textChanged(QString)),
                     this,SLOT(whopaysChanged(QString)));
    QObject::connect(ui->tariffaSpinBox,SIGNAL(valueChanged(double)),
                     this,SLOT(dailyTariffChanged(double)));
    QObject::connect(ui->beginDateEdit,SIGNAL(dateChanged(QDate)),
                     this,SLOT(beginDateChanged(QDate)));
    QObject::connect(ui->chiaveCheckBox,SIGNAL(clicked(bool)),
                     this,SLOT(enabledDeposit()));
    QObject::connect(ui->armadiettoAggLineEdit,SIGNAL(textChanged(QString)),
                     this,SLOT(depositChanged(QString)));
    QObject::connect(ui->badgeLineEdit,SIGNAL(textChanged(QString)),
                     this,SLOT(badgeChanged(QString)));

}



AddReservation::AddReservation(int workst_number,QDate beginDate,QDate maximumEndDate,QDate hintenddate, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddReservation),
    workstation_number(workst_number)
{
ui->setupUi(this);
ui->beginDateEdit->setDate(beginDate);
ui->endDateEdit->setDate(hintenddate);
std::cout << "re1f" << std::endl;
QDate myBirthday(1992,11,5);
if (maximumEndDate != myBirthday){
    std::cout << maximumEndDate.day() << std::endl;
    ui->endDateEdit->setMaximumDate(maximumEndDate);
    ui->endDateEdit->setDate(hintenddate);

}

QObject::connect(ui->aggiungiButton,SIGNAL(clicked(bool)),
                 this,SLOT(buttonOkPressed()));

QObject::connect(ui->aggiungiButton,SIGNAL(clicked(bool)),
                 this,SLOT(cancelOrOkButtonIsPressed()));
QObject::connect(ui->indietroButton,SIGNAL(clicked(bool)),
                 this,SLOT(cancelOrOkButtonIsPressed()));


this->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint);

ui->aggiungiButton->setDisabled(true);

QObject::connect(ui->nomeLineEdit,SIGNAL(textChanged(QString)),
                 this,SLOT(nameChanged(QString)));
QObject::connect(ui->cognomeLineEdit,SIGNAL(textChanged(QString)),
                 this,SLOT(surnameChanged(QString)));
QObject::connect(ui->chiPagaLineEdit,SIGNAL(textChanged(QString)),
                 this,SLOT(whopaysChanged(QString)));
QObject::connect(ui->tariffaSpinBox,SIGNAL(valueChanged(double)),
                 this,SLOT(dailyTariffChanged(double)));
QObject::connect(ui->beginDateEdit,SIGNAL(dateChanged(QDate)),
                 this,SLOT(beginDateChanged(QDate)));


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

void AddReservation::telephoneChanged(QString string){
    telephoneIsValid = string.length()>0;
    unlocksOkButton();
}

void AddReservation::emailChanged(QString string){
    emailIsValid = string.length()>0;
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
    if (tariffIsValid && nameIsValid && telephoneIsValid &&
       emailIsValid && surnameIsValid && whopaysIsValid  &&
       badgeIsValid && (depositIsValid || !ui->chiaveCheckBox->isChecked())){
        ui->aggiungiButton->setEnabled(true);
    }
    else{
        ui->aggiungiButton->setDisabled(true);
    }
}

void AddReservation::buttonOkPressed(){
    Reservation newuser;
    newuser.setName(ui->nomeLineEdit->text());
    newuser.setSurname(ui->cognomeLineEdit->text());
    newuser.setTelephone(ui->telefonoLineEdit->text());
    newuser.setEmail(ui->emailLineEdit->text());
    newuser.setWhoPays(ui->chiPagaLineEdit->text());
    newuser.setBadgeNumber(ui->badgeLineEdit->text().toInt());
    newuser.setDailyTariff(std::stof(ui->tariffaSpinBox->text().toStdString()));
    newuser.setEthernet(ui->ethernetCheckBox->isChecked());
    newuser.setDepositKey(ui->chiaveCheckBox->isChecked());
    newuser.setDepositNumber(ui->armadiettoAggLineEdit->text());
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
    close();
    emit cancelOrOkButtonSignal();
}

void AddReservation::beginDateChanged(QDate date){
    if (date>=ui->endDateEdit->date())
        ui->endDateEdit->setDate(date);
    ui->endDateEdit->setMinimumDate(date);
}

void AddReservation::enabledDeposit() {

    if (ui->armadiettoAggLineEdit->isEnabled()){
        ui->armadiettoAggLineEdit->setDisabled(true);
        ui->armadiettoAggLineEdit->setText("");
        depositIsValid = true;

    }
    else {
        ui->armadiettoAggLineEdit->setEnabled(true);
        depositIsValid = false;
    }
    unlocksOkButton();

}

void AddReservation::depositChanged(QString string){
    depositIsValid = string.length()>0;
    unlocksOkButton();
}

void AddReservation::badgeChanged(QString string){
    bool ret;
    string.toInt(&ret);
    badgeIsValid = string.length()>0 && ret;
    unlocksOkButton();
}
