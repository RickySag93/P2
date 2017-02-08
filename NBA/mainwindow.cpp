#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ct=new Controller();
    listaSquad=0;
    log=0;
    reg=0;
    addPlayer=0;
    listaPlayers=0;
    modifUsers=0;
    infogame=0;
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
    loadMatch(ui->dateEdit->date(),ct);

    ui->menuAmministratore->setEnabled(false);

    QObject::connect(ui->dateEdit,SIGNAL(dateChanged(QDate)),this,SLOT(on_dateEdit_userDateChanged(QDate)));
}

void MainWindow::loadMatch(QDate data,Controller *ct)
{

    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->setCursor(Qt::PointingHandCursor);
    ui->tableWidget->setColumnCount(5);
    int row=0;
    QStringList colonne;
    colonne<<"Away"<<"Punteggio"<<"Home"<<"Orario Inizio"<<"Info";
    ui->tableWidget->setHorizontalHeaderLabels(colonne);
    for(int i=0;i<ct->getData().getListaGame().size();i++)
    {
       if(data==ct->getData().getListaGame().at(i)->getData().date())
        {
        ui->tableWidget->setRowCount(row+1);
        QTableWidgetItem* Home=new QTableWidgetItem(ct->getData().getListaGame().at(i)->getHome());
        QTableWidgetItem* Away=new QTableWidgetItem(ct->getData().getListaGame().at(i)->getAway());
        QString punt=QString::number(ct->getData().getListaGame().at(i)->getApts())+" - "+QString::number(ct->getData().getListaGame().at(i)->getHpts());
        QTableWidgetItem* punteg=new QTableWidgetItem(punt);
        QTime t=ct->getData().getListaGame().at(i)->getData().time();QString tim=t.toString();
        QTableWidgetItem* time=new QTableWidgetItem(tim);QTableWidgetItem* info=new QTableWidgetItem();
        QIcon inf("../NBA/more_info.png");
        info->setIcon(inf);
        Away->setFlags(Qt::ItemIsSelectable);
        Home->setFlags(Qt::ItemIsSelectable);
        punteg->setFlags(Qt::ItemIsSelectable);
        time->setFlags(Qt::ItemIsSelectable);
        ui->tableWidget->setItem(row,0,Away);
        ui->tableWidget->setItem(row,1,punteg);
        ui->tableWidget->setItem(row,2,Home);
        ui->tableWidget->setItem(row,3,time);
        ui->tableWidget->setItem(row,4,info);
        row++;
        }
    }
    ui->tableWidget->sortItems(3);
}

void MainWindow::build_action(int row, int col)
{
    if(col==4){
        QString aw=ui->tableWidget->item(row,0)->text();
        Game* game=ct->searchGame(aw,ui->dateEdit->date());
        QString Hlogo=ct->getLogo(game->getHome());
        QString Alogo=ct->getLogo(game->getAway());
        if(infogame) infogame->close();
        infogame=new InfoGame(0,game,Hlogo,Alogo);
        infogame->show();
        }
}

MainWindow::~MainWindow()
{

    if(log) delete log;
    if(reg) delete reg;
    if(addPlayer) delete addPlayer;
    if(listaPlayers) delete listaPlayers;
    if(modifUsers) delete modifUsers;
    if(infogame) delete infogame;
    if(listaSquad) delete listaSquad;
    delete ct;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ct->getData().getUtente()->isPremium())
    {
    listaSquad=new Squadre(0,ct);
    listaSquad->show();
    }
    else {
       QMessageBox msg;
       msg.setText("Devi essere utente premium!");
       int ret=msg.exec();
       if(ret==QMessageBox::Ok){}
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(ct->getUtente()&&ct->getUtente()->getUsername()!="guest")
    {
        QMessageBox msg;
        msg.setText("Sei già loggato con il nome di: "+ct->getUtente()->getUsername());
        msg.setInformativeText("Vuoi uscire?");
        msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        int ret=msg.exec();

        if(ret==QMessageBox::Yes) {ct->setUtente(ct->getData().getListaUtenti().at(0));ui->menuAmministratore->setEnabled(false);}
    }
    else
    {
        log=new Login(0,ui->menuAmministratore,ct);
        log->show();
    }
}

void MainWindow::on_registrati_clicked()
{
    reg=new Registrazione(0,ct);
    reg->show();
}







void MainWindow::on_actionAggiungi_Giocatore_triggered()
{
    if(ct->getUtente()->getUsername()=="admin")
    {
    addPlayer=new AddGiocatore(0,ct);
    addPlayer->show();
    }
    else
    {
        QMessageBox msg;
        msg.setText("Solo l'amministratore può eseguire questa operazione");
        int ret=msg.exec();
        if(ret==QMessageBox::Ok){}
    }
}

void MainWindow::on_actionAggiorna_Liste_triggered()
{
    if(ct->getUtente()->getUsername()=="admin")
    {
    ct=new Controller(1);
    QMessageBox msg;
    msg.setText("Aggiornato");
    int ret=msg.exec();
    if(ret==QMessageBox::Ok){}
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if(ct->getData().getUtente()->isPremium())
    {
    listaPlayers=new Giocatori(0,ct);
    listaPlayers->show();
    }
    else {
       QMessageBox msg;
       msg.setText("Devi essere utente premium!");
       int ret=msg.exec();
       if(ret==QMessageBox::Ok){}
    }
}

void MainWindow::on_actionModifica_Utenti_triggered()
{
    if(ct->getUtente()->getUsername()=="admin")
    {
    modifUsers=new ModifUtente(0,ct);
    modifUsers->show();
    }
    else
    {
        QMessageBox msg;
        msg.setText("Solo l'amministratore può eseguire questa operazione");
        int ret=msg.exec();
        if(ret==QMessageBox::Ok){}
    }
}

void MainWindow::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    if(ct->getData().getUtente()->isPremium()) build_action(item->row(),item->column());
    else
    {
        QMessageBox msg;
        msg.setText("Devi essere utente premium!");
        int ret=msg.exec();
        if(ret==QMessageBox::Ok){}
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(log) log->closeEvent(event);
    if(reg) reg->closeEvent(event);
    if(listaPlayers) listaPlayers->closeEvent(event);
    if(listaSquad) listaSquad->close();
    if(addPlayer) addPlayer->closeEvent(event);
    if(modifUsers) modifUsers->closeEvent(event);
    if(infogame) infogame->closeEvent(event);
    QMainWindow::closeEvent(event);
}

void MainWindow::on_dateEdit_userDateChanged(const QDate &date)
{
    loadMatch(date,ct);
}
