#ifndef CHECKAVAILABILITY_H
#define CHECKAVAILABILITY_H

#include <QDialog>

namespace Ui {
class CheckAvailability;
}

class CheckAvailability : public QDialog
{
    Q_OBJECT

public:
    CheckAvailability(QDate current_date,QWidget *parent = 0);
    ~CheckAvailability();

private slots:
    void on_beginDateEdit_dateChanged(const QDate &date);

    void on_endDateEdit_dateChanged(const QDate &date);

signals:
    void beginDateChangedSignal(const QDate& date);
    void endDateChangedSignal(const QDate& date);

private:
    Ui::CheckAvailability *ui;
};

#endif // CHECKAVAILABILITY_H
