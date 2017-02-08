#include "addgiocatore.h"
#include "ui_addgiocatore.h"

AddGiocatore::AddGiocatore(QWidget *parent,Controller*ctrl) :
    QDialog(parent),
    ui(new Ui::AddGiocatore)
{
    ct=ctrl;
    ui->setupUi(this);
}

void AddGiocatore::save(QString path, Player *player)
{
    int size=path.size();
    if(size<4 || path.at(size-1)!='l' || path.at(size-2)!='m' || path.at(size-3)!='x' || path.at(size-4)!='.') path+=".xml";
    QFile file(path);
    file.open(QIODevice::WriteOnly);
    QXmlStreamWriter xmlStreamWriter(&file);
    xmlStreamWriter.setAutoFormatting(true);
    xmlStreamWriter.writeStartDocument();
    xmlStreamWriter.writeStartElement("dati");
    for(int i=0;i<ct->getData().getListaPlayers().size();i++){
        xmlStreamWriter.writeStartElement("player");
        xmlStreamWriter.writeTextElement("nome",ct->getData().getListaPlayers().at(i)->getNome());
        xmlStreamWriter.writeTextElement("cognome",ct->getData().getListaPlayers().at(i)->getCognome());
        xmlStreamWriter.writeTextElement("foto",ct->getData().getListaPlayers().at(i)->getFoto());
        xmlStreamWriter.writeTextElement("team",ct->getData().getListaPlayers().at(i)->getTeam());
        xmlStreamWriter.writeTextElement("y",QString::number(ct->getData().getListaPlayers().at(i)->getBirthday().year()));
        xmlStreamWriter.writeTextElement("m",QString::number(ct->getData().getListaPlayers().at(i)->getBirthday().month()));
        xmlStreamWriter.writeTextElement("d",QString::number(ct->getData().getListaPlayers().at(i)->getBirthday().day()));
        xmlStreamWriter.writeTextElement("maxpts",QString::number(ct->getData().getListaPlayers().at(i)->getMaxPts()));
        xmlStreamWriter.writeTextElement("maxreb",QString::number(ct->getData().getListaPlayers().at(i)->getMaxReb()));
        xmlStreamWriter.writeTextElement("maxass",QString::number(ct->getData().getListaPlayers().at(i)->getMaxAss()));
        xmlStreamWriter.writeTextElement("seaspts",QString::number(ct->getData().getListaPlayers().at(i)->getSeasPts()));
        xmlStreamWriter.writeTextElement("seasreb",QString::number(ct->getData().getListaPlayers().at(i)->getSeasReb()));
        xmlStreamWriter.writeTextElement("seasass",QString::number(ct->getData().getListaPlayers().at(i)->getSeasAss()));

        xmlStreamWriter.writeEndElement();
    }
    xmlStreamWriter.writeStartElement("game");
    xmlStreamWriter.writeTextElement("nome",player->getNome());
    xmlStreamWriter.writeTextElement("cognome",player->getCognome());
    xmlStreamWriter.writeTextElement("foto",player->getFoto());
    xmlStreamWriter.writeTextElement("team",player->getTeam());
    xmlStreamWriter.writeTextElement("y",QString::number(player->getBirthday().year()));
    xmlStreamWriter.writeTextElement("m",QString::number(player->getBirthday().month()));
    xmlStreamWriter.writeTextElement("d",QString::number(player->getBirthday().day()));
    xmlStreamWriter.writeTextElement("maxpts",QString::number(player->getMaxPts()));
    xmlStreamWriter.writeTextElement("maxreb",QString::number(player->getMaxReb()));
    xmlStreamWriter.writeTextElement("maxass",QString::number(player->getMaxAss()));
    xmlStreamWriter.writeTextElement("seaspts",QString::number(player->getSeasPts()));
    xmlStreamWriter.writeTextElement("seasreb",QString::number(player->getSeasReb()));
    xmlStreamWriter.writeTextElement("seasass",QString::number(player->getSeasAss()));

    xmlStreamWriter.writeEndElement();

    xmlStreamWriter.writeEndDocument();
    file.close();
}

void AddGiocatore::closeEvent(QCloseEvent *event)
{
    QDialog::closeEvent(event);
}

AddGiocatore::~AddGiocatore()
{
    delete ui;
}

void AddGiocatore::on_buttonBox_accepted()
{
    QString nome,cognome,squadra,foto;
    int anno,mese,giorno,maxpts,maxreb,maxass;
    double seaspts,seasreb,seasass;
    nome=ui->nome->text();
    cognome=ui->cognome->text();
    squadra=ui->team->text();
    anno=ui->birthday->date().year();
    foto=ui->foto->text();
    mese=ui->birthday->date().month();
    giorno=ui->birthday->date().day();
    maxpts=ui->maxpts->text().toInt();
    maxreb=ui->maxreb->text().toInt();
    maxass=ui->maxass->text().toInt();
    seaspts=ui->seaspts->text().toDouble();
    seasreb=ui->seasreb->text().toDouble();
    seasass=ui->seasass->text().toDouble();
    Player* player=new Player(nome,cognome,squadra,foto,anno,mese,giorno,maxpts,maxreb,maxass,seaspts,seasreb,seasass);
    save(ct->getData().getFileDataPlayer(),player);qDebug()<<"player salvato";
    QMessageBox msg;
    msg.setText("Giocatore aggiunto");
    int ret=msg.exec();
    if(ret==QMessageBox::Ok) {msg.close();}

}


