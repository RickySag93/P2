#ifndef RECORD_H
#define RECORD_H
#include <QString>
#include <QDebug>

class Record
{
private:
    double win,lose;
public:
    Record();
    Record(double,double);
    Record(const Record&);
    QString getWin() const;
    QString getLose() const;
    QString toString();
    void addWin();
    void addLose();
    void setWin(double);
    void setLose(double);
    double getPerc() const;

};

#endif // RECORD_H
