#include "squadre.h"
#include "ui_squadre.h"

Squadre::Squadre(QWidget *parent, Controller *ctrl) :
    QWidget(parent),
    ui(new Ui::Squadre)
{
    ui->setupUi(this);
    ct=ctrl;
    info=0;
    showTeam();
}



void Squadre::showTeam()
{
    int i=0,w=0,e=0;
    while(i<ct->getData().getListaTeam().count()){
    QListWidgetItem *newItem = new QListWidgetItem;
    newItem->setText(ct->getData().getListaTeam().at(i)->getCity()+" "+ct->getData().getListaTeam().at(i)->getNome());
    newItem->setIcon(QIcon(ct->getData().getListaTeam().at(i)->getLogo()));
    if(ct->getData().getListaTeam().at(i)->getConf()=="West")
    {ui->listWest->insertItem(w, newItem);w++;}
    else
    {ui->listEast->insertItem(e, newItem);e++;}
    i++;}
}

void Squadre::closeEvent(QCloseEvent *event)
{
    if(info) info->close();
    QWidget::closeEvent(event);
}


void Squadre::on_listEast_itemDoubleClicked(QListWidgetItem *item)
{
    QString tex=item->text();int i=0;
    while (tex!=ct->getData().getListaTeam().at(i)->getCity()+" "+ct->getData().getListaTeam().at(i)->getNome()) i++;
    Team* tt=ct->getData().getListaTeam().at(i);
    if(info) {
        info->close();
        InfoTeam* tmp=info;
        info=new InfoTeam(0,tt);
        delete tmp;
        info->show();
    }
    else{
    info=new InfoTeam(0,tt);
    info->show();}
}

void Squadre::on_listWest_itemDoubleClicked(QListWidgetItem *item)
{
    QString tex=item->text();int i=0;
    while (tex!=ct->getData().getListaTeam().at(i)->getCity()+" "+ct->getData().getListaTeam().at(i)->getNome()) i++;
    Team* tt=ct->getData().getListaTeam().at(i);
    if(info) {
        info->close();
        InfoTeam* tmp=info;
        info=new InfoTeam(0,tt);
        delete tmp;
        info->show();
    }
    else{
    info=new InfoTeam(0,tt);
    info->show();}
}

Squadre::~Squadre()
{
    if(info) delete info;
    delete ui;
}
