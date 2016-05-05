#include "positionswindow.h"
#include "ui_positionswindow.h"

PositionsWindow::PositionsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PositionsWindow),
    workstations(QDate::currentDate()),
    freeSpotColor(new QColor(114,233,200)),
    notFreeSpotColor(new QColor(253,152,152)),
    notAvailableInPeriodColor(new QColor(190,190,255)),
    checkAvailOpen(false){
    meetingRoomList.loadData("json","prenotazioni_riunioni");
    list.loadData("json","prenotazioni");

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


    changeCurrentDate(QDate::currentDate());
    workstations.colorItems(list,*freeSpotColor,*notFreeSpotColor);
    positionsView->setScene(scene);

    ui->positionsView->setContextMenuPolicy(Qt::CustomContextMenu);
    QObject::connect(ui->positionsView, SIGNAL(customContextMenuRequested(QPoint)),
                this,SLOT(customMenuRequested(QPoint)));

    QObject::connect(ui->actionControlla_disponibilit,SIGNAL(triggered(bool)),
                     this,SLOT(openCheckAvailability()));

    QObject::connect(ui->actionApri_Calendario,SIGNAL(triggered(bool)),
                     this,SLOT(openCalendar()));

    QObject::connect(ui->actionProgramma_aula_riunioni_aula_corsi,SIGNAL(triggered(bool)),
                     this,SLOT(openMeetingRoomProgram()));
}

PositionsWindow::~PositionsWindow(){
    delete ui;
    delete freeSpotColor;
    delete notFreeSpotColor;
    delete notAvailableInPeriodColor;
}

void PositionsWindow::openCalendar(){
    Calendar* c = new Calendar(displayedDate);

    QObject::connect(this,SIGNAL(changingDate(QDate)),
                     c,SLOT(dateChanged(QDate)));
    QObject::connect(c,SIGNAL(sendChosenDate(const QDate&)),
                     this,SLOT(receiveNewDate(const QDate&)));
    QObject::connect(this,SIGNAL(addingReservation()),
                     c,SLOT(disable()));
    QObject::connect(this,SIGNAL(finishedAddingReservation()),
                     c,SLOT(enable()));
    QObject::connect(this,SIGNAL(destroyed(QObject*)),
                     c,SLOT(close()));
    c->show();
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

        if (displayedDate<QDate::currentDate())
            addrsv->setDisabled(true);
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

    AddReservation* addreservation;
    if (checkAvailOpen)
        addreservation = new AddReservation(lastWorkstationClicked,displayedDate,workstations.freeUntil(lastWorkstationClicked),endDateAvailability);
    else
        addreservation = new AddReservation(lastWorkstationClicked,displayedDate,workstations.freeUntil(lastWorkstationClicked));
    QObject::connect(addreservation,SIGNAL(sendReservationToMainWindow(Reservation)),
                     this,SLOT(addReservationResult(Reservation)));
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
    QObject::connect(details,SIGNAL(sendModifiedUserSignal(Reservation*,Reservation)),
                     this,SLOT(modifyUser(Reservation*,Reservation)));
    QObject::connect(details,SIGNAL(deleteUserSignal(Reservation*)),
                     this,SLOT(deleteUser(Reservation*)));

    details->show();
}

void PositionsWindow::modifyUser(Reservation* old_user,Reservation new_user){
    list.modifyElement(*old_user,new_user);
    list.saveData("json","prenotazioni");
    workstations.colorItems(list,*freeSpotColor,*notFreeSpotColor);
}

void PositionsWindow::deleteUser(Reservation *user){
    list.deleteElement(*user);
    list.saveData("json","prenotazioni");
    workstations.colorItems(list,*freeSpotColor,*notFreeSpotColor);
}

void PositionsWindow::enableAgain(){
    emit finishedAddingReservation();
    this->setEnabled(true);
}

void PositionsWindow::addReservationResult(Reservation user){
    list.addElement(user);
    if (!checkAvailOpen)
        workstations.colorItems(list,*freeSpotColor,*notFreeSpotColor);
    else
        workstations.colorItemsWithAvailability(list,*freeSpotColor,*notAvailableInPeriodColor,endDateAvailability);
    list.saveData("json","prenotazioni");
}

