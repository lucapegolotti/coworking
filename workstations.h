#ifndef WORKSTATIONS_H
#define WORKSTATIONS_H

#include <userslist.h>
#include <QGraphicsRectItem>
#include <QList>
#include <QColor>
#include <QBrush>
#include <date.h>
#include <QDate>
#include <user.h>
class Workstations{
 public:

    Workstations(QDate date);

    void setCurrentDate(QDate date);

    void addGraphicItem(QGraphicsRectItem* item);

    void colorItems(UsersList& list,
                    const QBrush availcolor, const QBrush notavailcolor);

    int pointIsContainedInWorkstationN(QPointF point);

    bool isWorkstationOfThatColor(int number, QBrush color);

    void updateCurrentOrNextUser(UsersList &list);

    void setToolTips(UsersList &list);


 private:
    std::vector<QGraphicsRectItem*> workstations;

    User* currentOrNextUser[32];

    QDate currentDate;

};

#endif // WORKSTATIONS_H
