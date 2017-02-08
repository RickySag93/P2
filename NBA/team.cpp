#include "team.h"


Team::Team(const Team & t)
{
    nome=t.getNome();
    city=t.getCity();
    conference=t.getConf();
    arena=t.getArena();
    coach=t.getCoach();
    fondazione=t.getFondaz();
    logo=t.getLogo();
    record=t.getRecord();
}


Team::Team()
{

}

Team::Team(QString nom, QString cit, QString conf, QString stadio, QString mimmo, int fond, QString img, int win, int lose)
{
    nome=nom;
    city=cit;
    conference=conf;
    arena=stadio;
    coach=mimmo;
    fondazione=fond;
    logo=img;
    record.setWin(win);
    record.setLose(lose);
}

QString Team::toString() const {return city+" "+nome;}
QString Team::getNome() const {return nome;}
QString Team::getCity() const {return city;}
QString Team::getArena() const {return arena;}
QString Team::getCoach() const {return coach;}
QString Team::getConf() const {return conference;}
int Team::getFondaz() const {return fondazione;}


QString Team::getLogo() const {return logo;}
Record Team::getRecord() const {return record;}

double Team::getPerc() const
{
    return record.getPerc();
}
void Team::setNome(QString n) {nome=n;}
void Team::setCity(QString n) {city=n;}
void Team::setArena(QString n) {arena=n;}
void Team::setCoach(QString n) {coach=n;}
void Team::setFondaz(int n) {fondazione=n;}
void Team::setLogo(QString n) {logo=n;}
void Team::setConf(QString c) {conference=c;}

void Team::aggiornaRecord(int g) {
    if (g==1) record.addWin();
    else record.addLose();
}











