#include "data.h"

bool Data::primo=true;
QString Data::file_data_team="../NBA/squadre.xml";
QString Data::file_data_player="../NBA/giocatori.xml";
QString Data::file_data_user="../NBA/utenti.xml";
QString Data::file_data_game="../NBA/result.xml";

Data::Data()
{
}

QVector<Player *> Data::getListaPlayers() const
{
    return allPlayer;
}

QVector<Team *> Data::getListaTeam() const
{
    return allTeam;
}

QVector<Utente*> Data::getListaUtenti() const
{
    return allUser;
}

QVector<Game *> Data::getListaGame() const
{
    return allGame;
}

QString Data::getFileDataTeam() const
{
    return file_data_team;
}

QString Data::getFileDataPlayer() const
{
    return file_data_player;
}

QString Data::getFileDataUser() const
{
    return file_data_user;
}

QString Data::getFileDataGame() const
{
    return file_data_game;
}

Utente* Data::getUtente() const
{
    return utente;
}

void Data::setUtente(Utente *u)
{
    utente=u;
}

void Data::loadTeam(QString path)
{
    if(!primo) allTeam.clear();
    else primo=false;
    QFile file(path);
    QString name,citta,conf,stadio,allenatore,img;
    int fondaz=0,w=0,l=0;
    if(file.open(QFile::ReadOnly)) {
        QXmlStreamReader xmlStreamReader(&file);
        xmlStreamReader.readNext();
        while(!xmlStreamReader.atEnd()) {
            if(xmlStreamReader.isStartElement()) {
                if(xmlStreamReader.name()=="nome") {name=xmlStreamReader.readElementText();}
                if(xmlStreamReader.name()=="city") {citta=xmlStreamReader.readElementText();}
                if(xmlStreamReader.name()=="conference") {conf=xmlStreamReader.readElementText();}
                if(xmlStreamReader.name()=="arena") {stadio=xmlStreamReader.readElementText();}
                if(xmlStreamReader.name()=="coach") {allenatore=xmlStreamReader.readElementText();}
                if(xmlStreamReader.name()=="anno") {fondaz=xmlStreamReader.readElementText().toInt();}
                if(xmlStreamReader.name()=="logo") {img=xmlStreamReader.readElementText();}
                if(xmlStreamReader.name()=="win") {w=xmlStreamReader.readElementText().toInt();}
                if(xmlStreamReader.name()=="lose") {
                    l=xmlStreamReader.readElementText().toInt();
                    Team* t=new Team(name,citta,conf,stadio,allenatore,fondaz,img,w,l);
                    ordinaTeam(t);//qDebug()<<citta<<name<<conf;
                }
        }
        xmlStreamReader.readNext();
        }
        file.close();
    }

}

void Data::loadPlayer(QString path)
{
    QFile file(path);
    QString nome, cognome,team,foto;
    int anno=0,mese=0,giorno=0;
    int maxpts=0,maxreb=0,maxass=0;
    double seaspts=0,seasreb=0,seasass=0;
    if(file.open(QFile::ReadOnly)) {
        QXmlStreamReader xmlStreamReader(&file);
        xmlStreamReader.readNext();
        while(!xmlStreamReader.atEnd()) {
            if(xmlStreamReader.isStartElement()) {
                if(xmlStreamReader.name()=="nome") nome=xmlStreamReader.readElementText();
                if(xmlStreamReader.name()=="cognome") cognome=xmlStreamReader.readElementText();
                if(xmlStreamReader.name()=="foto") foto=xmlStreamReader.readElementText();
                if(xmlStreamReader.name()=="team") team=xmlStreamReader.readElementText();
                if(xmlStreamReader.name()=="y") anno=xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="m") mese=xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="d") giorno=xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="maxpts") maxpts=xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="maxreb") maxreb=xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="maxass") maxass=xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="seaspts") seaspts=xmlStreamReader.readElementText().toDouble();
                if(xmlStreamReader.name()=="seasreb") seasreb=xmlStreamReader.readElementText().toDouble();
                if(xmlStreamReader.name()=="seasass") {seasass=xmlStreamReader.readElementText().toDouble();
                    Player* p=new Player(nome,cognome,team,foto,anno,mese,giorno,maxpts,maxreb,maxass,seaspts,seasreb,seasass);
                    allPlayer.push_back(p);
                }
        }
        xmlStreamReader.readNext();
        }
        file.close();
    }
}

void Data::loadUser(QString path)
{
    QFile file(path);
    QString user,pass,prem;int d=0,m=0,y=0;
    if(file.open(QFile::ReadOnly)) {
        QXmlStreamReader xmlStreamReader(&file);
        xmlStreamReader.readNext();
        while(!xmlStreamReader.atEnd()) {
            if(xmlStreamReader.isStartElement()) {
                if(xmlStreamReader.name()=="user") user=xmlStreamReader.readElementText();
                if(xmlStreamReader.name()=="pass") pass=xmlStreamReader.readElementText();
                if(xmlStreamReader.name()=="d") d=xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="m") m=xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="y") y=xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="prem") {prem=xmlStreamReader.readElementText();
                    if(prem=="yes") {QDate* scad=new QDate(y,m,d);UtentePrem* u=new UtentePrem(user,pass,*scad);allUser.push_back(u);}
                    else {Utente* um=new Utente(user,pass);allUser.push_back(um);}

                }

        }
        xmlStreamReader.readNext();
        }
        file.close();
    }

}

