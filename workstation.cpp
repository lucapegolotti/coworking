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

void Workstations::updateCurrentOrNextUser(UsersList &list){
    for (int i = 0; i < 32; i++){
        currentOrNextUser[i] = NULL;
    }
    for (QList<User>::Iterator iterator = list.getList().begin();
         iterator < list.getList().end(); iterator++){
        User cur_user = *iterator;
        QDate beginDate = cur_user.getBeginDate();
        QDate endDate = cur_user.getEndDate();
        int targetWorkstation = cur_user.getWorkstation()-1;
        if (currentOrNextUser[targetWorkstation] == NULL && (beginDate > currentDate || (beginDate<=currentDate &&
                                                                      endDate>=currentDate))){
            currentOrNextUser[targetWorkstation] = &(*iterator);
        }
        else if (currentOrNextUser[targetWorkstation] != NULL){
            User cur_user2 = *currentOrNextUser[targetWorkstation];
            if (beginDate>currentDate && cur_user2.getBeginDate()>beginDate){
                currentOrNextUser[targetWorkstation] = &(*iterator);
            }
        }


    }
}

void Workstations::setToolTips(UsersList& list){
    updateCurrentOrNextUser(list);
    int index = -1;
    for (std::vector<QGraphicsRectItem*>::iterator it = workstations.begin(); it < workstations.end(); it++){
        QGraphicsRectItem* curr = *it;
        index++;
        if (currentOrNextUser[index] == NULL){
            curr->setToolTip("Libero sempre");
        }
        else {
            QDate beginDate = currentOrNextUser[index]->getBeginDate();
            if (beginDate>currentDate){
                QString tooltip = "Libero fino al ";
                tooltip.append(QString::number(beginDate.day()))
                       .append("/")
                       .append(QString::number(beginDate.month()))
                       .append("/")
                       .append(QString::number(beginDate.year()));

                curr->setToolTip(tooltip);
            }
            else{
                QDate endDate = currentOrNextUser[index]->getEndDate();
                QString name;
                name.append(currentOrNextUser[index]->getName()).append(" ").append(currentOrNextUser[index]->getSurname());
                QString tooltip = "Occupato da ";
                tooltip.append(name).append(" fino al ");
                tooltip.append(QString::number(endDate.day()))
                       .append("/")
                       .append(QString::number(endDate.month()))
                       .append("/")
                       .append(QString::number(endDate.year()));
                curr->setToolTip(tooltip);
            }
        }

    }
}

void Workstations::colorItems(UsersList &list,
                              const QBrush availcolor, const QBrush notavailcolor){
    setToolTips(list);
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

void Workstations::colorItemsWithAvailability(UsersList& list,
                                const QBrush availcolor, const QBrush notavailcolor, const QBrush notavailperiodcolor,
                                QDate end_date){
    QList<User>& userlist = list.getList();
    updateCurrentOrNextUser(list);
    int i = 0;
    for (std::vector<QGraphicsRectItem*>::iterator iterator = workstations.begin();
         iterator < workstations.end(); iterator++){
        (*iterator)->setBrush(notavailperiodcolor);
        if (currentOrNextUser[i] == NULL){
            (*iterator)->setBrush(availcolor);
        } else if (end_date<currentOrNextUser[i]->getBeginDate()){
            (*iterator)->setBrush(availcolor);
        }
        i++;
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
    bool aux = false;
    for (std::vector<QGraphicsRectItem*>::iterator iterator = workstations.begin();
         iterator < workstations.end(); iterator++){
        i++;
        QGraphicsRectItem* rect = *iterator;
        if (rect->contains(point)){
            aux = true;
            break;
        }
    }
    return (aux ? i : -1);
}

User* Workstations::userInPosition(int pos){
    return currentOrNextUser[pos-1];
}

bool Workstations::isWorkstationOfThatColor(int number, QBrush color){
    return (workstations.at(number-1)->brush() == color);
}

QDate Workstations::freeUntil(int index){
    if (currentOrNextUser[index-1] == NULL){
        return {1992,11,5};
    }
    std::cout<< currentOrNextUser[index-1]->getBeginDate().day()<<std::endl;
    return currentOrNextUser[index-1]->getBeginDate();
}
