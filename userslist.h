#ifndef USERSLIST_H
#define USERSLIST_H

#include <user.h>
#include <Qt>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>

class UsersList {
 public:
    QList<User>& getList();

    void addUser(User user);

    void modifyUser(const User& old_user,const User &new_user);

    void deleteUser(const User& user);

    int numberUsers();

    void read(const QJsonObject& json);

    void write(QJsonObject& json) const;

    bool saveData(QString format);

    bool loadData(QString format);

 private:
    QList<User> list;
};

#endif // USERSLIST_H
