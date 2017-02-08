#include "giocatori.h"
#include "ui_giocatori.h"

Giocatori::Giocatori(QWidget *parent, Controller *ctrl) :
    QDialog(parent),
    ui(new Ui::Giocatori)
{
    ct=ctrl;
    infopl=0;
    ui->setupUi(this);
    showPlayers();
    ui->comboBox->addItem("");
    for(int i=0;i<ct->getData().getListaTeam().size();i++)
        ui->comboBox->addItem(ct->getData().getListaTeam().at(i)->getNome());

}

void Giocatori::showPlayers()
{
    for(int i=0;i<ct->getData().getListaPlayers().size();i++)
    {
        QListWidgetItem* item=new QListWidgetItem;
        item->setText(ct->getData().getListaPlayers().at(i)->getNome()+" "+ct->getData().getListaPlayers().at(i)->getCognome());
        ui->listGiocatori->insertItem(i,item);
    }
    ui->listGiocatori->sortItems(Qt::AscendingOrder);
}

void Giocatori::closeEvent(QCloseEvent *event)
{
    if(infopl) infopl->close();
    QDialog::closeEvent(event);
}

Giocatori::~Giocatori()
{
    if(infopl) delete infopl;
    delete ui;
}

void Giocatori::on_pushButton_clicked()
{
    ui->listGiocatori->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->lineEdit->clear();
    showPlayers();
}



void Giocatori::on_pushButton_2_clicked()
{
    ui->listGiocatori->clear();
    ui->comboBox->setCurrentIndex(0);
    QString n=ui->lineEdit->text();
    if(n.size()<2) return;
    for(int i=0;i<ct->getData().getListaPlayers().size();i++)
    {
        if(ct->findPlayer(n,ct->getData().getListaPlayers().at(i)->getNome()) || ct->findPlayer(n,ct->getData().getListaPlayers().at(i)->getCognome()))
        {
            QListWidgetItem* item=new QListWidgetItem;
            item->setText(ct->getData().getListaPlayers().at(i)->getNome()+" "+ct->getData().getListaPlayers().at(i)->getCognome());
            ui->listGiocatori->insertItem(i,item);
        }
    }
    ui->listGiocatori->sortItems(Qt::AscendingOrder);

}

void Giocatori::on_listGiocatori_itemDoubleClicked(QListWidgetItem *item)
{
    QString nome=item->text();Player*p=0;
    for(int i=0;i<ct->getData().getListaPlayers().size();i++) {
        if(nome==ct->getData().getListaPlayers().at(i)->getNome()+" "+ct->getData().getListaPlayers().at(i)->getCognome())
            p=ct->getData().getListaPlayers().at(i);
    }
    if(infopl)
    {
        infopl->close();
        InfoPlayer* tmp=infopl;
        infopl=new InfoPlayer(0,p);
        delete tmp;
        infopl->show();
    }
    else{
    infopl=new InfoPlayer(0,p);
    infopl->show();}
}



void Giocatori::on_comboBox_currentIndexChanged(const QString &arg1)
{
        if(arg1=="") return;
        ui->listGiocatori->clear();


    for(int i=0;i<ct->getData().getListaPlayers().size();i++)
        {
            if(arg1==ct->getData().getListaPlayers().at(i)->getTeam())
            {
                QListWidgetItem* item=new QListWidgetItem;
                item->setText(ct->getData().getListaPlayers().at(i)->getNome()+" "+ct->getData().getListaPlayers().at(i)->getCognome());
                ui->listGiocatori->insertItem(i,item);
            }
        }

}
