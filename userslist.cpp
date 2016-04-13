#include <userslist.h>

void UsersList::addUser(User user){
    list.append(user);
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

void UsersList::write(QJsonObject& json) const{
    QJsonArray us_array;
    foreach( const User user, list){
        QJsonObject obj;
        user.write(obj);
        us_array.append(obj);
    }
    json["users"] = us_array;
}

bool UsersList::saveData(){
    QFile sfile("utenti.dat");

    if (!sfile.open(QIODevice::WriteOnly)){
        qWarning("Could not open file");
        return false;
    }

    QJsonObject json;
    write(json);
    QJsonDocument saveDoc(json);
    sfile.write(saveDoc.toBinaryData());

    return true;

}

bool UsersList::loadData(){
    QFile lfile("utenti.dat");

    if (!lfile.open(QIODevice::WriteOnly)){
        qWarning("Could not open file");
        return false;
    }

    QByteArray savedata = lfile.readAll();


    QJsonDocument loaddoc(QJsonDocument::fromBinaryData(savedata));

    read(loaddoc.object());

    return true;

}
