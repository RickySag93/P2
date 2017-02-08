#include "registrazione.h"
#include "ui_registrazione.h"

Registrazione::Registrazione(QWidget *parent, Controller *ctrl) :
    QDialog(parent),
    ui(new Ui::Registrazione)
{
    ct=ctrl;
    ui->setupUi(this);
}


void Registrazione::save(QString path,Utente* u)
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
  //nuovo utente
    xmlStreamWriter.writeStartElement("utente");
    xmlStreamWriter.writeTextElement("user",u->getUsername());
    xmlStreamWriter.writeTextElement("pass",u->getPassword());
    UtentePrem* utt=dynamic_cast<UtentePrem*>(u);
    if(utt)
    {
        xmlStreamWriter.writeTextElement("d",QString::number(utt->getScadenza().day()));
        xmlStreamWriter.writeTextElement("m",QString::number(utt->getScadenza().month()));
        xmlStreamWriter.writeTextElement("y",QString::number(utt->getScadenza().year()));
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
//fine nuovo utente
    xmlStreamWriter.writeEndDocument();
    file.close();
}

void Registrazione::closeEvent(QCloseEvent *event)
{
    QDialog::closeEvent(event);
}

Registrazione::~Registrazione()
{
    delete ui;
}

void Registrazione::on_buttonBox_accepted()
{
    QString user=ui->username->text();
    QString pass=ui->password->text();

    bool found=false;int i=0;
    while (!found&&i<ct->getData().getListaUtenti().count())
    {
        if(user==ct->getData().getListaUtenti().at(i)->getUsername()) found=true;
        else i++;
    }
    if (!found)
    {
        if (ui->Premium->isChecked())
        {
            QDate* d=new QDate(QDate::currentDate());
            *d=d->addYears(1);
            UtentePrem* u=new UtentePrem(user,pass,*d);
            save(ct->getData().getFileDataUser(),u);
        }
        else
        {
        Utente* u=new Utente(user,pass);
        save(ct->getData().getFileDataUser(),u);
        }
        QMessageBox msg;
        msg.setText("Riavvia l'applicazione per poter accedere con il tuo nuovo account!");
        int ret=msg.exec();
        if(ret==QMessageBox::Ok) {msg.close();}
    }
    else
    {
        QMessageBox msg;
        msg.setText("Username già in uso!");
        msg.setInformativeText("Prova con un altro");
        msg.setStandardButtons(QMessageBox::Ok);
        int ret=msg.exec();
        if(ret==QMessageBox::Ok) {msg.close();this->show();}
    }
}
