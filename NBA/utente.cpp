#include "utente.h"

 Utente::Utente()
{
    username="guest";
    password="guest";
}

Utente::Utente(QString u, QString p) {
    username=u;password=p;

}

QString Utente::getUsername() const {return username;}
QString Utente::getPassword() const {return password;}


void Utente::setUsername(QString p) {username=p;}
void Utente::setPassword(QString p) {password=p;}

bool Utente::operator==(Utente &u) const
{
    return username==u.getUsername()&&password==u.getPassword();
}

bool Utente::isPremium() const
{
    return false;
}

Utente::~Utente()
{

}
