#include "modifutente.h"
#include "ui_modifutente.h"

ModifUtente::ModifUtente(QWidget *parent, Controller *ctrl) :
    QDialog(parent),
    ui(new Ui::ModifUtente)
{
    ct=ctrl;
    utente=0;
    ui->setupUi(this);
    showUtenti();
}

void ModifUtente::showUtenti()
{
    for(int i=0;i<ct->getData().getListaUtenti().size();i++) {
        QListWidgetItem* item=new QListWidgetItem;
        item->setText(ct->getData().getListaUtenti().at(i)->getUsername());
        ui->listUtenti->insertItem(i,item);
    }
}

void ModifUtente::save(QString path)
{
    int size=path.size();
    if(size<4 || path.at(size-1)!='l' || path.at(size-2)!='m' || path.at(size-3)!='x' || path.at(size-4)!='.') path+=".xml";
    QFile file(path);
    file.open(QIODevice::WriteOnly);
    QXmlStreamWriter xmlStreamWriter(&file);
    xmlStreamWriter.setAutoFormatting(true);
    xmlStreamWriter.writeStartDocument();
    xmlStreamWriter.writeStartElement("dati");
    for(int i=0;i<ct->getData().getListaUtenti().size();i++){
        xmlStreamWriter.writeStartElement("utente");
        xmlStreamWriter.writeTextElement("user",ct->getData().getListaUtenti().at(i)->getUsername());
        xmlStreamWriter.writeTextElement("pass",ct->getData().getListaUtenti().at(i)->getPassword());
        UtentePrem* ut=dynamic_cast<UtentePrem*>(ct->getData().getListaUtenti().at(i));
        if(ut)
        {
            xmlStreamWriter.writeTextElement("d",QString::number(ut->getScadenza().day()));
            xmlStreamWriter.writeTextElement("m",QString::number(ut->getScadenza().month()));
            xmlStreamWriter.writeTextElement("y",QString::number(ut->getScadenza().year()));
            xmlStreamWriter.writeTextElement("prem","yes");
            xmlStreamWriter.writeEndElement();
        }
        else
        {
            xmlStreamWriter.writeTextElement("d",QString::number(0));
            xmlStreamWriter.writeTextElement("m",QString::number(0));
            xmlStreamWriter.writeTextElement("y",QString::number(0));
            xmlStreamWriter.writeTextElement("prem","no");
            xmlStreamWriter.writeEndElement();
        }
    }

    xmlStreamWriter.writeEndDocument();
    file.close();
}

void ModifUtente::saveWithout(QString path, int j)
{
    int size=path.size();
    if(size<4 || path.at(size-1)!='l' || path.at(size-2)!='m' || path.at(size-3)!='x' || path.at(size-4)!='.') path+=".xml";
    QFile file(path);
    file.open(QIODevice::WriteOnly);
    QXmlStreamWriter xmlStreamWriter(&file);
    xmlStreamWriter.setAutoFormatting(true);
    xmlStreamWriter.writeStartDocument();
    xmlStreamWriter.writeStartElement("dati");
    for(int i=0;i<ct->getData().getListaUtenti().size();i++){
        if(i!=j){
            xmlStreamWriter.writeStartElement("utente");
            xmlStreamWriter.writeTextElement("user",ct->getData().getListaUtenti().at(i)->getUsername());
            xmlStreamWriter.writeTextElement("pass",ct->getData().getListaUtenti().at(i)->getPassword());
            UtentePrem* ut=dynamic_cast<UtentePrem*>(ct->getData().getListaUtenti().at(i));
            if(ut)
            {
                xmlStreamWriter.writeTextElement("d",QString::number(ut->getScadenza().day()));
                xmlStreamWriter.writeTextElement("m",QString::number(ut->getScadenza().month()));
                xmlStreamWriter.writeTextElement("y",QString::number(ut->getScadenza().year()));
                xmlStreamWriter.writeTextElement("prem","yes");
                xmlStreamWriter.writeEndElement();
            }
            else
            {
                xmlStreamWriter.writeTextElement("d",QString::number(0));
                xmlStreamWriter.writeTextElement("m",QString::number(0));
                xmlStreamWriter.writeTextElement("y",QString::number(0));
                xmlStreamWriter.writeTextElement("prem","no");
                xmlStreamWriter.writeEndElement();
            }
        }
    }

    xmlStreamWriter.writeEndDocument();
    file.close();
}

void ModifUtente::closeEvent(QCloseEvent *event)
{
    QDialog::closeEvent(event);
}

ModifUtente::~ModifUtente()
{
    delete ui;
}


void ModifUtente::on_listUtenti_itemClicked(QListWidgetItem *item)
{
    utente=ct->findUser(item->text());qDebug()<<utente->getUsername();
    ui->username->setText(utente->getUsername());
    ui->password->setText(utente->getPassword());
    //if(dynamic_cast<const UtentePrem*>(utente)) ui->premium->setChecked(true);
    //else ui->premium->setChecked(false);
}

void ModifUtente::on_pushButton_clicked()
{
    utente->setUsername(ui->username->text());
    utente->setPassword(ui->password->text());
    //if(ui->premium->isChecked()) utente->setPremium(true);
    //else utente->setPremium(false);
    save(ct->getData().getFileDataUser());

}

void ModifUtente::on_elimina_clicked()
{
    int i=0;
    while(utente->getUsername()!=ct->getData().getListaUtenti().at(i)->getUsername()) i++;
    ct->getData().getListaUtenti().remove(i);
    saveWithout(ct->getData().getFileDataUser(),i);
    QMessageBox msg;
    msg.setText("Aggiorna le liste ora");
    int ret=msg.exec();
    if(ret==QMessageBox::Ok) this->close();
}
