#ifndef DATA_H
#define DATA_H
#include <QVector>
#include <QXmlStreamReader>
#include <QString>
#include <team.h>
#include "utente.h"
#include "utenteprem.h"
#include "game.h"
#include "player.h"
#include "QFile"
#include <QDebug>

class Data
{
private:
    QVector<Player*> allPlayer;
    QVector<Team*> allTeam;
    QVector<Utente*> allUser;
    QVector<Game*> allGame;
    Utente* utente;
    static bool primo;
    static QString file_data_team,file_data_player,file_data_user,file_data_game;

public:
    Data();
    QVector<Player*> getListaPlayers() const;
    QVector<Team*> getListaTeam() const;
    QVector<Utente*> getListaUtenti() const;
    QVector<Game*> getListaGame() const;
    QString getFileDataTeam() const;
    QString getFileDataPlayer() const;
    QString getFileDataUser() const;
    QString getFileDataGame() const;
    Utente* getUtente() const;
    void setUtente(Utente *);
    void loadTeam(QString);
    void loadPlayer(QString);
    void loadUser(QString);
    void loadGame(QString);
    Game *searchGame(QString, QDate date) const;
    Team* findTeam(const QString&) const;
    bool findPlayer(QString,QString) const;
    Utente* findUser(const QString&) const;
    void deleteTutto();
    void ordinaTeam(Team*);
    ~Data();
};

#endif // DATA_H
