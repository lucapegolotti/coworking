#ifndef USER_H
#define USER_H

#include <QUuid>
#include <QString>
#include <QJsonObject>

class User {
 public:

    User();

    void setName(QString name);

    void setSurname(QString surname);

    void setWhoPays(QString who);

    void setDailyTariff(float tariff);

    void detractMeetingroomHours(int hoursSpent);

    void setAllDayAccess(bool value);

    void setDepositKey(bool value);

    void setEthernet(bool value);

    void setTelephone(bool value);

    void setBeginDate(int day, int month, int year);

    void setEndDate(int day, int month, int year);

    QString getName();

    QString getSurname();

    QString getWhoPays();

    float getDailyTariff();

    int getMeetingroomHourse();

    bool getAllDayAccess();

    bool getDepositKey();

    bool getEthernet();

    bool getTelephone();

    int getBeginDay();

    int getBeginMonth();

    int getBeginYear();

    int getEndDay();

    int getEndMonth();

    int getEndYear();

    void read(const QJsonObject& json);

    void write(QJsonObject& json) const;




 private:

    QString name;

    QString surname;

    QString whoPays;

    float dailyTariff;

    int meetingroomHoursLeft;

    // booleans
    bool allDayAccess;
    bool depositKey;
    bool ethernet;
    bool telephone;

    // dates
    int beginDay;
    int beginMonth;
    int beginYear;

    int endDay;
    int endMonth;
    int endYear;

};

#endif // USER_H