void PositionsWindow::receiveNewDate(const QDate &date){
    changeCurrentDate(date);
}

void PositionsWindow::openCheckAvailability(){
    checkAvailOpen = true;
    CheckAvailability* check = new CheckAvailability(displayedDate);
    check->show();

    QObject::connect(check,SIGNAL(beginDateChangedSignal(QDate)),
                     this,SLOT(receiveNewBeginDateAvailability(QDate)));
    QObject::connect(check,SIGNAL(endDateChangedSignal(QDate)),
                     this,SLOT(receiveNewEndDateAvailability(QDate)));
    QObject::connect(check,SIGNAL(closeIsPressedSignal()),
                     this,SLOT(checkAvailabilityIsClosed()));
    endDateAvailability = displayedDate;
    workstations.colorItemsWithAvailability(list,*freeSpotColor,*notAvailableInPeriodColor,endDateAvailability);
}

void PositionsWindow::checkAvailabilityIsClosed(){
    checkAvailOpen = false;
    workstations.setCurrentDate(displayedDate);
    workstations.colorItems(list,*freeSpotColor,*notFreeSpotColor);
}

void PositionsWindow::receiveNewEndDateAvailability(QDate date){
    endDateAvailability = date;
    workstations.colorItemsWithAvailability(list,*freeSpotColor,
                                            *notAvailableInPeriodColor,endDateAvailability);
}

void PositionsWindow::receiveNewBeginDateAvailability(QDate date){
    changeCurrentDate(date);
    workstations.colorItemsWithAvailability(list,*freeSpotColor,
                                            *notAvailableInPeriodColor,endDateAvailability);
}

void PositionsWindow::changeCurrentDate(QDate date){
    displayedDate = date;
    workstations.setCurrentDate(displayedDate);
    int day = date.day();
    int weekday = date.dayOfWeek();
    QString weekday_string;
    switch (weekday){
        case 1:
        weekday_string = "Lunedì";
        break;
        case 2:
        weekday_string = "Martedì";
        break;
        case 3:
        weekday_string = "Mercoledì";
        break;
        case 4:
        weekday_string = "Giovedì";
        break;
        case 5:
        weekday_string = "Venerdì";
        break;
        case 6:
        weekday_string = "Sabato";
        break;
        case 7:
        weekday_string = "Domenica";
        break;

    }

    int month = date.month();
    QString month_string;
    switch (month) {
        case 1:
        month_string = "Gennaio";
        break;
        case 2:
        month_string = "Febbraio";
        break;
        case 3:
        month_string = "Marzo";
        break;
        case 4:
        month_string = "Aprile";
        break;
        case 5:
        month_string = "Maggio";
        break;
        case 6:
        month_string = "Giugno";
        break;
        case 7:
        month_string = "Luglio";
        break;
        case 8:
        month_string = "Agosto";
        break;
        case 9:
        month_string = "Settembre";
        break;
        case 10:
        month_string = "Ottobre";
        break;
        case 11:
        month_string = "Novembre";
        break;
        case 12:
        month_string = "Dicembre";
        break;

    }
    QString string_date = "<html><head/><body><p><span style=' font-size:24pt; color:#8ea8f1;'>";
            string_date.append(weekday_string).
            append(" ").append(QString::number(day)).
            append(" ").append(month_string).
            append(" ").append(QString::number(displayedDate.year())).append("</span></p></body></html>");
    ui->dataLabel->setText(string_date);
    workstations.colorItems(list,*freeSpotColor,*notFreeSpotColor);

    emit changingDate(displayedDate);
}

void PositionsWindow::on_previousButton_clicked()
{
    changeCurrentDate(displayedDate.addDays(-1));
}

void PositionsWindow::on_followingButton_clicked()
{
    changeCurrentDate(displayedDate.addDays(1));
}

void PositionsWindow::openMeetingRoomProgram() {
    MeetingRoomDaily* check = new MeetingRoomDaily(displayedDate,&meetingRoomList);
    QObject::connect(this,SIGNAL(changingDate(QDate)),
                     check,SLOT(updateToNewDate(QDate)));
    check->show();
}
