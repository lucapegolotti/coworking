#include "meetingroomdaily.h"
#include "ui_meetingroomdaily.h"

MeetingRoomDaily::MeetingRoomDaily(MeetingRoomProgram program,
                                   GenericList<RSVMeetingRoom> *list,
                                   QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MeetingRoomDaily),
    displayed_program(program),
    rsvlist(list) {
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

    updateWithProgram(program);

}

MeetingRoomDaily::~MeetingRoomDaily()
{
    delete ui;
}

void MeetingRoomDaily::updateWithProgram(MeetingRoomProgram &program){
    displayed_program = program;
    for (int i = 0; i < 15; i++){
        names_labels[i]->setText(program.getNameAt(i));
        qDebug() << names_labels[i]->text();
    }
}

void MeetingRoomDaily::customMenuRequested(QPoint pos){
    QMenu *menu = new QMenu(this);
    QAction* addrsv = new QAction("Aggiungi prenotazione",this);

    menu->addAction(addrsv);

    menu->popup(ui->listWidget->viewport()->mapToGlobal(pos));

    QObject::connect(addrsv,SIGNAL(triggered(bool)),
                 this,SLOT(addReservation()));

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
    rsvlist->addElement(rsv);
    rsvlist->saveData("json","prenotazioni_riunioni");
    displayed_program.addReservation(rsv);
    updateWithProgram(displayed_program);
}
