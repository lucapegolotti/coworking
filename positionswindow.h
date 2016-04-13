#ifndef POSITIONSWINDOW_H
#define POSITIONSWINDOW_H

#include <QMainWindow>
#include <QGraphicsRectItem>
#include <vector>
#include <QMouseEvent>
#include <ctime>
#include <iostream>

namespace Ui {
class PositionsWindow;
}

class PositionsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PositionsWindow(QWidget *parent = 0);

    ~PositionsWindow();

    std::vector<QGraphicsRectItem*> GetWorkstations();

    void mousePressEvent(QMouseEvent* event);

public slots:
    void changeColor();

private:
    Ui::PositionsWindow *ui;

    std::vector<QGraphicsRectItem*> workstations;

    QColor* freeSpotColor;

    QColor* notFreeSpotColor;

    void setTime();



};

#endif // POSITIONSWINDOW_H
