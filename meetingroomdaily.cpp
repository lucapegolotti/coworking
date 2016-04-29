#include "meetingroomdaily.h"
#include "ui_meetingroomdaily.h"

MeetingRoomDaily::MeetingRoomDaily(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MeetingRoomDaily) {
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

}

MeetingRoomDaily::~MeetingRoomDaily()
{
    delete ui;
}

void MeetingRoomDaily::updateWithProgram(MeetingRoomProgram &program){
    for (int i = 0; i < 15; i++){
        names_labels[i]->setText(program.getNameAt(i));
    }
}
