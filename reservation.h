#ifndef USER_H
#define USER_H

#include <QUuid>
#include <QString>
#include <QJsonObject>
#include <QDate>

class Reservation {
 public:

    Reservation();

    Reservation(QString name, QString surname, QString whopays, int workstation,
         float tariff, int hourLeft, bool alldayacc, bool deposit,
         bool ethernet, QDate beginDate, QDate endDate);

    void setName(QString name);

    void setSurname(QString surname);

    void setWhoPays(QString who);

    void setWorkstation(int workstation);

    void setDailyTariff(float tariff);

    void detractMeetingroomHours(int hoursSpent);

    void setAllDayAccess(bool value);

    void setDepositKey(bool value);

    void setEthernet(bool value);

    void setBeginDate(int day, int month, int year);

    void setEndDate(int day, int month, int year);

    QString getName() const;

    QString getSurname() const;

    QString getWhoPays() const;

    int getWorkstation() const;

    float getDailyTariff() const;

    int getMeetingroomHourse() const;

    bool getAllDayAccess() const;

    bool getDepositKey() const;

    bool getEthernet() const;

    int getBeginDay() const;

    int getBeginMonth() const;

    int getBeginYear() const;

    QDate getBeginDate() const;

    int getEndDay() const;

    int getEndMonth() const;

    int getEndYear() const;

    QDate getEndDate() const;

    void read(const QJsonObject& json);

    void write(QJsonObject& json) const;

    bool operator==(const Reservation& other) const;

 private:

    QString name;

    QString surname;

    QString whoPays;

    int workstation;

    float dailyTariff;

    int meetingroomHoursLeft;

    // booleans
    bool allDayAccess;

    bool depositKey;

    bool ethernet;

    // dates
    int beginDay;

    int beginMonth;

    int beginYear;

    int endDay;

    int endMonth;

    int endYear;

};

#endif // USER_H
