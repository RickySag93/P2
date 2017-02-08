#include "utenteprem.h"

UtentePrem::UtentePrem()
{

}

UtentePrem::UtentePrem(QString u, QString s, QDate d): Utente(u,s),scadenza(d) {}


QDate UtentePrem::getScadenza() const
{
    return scadenza;
}

void UtentePrem::setScadenza(QDate d)
{
    scadenza=d;
}

bool UtentePrem::isPremium() const
{
    return true;
}
