#include <workstations.h>
#include <iostream>

Workstations::Workstations(QDate date) :
    currentDate(date){
    for (int i = 0; i < 32; i++){
        currentOrNextReservation[i] = NULL;
    }
}

void Workstations::setCurrentDate(QDate date){
    currentDate = date;
}

void Workstations::addGraphicItem(QGraphicsRectItem *item){
    workstations.push_back(item);
}

void Workstations::updateCurrentOrNextReservation(GenericList<Reservation> &list){
    for (int i = 0; i < 32; i++){
        if (currentOrNextReservation[i] != NULL)
            delete currentOrNextReservation[i];
        currentOrNextReservation[i] = NULL;
    }
    for (QList<Reservation>::Iterator iterator = list.getList().begin();
         iterator < list.getList().end(); iterator++){
        Reservation cur_user = *iterator;
        QDate beginDate = cur_user.getBeginDate();
        QDate endDate = cur_user.getEndDate();
        int targetWorkstation = cur_user.getWorkstation()-1;
        if (currentOrNextReservation[targetWorkstation] == NULL && (beginDate > currentDate || (beginDate<=currentDate &&
                                                                      endDate>=currentDate))){
            currentOrNextReservation[targetWorkstation] = new Reservation(cur_user);
        }
        else if (currentOrNextReservation[targetWorkstation] != NULL){
            Reservation cur_user2 = *currentOrNextReservation[targetWorkstation];
            if (beginDate>currentDate && cur_user2.getBeginDate()>beginDate){
                currentOrNextReservation[targetWorkstation] = new Reservation(cur_user);
            }
        }


    }
}

void Workstations::setToolTips(GenericList<Reservation>& list){
    updateCurrentOrNextReservation(list);
    int index = -1;
    for (std::vector<QGraphicsRectItem*>::iterator it = workstations.begin(); it < workstations.end(); it++){
        QGraphicsRectItem* curr = *it;
        index++;
        if (currentOrNextReservation[index] == NULL){
            curr->setToolTip("Libero sempre");
        }
        else {
            QDate beginDate = currentOrNextReservation[index]->getBeginDate();
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
                QDate endDate = currentOrNextReservation[index]->getEndDate();
                QString name;
                name.append(currentOrNextReservation[index]->getName()).append(" ").append(currentOrNextReservation[index]->getSurname());
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

void Workstations::colorItems(GenericList<Reservation> &list,
                              const QBrush availcolor, const QBrush notavailcolor){
    setToolTips(list);
    QList<Reservation>& userlist = list.getList();

    for (std::vector<QGraphicsRectItem*>::iterator iterator = workstations.begin();
         iterator < workstations.end(); iterator++){
        (*iterator)->setBrush(availcolor);
    }

    for (QList<Reservation>::Iterator iterator = userlist.begin();
         iterator < userlist.end(); iterator++){
        Reservation cur_user = *iterator;
        QDate beginDate(cur_user.getBeginYear(),cur_user.getBeginMonth(),cur_user.getBeginDay());
        QDate endDate(cur_user.getEndYear(),cur_user.getEndMonth(),cur_user.getEndDay());
        if ( currentDate>= beginDate && currentDate <= endDate){
            workstations.at(cur_user.getWorkstation()-1)->setBrush(notavailcolor);
        }
    }

}

void Workstations::colorItemsWithAvailability(GenericList<Reservation>& list,
                                const QBrush availcolor, const QBrush notavailperiodcolor,
                                QDate end_date){
    updateCurrentOrNextReservation(list);
    int i = 0;
    for (std::vector<QGraphicsRectItem*>::iterator iterator = workstations.begin();
         iterator < workstations.end(); iterator++){
        (*iterator)->setBrush(notavailperiodcolor);
        if (currentOrNextReservation[i] == NULL){
            (*iterator)->setBrush(availcolor);
        } else if (end_date<currentOrNextReservation[i]->getBeginDate()){
            (*iterator)->setBrush(availcolor);
        }
        i++;
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

Reservation* Workstations::userInPosition(int pos){
    return currentOrNextReservation[pos-1];
}

bool Workstations::isWorkstationOfThatColor(int number, QBrush color){
    return (workstations.at(number-1)->brush() == color);
}

QDate Workstations::freeUntil(int index){
    if (currentOrNextReservation[index-1] == NULL){
        return {1992,11,5};
    }
    std::cout<< currentOrNextReservation[index-1]->getBeginDate().day()<<std::endl;
    return currentOrNextReservation[index-1]->getBeginDate();
}
