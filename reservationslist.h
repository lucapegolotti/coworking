#ifndef USERSLIST_H
#define USERSLIST_H

#include <reservation.h>
#include <Qt>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>

class ReservationsList {
 public:
    QList<Reservation>& getList();

    void addUser(Reservation user);

    void modifyUser(const Reservation& old_user,const Reservation &new_user);

    void deleteUser(const Reservation& user);

    int numberUsers();

    void read(const QJsonObject& json);

    void write(QJsonObject& json) const;

    bool saveData(QString format);

    bool loadData(QString format);

 private:
    QList<Reservation> list;
};

#endif // USERSLIST_H
