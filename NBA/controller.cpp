#include "controller.h"
Controller::Controller(int i)
{
    data.loadTeam(data.getFileDataTeam());
    data.loadPlayer(data.getFileDataPlayer());
    data.loadUser(data.getFileDataUser());
    data.loadGame(data.getFileDataGame());
    data.setUtente(data.getListaUtenti().at(i));//qDebug()<<data.getUtente()->getUsername();
}
Data& Controller::getData()  {return data;}

Game *Controller::searchGame(QString away, QDate date) const
{
    return data.searchGame(away,date);
}

Team *Controller::findTeam(const QString &s) const
{
    return data.findTeam(s);
}

bool Controller::findPlayer(QString a, QString b) const
{
    return data.findPlayer(a,b);
}

Utente *Controller::findUser(const QString &u) const
{
    return data.findUser(u);
}

QString Controller::getLogo(QString nome) const
{
    for(int i=0;i<data.getListaTeam().size();i++)
        if(data.getListaTeam().at(i)->getNome()==nome) return data.getListaTeam().at(i)->getLogo();
    return "";
}


Utente *Controller::getUtente() const
{
    return data.getUtente();
}

void Controller::setUtente(Utente *u)
{
    data.setUtente(u);
}
