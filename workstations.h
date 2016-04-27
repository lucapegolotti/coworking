#ifndef WORKSTATIONS_H
#define WORKSTATIONS_H

#include <reservationslist.h>
#include <QGraphicsRectItem>
#include <QList>
#include <QColor>
#include <QBrush>
#include <QDate>
#include <reservation.h>
class Workstations{
 public:

    Workstations(QDate date);

    void setCurrentDate(QDate date);

    void addGraphicItem(QGraphicsRectItem* item);

    void colorItems(ReservationsList& list,
                    const QBrush availcolor, const QBrush notavailcolor);

    void colorItemsWithAvailability(ReservationsList& list,
                                    const QBrush availcolor, const QBrush notavailperiodcolor,
                                    QDate end_date);

    int pointIsContainedInWorkstationN(QPointF point);

    bool isWorkstationOfThatColor(int number, QBrush color);

    void updateCurrentOrNextUser(ReservationsList &list);

    void setToolTips(ReservationsList &list);

    Reservation* userInPosition(int pos);

    QDate freeUntil(int index);


 private:
    std::vector<QGraphicsRectItem*> workstations;

    Reservation* currentOrNextUser[32];

    QDate currentDate;

};

#endif // WORKSTATIONS_H
