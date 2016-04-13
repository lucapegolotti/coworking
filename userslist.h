#ifndef USERSLIST_H
#define USERSLIST_H

#include <user.h>
#include <Qt>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>

class UsersList {
 public:
    void addUser(User user);

    int numberUsers();

    void read(const QJsonObject& json);

    void write(QJsonObject& json) const;

    bool saveData();

    bool loadData();

 private:
    QList<User> list;
};

#endif // USERSLIST_H
