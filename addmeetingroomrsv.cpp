#include "addmeetingroomrsv.h"
#include "ui_addmeetingroomrsv.h"

AddMeetingRoomRSV::AddMeetingRoomRSV(QString aula, MeetingRoomProgram program,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMeetingRoomRSV),
    program(program)
{
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint);

    ui->setupUi(this);
    ui->aggiungiButton->setDisabled(true);
    this->setWindowTitle(aula);

    QObject::connect(ui->nomeLineEdit, SIGNAL(textChanged(QString)),
                     this,SLOT(nameIsChanged(QString)));
    QObject::connect(ui->cognomeLineEdit,SIGNAL(textChanged(QString)),
                     this,SLOT(surnameIsChanged(QString)));
    QObject::connect(ui->oraInizioSpinBox,SIGNAL(valueChanged(int)),
                     this,SLOT(beginHourChanged(int)));
    QObject::connect(ui->oraFineSpinBox,SIGNAL(valueChanged(int)),
                     this,SLOT(endHourChanged(int)));
    QObject::connect(ui->indietroButton,SIGNAL(clicked(bool)),
                     this,SLOT(close()));
    QObject::connect(ui->aggiungiButton,SIGNAL(clicked(bool)),
                     this,SLOT(add()));
}

AddMeetingRoomRSV::~AddMeetingRoomRSV()
{
    delete ui;
}

void AddMeetingRoomRSV::beginHourChanged(int newhour){
    if (newhour >= ui->oraFineSpinBox->value()){
        ui->oraFineSpinBox->setValue(newhour);
    }
    enableAggiungi();
}

void AddMeetingRoomRSV::endHourChanged(int newhour){
    if (newhour <= ui->oraInizioSpinBox->value()){
        ui->oraInizioSpinBox->setValue(newhour);
    }
    enableAggiungi();
}

void AddMeetingRoomRSV::nameIsChanged(QString name){
    namechanged = name.length()>0;
    enableAggiungi();

}

void AddMeetingRoomRSV::surnameIsChanged(QString surname){
    surnamechanged = surname.length()>0;
    enableAggiungi();

}

void AddMeetingRoomRSV::enableAggiungi(){
    ui->aggiungiButton->setEnabled(false);
    if (surnamechanged && namechanged && hoursAreSuitable()){
        ui->aggiungiButton->setEnabled(true);
    }
}

bool AddMeetingRoomRSV::hoursAreSuitable(){
    int start = ui->oraInizioSpinBox->value()-9;
    int end = ui->oraFineSpinBox->value()-9;
    for (int i = start; i <= end; i++){
        if (program.getNameAt(i) != ""){
            return false;
        }
    }
    return true;
}

void AddMeetingRoomRSV::add(){
    addSignal(ui->nomeLineEdit->text(),
                   ui->cognomeLineEdit->text(),
                   ui->oraInizioSpinBox->value(),
                   ui->oraFineSpinBox->value());
    this->close();
}
