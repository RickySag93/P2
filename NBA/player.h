#ifndef PLAYER_H
#define PLAYER_H
#include <QString>
#include <QDate>

class Player
{
private:
    QString nome, cognome,team,foto;
    QDate birthday;
    int maxPts,maxReb,maxAss;
    double SeasonPts, SeasonReb,SeasonAss;

public:
    Player();
    Player(QString n, QString c,QString sq,QString f, int anno,int mese,int giorno, int mP, int mR, int mA, double sP, double sR, double sA);
    Player(const Player&pl);
    QString getNome() const;
    QString getCognome() const;
    QString getFoto() const;
    QDate getBirthday() const;
    QString getTeam() const;
    int getMaxPts() const;
    int getMaxReb() const;
    int getMaxAss() const;
    double getSeasPts() const;
    double getSeasReb() const;
    double getSeasAss() const;
    void setTeam(QString) ;
};

#endif // PLAYER_H