void Data::loadGame(QString path)
{
    QFile file(path);
    QString home,away,link;
    int Hpts=0,Apts=0,Hreb=0,Areb=0,Hass=0,Aass=0,y=0,m=0,d=0,h=0,min=0;
    double Hfg=0,Afg=0,H3p=0,A3p=0;
    QStringList htab,atab;
    if(file.open(QFile::ReadOnly)) {
        QXmlStreamReader xmlStreamReader(&file);
        xmlStreamReader.readNext();
        while(!xmlStreamReader.atEnd()) {
            if(xmlStreamReader.isStartElement()) {
                if(xmlStreamReader.name()=="home") home=xmlStreamReader.readElementText();
                if(xmlStreamReader.name()=="away") away=xmlStreamReader.readElementText();
                if(xmlStreamReader.name()=="link") link=xmlStreamReader.readElementText();
                if(xmlStreamReader.name()=="hpts") Hpts=xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="apts") Apts=xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="hreb") Hreb=xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="areb") Areb=xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="hass") Hass=xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="aass") Aass=xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="hfg") Hfg=xmlStreamReader.readElementText().toDouble();
                if(xmlStreamReader.name()=="afg") Afg=xmlStreamReader.readElementText().toDouble();
                if(xmlStreamReader.name()=="h3p") H3p=xmlStreamReader.readElementText().toDouble();
                if(xmlStreamReader.name()=="a3p") A3p=xmlStreamReader.readElementText().toDouble();
                if(xmlStreamReader.name()=="y") y=xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="m") m=xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="d") d=xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="h") {h=xmlStreamReader.readElementText().toInt();htab.clear();atab.clear();}
                if(xmlStreamReader.name()=="min")
                {
                    min=xmlStreamReader.readElementText().toInt();
                    Game* g=new Game(home,away,link,Hpts,Apts,Hreb,Areb,Hass,Aass,Hfg,Afg,H3p,A3p,y,m,d,h,min,htab,atab);
                    allGame.push_back(g);//qDebug()<<"aggiunto game";
                }
                if(xmlStreamReader.name()=="htab") {
                    htab<<xmlStreamReader.readElementText();
                }
                if(xmlStreamReader.name()=="atab") {
                    atab<<xmlStreamReader.readElementText();
                }
            }
        xmlStreamReader.readNext();
        }

    file.close();
    }
}

Game* Data::searchGame(QString away, QDate date) const
{
    Game* g=0;
    for(int i=0;i<allGame.size();i++)
    {
        if(date==allGame.at(i)->getData().date())
            if(away==allGame.at(i)->getAway()) g=allGame.at(i);
    }

    return g;
}



Team *Data::findTeam(const QString & nome) const
{
    for(int i=0;i<allTeam.size();i++)
    {
        if(nome==allTeam.at(i)->getNome()) return allTeam.at(i);
    }
    return 0;
}



bool Data::findPlayer(QString a, QString b) const //ricerca da almeno 2 lettere
{
    int j=0; bool f=false; a=a.toLower();b=b.toLower();
    if(a.size()>b.size()) return false;
    while(j<=b.size()-a.size())
    {
        if(a.at(0)==b.at(j)) for(int i=1,z=j+1;i<a.size();) {
            if(a.at(i)==b.at(z)&&i==(a.size()-1)) {f=true;i++;}
            else if(a.at(i)==b.at(z)) {i++;z++;}
            else i=a.size();
        }
        j++;
    }
    return f;
}

Utente *Data::findUser(const QString &u) const
{
    for(int i=0;i<allUser.size();i++)
        if(u==allUser.at(i)->getUsername()) return allUser.at(i);
    return 0;
}

void Data::deleteTutto()
{
    for(int i=0;i<allGame.size();i++)
        delete allGame.at(i);
    for(int i=0;i<allUser.size();i++)
        delete allUser.at(i);
    for(int i=0;i<allPlayer.size();i++)
        delete allPlayer.at(i);
    for(int i=0;i<allTeam.size();i++)
        delete allTeam.at(i);

}

void Data::ordinaTeam(Team *t)
{
    int i=0;
    if(allTeam.isEmpty()) {allTeam.push_back(t);return;}
    else
    {
        i=0;
        while(i<allTeam.size()&&t->getPerc()<allTeam.at(i)->getPerc()) i++;
        if(i==allTeam.size()) {allTeam.push_back(t);return;}
        else
            allTeam.insert(i,t);

    }


}

Data::~Data()
{
    deleteTutto();

}

