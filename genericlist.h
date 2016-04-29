#ifndef GENERICLIST_H
#define GENERICLIST_H

#include <Qt>
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

template <class Data>
class GenericList {
 public:

    QList<Data>& getList();

    void addElement(Data user);

    void modifyElement(const Data old_data,const Data new_data);

    void deleteElement(const Data data);

    int numberElements();

    void read(const QJsonObject& json);

    void write(QJsonObject& json) const;

    bool saveData(QString format);

    bool loadData(QString format);

 private:

    QList<Data> list;
};

#include <genericlist-inl.h>

#endif // GENERICSLIST_H
