#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "data.h"
#include "team.h"
#include <QDebug>
class Controller
{
private:
    Data data;
public:
    Controller(int i=0);
    Data& getData();

    Game *searchGame(QString, QDate) const;
    Team* findTeam(const QString&) const;
    bool findPlayer(QString,QString) const;
    Utente* findUser(const QString&) const;
    QString getLogo(QString) const;


    Utente* getUtente() const;
    void setUtente(Utente*);
};

#endif // CONTROLLER_H
