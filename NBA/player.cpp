#include "player.h"

Player::Player()
{

}

Player::Player(QString n, QString c, QString sq, QString f, int anno, int mese, int giorno, int mP, int mR, int mA, double sP, double sR, double sA)
{
    nome=n;cognome=c;foto=f;birthday=QDate(anno,mese,giorno);
    maxPts=mP;maxReb=mR;maxAss=mA;
    SeasonPts=sP;SeasonReb=sR;SeasonAss=sA;
    team=sq;
}



Player::Player(const Player &pl)
{
    nome=pl.getNome();cognome=pl.getCognome();birthday=pl.getBirthday();
    maxPts=pl.getMaxPts();maxReb=pl.getMaxReb();maxAss=pl.getMaxAss();
    SeasonPts=pl.getSeasPts();SeasonReb=pl.getSeasReb();SeasonAss=pl.getSeasAss();
    team=pl.getTeam();foto=pl.getFoto();
}

QString Player::getNome() const
{
    return nome;
}

QString Player::getCognome() const
{
    return cognome;
}

QString Player::getFoto() const
{
    return foto;
}

QDate Player::getBirthday() const {return birthday;}
QString Player::getTeam() const {return team;}

int Player::getMaxPts() const {return maxPts;}
int Player::getMaxReb() const {return maxReb;}
int Player::getMaxAss() const {return maxAss;}

double Player::getSeasPts() const {return SeasonPts;}
double Player::getSeasReb() const {return SeasonReb;}
double Player::getSeasAss() const {return SeasonAss;}

void Player::setTeam(QString t) {team=t;}
