#include <workstations.h>
#include <iostream>

Workstations::Workstations(QDate date) :
    currentDate(date){}

void Workstations::setCurrentDate(QDate date){
    currentDate = date;
}

void Workstations::addGraphicItem(QGraphicsRectItem *item){
    workstations.push_back(item);
}

void Workstations::colorItems(UsersList &list,
                              const QBrush availcolor, const QBrush notavailcolor){
    QList<User>& userlist = list.getList();

    for (std::vector<QGraphicsRectItem*>::iterator iterator = workstations.begin();
         iterator < workstations.end(); iterator++){
        (*iterator)->setBrush(availcolor);
    }

    for (QList<User>::Iterator iterator = userlist.begin();
         iterator < userlist.end(); iterator++){
        User cur_user = *iterator;
        QDate beginDate(cur_user.getBeginYear(),cur_user.getBeginMonth(),cur_user.getBeginDay());
        QDate endDate(cur_user.getEndYear(),cur_user.getEndMonth(),cur_user.getEndDay());
        if ( currentDate>= beginDate && currentDate <= endDate){
            workstations.at(cur_user.getWorkstation()-1)->setBrush(notavailcolor);
        }
    }

}

int Workstations::pointIsContainedInWorkstationN(QPointF point){
    int i = 0;
    for (std::vector<QGraphicsRectItem*>::iterator iterator = workstations.begin();
         iterator < workstations.end(); iterator++){
        i++;
        QGraphicsRectItem* rect = *iterator;
        if (rect->contains(point)){
            break;
        }
    }
    return (i<workstations.size() ? i : -1);
}

bool Workstations::isWorkstationOfThatColor(int number, QBrush color){
    return (workstations.at(number-1)->brush() == color);
}
