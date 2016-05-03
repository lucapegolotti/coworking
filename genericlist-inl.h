#ifndef GENERICLISTINL_H
#define GENERICLISTINL_H

#include <QString>

template<class Data>
QList<Data>& GenericList<Data>::getList(){
    return list;
}

template <class Data>
void GenericList<Data>::addElement(Data user) {
    list.push_front(user);
}

template<class Data>
int GenericList<Data>::numberElements(){
    return list.size();
}

template<class Data>
void GenericList<Data>::read(const QJsonObject& json){
    list.clear();
    QJsonArray us_array = json["rsv"].toArray();
    for (int i = 0; i < us_array.size(); i++){
        QJsonObject obj = us_array[i].toObject();
        Data data;
        data.read(obj);
        list.append(data);
    }
}

template<class Data>
void GenericList<Data>::modifyElement(const Data old_element,const Data new_element){
    list.removeOne(old_element);
    list.push_front(new_element);
}

template<class Data>
void GenericList<Data>::deleteElement(const Data element){
    list.removeOne(element);
}

template<class Data>
void GenericList<Data>::write(QJsonObject& json) const{
    QJsonArray us_array;
    foreach( const Data element, list){
        QJsonObject obj;
        element.write(obj);
        us_array.append(obj);
    }
    json["rsv"] = us_array;
}

template<class Data>
bool GenericList<Data>::saveData(QString format, QString filename){
    filename.append(".").append(format);
    QFile sfile(filename);

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

template<class Data>
bool GenericList<Data>::loadData(QString format, QString filename){

    filename.append(".").append(format);
    QFile lfile(filename);

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


#endif // GENERICLISTINL_H
