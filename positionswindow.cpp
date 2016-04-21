#include "positionswindow.h"
#include "ui_positionswindow.h"

PositionsWindow::PositionsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PositionsWindow),
    workstations(QDate::currentDate()),
    freeSpotColor(new QColor(114,233,200)),
    notFreeSpotColor(new QColor(253,152,152)){

    list.loadData("json");

    ui->setupUi(this);

    QGraphicsView* positionsView =  ui->positionsView;

    const float mult = 1.4;
    const float xorigin = -20;
    const float yorigin = 25;
    const float multy = yorigin * mult;

    QGraphicsScene* scene = new QGraphicsScene(150,100,300,300,positionsView);
    QColor* backgroundColor = new QColor(242,250,255);
    scene->setBackgroundBrush(*backgroundColor);


    QGraphicsRectItem* rect = new QGraphicsRectItem(mult*(-5+xorigin),mult*0+multy,mult*25,mult*50);

    scene->addItem(rect);
    workstations.addGraphicItem(rect);

    rect = new QGraphicsRectItem(mult*(20+xorigin),mult*0+multy,mult*25,mult*50);

    scene->addItem(rect);
    workstations.addGraphicItem(rect);

    rect = new QGraphicsRectItem(mult*(-5+xorigin),mult*50+multy,mult*25,mult*50);

    scene->addItem(rect);
    workstations.addGraphicItem(rect);

    rect = new QGraphicsRectItem(mult*(20+xorigin),mult*50+multy,mult*25,mult*50);

    scene->addItem(rect);
    workstations.addGraphicItem(rect);

    rect = new QGraphicsRectItem(mult*(95+xorigin),mult*0+multy,mult*25,mult*50);

    scene->addItem(rect);
    workstations.addGraphicItem(rect);

    rect = new QGraphicsRectItem(mult*(120+xorigin),mult*0+multy,mult*25,mult*50);

    scene->addItem(rect);
    workstations.addGraphicItem(rect);

    rect = new QGraphicsRectItem(mult*(95+xorigin),mult*50+multy,mult*50,mult*25);

    scene->addItem(rect);
    workstations.addGraphicItem(rect);

    rect = new QGraphicsRectItem(mult*(195+xorigin),mult*0+multy,mult*25,mult*50);

    scene->addItem(rect);
    workstations.addGraphicItem(rect);

    rect = new QGraphicsRectItem(mult*(220+xorigin),mult*0+multy,mult*25,mult*50);

    scene->addItem(rect);
    workstations.addGraphicItem(rect);

    rect = new QGraphicsRectItem(mult*(-30+xorigin),mult*175+multy,mult*50,mult*25);

    scene->addItem(rect);
    workstations.addGraphicItem(rect);

    rect = new QGraphicsRectItem(mult*(-30+xorigin),mult*200+multy,mult*50,mult*25);

    scene->addItem(rect);
    workstations.addGraphicItem(rect);

    rect = new QGraphicsRectItem(mult*(20+xorigin),mult*175+multy,mult*50,mult*25);

    scene->addItem(rect);
    workstations.addGraphicItem(rect);

    rect = new QGraphicsRectItem(mult*(20+xorigin),mult*200+multy,mult*50,mult*25);

    scene->addItem(rect);
    workstations.addGraphicItem(rect);

    rect = new QGraphicsRectItem(mult*(70+xorigin),mult*175+multy,mult*25,mult*50);

    scene->addItem(rect);
    workstations.addGraphicItem(rect);

    rect = new QGraphicsRectItem(mult*(200+xorigin),mult*250+multy,mult*25,mult*50);

    scene->addItem(rect);
    workstations.addGraphicItem(rect);

    rect = new QGraphicsRectItem(mult*(225+xorigin),mult*250+multy,mult*25,mult*50);

    scene->addItem(rect);
    workstations.addGraphicItem(rect);

    rect = new QGraphicsRectItem(mult*(200+xorigin),mult*200+multy,mult*25,mult*50);

    scene->addItem(rect);
    workstations.addGraphicItem(rect);

    rect = new QGraphicsRectItem(mult*(225+xorigin),mult*200+multy,mult*25,mult*50);

    scene->addItem(rect);
    workstations.addGraphicItem(rect);

    rect = new QGraphicsRectItem(mult*(200+xorigin),mult*150+multy,mult*25,mult*50);

    scene->addItem(rect);
    workstations.addGraphicItem(rect);

    rect = new QGraphicsRectItem(mult*(225+xorigin),mult*150+multy,mult*25,mult*50);

    scene->addItem(rect);
    workstations.addGraphicItem(rect);

    const int a = 150;
    const int b = -10;
    rect = new QGraphicsRectItem(mult*(a+200+xorigin),mult*(b+250)+multy,mult*25,mult*50);

    scene->addItem(rect);
    workstations.addGraphicItem(rect);

    rect = new QGraphicsRectItem(mult*a+mult*(225+xorigin),mult*b+mult*250+multy,mult*25,mult*50);

    scene->addItem(rect);
    workstations.addGraphicItem(rect);

    rect = new QGraphicsRectItem(mult*a+mult*(200+xorigin),mult*b+mult*200+multy,mult*25,mult*50);

    scene->addItem(rect);
    workstations.addGraphicItem(rect);

    rect = new QGraphicsRectItem(mult*a+mult*(225+xorigin),mult*b+mult*200+multy,mult*25,mult*50);

    scene->addItem(rect);
    workstations.addGraphicItem(rect);

    rect = new QGraphicsRectItem(mult*a+mult*(200+xorigin),mult*b+mult*150+multy,mult*25,mult*50);

    scene->addItem(rect);
    workstations.addGraphicItem(rect);

    rect = new QGraphicsRectItem(mult*a+mult*(225+xorigin),mult*b+mult*150+multy,mult*25,mult*50);

    scene->addItem(rect);
    workstations.addGraphicItem(rect);

    rect = new QGraphicsRectItem(mult*(270+xorigin),mult*30+multy,mult*40,mult*20);

    scene->addItem(rect);
    workstations.addGraphicItem(rect);

    rect = new QGraphicsRectItem(mult*(310+xorigin),mult*30+multy,mult*40,mult*20);

    scene->addItem(rect);
    workstations.addGraphicItem(rect);

    rect = new QGraphicsRectItem(mult*(350+xorigin),mult*30+multy,mult*40,mult*20);

    scene->addItem(rect);
    workstations.addGraphicItem(rect);

    rect = new QGraphicsRectItem(mult*(270+xorigin),mult*50+multy,mult*40,mult*20);

    scene->addItem(rect);
    workstations.addGraphicItem(rect);

    rect = new QGraphicsRectItem(mult*(310+xorigin),mult*50+multy,mult*40,mult*20);

    scene->addItem(rect);
    workstations.addGraphicItem(rect);

    rect = new QGraphicsRectItem(mult*(350+xorigin),mult*50+multy,mult*40,mult*20);

    scene->addItem(rect);
    workstations.addGraphicItem(rect);


    // big rectangles
    rect = new QGraphicsRectItem(mult*(-30+xorigin),0+multy,mult*100,mult*150);
    scene->addItem(rect);

    rect = new QGraphicsRectItem(mult*(70+xorigin),mult*0+multy,mult*100,mult*100);
    scene->addItem(rect);

    rect = new QGraphicsRectItem(mult*(170+xorigin),mult*0+multy,mult*100,mult*100);
    scene->addItem(rect);

    rect = new QGraphicsRectItem(mult*(-30+xorigin),mult*150+multy,mult*170,mult*100);
    scene->addItem(rect);

    // lines
    QGraphicsLineItem* line = new QGraphicsLineItem(mult*(140+xorigin),mult*250+multy,mult*(140+xorigin),mult*300+multy);
    scene->addItem(line);

    line = new QGraphicsLineItem(mult*(180+xorigin),mult*300+multy,mult*(270+xorigin),mult*300+multy);
    scene->addItem(line);

    line = new QGraphicsLineItem(mult*(270+xorigin),mult*290+multy,mult*(270+xorigin),mult*300+multy);
    scene->addItem(line);

    line = new QGraphicsLineItem(mult*(270+xorigin),mult*290+multy,mult*(450+xorigin),mult*290+multy);
    scene->addItem(line);

    line = new QGraphicsLineItem(mult*(450+xorigin),mult*140+multy,mult*(450+xorigin),mult*290+multy);
    scene->addItem(line);

    line = new QGraphicsLineItem(mult*+(270+xorigin),0+multy,mult*(500+xorigin),0+multy);
    scene->addItem(line);

    line = new QGraphicsLineItem(mult*(500+xorigin),0+multy,mult*(500+xorigin),mult*100+multy);
    scene->addItem(line);

    line = new QGraphicsLineItem(mult*(450+xorigin),mult*100+multy,mult*(500+xorigin),mult*100+multy);
    scene->addItem(line);


    displayedDate = QDate::currentDate();
    workstations.colorItems(list,*freeSpotColor,*notFreeSpotColor);
    positionsView->setScene(scene);

    ui->positionsView->setContextMenuPolicy(Qt::CustomContextMenu);
    QObject::connect(ui->positionsView, SIGNAL(customContextMenuRequested(QPoint)),
                this,SLOT(customMenuRequested(QPoint)));



}

