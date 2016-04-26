#include <reservationslist.h>

QList<Reservation>& ReservationsList::getList(){
    return list;
}

void ReservationsList::addUser(Reservation user){
    list.push_front(user);
}

int ReservationsList::numberUsers(){
    return list.size();
}

void ReservationsList::read(const QJsonObject& json){
    list.clear();
    QJsonArray us_array = json["rsv"].toArray();
    for (int i = 0; i < us_array.size(); i++){
        QJsonObject obj = us_array[i].toObject();
        Reservation user;
        user.read(obj);
        list.append(user);
    }
}

void ReservationsList::modifyUser(const Reservation &old_user,const Reservation& new_user){
    list.removeOne(old_user);
    list.push_front(new_user);
}

void ReservationsList::deleteUser(const Reservation &user){
    list.removeOne(user);
}


void ReservationsList::write(QJsonObject& json) const{
    QJsonArray us_array;
    foreach( const Reservation user, list){
        QJsonObject obj;
        user.write(obj);
        us_array.append(obj);
    }
    json["users"] = us_array;
}

bool ReservationsList::saveData(QString format){
    QFile sfile( format == "json" ?
                     QStringLiteral("prenotazioni.json") :
                     QStringLiteral("prenotazioni.dat"));

    if (!sfile.open(QIODevice::WriteOnly)){
        qWarning("Could not open file");
        return false;
    }

    QJsonObject json;
    write(json);
    QJsonDocument saveDoc(json);
    sfile.write( format == "json" ?
                     saveDoc.toJson() :
                     saveDoc.toBinaryData());


    return true;

}

bool ReservationsList::loadData(QString format){
    QFile lfile( format == "json" ?
                     QStringLiteral("prenotazioni.json") :
                     QStringLiteral("prenotazioni.dat"));

    if (!lfile.open(QIODevice::ReadOnly)){
        qWarning("Could not open file");
        return false;
    }

    QByteArray savedata = lfile.readAll();


    QJsonDocument loaddoc(format == "json"?
                              QJsonDocument::fromJson(savedata) :
                              QJsonDocument::fromBinaryData(savedata));


    read(loaddoc.object());

    return true;

}
