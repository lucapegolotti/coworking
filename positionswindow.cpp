#include "positionswindow.h"
#include "ui_positionswindow.h"

PositionsWindow::PositionsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PositionsWindow),
    workstations(),
    freeSpotColor(new QColor(114,233,200)),
    notFreeSpotColor(new QColor(253,152,152)){

    ui->setupUi(this);
    ui->dateLabel->setText("Here is date");

    QGraphicsView* positionsView =  ui->positionsView;

    const float mult = 1.4;
    const float xorigin = -20;
    const float yorigin = 25;
    const float multy = yorigin * mult;

    QGraphicsScene* scene = new QGraphicsScene(150,100,300,300,positionsView);
    QColor* backgroundColor = new QColor(242,250,255);
    scene->setBackgroundBrush(*backgroundColor);


    QGraphicsRectItem* rect = new QGraphicsRectItem(mult*(-5+xorigin),mult*0+multy,mult*25,mult*50);
    rect->setBrush(*freeSpotColor);
    scene->addItem(rect);
    workstations.push_back(rect);

    rect = new QGraphicsRectItem(mult*(20+xorigin),mult*0+multy,mult*25,mult*50);
    rect->setBrush(*freeSpotColor);
    scene->addItem(rect);
    workstations.push_back(rect);

    rect = new QGraphicsRectItem(mult*(-5+xorigin),mult*50+multy,mult*25,mult*50);
    rect->setBrush(*freeSpotColor);
    scene->addItem(rect);
    workstations.push_back(rect);

    rect = new QGraphicsRectItem(mult*(20+xorigin),mult*50+multy,mult*25,mult*50);
    rect->setBrush(*freeSpotColor);
    scene->addItem(rect);
    workstations.push_back(rect);

    rect = new QGraphicsRectItem(mult*(95+xorigin),mult*0+multy,mult*25,mult*50);
    rect->setBrush(*freeSpotColor);
    scene->addItem(rect);
    workstations.push_back(rect);

    rect = new QGraphicsRectItem(mult*(120+xorigin),mult*0+multy,mult*25,mult*50);
    rect->setBrush(*freeSpotColor);
    scene->addItem(rect);
    workstations.push_back(rect);

    rect = new QGraphicsRectItem(mult*(95+xorigin),mult*50+multy,mult*50,mult*25);
    rect->setBrush(*freeSpotColor);
    scene->addItem(rect);
    workstations.push_back(rect);

    rect = new QGraphicsRectItem(mult*(195+xorigin),mult*0+multy,mult*25,mult*50);
    rect->setBrush(*freeSpotColor);
    scene->addItem(rect);
    workstations.push_back(rect);

    rect = new QGraphicsRectItem(mult*(220+xorigin),mult*0+multy,mult*25,mult*50);
    rect->setBrush(*freeSpotColor);
    scene->addItem(rect);
    workstations.push_back(rect);

    rect = new QGraphicsRectItem(mult*(-30+xorigin),mult*175+multy,mult*50,mult*35);
    rect->setBrush(*freeSpotColor);
    scene->addItem(rect);
    workstations.push_back(rect);

    rect = new QGraphicsRectItem(mult*(-30+xorigin),mult*200+multy,mult*50,mult*25);
    rect->setBrush(*freeSpotColor);
    scene->addItem(rect);
    workstations.push_back(rect);

    rect = new QGraphicsRectItem(mult*(20+xorigin),mult*175+multy,mult*50,mult*25);
    rect->setBrush(*freeSpotColor);
    scene->addItem(rect);
    workstations.push_back(rect);

    rect = new QGraphicsRectItem(mult*(20+xorigin),mult*200+multy,mult*50,mult*25);
    rect->setBrush(*freeSpotColor);
    scene->addItem(rect);
    workstations.push_back(rect);

    rect = new QGraphicsRectItem(mult*(70+xorigin),mult*175+multy,mult*25,mult*50);
    rect->setBrush(*freeSpotColor);
    scene->addItem(rect);
    workstations.push_back(rect);

    rect = new QGraphicsRectItem(mult*(200+xorigin),mult*250+multy,mult*25,mult*50);
    rect->setBrush(*freeSpotColor);
    scene->addItem(rect);
    workstations.push_back(rect);

    rect = new QGraphicsRectItem(mult*(225+xorigin),mult*250+multy,mult*25,mult*50);
    rect->setBrush(*freeSpotColor);
    scene->addItem(rect);
    workstations.push_back(rect);

    rect = new QGraphicsRectItem(mult*(200+xorigin),mult*200+multy,mult*25,mult*50);
    rect->setBrush(*freeSpotColor);
    scene->addItem(rect);
    workstations.push_back(rect);

    rect = new QGraphicsRectItem(mult*(225+xorigin),mult*200+multy,mult*25,mult*50);
    rect->setBrush(*freeSpotColor);
    scene->addItem(rect);
    workstations.push_back(rect);

    rect = new QGraphicsRectItem(mult*(200+xorigin),mult*150+multy,mult*25,mult*50);
    rect->setBrush(*freeSpotColor);
    scene->addItem(rect);
    workstations.push_back(rect);

    rect = new QGraphicsRectItem(mult*(225+xorigin),mult*150+multy,mult*25,mult*50);
    rect->setBrush(*freeSpotColor);
    scene->addItem(rect);
    workstations.push_back(rect);

    const int a = 150;
    const int b = -10;
    rect = new QGraphicsRectItem(mult*(a+200+xorigin),mult*(b+250)+multy,mult*25,mult*50);
    rect->setBrush(*freeSpotColor);
    scene->addItem(rect);
    workstations.push_back(rect);

    rect = new QGraphicsRectItem(mult*a+mult*(225+xorigin),mult*b+mult*250+multy,mult*25,mult*50);
    rect->setBrush(*freeSpotColor);
    scene->addItem(rect);
    workstations.push_back(rect);

    rect = new QGraphicsRectItem(mult*a+mult*(200+xorigin),mult*b+mult*200+multy,mult*25,mult*50);
    rect->setBrush(*freeSpotColor);
    scene->addItem(rect);
    workstations.push_back(rect);

    rect = new QGraphicsRectItem(mult*a+mult*(225+xorigin),mult*b+mult*200+multy,mult*25,mult*50);
    rect->setBrush(*freeSpotColor);
    scene->addItem(rect);
    workstations.push_back(rect);

    rect = new QGraphicsRectItem(mult*a+mult*(200+xorigin),mult*b+mult*150+multy,mult*25,mult*50);
    rect->setBrush(*freeSpotColor);
    scene->addItem(rect);
    workstations.push_back(rect);

    rect = new QGraphicsRectItem(mult*a+mult*(225+xorigin),mult*b+mult*150+multy,mult*25,mult*50);
    rect->setBrush(*freeSpotColor);
    scene->addItem(rect);
    workstations.push_back(rect);

    rect = new QGraphicsRectItem(mult*(270+xorigin),mult*30+multy,mult*40,mult*20);
    rect->setBrush(*freeSpotColor);
    scene->addItem(rect);
    workstations.push_back(rect);

    rect = new QGraphicsRectItem(mult*(310+xorigin),mult*30+multy,mult*40,mult*20);
    rect->setBrush(*freeSpotColor);
    scene->addItem(rect);
    workstations.push_back(rect);

    rect = new QGraphicsRectItem(mult*(350+xorigin),mult*30+multy,mult*40,mult*20);
    rect->setBrush(*freeSpotColor);
    scene->addItem(rect);
    workstations.push_back(rect);

    rect = new QGraphicsRectItem(mult*(270+xorigin),mult*50+multy,mult*40,mult*20);
    rect->setBrush(*freeSpotColor);
    scene->addItem(rect);
    workstations.push_back(rect);

    rect = new QGraphicsRectItem(mult*(310+xorigin),mult*50+multy,mult*40,mult*20);
    rect->setBrush(*freeSpotColor);
    scene->addItem(rect);
    workstations.push_back(rect);

    rect = new QGraphicsRectItem(mult*(350+xorigin),mult*50+multy,mult*40,mult*20);
    rect->setBrush(*freeSpotColor);
    scene->addItem(rect);
    workstations.push_back(rect);


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



    positionsView->setScene(scene);


}

PositionsWindow::~PositionsWindow(){

    delete ui;
    delete freeSpotColor;
    delete notFreeSpotColor;
}

void PositionsWindow::changeColor(){

}

std::vector<QGraphicsRectItem*> PositionsWindow::GetWorkstations(){
    return workstations;
}

void PositionsWindow::mousePressEvent(QMouseEvent* event){
    QPointF position_old = event->localPos();
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
    delete new_position;
}

