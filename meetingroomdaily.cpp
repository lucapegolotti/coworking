 #include "meetingroomdaily.h"
#include "ui_meetingroomdaily.h"

MeetingRoomDaily::MeetingRoomDaily(QDate current_date,
                                   GenericList<RSVMeetingRoom> *list,
                                   QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MeetingRoomDaily),
    rsvlist(list),
    displayed_date(current_date),
    displayed_program(*list, current_date){
    ui->setupUi(this);
    QFont font1;

    int row = 0;
    for (int i = 0; i < 15; i++){
        QListWidgetItem* hour = new QListWidgetItem();
        QString hour_text = QString::number(i+9);
        hour_text.append(".00 :");
        hour->setText(hour_text);
        hour->setTextAlignment(0);
        hour->setFlags(Qt::NoItemFlags);
        ui->listWidget->insertItem(row,hour);

        row++;
        QListWidgetItem* item = new QListWidgetItem();
        names_labels[i] = item;
        item->setFlags(Qt::NoItemFlags);
        item->setText("");
        item->setFont(font1);
        item->setTextAlignment(2);
        ui->listWidget->insertItem(row,item);

        row++;
        QListWidgetItem* separator = new QListWidgetItem();
        QSize size;
        size.setHeight(3);
        size.setWidth(432);
        separator->setSizeHint(size);
        separator->setText("");
        separator->setFlags(Qt::NoItemFlags);
        ui->listWidget->insertItem(row,separator);


        QFrame* frame = new QFrame();
        frame->setFrameShape(QFrame::HLine);
        ui->listWidget->setItemWidget(separator,frame);
        row++;
    }

    ui->riunioniButton->setChecked(true);

    ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    QObject::connect(ui->listWidget, SIGNAL(customContextMenuRequested(QPoint)),
                this,SLOT(customMenuRequested(QPoint)));

    updateToNewDate(displayed_date);

}

MeetingRoomDaily::~MeetingRoomDaily()
{
    delete ui;
}

void MeetingRoomDaily::updateToNewDate(QDate newDate){
    displayed_date = newDate;
    displayed_program.updateToDate(newDate,ui->corsiButton->isChecked());
    updateWithProgram();
}

void MeetingRoomDaily::updateWithProgram(){
    for (int i = 0; i < 15; i++){
        names_labels[i]->setText(displayed_program.getNameAt(i));
    }
}

void MeetingRoomDaily::customMenuRequested(QPoint pos){
    QMenu *menu = new QMenu(this);
    QAction* addrsv = new QAction("Aggiungi prenotazione",this);

    menu->addAction(addrsv);

    menu->popup(ui->listWidget->viewport()->mapToGlobal(pos));

    QObject::connect(addrsv,SIGNAL(triggered(bool)),
                 this,SLOT(addReservation()));
    QListWidgetItem* pressed = ui->listWidget->itemAt(pos);
    if (pressed == nullptr){
        return;
    }
    int row = 0;
    for (int i = 0 ; i < 15; i++){
        if (ui->listWidget->item(row) == pressed)
            return;
        row = row + 1;
        if (ui->listWidget->item(row) == pressed && ui->listWidget->item(row)->text() != ""){
            QAction* deletersv = new QAction("Cancella prenotazione",this);

            menu->addAction(deletersv);

            menu->popup(ui->listWidget->viewport()->mapToGlobal(pos));

            QObject::connect(deletersv,SIGNAL(triggered(bool)),
                         this,SLOT(deleteReservation()));
            last_rsv_clicked = displayed_program.rsvat(i);
            return;
        }
        row = row+1;
        if (ui->listWidget->item(row) == pressed)
            return;
        row = row + 1;
    }



}

void MeetingRoomDaily::addReservation(){
    QString type_rsv = ui->corsiButton->isChecked()? "Aula corsi" : "Aula riunioni";
    AddMeetingRoomRSV* add = new AddMeetingRoomRSV(type_rsv,displayed_program);
    QObject::connect(add,SIGNAL(addSignal(QString,QString,int,int)),
                     this,SLOT(add(QString,QString,int,int)));
    add->show();
}

void MeetingRoomDaily::add(QString name,QString surname,int inithour,int endhour){
    RSVMeetingRoom rsv;
    rsv.setName(name);
    rsv.setSurname(surname);
    rsv.setStartingHour(inithour);
    rsv.setEndingHour(endhour);
    rsv.setDate(displayed_program.getDate());
    rsv.setClassroom(ui->corsiButton->isChecked());
    rsvlist->addElement(rsv);
    rsvlist->saveData("json",FILE_PATH("prenotazioni_riunioni"));
    // displayed_program.updateToDate(displayed_date,ui->corsiButton->isChecked());
    displayed_program.addReservation(rsv);
    updateWithProgram();

}

void MeetingRoomDaily::on_riunioniButton_clicked() {
    updateToNewDate(displayed_date);
}

void MeetingRoomDaily::on_corsiButton_clicked() {
    updateToNewDate(displayed_date);
}

void MeetingRoomDaily::deleteReservation(){
    qDebug() << last_rsv_clicked.getName();
    rsvlist->deleteElement(last_rsv_clicked);
    rsvlist->saveData("json",FILE_PATH("prenotazioni_riunioni"));
    displayed_program.deleteReservation(last_rsv_clicked);
    updateWithProgram();
}
