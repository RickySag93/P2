#include "game.h"



Game::Game()
{

}

Game::Game(QString ho, QString a,QString l, int Hp, int Ap, int Hr, int Ar, int Ha, int Aa, double hfg, double afg, double h3p, double a3p, int y,int m,int d,int h,int min,QStringList htab,QStringList atab)
{
    home=ho;away=a;link=l;
    Hpts=Hp;Apts=Ap;
    Hreb=Hr;Areb=Ar;
    Hass=Ha;Aass=Aa;
    Hfg=hfg;Afg=afg;
    H3p=h3p;A3p=a3p;
    Htab=htab;Atab=atab;


    QDate* date=new QDate(y,m,d);
    QTime* t=new QTime(h,min,0);
    QDateTime* dt=new QDateTime(*date,*t);
    time=*dt;
}

QString Game::getHome() const {return home;}
QString Game::getAway() const {return away;}

QString Game::getLink() const
{
    return link;
}
int Game::getHpts() const {return Hpts;}
int Game::getApts() const {return Apts;}
int Game::getHreb() const {return Hreb;}
int Game::getAreb() const {return Areb;}
int Game::getHass() const {return Hass;}
int Game::getAass() const {return Aass;}
double Game::getHfg() const {return Hfg;}
double Game::getAfg() const {return Afg;}
double Game::getH3p() const {return H3p;}
double Game::getA3p() const {return A3p;}
QStringList Game::getHtab() const {return Htab;}
QStringList Game::getAtab() const {return Atab;}
QDateTime Game::getData() const {return time;}

void Game::setHome(QString t) {home=t;}
void Game::setAway(QString t) {away=t;}
void Game::setHpts(int n) {Hpts=n;}
void Game::setApts(int n) {Apts=n;}
void Game::setHreb(int n) {Hreb=n;}
void Game::setAreb(int n) {Areb=n;}
void Game::setHass(int n) {Hass=n;}
void Game::setAass(int n) {Aass=n;}
void Game::setHfg(double n) {Hfg=n;}
void Game::setAfg(double n) {Afg=n;}
void Game::setH3p(double n) {H3p=n;}
void Game::setA3p(double n) {A3p=n;}
void Game::setData(const QDateTime& d) {time=d;}




