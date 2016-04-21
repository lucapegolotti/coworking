#include <userslist.h>

QList<User>& UsersList::getList(){
    return list;
}

void UsersList::addUser(User user){
    list.push_front(user);
}

int UsersList::numberUsers(){
    return list.size();
}

void UsersList::read(const QJsonObject& json){
    list.clear();
    QJsonArray us_array = json["users"].toArray();
    for (int i = 0; i < us_array.size(); i++){
        QJsonObject obj = us_array[i].toObject();
        User user;
        user.read(obj);
        list.append(user);
    }
}

void UsersList::modifyUser(const User &old_user,const User& new_user){
    list.removeOne(old_user);
    list.push_front(new_user);
}

void UsersList::deleteUser(const User &user){
    list.removeOne(user);
}


void UsersList::write(QJsonObject& json) const{
    QJsonArray us_array;
    foreach( const User user, list){
        QJsonObject obj;
        user.write(obj);
        us_array.append(obj);
    }
    json["users"] = us_array;
}

bool UsersList::saveData(QString format){
    QFile sfile( format == "json" ?
                     QStringLiteral("utenti.json") :
                     QStringLiteral("utenti.dat"));

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

bool UsersList::loadData(QString format){
    QFile lfile( format == "json" ?
                     QStringLiteral("utenti.json") :
                     QStringLiteral("utenti.dat"));

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