PositionsWindow::~PositionsWindow(){

    delete ui;
    delete freeSpotColor;
    delete notFreeSpotColor;
}

void PositionsWindow::customMenuRequested(const QPoint &pos){

    QPointF position_old = pos;
    QPointF* new_position  = new QPointF(position_old.x() - 120, position_old.y() - 25 );

    lastWorkstationClicked = workstations.pointIsContainedInWorkstationN(*new_position);
    if (lastWorkstationClicked != -1 &&
            workstations.isWorkstationOfThatColor(lastWorkstationClicked,*freeSpotColor)){

        QMenu *menu = new QMenu(this);
        QAction* addrsv = new QAction("Aggiungi prenotazione",this);

        QObject::connect(addrsv,SIGNAL(triggered(bool)),
                     this,SLOT(addReservation(bool)));


        menu->addAction(addrsv);

        menu->popup(ui->positionsView->viewport()->mapToGlobal(pos));
    }
    if (lastWorkstationClicked != -1 &&
            workstations.isWorkstationOfThatColor(lastWorkstationClicked,*notFreeSpotColor)){

        QMenu *menu = new QMenu(this);
        QAction* details = new QAction("Dettagli prenotazione",this);

        QObject::connect(details,SIGNAL(triggered(bool)),
                     this,SLOT(showDetails(bool)));

        menu->addAction(details);

        menu->popup(ui->positionsView->viewport()->mapToGlobal(pos));
    }
}

