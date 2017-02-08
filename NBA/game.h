#ifndef GAME_H
#define GAME_H

#include <QVector>
#include <QDateTime>
#include <QStringList>
#include "team.h"
//#include "player.h"

class Game
{
private:
    QString home, away,link;
    int Hpts,Apts,Hreb,Areb,Hass,Aass;
    double Hfg,Afg,H3p,A3p;
    QStringList Htab,Atab;
    QDateTime time;
public:
    Game();
    Game(QString ho,QString a,QString l,int Hp,int Ap,int Hr,int Ar,int Ha,int Aa,double hfg,double afg,double h3p,double a3p,int y,int m,int d,int h,int min,QStringList htab,QStringList atab);
    QString getHome() const;
    QString getAway() const;
    QString getLink() const;
    int getHpts() const;
    int getApts() const;
    int getHreb() const;
    int getAreb() const;
    int getHass() const;
    int getAass() const;
    double getHfg() const;
    double getAfg() const;
    double getH3p() const;
    double getA3p() const;
    QStringList getHtab() const;
    QStringList getAtab() const;
    QDateTime getData() const;

    void setHome(QString) ;
    void setAway(QString) ;
    void setHpts(int) ;
    void setApts(int) ;
    void setHreb(int) ;
    void setAreb(int) ;
    void setHass(int) ;
    void setAass(int) ;
    void setAfoul(int) ;
    void setHfg(double) ;
    void setAfg(double) ;
    void setH3p(double) ;
    void setA3p(double) ;
    void setData(const QDateTime&) ;

};

#endif // GAME_H
