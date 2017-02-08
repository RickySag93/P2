#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "squadre.h"
#include "controller.h"
#include "utente.h"
#include "login.h"
#include "registrazione.h"
#include  "addgiocatore.h"
#include "giocatori.h"
#include "modifutente.h"
#include "infogame.h"
#include <QDebug>
#include <QMessageBox>
#include <QTableWidget>
#include <QDateEdit>
#include <QVBoxLayout>
#include <QFileDialog>

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    void build_action(int,int);
    void closeEvent(QCloseEvent* event);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_registrati_clicked();

void loadMatch(QDate data, Controller* ct);


    void on_actionAggiungi_Giocatore_triggered();

    void on_actionAggiorna_Liste_triggered();

    void on_pushButton_3_clicked();

    void on_actionModifica_Utenti_triggered();

    void on_tableWidget_itemClicked(QTableWidgetItem *item);

    void on_dateEdit_userDateChanged(const QDate &date);

private:
    Ui::MainWindow *ui;
    Squadre* listaSquad;
    Login* log;
    Registrazione* reg;
    Controller* ct;
    AddGiocatore* addPlayer;
    Giocatori* listaPlayers;
    ModifUtente* modifUsers;
    InfoGame* infogame;

};

#endif // MAINWINDOW_H