void PositionsWindow::addReservation(bool){
    emit addingReservation();
    this->setDisabled(true);
    AddReservation* addreservation = new AddReservation(lastWorkstationClicked,displayedDate);
    QObject::connect(addreservation,SIGNAL(sendReservationToMainWindow(User)),
                     this,SLOT(addReservationResult(User)));
    QObject::connect(addreservation,SIGNAL(cancelOrOkButtonSignal()),
                     this,SLOT(enableAgain()));
    addreservation->show();
}

void PositionsWindow::showDetails(bool){
    emit addingReservation();
    this->setDisabled(true);
    DetailsReservation* details = new DetailsReservation(workstations.userInPosition(lastWorkstationClicked));
    QObject::connect(details,SIGNAL(cancelOrOkButtonSignal()),
                     this,SLOT(enableAgain()));
    QObject::connect(details,SIGNAL(sendModifiedUserSignal(User*,User)),
                     this,SLOT(modifyUser(User*,User)));
    QObject::connect(details,SIGNAL(deleteUserSignal(User*)),
                     this,SLOT(deleteUser(User*)));

    details->show();
}

void PositionsWindow::modifyUser(User* old_user,User new_user){
    list.modifyUser(*old_user,new_user);
    list.saveData("json");
    workstations.colorItems(list,*freeSpotColor,*notFreeSpotColor);
}

void PositionsWindow::deleteUser(User *user){
    list.deleteUser(*user);
    list.saveData("json");
    workstations.colorItems(list,*freeSpotColor,*notFreeSpotColor);
}

void PositionsWindow::enableAgain(){
    emit finishedAddingReservation();
    this->setEnabled(true);
}

void PositionsWindow::addReservationResult(User user){
    list.addUser(user);
    workstations.colorItems(list,*freeSpotColor,*notFreeSpotColor);
    list.saveData("json");
}

void PositionsWindow::mousePressEvent(QMouseEvent* event){
    /*if (event->button() == Qt::RightButton){
        this->setContextMenuPolicy(Qt::CustomContextMenu);

    }*/

  /*  QPointF position_old = event->localPos();
    QPointF* new_position  = new QPointF(position_old.x() - 150, position_old.y() - 75 );

    for (std::vector<QGraphicsRectItem*>::iterator it = workstations.begin(); it < workstations.end(); it++){
        if ((*it)->contains(*new_position)){
            if ((*it)->brush() == (*freeSpotColor)){
                (*it)->setBrush(*notFreeSpotColor);
            }
            else{
                (*it)->setBrush(*freeSpotColor);
            }

            break;
        }
    }
    delete new_position;*/
}


void PositionsWindow::receiveNewDate(const QDate &date){
    displayedDate = date;
    workstations.setCurrentDate(displayedDate);
    workstations.colorItems(list,*freeSpotColor,*notFreeSpotColor);
}

