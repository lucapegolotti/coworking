#include <workstations.h>
#include <iostream>

void Workstations::addGraphicItem(QGraphicsRectItem *item){
    workstations.push_back(item);
}

void Workstations::colorItems(UsersList &list, QDate date,
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
        if ( date>= beginDate && date <= endDate){
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
        std::cout << rect->pos().rx()  <<"," << rect->pos().ry()<< std::endl;
        if (rect->contains(point)){
            break;
        }
    }
    std::cout << point.rx() << ","<< point.ry() << std::endl;
    return (i<workstations.size() ? i : -1);
}
