#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent,QMenu* main, Controller *ctr) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ct=ctr;
    mainw=main;
    ui->setupUi(this);
}

void Login::closeEvent(QCloseEvent *event)
{
    QDialog::closeEvent(event);
}

Login::~Login()
{
    delete ui;
}

void Login::on_buttonBox_rejected()
{
    this->close();
}

void Login::on_buttonBox_accepted()
{
    QString user=ui->Username->text();
    QString pass=ui->Password->text();
    Utente* loc=new Utente(user,pass);
    bool found=false;int i=0;
    while (!found&&i<ct->getData().getListaUtenti().count())
    {
        if(loc->getUsername()==ct->getData().getListaUtenti().at(i)->getUsername()&&loc->getPassword()==ct->getData().getListaUtenti().at(i)->getPassword()) found=true;
        else i++;
    }

    if(found){
    ct->setUtente(ct->getData().getListaUtenti().at(i));//qDebug()<<ct->getData().getUtente()->getUsername();
    if(ct->getUtente()->getUsername()=="admin") mainw->setEnabled(true);
    QMessageBox msg;msg.setText("Log-in riuscito!");int ret=msg.exec();if(ret==QMessageBox::Ok){}
    }
    else {QMessageBox msg;msg.setText("Nome utente o password non validi");int ret=msg.exec();if(ret==QMessageBox::Ok){}}
}


