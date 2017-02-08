#ifndef TEAM_H
#define TEAM_H
#include <QString>
#include <QImage>
#include <QVector>
#include <QDebug>
#include "record.h"
#include "player.h"

class Team
{
private:
    QString nome,city,arena,coach,logo,conference;
    int fondazione;
    Record record;
public:
    Team();
    Team(QString nom,QString cit,QString conf,QString stadio,QString mimmo,int fond,QString img,int win,int lose);
    Team(const Team&);
    QString toString() const;
    QString getNome() const;
    QString getCity() const;
    QString getArena() const;
    QString getCoach() const;
    QString getConf() const;
    int getFondaz() const;
    QString getLogo() const;
    Record getRecord() const;
    double getPerc() const;
    void setNome(QString);
    void setCity(QString);
    void setArena(QString);
    void setCoach(QString);
    void setFondaz(int);
    void setLogo(QString);
    void setConf(QString);
    void aggiornaRecord(int);

};




#endif // TEAM_H
