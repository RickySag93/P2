#ifndef UTENTEPREM_H
#define UTENTEPREM_H
#include "utente.h"
#include <QDate>

class UtentePrem : public Utente
{
private:
    QDate scadenza;
public:
    UtentePrem();
    UtentePrem(QString,QString,QDate);
    QDate getScadenza() const;
    void setScadenza(QDate);
    bool isPremium() const;

};

#endif // UTENTEPREM_H
