#ifndef WORKSTATIONS_H
#define WORKSTATIONS_H

#include <userslist.h>
#include <QGraphicsRectItem>
#include <QList>
#include <QColor>
#include <QBrush>
#include <date.h>
#include <QDate>
class Workstations{
 public:

    void addGraphicItem(QGraphicsRectItem* item);

    void colorItems(UsersList& list, QDate date,
                    const QBrush availcolor, const QBrush notavailcolor);

    int pointIsContainedInWorkstationN(QPointF point);


 private:
    std::vector<QGraphicsRectItem*> workstations;

};

#endif // WORKSTATIONS_H
