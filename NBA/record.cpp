#include "record.h"

Record::Record() {}

Record::Record(double w, double l): win(w),lose(l) {}

Record::Record(const Record &r)
{
    win=r.win;
    lose=r.lose;
}

QString Record::getWin() const
{
    return QString::number(win);
}

QString Record::getLose() const
{
    return QString::number(lose);
}


void Record::addWin()
{
    ++win;
}

void Record::addLose()
{
    ++lose;
}

void Record::setWin(double w)
{
    win=w;
}

void Record::setLose(double l)
{
    lose=l;
}

double Record::getPerc() const
{
    double ris=win/(win+lose);
    return ris;
}

